#include <cstdio>
#include <queue>
#include <unistd.h>
#include <pthread.h>

typedef void (*handler_t)(int data); //定义函数指针类型
class ThreadTask{
    private:
        int _data;//线程池中线程要处理的数据
        handler_t _handler;//线程池中线程要执行的处理函数，使用这个函数处理数据
    public:
        void SetTask(int data, handler_t handler) {
            _data = data;
            _handler = handler;
        }//传入数据与处理函数，设置任务
        void Run() {  
            return _handler(_data) ;  
        };//提供公有接口调用就能够完成任务处理
};
#define MAX_QUEUE 10
#define MAX_THREAD 5
class ThreadPool{
    private:
        int thr_max;//线程池中线程的最大数量，初始化时创建这么多个线程
        std::queue<ThreadTask> _queue;//因为队列没有设置最大数量限制因此生产者直接入队数据即可不需要等待
        pthread_mutex_t _mutex;
        pthread_cond_t _cond_pop;//用户消费者-线程池中线程在没有数据的时候阻塞
    private:
        static void *thread_start(void *arg) {
            ThreadPool *pool = (ThreadPool*)arg;
            while(1) {
                pthread_mutex_lock(&pool->_mutex);
                while(pool->_queue.empty()) {
                    pthread_cond_wait(&pool->_cond_pop, &pool->_mutex);
                }
                ThreadTask task;
                task = pool->_queue.front();
                pool->_queue.pop();
                pthread_mutex_unlock(&pool->_mutex);
                task.Run();//----任务处理一定要放到解锁之后进行
            }
            return NULL;
        }//线程入口函数，不断循环从队列中取出任务，执行Run完成任务处理。
    public:
        ThreadPool(int maxt = MAX_THREAD){
            pthread_mutex_init(&_mutex, NULL);
            pthread_cond_init(&_cond_pop, NULL);
            for (int i = 0; i < maxt; i++) {
                pthread_t tid;
                int ret = pthread_create(&tid, NULL, thread_start, (void*)this);
                if (ret != 0) {
                    printf("thread create error\n");
                    _exit(0);
                }
            }
        }
        ~ThreadPool() {
            pthread_mutex_destroy(&_mutex);
            pthread_cond_destroy(&_cond_pop);
        }
        bool PushTask(ThreadTask &tt) {
            pthread_mutex_lock(&_mutex);
            _queue.push(tt);
            pthread_mutex_unlock(&_mutex);
            pthread_cond_signal(&_cond_pop);
            return  true;
        }//任务入队函数
};

void test(int data)
{
    printf("%p get a data:%d\n", pthread_self(), data);
    sleep(3);
}
int main (int argc, char *argv[])
{
    ThreadPool pool;
    
    for (int i = 0; i < 10; i++) {
        ThreadTask task;
        task.SetTask(i, test);
        pool.PushTask(task);
    }
    while(1) {
        sleep(1);
    }
    return 0;
}

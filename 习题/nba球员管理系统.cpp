#include <stdio.h>
#include <stdlib.h>             //exit函数头文件 
#include <string.h>             //字符串相关操作头文件 
#define  MAX_STUDENT  30        //最大学生数 

//函数声明，本程序共10个子函数，每个函数对应一个操作 
void student_scanf(int n);
void student_printf(int n);
int student_find_name(int n);
int student_find_num(int n);
void student_sort_num(int n);
void student_sort_sum(int n);
int student_alter_num(int n);
int student_alter_name(int n);
int student_delete_num(int n);
int student_delete_name(int n);
//全局数组变量，用于存储学生信息 
char names[MAX_STUDENT][50];
int math[MAX_STUDENT];
int english[MAX_STUDENT];
int computer[MAX_STUDENT];
int sum[MAX_STUDENT];
int num[MAX_STUDENT];
//以下变量用于学生信息数组排序，作为临时数组 
int temp_num[MAX_STUDENT];
char temp_names[MAX_STUDENT][50];
int temp_math[MAX_STUDENT];
int temp_english[MAX_STUDENT];
int temp_computer[MAX_STUDENT];
int temp_sum[MAX_STUDENT];
//sort数组存储排好序的学号或姓名下标 
int sort[MAX_STUDENT];
//循环全局变量 
int i, j;

//main主函数
int main(void)
{
    int choice,n;
    while (1)
    {
        printf("*************************************\n");
        printf("欢迎使用学生成绩管理系统\n");
        printf("[1] 输入球员信息\n");
        printf("[2] 输出所有球员成绩\n");
        printf("[3] 按号码查找某个球员信息\n");
        printf("[4] 按姓名查找某个球员信息\n");
        //printf("[5] 按学号对学生排序\n");
        //printf("[6] 按总成绩对学生排序\n");
        printf("[5] 按号码修改某个球员信息\n");
        printf("[6] 按姓名修改某个球员信息\n");
        printf("[7] 按号码删除某个球员信息\n");
        printf("[8] 按姓名删除某个球员信息\n");
        printf("[0] 退出程序\n");
        printf("请输入您的选择（0 - 8）:");
        scanf("%d",&choice);
        printf("**************************************)\n");

        switch (choice)
        {
        case 1://录入;
            printf("请输入录入的球员信息数： ");
            scanf("%d",&n); 
            student_scanf(n);
            break;

        case 2://输出;
            student_printf(n);
            break;

        case 3://根据学号查找
            student_find_num(n);
            break;

        case 4://根据姓名查找
            student_find_name(n);
            break;

        /*case 5://按学号排序
            student_sort_num(n);
            break;

        case 6://按姓名排序 
            student_sort_sum(n);
            break;*/ 

        case 5://按学号修改 
            student_alter_num(n);
            break;

        case 6://按姓名修改 
            student_alter_name(n);
            break;

        case 7://按学号删除 
            student_delete_num(n);
            n--;
            break;

        case 8://按姓名删除 
            student_delete_name(n);
            n--;
            break;

        case 0://退出程序 
            printf("退出程序\n");
            printf("程序结束，谢谢使用!\n");
            exit(0);

        default:
            printf("您输入的菜单有误。请重新输入！\n");

        }

    }
    return 0;
}
//1.输入信息
void student_scanf(int n)
{

    for (i = 0; i<n; ++i)
    {
        printf("\n请输入第%d个球员的信息:\n", i + 1);
        
        printf("\n姓名:");
        scanf("%s", names[i]);
		printf("\n号码:");
        scanf("%d", &num[i]);
        printf("\n身高:");
        scanf("%d", &math[i]);
        printf("\n臂展:");
        scanf("%d", &english[i]);
        printf("\n体重:");
        scanf("%d", &computer[i]);
        printf("\n年龄:");
        scanf("%d", &sum[i]);
        
    }
}
//2.打印信息        
void student_printf(int n)
{

    printf("\n姓名\t号码\t身高\t臂展\t体重\t年龄\n");
    printf("----------------------------------------------------------\n");

    for (i = 0; i<n; ++i)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",  names[i],num[i], math[i], english[i], computer[i], sum[i]);
    }
    printf("-------------------------------------------------------\n");
}

//3.按学号查找
int student_find_num(int n)
{
    int nums;
    int result;
    printf("请输入待查找的球员号码:");
    scanf("%d",&nums);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (nums == num[i])
        {
            result = i;

            break;
        }

    }

    //最后判断q值
    if (result == -1)
    {
        printf("没有该球员信息!\n");
        return 0;
    }
    else
    {
        //先打印表头
         printf("\n姓名\t号码\t身高\t臂展\t体重\t年龄\n");
        //再打印数据

        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t%d\n",  names[result], num[result], math[result], english[result], computer[result], sum[result]);
        printf("打印出查找结果!\n");
    }
    return 1;
}

//4.用姓名查找成绩
int student_find_name(int n)
{
    char name[200];
    int result;
    printf("请输入待查找的球员姓名:");
    scanf("%s", name);
    result = -1;
    for (i = 0; i<n; ++i)
    {
        if (strcmp(name, names[i]) == 0)
        {
            result = i;
            break;
        }
    }
    if (result == -1)
    {//未找到结果
        printf("没有该球员信息!\n");
        return 0;
    }
    else//找到结果
    {
         printf("\n姓名\t号码\t身高\t臂展\t体重\t年龄\n");
        printf("%s\t%d\t%d\t\t%d\t\t%d\t\t%d\n", names[result], num[result], math[result], english[result], computer[result], sum[result]);
        printf("已完成查找!\n");
    }


    return 1;
}

//5.按学号排序
void student_sort_num(int n)
{
    int min,max;
    for(i=0; i<n; ++i)  //复制临时数组 
    {
        temp_num[i] = num[i];
    }

    max = 0;        //查找学号最大值，将其下标存至sort数组的最后一个值中 
    for(j=1; j<n; j++)
    {
        if(temp_num[max]<temp_num[j])
            max = j;
    } 
    sort[n-1] = max;    //sort数组的最后一个数 
    for(i=0; i<n-1; ++i)
    {
        min = i;        //查找学号最小值
        for(j=0; j<n; ++j)
        {
            if(temp_num[min]>temp_num[j])
                min = j;
        } 
        //sort数组记录排序的学生信息的下标 
        sort[i] = min;
        temp_num[min] = temp_num[max];      //利用临时数组将查找过的学生信息的学号设为最大值，排除查找干扰        
    }
    for(i=0; i<n; ++i)  //再复制一次临时数组 
    {
        temp_num[i] = num[i];
        strcpy(temp_names[i],names[i]);
        temp_math[i] = math[i];
        temp_english[i] = english[i];
        temp_computer[i] = computer[i];
        temp_sum[i] = sum[i];
    }

    for(i=0; i<n; i++)  //按照下标对原数组进行修改 
    {
        num[i] = temp_num[sort[i]]; 
        strcpy(names[i],temp_names[sort[i]]); 
        math[i] = temp_math[sort[i]]; 
        english[i] = temp_english[sort[i]]; 
        computer[i] = temp_computer[sort[i]]; 
        sum[i] = temp_sum[sort[i]];
    }
    printf("排序完毕，请按菜单键2查看排序结果！\n");
    return ;
} 

//7.按学号修改学生信息
int student_alter_num(int n) 
{
    int nums;
    int result;
    printf("请输入待修改的球员号码:");
    scanf("%d",&nums);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (nums == num[i])
        {
            result = i;
            break;
        }
    }

    //最后判断q值
    if (result == -1)
    {
        printf("没有该球员信息!\n");
        return 0;
    }
    else    //修改信息值 
    {
        printf("请重新输入该球员信息：\n");
        printf("姓名：\n");
        scanf("%s",names[result]); 
		printf("号码：\n");
        scanf("%d",&num[result]); 
        printf("身高：\n");
        scanf("%d",&math[result]);
        printf("臂展：\n");
        scanf("%d",&english[result]);
        printf("体重：\n");
        scanf("%d",&computer[result]);
        printf("年龄：\n");
		scanf("%d",&sum[result]) ;
        
    }
    return 1;
} 

//8.按姓名修改学生信息
int student_alter_name(int n) 
{
    char name[50];
    int result;
    printf("请输入待修改的球员姓名:");
    scanf("%s",name);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (strcmp(name,names[i])==0)
        {
            result = i;
            break;
        }
    }
    //最后判断q值
    if (result == -1)
    {
        printf("没有该球员信息!\n");
        return 0;
    }
    else        //修改信息值 
    {
        printf("请重新输入该球员信息：\n");
        
        printf("姓名：\n");
        scanf("%s",names[result]);
		printf("号码：\n");
        scanf("%d",&num[result]); 
        printf("身高：\n");
        scanf("%d",&math[result]);
        printf("臂展：\n");
        scanf("%d",&english[result]);
        printf("体重：\n");
        scanf("%d",&computer[result]);
        printf("年龄：\n");
		scanf("%d",&sum[result]); 
         
    }
    return 1;
} 


//9.按学号删除学生信息
int student_delete_num(int n) 
{
    int nums;
    int result;
    printf("请输入待删除的球员号码:");
    scanf("%d",&nums);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (nums == num[i])
        {
            result = i;
            break;
        }
    }
    //最后判断q值
    if (result == -1)
    {
        printf("没有该球员信息!\n");
        return 0;
    }
    else    //删除当前学生信息即为将数组从result的位置依次前挪一个位置 
    {
        for(i=result; i<n-1; ++i)   //最后在main函数中，要将n的值减1 
        {
            num[i] = num[i+1]; 
            strcpy(names[i],names[i+1]); 
            math[i] = math[i+1]; 
            english[i] = english[i+1]; 
            computer[i] = computer[i+1]; 
            sum[i] = sum[i+1];
        } 

    }
    return 1;
} 

//10.按姓名删除学生信息
int student_delete_name(int n) 
{
    char name[50];
    int result;
    printf("请输入待删除的球员姓名:");
    scanf("%s",name);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (strcmp(name,names[i])==0)
        {
            result = i;
            break;
        }
    }
    //最后判断q值
    if (result == -1)
    {
        printf("没有该球员信息!\n");
        return 0;
    }
    else    //删除当前学生信息即为将数组从result的位置依次前挪一个位置 
    {
        for(i=result; i<n-1; ++i)       //最后在main函数中，要将n的值减1 
        {
            num[i] = num[i+1]; 
            strcpy(names[i],names[i+1]); 
            math[i] = math[i+1]; 
            english[i] = english[i+1]; 
            computer[i] = computer[i+1]; 
            sum[i] = sum[i+1];
        } 
    }
    return 1;
} 



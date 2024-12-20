#include "sms_struct.h"

/*查找记录模块*/
void search(STUDENT *stud,int n)
{
	int i=0;
	char s[15];                      /*存放姓名的字符数组*/
	printf("请输入您要查找的学生姓名:\n");
	scanf("%s",s);                   /*输入姓名*/
	while(i<n && strcmp(stud[i].name,s))
	{
		i++;
	}
	if(i==n)                      /**/
		printf("\n您要查找的是%s，很遗憾，查无此人！\n",s);
	else                             /*显示找到的记录信息*/
	{  
		printf("*********************************** Found *****************************************\n");
		printf("   学号          姓名          成绩1　成绩2　成绩3    总分   平均分  名次\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("    %-11s%-15s%5.2f%7.2f%7.2f %9.2f  %6.2f  %3d \n",  stud[i].no,stud[i].name,stud[i].score[0],stud[i].score[1],
				stud[i].score[2],stud[i].sum,stud[i].average,stud[i].order);
		printf("***********************************************************************************\n");
	}
}


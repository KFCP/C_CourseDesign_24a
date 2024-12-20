#include "sms_struct.h"
/*删除记录模块*/
int delete1(STUDENT *stud,int n)
{
	int i=0;
	char k[5];      /*定义字符串数组，用来确认删除信息*/
	char s[15];     /*存放学号*/
	printf("请输入要删除学生的姓名：\n");      /*显示提示信息*/
	scanf("%s",s);  /*输入要删除记录的姓名*/
	while(i<n && strcmp(stud[i].name,s))
	{
		i++;
	}
	if(i==n)                      /**/
		printf("\n您要删除的是%s，很遗憾，查无此人！\n",s);
	else               /*显示找到的记录信息*/
	{
		printf("*********************************** Found *****************************************\n");
		printf("   学号          姓名          成绩1　成绩2　成绩3    总分   平均分  名次\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("    %-11s%-15s%5.2f%7.2f%7.2f %9.2f  %6.2f  %3d \n",  stud[i].no,stud[i].name,stud[i].score[0],stud[i].score[1],
				stud[i].score[2],stud[i].sum,stud[i].average,stud[i].order);
		printf("***********************************************************************************\n");
		
		do{
			printf("您确实要删除此记录吗?(y/n):");
			scanf("%s",k);
        }while(k[0]!='y'&&k[0]!='n');
		
		if(k[0]!='n')        /*删除确认判断*/
		{
			for(;i<n;i++)
			{
				strcpy(stud[i].no,stud[i+1].no);
				strcpy(stud[i].name,stud[i+1].name);
				stud[i].score[0]=stud[i+1].score[0];
				stud[i].score[1]=stud[i+1].score[1];
				stud[i].score[2]=stud[i+1].score[2];
				stud[i].sum=stud[i+1].sum;
				stud[i].average=stud[i+1].average;
				stud[i].order=stud[i+1].order-1;
			}
			printf("\n 已经成功删除姓名为 %s 的学生的记录！\n",s);
		}
	}
	return n-1;
}

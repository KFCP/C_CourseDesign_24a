#include "sms_struct.h"
/*显示模块*/
void print(STUDENT *stud,int n)
{
	int i=0;               /* 统计记录条数*/
	if(n==0)
	{
		printf("\n    很遗憾，空表中没有任何记录可供显示！\n");
	}
	else
	{
		printf("********************************** STUDENT ****************************************\n");
		printf("  记录号　  学号          姓名      成绩1　成绩2　成绩3    总分   平均分  名次\n");
		printf("-----------------------------------------------------------------------------------\n");
		while(i<n)
		{
			printf("    %-4d %-11s%-15s%5.2f%7.2f%7.2f %9.2f  %6.2f  %3d \n", i+1, stud[i].no,stud[i].name,stud[i].score[0],stud[i].score[1],
					stud[i].score[2],stud[i].sum,stud[i].average,stud[i].order);
			i++;
		}
		printf("***********************************************************************************\n\n");
	}
}

/*
void main()
{
	STUDENT stu[2]={{"1","xds",77,88,99,264,88,0},{"2","yyy",78,88,99,265,88,0}};
	print(stu,2);
}
*/
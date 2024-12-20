#include "sms_struct.h"
/*在指定位置插入记录*/
int insert(STUDENT *stud,int n)
{
	int i=0,j;
	float s;
	int position;
	printf("请输入插入记录的位置：\n");      /*显示提示信息*/
	scanf("%d",&position);  /*输入插入记录的位置*/
	while(position<0 || position>n)
	{
		printf("输入位置有误，请重新输入插入记录的位置：\n");      /*显示提示信息*/
		scanf("%d",position);  /*输入要删除记录的姓名*/
	}
	
	//将插入位置开始的所有记录向后移动
	for(i=n-1;i>=position;i--)
	{
		strcpy(stud[i+1].no,stud[i].no);
		strcpy(stud[i+1].name,stud[i].name);
		stud[i+1].score[0]=stud[i].score[0];
		stud[i+1].score[1]=stud[i].score[1];
		stud[i+1].score[2]=stud[i].score[2];
		stud[i+1].sum=stud[i].sum;
		stud[i+1].average=stud[i].average;
		stud[i+1].order=stud[i].order;
	}

	//录入记录并插入
	i=position;
	printf("\n请按如下提示输入相关信息.\n\n");
	printf("输入学号:");
	scanf("%s",stud[i].no);        /*输入学号*/
	printf("输入姓名:");
	scanf("%s",stud[i].name);      /*输入姓名*/
	printf("输入%d 个成绩:\n",N);    /*提示开始输入成绩*/
	s=0;                                      /*计算每个学生的总分，初值为*/
	for(j=0;j<N;j++)                          /*N门课程循环N次*/
	{
		do{
			printf("score[%d]:",j);                 /*提示输入第几门课程*/
			scanf("%f",&stud[i].score[j]);            /*输入成绩*/
			if(stud[i].score[j]>100||stud[i].score[j]<0)/*确保成绩在~100之间*/ 
				printf("非法数据，请重新输入！\n");      /*出错提示信息*/
		}while(stud[i].score[j]>100||stud[i].score[j]<0);
		s=s+stud[i].score[j];                        /*累加各门课程成绩*/
	}
	stud[i].sum=s;               /*将总分保存*/
	stud[i].average=(float)s/N;  /*求出平均值*/
	stud[i].order=0;             /*未排序前此值为*/

	printf("\n 已经在位置成功插入新记录！\n",position);
	return n+1;
}

#include "sms_struct.h"
/*创建结构体数组，完成数据录入功能*/
int Input(STUDENT *stud,int n)
{
	int i,j;
	float s;
	char sign; 
	i=0;
	while(sign!='n'&&sign!='N') 
	{ 
		printf("\n请按如下提示输入相关信息.\n\n");
		printf("输入学号:");
		scanf("%s",stud[n+i].no);        /*输入学号*/
		printf("输入姓名:");
		scanf("%s",stud[n+i].name);      /*输入姓名*/
		printf("输入%d 个成绩:\n",N);    /*提示开始输入成绩*/
		s=0;                                      /*计算每个学生的总分，初值为*/
		for(j=0;j<N;j++)                          /*N门课程循环N次*/
		{
			do{
				printf("score[%d]:",j);                 /*提示输入第几门课程*/
				scanf("%f",&stud[n+i].score[j]);            /*输入成绩*/
				if(stud[n+i].score[j]>100||stud[n+i].score[j]<0)/*确保成绩在~100之间*/ 
					printf("非法数据，请重新输入！\n");      /*出错提示信息*/
			}while(stud[n+i].score[j]>100||stud[n+i].score[j]<0);
			s=s+stud[n+i].score[j];                        /*累加各门课程成绩*/
		}
		stud[n+i].sum=s;               /*将总分保存*/
		stud[n+i].average=(float)s/N;  /*求出平均值*/
		stud[n+i].order=0;             /*未排序前此值为*/

		printf("该学生的总分为：%4.2f\n\t平均分为：%4.2f\n",stud[n+i].sum,stud[n+i].average); 
		printf("=====>提示：继续添加记录?(Y/N)"); 
		getchar();		/*把键盘缓冲区中的前面输入的回车键给读掉，不然下面sign读到的是回车符*/
		scanf("%c",&sign);
		i++; 
	} 
	return(n+i); 
}

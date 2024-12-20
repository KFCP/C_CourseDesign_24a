#include "sms_struct.h"

void swap(STUDENT *stud1,STUDENT *stud2)
{
	int i;
	char temp1[15];
	float temp2;
	float temp3;
	strcpy(temp1,stud1->no);strcpy(stud1->no,stud2->no); strcpy(stud2->no,temp1);
	strcpy(temp1,stud1->name);strcpy(stud1->name,stud2->name); strcpy(stud2->name,temp1);
	for(i=0;i<3;i++)
	{
		temp2=stud1->score[i];
		stud1->score[i]=stud2->score[i];
		stud2->score[i]=temp2;
	}
	temp3=stud1->sum;	stud1->sum=stud2->sum;	stud2->sum=temp3;
	temp3=stud1->average;	stud1->average=stud2->average;	stud2->average=temp3;
}

/*排序模块，实现根据总分sum的值按降序排列*/
void sort(STUDENT *stud,int n)
{
	int i,j; 
	int maxPosition;
	for(i=0;i<n-1;i++) 
	{
		maxPosition=i;
		for(j=i+1;j<n;j++) 
		{
			if(stud[j].sum > stud[maxPosition].sum) 
			{
				maxPosition = j;
			}
		}
		if(maxPosition!=i)
		{
			swap(&stud[i],&stud[maxPosition]);
		}
	}

	i=0;
	while(i<n)
	{
		stud[i].order=i+1;
		i++;
	}
	printf("按总分从高到低排名成功!!!\n");      /*排序成功*/
}


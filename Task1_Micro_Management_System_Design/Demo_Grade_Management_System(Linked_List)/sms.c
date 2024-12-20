/******头文件（.h）***********/
#include "stdio.h"     /*printf()、scanf()等I/O函数*/
#include "malloc.h"    /*malloc()内存分配函数*/
#include "stdlib.h"    /*atoi()、exit()、system()等函数*/
#include "string.h"    /*strcpy()、strlen()、strcmp()等函数*/

#define N 3            /*定义常数*/

typedef struct stu     /*定义结构体类型*/
{
	char no[11];
	char name[15];
	float score[N];
	float sum;
	float average;
	int order;
	struct stu *next;
}STUDENT;

/*菜单函数，返回值为整数*/
int menu_select()
{
	char s[3];
	int c;
	printf("\n         ***************主菜单**************\n");
	printf("             1. 输入记录\n"); 
	printf("             2. 显示所有记录\n"); 
	printf("             3. 对所有记录进行排序\n"); 
	printf("             4. 按姓名查找记录并显示\n"); 
	printf("             5. 插入记录\n"); 
	printf("             6. 删除记录\n"); 
	printf("             7. 将所有记录保存到文件\n"); 
	printf("             8. 从文件中读入所有记录\n"); 
	printf("             9. 退出\n"); 
	printf("         ***********************************\n\n"); 
	do
	{ 
		printf("         请选择操作(1-9):"); 
		scanf("%s",s);
		c=atoi(s);
	}while(c<0||c>9); /*选择项不在0~9之间重输*/
	return(c); /*返回选择项，主程序根据该数调用相应的函数*/ 
}


/*创建链表，完成数据录入功能，新结点在表头插入*/
STUDENT *create()
{
	int i; 
	float s;
	STUDENT *h=NULL,*info;             /*h:头结点指针；info:新结点指针*/
	for(;;)
	{
		info=(STUDENT *)malloc(sizeof(STUDENT));  /*申请空间*/
		if(!info)                                 /*如果指针info为空*/
		{
			 printf("\n内存分配失败");                 
			 return NULL;                         /*返回空指针*/
		}
		printf("\n请按如下提示输入相关信息.\n\n");
		printf("输入学号（输入'#'结束）:");
		scanf("%s",info->no);    /*输入学号并校验*/
		if(info->no[0]=='#') break;               /*如果学号首字符为#则结束输入*/
		printf("输入姓名:");
		scanf("%s",info->name);      /*输入姓名，并进行校验*/
		printf("输入%d 个成绩:\n",N);    /*提示开始输入成绩*/
		s=0;                                      /*计算每个学生的总分，初值为0*/
		for(i=0;i<N;i++)                          /*N门课程循环N次*/
		{
			do{
				printf("score[%d]:",i);                 /*提示输入第几门课程*/
				scanf("%f",&info->score[i]);            /*输入成绩*/
				if(info->score[i]>100||info->score[i]<0)/*确保成绩在0~100之间*/ 
					printf("非法数据，请重新输入！\n");      /*出错提示信息*/
			}while(info->score[i]>100||info->score[i]<0);
			s=s+info->score[i];                        /*累加各门课程成绩*/
		}
		info->sum=s;               /*将总分保存*/
		info->average=(float)s/N;  /*求出平均值*/
		info->order=0;             /*未排序前此值为0*/
		info->next=h;              /*将头结点做为新输入结点的后继结点*/
		h=info;            /*新输入结点为新的头结点*//*没排序前,后输入的数据将排在最上*/
	}
	return(h);                    /*返回头指针*/
}


/*显示模块*/
void print(STUDENT *h)
{
	int i=0;               /* 统计记录条数*/
	STUDENT *p;            /*移动指针*/
	p=h;                   /*初值为头指针*/
	if(p==NULL)
	{
		printf("\n    很遗憾，空表中没有任何记录可供显示！\n");
	}
	else
	{
		printf("********************************** STUDENT ****************************************\n");
		printf("  记录号　  学号          姓名      成绩1　成绩2　成绩3    总分   平均分  名次\n");
		printf("-----------------------------------------------------------------------------------\n");
		while(p!=NULL)
		{
			i++;
			printf("    %-4d %-11s%-15s%6.2f%7.2f%7.2f %9.2f  %6.2f  %3d \n", i, p->no,p->name,p->score[0],p->score[1],
					p->score[2],p->sum,p->average,p->order);
			p=p->next;
		}
		printf("***********************************************************************************\n\n");
	}
}

/*排序模块，实现根据总分sum的值按降序将链表重新排列*/
STUDENT *sort(STUDENT *h)
{
   int i=0;                         /*用来保存名次*/
   STUDENT *p,*q,*t,*h1;            /*定义临时指针*/
   h1=h->next;                      /*将原表的头指针所指的下一个结点作头指针*/
   h->next=NULL;                    /*断开原来链表头结点与其它结点的连接*/
   while(h1!=NULL)                  /*当原表不为空时，进行排序*/
   {
	  t=h1;                         /*取原表的头结点*/
      h1=h1->next;                  /*原表头结点指针后移*/
      p=h;                          /*设定移动指针p，从头指针开始*/
      q=h;                          /*设定移动指针q做为p的前驱，初值为头指针*/
      while(p!=NULL&&t->sum<p->sum) /*作总分比较*/
      {
		  q=p;                      /*待插入点值小，则新表指针后移*/
		  p=p->next;
	  }

      if(p==q)                      /*p==q，上面的while没有执行，也即插入点大于头指针，此点应排在首位*/
      { 
		  t->next=p;                /*待排序点的后继为p*/
          h=t;                      /*新头结点为待排序点*/
      }
      else                          /*待排序点应插入在q和p之间，如p为空则是尾部*/
      {		   
		  t->next=p;                /*t的后继是p*/
          q->next=t;                /*q的后继是t*/
      }
   }								/*链表重新排列（排序）完成*/
    
   //由于链表已经排好序，所以只要从头指针开始，依次置名次号即可
   p=h;                             /*已排好序的头指针赋给p*/
   while(p!=NULL)                   /*赋予各组数据排序号*/
   {
      i++;                          /*结点序号*/
      p->order=i;                   /*将名次赋值*/
      p=p->next;                    /*指针后移*/
   }
   printf("按总分从高到低排名成功!!!\n");      /*排序成功*/
   return (h);                      /*返回头指针*/
}

/*查找记录模块*/
void search(STUDENT *h)
{
	STUDENT *p;                      /*移动指针*/
	char s[15];                      /*存放姓名的字符数组*/
	printf("请输入您要查找的学生姓名:\n");
	scanf("%s",s);                   /*输入姓名*/
	p=h;                             /*将头指针赋给p*/
	while(p!=NULL&&strcmp(p->name,s))/*当记录的姓名不是要找的，并且指针不为空时*/
		p=p->next;                   /*移动指针，指向下一结点，继续查找*/
	if(p==NULL)                      /*指针为空，说明未能找到所要的结点*/
		printf("\n您要查找的是%s，很遗憾，查无此人！\n",s);
	else                             /*显示找到的记录信息*/
	{  
		printf("*********************************** Found *****************************************\n");
		printf("   学号          姓名          成绩1　成绩2　成绩3    总分   平均分  名次\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("    %-11s%-15s%6.2f%7.2f%7.2f %9.2f  %6.2f  %3d \n",  p->no,p->name,p->score[0],p->score[1],
				p->score[2],p->sum,p->average,p->order);
		printf("***********************************************************************************\n");
	}
}

/*在链表头部添加记录*/
STUDENT  *insert(STUDENT *h)
{  
	STUDENT *info;                   /*p指向插入位置，q是其前驱，info指新插入记录*/
	int i,n=0;
	float s1;
	printf("\n请添加新记录！\n");
	info=(STUDENT *)malloc(sizeof(STUDENT)); /*申请空间*/
	if(!info)
	{  
		printf("\n内存分配失败！"); 
		return NULL;                         /*返回空指针*/
	}
	printf("输入学号:");
	scanf("%s",info->no);  /*以下是待插入数据的录入和处理，具体同创建模块同*/
	printf("输入姓名:");
	scanf("%s",info->name);
	printf("输入 %d 个成绩：\n",N);
	s1=0;
	for(i=0;i<N;i++)
	{
		do{
			 printf("score[%d]:",i);
			 scanf("%f",&info->score[i]);
			 if(info->score[i]>100||info->score[i]<0)
				printf("非法数据，请重新输入！\n");
		}while(info->score[i]>100||info->score[i]<0);
		s1=s1+info->score[i];                  
	}
	info->sum=s1;                             
	info->average=(float)s1/N;   
	info->order=0;             /*未排序前此值为*/
	info->next=NULL;           /*设后继指针为空*/

	info->next=h;              /*将指针赋值给p*/
	h=info;                    /*将指针赋值给q*/

    printf("\n ----已经添加 %s 到链表头部！----\n",info->name);
    return(h);                 /*返回头指针*/
}

/*删除记录模块*/
STUDENT *delete1(STUDENT *h)
{
	char k[5];					/*定义字符串数组，用来确认删除信息*/
	STUDENT *p,*q;				/*p为查找到要删除的结点指针，q为其前驱指针*/
	char s[11];					/*存放学号*/
	printf("请输入要删除学生的学号：\n");      /*显示提示信息*/
	scanf("%s",s);				/*输入要删除记录的学号*/
	q=p=h;						/*给q和p赋初值头指针*/
	while(p!=NULL&&strcmp(p->no,s))   /*当记录的学号不是要找的，或指针不为空时*/
	{  
		q=p;					/*将p指针值赋给q作为p的前驱指针*/
		p=p->next;				/*将p指针指向下一条记录*/
	}
	if(p==NULL)					/*如果p为空，说明链表中没有该结点*/
		printf("\n很遗憾，链表中没有您要删除的学号为 %s 的学生！\n",s);
	else						/*p不为空，显示找到的记录信息*/
	{
		printf("*********************************** Found *****************************************\n");
		printf("   学号          姓名          成绩1　成绩2　成绩3    总分   平均分  名次\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("    %-11s%-15s%6.2f%7.2f%7.2f %9.2f  %6.2f  %3d \n",  p->no,p->name,p->score[0],p->score[1],
				p->score[2],p->sum,p->average,p->order);
		printf("***********************************************************************************\n");
		
		do{
			printf("您确实要删除此记录吗?(y/n):");
			scanf("%s",k);
        }while(k[0]!='y'&&k[0]!='n');
		
		if(k[0]!='n')				/*删除确认判断*/
		{
			if(p==h)				/*如果p==h，说明被删结点是头结点*/
				h=p->next;			/*修改头指针指向下一条记录*/
			else
				q->next=p->next;    /*不是头指针，将p的后继结点作为q的后继结点*/
			free(p);				/*释放p所指结点空间*/
			printf("\n 已经成功删除学号为 %s 的学生的记录！\n",s);
		}
	}
	return(h);						/*返回头指针*/
}

/*保存数据到文件模块*/
void save(STUDENT *h)
{
   FILE *fp;                                      /*定义指向文件的指针*/
   STUDENT *p;                                    /*定义移动指针*/
   char outfile[20];                              /*保存输出文件名*/
   printf("请输入导出文件名，例如：d:\\xds\\score.txt:\n");
   scanf("%s",outfile);
   if((fp=fopen(outfile,"wb"))==NULL)             /*为输出打开一个二进制文件，如没有则建立*/
   {
      printf("不能打开文件，文件保存失败！\n");
   }
   else
   {
	   p=h;                                       /*移动指针从头指针开始*/
	   while(p!=NULL)                             /*如p不为空*/
	   {
		  fwrite(p,sizeof(STUDENT),1,fp);         /*写入一条记录*/
		  p=p->next;                              /*指针后移*/
	   }
	   fclose(fp);                                /*关闭文件*/
	   printf("-----所有记录已经成功保存至文件%s中!-----\n",outfile);   /*显示保存成功*/
   }
}

/*导入信息模块*/
STUDENT *load()
{
   STUDENT *p,*q,*h=NULL;                         /*定义记录指针变量*/
   FILE *fp;                                      /* 定义指向文件的指针*/
   char infile[20];                               /*保存文件名*/
   printf("请输入导入文件名，例如：d:\\xds\\score.txt:\n");
   scanf("%s",infile);                            /*输入文件名*/
   if((fp=fopen(infile,"rb"))==NULL)              /*打开一个二进制文件，为读方式*/
   {  
		printf("文件打开失败！\n");               /*如不能打开，返回头指针*/
		return h;
   }
   p=(STUDENT *)malloc(sizeof(STUDENT));          /*申请空间*/
   if(!p)
   {  
		printf("内存分配失败!\n");                /*如没有申请到，则内存溢出*/
		return h;                                 /*返回空头指针*/
   }
   h=p;                                           /*申请到空间，将其作为头指针*/
   while(!feof(fp))                               /*循环读数据直到文件尾结束*/
   {
	   if(1!=fread(p,sizeof(STUDENT),1,fp))
			break;                                  /*如果没读到数据，跳出循环*/
		p->next=(STUDENT *)malloc(sizeof(STUDENT)); /*为下一个结点申请空间*/
		if(!p->next)
		{
			 printf("内存分配失败!\n");             /*如没有申请到，则内存溢出*/
			 return h;
		}
		q=p;                                        /*保存当前结点的指针，作为下一结点的前驱*/
		p=p->next;                                  /*指针后移，新读入数据链到当前表尾*/
	}
	q->next=NULL;                                  /*最后一个结点的后继指针为空*/
	fclose(fp);                                    /*关闭文件*/
	printf("已经成功从文件%s导入数据!!!\n",infile);
	return h;                                      /*返回头指针*/
}

/******主函数开始*******/
main()
{
	STUDENT *head = NULL;       /*链表定义头指针*/
	system("color 5e");         /*调DOS命令清屏，可用color ?命令查看命令格式*/
	for(;;)						/*无限循环*/
	{
		switch(menu_select())   /*调用主菜单函数，返回值整数作开关语句的条件*/
		{
			 case 1: head=create();break;        /*创建链表*/
			 case 2: print(head);break;          /*显示全部记录*/
			 case 3: head=sort(head);break;      /*排序*/
			 case 4: search(head);break;         /*查找记录*/
			 case 5: head=insert(head);break;	 /*插入记录*/
			 case 6: head=delete1(head);break;   /*删除记录*/
			 case 7: save(head);break;           /*保存文件*/
			 case 8: head=load();break;          /*读文件*/
			 case 9: exit(0);                    /*程序结束*/
		}
	}
}

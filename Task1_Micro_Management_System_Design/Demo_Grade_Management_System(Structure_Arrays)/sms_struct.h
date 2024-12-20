#ifndef sms_stuct_INCLUDED   //防止下面的内容被重复包含
#define sms_stuct_INCLUDED

	#include<stdio.h> //printf()、scanf()等函数
	#include<string.h>//strlen()、strcpy()等函数  
	#include<stdlib.h>//atoi()函数

	//定义常数
	#define N 3            

	//定义结构体	
	typedef struct student     
	{
		char no[11];
		char name[15];
		float score[N];
		float sum;
		float average;
		int order;
	}STUDENT;

	//函数声明
	int Input(STUDENT *stud,int n);		//输入记录
	void print(STUDENT *stud,int n);	//显示记录
	void sort(STUDENT *stud,int n);		//排序记录
	void search(STUDENT *stud,int n);	//查找记录
	int insert(STUDENT *stud,int n);	//插入记录
	int delete1(STUDENT *stud,int n);	//删除记录
	void save(STUDENT *stud,int n);		//存储记录
	int load(STUDENT *stud);			//导入记录

#endif
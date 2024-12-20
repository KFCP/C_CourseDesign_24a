#include "sms_struct.h"
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
		//scanf("%d",&c);
	}while(c<0||c>9); /*选择项不在~9之间重输*/
	return(c); /*返回选择项，主程序根据该数调用相应的函数*/
}


/******主函数开始*******/

main()
{
	int n=0;
	STUDENT student[20];        /*定义结构数组*/
//	system("color 5e");             /*清屏*/
	for(;;)               /*无限循环*/
	{
		switch(menu_select())               /*调用主菜单函数，返回值整数作开关语句的条件*/
		{
			 case 1: n=Input(student,n);break;        /*新建记录*/
			 case 2: print(student,n);break;          /*显示全部记录*/
			 case 3: sort(student,n);break;      /*排序*/
			 case 4: search(student,n);break;         /*查找记录*/
			 case 5: n=insert(student,n);break;  /*插入记录*/
			 case 6: n=delete1(student,n);break;    /*删除记录*/
			 case 7: save(student,n);break;           /*保存文件*/
			 case 8: n=load(student);break;         /*读文件*/
			 case 9: exit(0);                    /*程序结束*/
		}
	}
}

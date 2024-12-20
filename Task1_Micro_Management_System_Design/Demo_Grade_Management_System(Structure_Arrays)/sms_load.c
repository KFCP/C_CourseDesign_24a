#include "sms_struct.h"

/*导入信息模块*/
int load(STUDENT *stud)
{
   int i;
   FILE *fp;                                      /* 定义指向文件的指针*/
   char infile[20];                               /*保存文件名*/
   printf("请输入导入文件名，例如：G:\\f1\\score.txt:\n");
   scanf("%s",infile);                            /*输入文件名*/
   if((fp=fopen(infile,"rb"))==NULL)              /*打开一个二进制文件，为读方式*/
   {  
		printf("文件打开失败！\n");             
		return 0;
   }
   i=0;
   while(!feof(fp))                               /*循环读数据直到文件尾结束*/
   {
	   if(1!=fread(&stud[i],sizeof(STUDENT),1,fp))
			break;                                       /*如果没读到数据，跳出循环*/
	   i++;
   }
	fclose(fp);                                    /*关闭文件*/
	printf("已经成功从文件%s导入数据!!!\n",infile);
	return i;
}

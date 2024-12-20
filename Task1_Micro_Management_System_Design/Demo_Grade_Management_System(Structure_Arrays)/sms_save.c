#include "sms_struct.h"

/*保存数据到文件模块*/
void save(STUDENT *stud,int n)
{
   FILE *fp;                                      /*定义指向文件的指针*/
   int i=0;
   char outfile[20];                              /*保存输出文件名*/
   printf("请输入导出文件名，例如：G:\\f1\\score.txt:\n");
   scanf("%s",outfile);
   if((fp=fopen(outfile,"wb"))==NULL)             /*为输出打开一个二进制文件，如没有则建立*/
   {
      printf("Can not open file\n");
      exit(1);
   }
   while(i<n)                                 
   {
      fwrite(&stud[i],sizeof(STUDENT),1,fp);             /*写入一条记录*/
      i++;                                 
   }
   fclose(fp);                                    /*关闭文件*/
   printf("-----所有记录已经成功保存至文件%s中!-----\n",outfile);          /*显示保存成功*/
}
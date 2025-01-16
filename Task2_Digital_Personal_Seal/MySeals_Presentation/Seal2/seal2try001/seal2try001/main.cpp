/****************************************************************************

 ****  FileName:  demo.c

 ****  Function:  真彩色bmp图片文件的创建

 ****  Usage:     demo  xxxx.bmp

*****************************************************************************/

#include <conio.h>

#include <stdlib.h>

#include <stdio.h>

#include <math.h>

#include <malloc.h>

#include <string.h>

typedef unsigned char BYTE;

typedef unsigned short WORD;

typedef unsigned long DWORD;



/****  The file header of bmp file 文件头*****/

#include <pshpack2.h> //This file turns 2 byte packing of structures on, then sizeof(BITMAPFILEHEADER)=14, otherwise sizeof(BITMAPFILEHEADER)=16

typedef struct tagBITMAPFILEHEADER
{

    WORD bfType;

    DWORD bfSize;

    WORD bfReserved1;

    WORD bfReserved2;

    DWORD bfoffBits;

} BITMAPFILEHEADER;

#include <poppack.h> //This file turns packing of structures off



/****  The information header of bmp file 信息头*****/

typedef struct tagBITMAPINFOHEADER
{

    DWORD biSize;

    DWORD biWidth;

    DWORD biHeight;

    WORD  biPlanes;

    WORD  biBitCount;

    DWORD biCompress;

    DWORD biSizeImage;

    DWORD biXPeIsPerMeter;

    DWORD biYPeIsPerMeter;

    DWORD biCIrUsed;

    DWORD biClrImprotant;

} BITMAPINFOHEADER;



/****  The RGB data of bmp file 图像RGB数据*****/

typedef struct tagRGBDATA
{

    BYTE rgbBlue;

    BYTE rgbGreen;

    BYTE rgbRed;

} RGBDATA;

char str_key[4];
char str_col[120];

int main(int argc, char *argv[])
{
    RGBDATA *bmpData=NULL; //图像数据指针

    FILE *fp1,*fp2; //BMP文件指针

    unsigned char BM[100];

    char str[200];

    long i,j,k;

    long width=120; //图像宽度

    long height=120; //图像高度

    long dataSize=width*height;

    BITMAPFILEHEADER bmfHeader;

    BITMAPINFOHEADER bmiHeader;

    if(argc<2)

    {

        printf("\n    请指定您要生成的BMP文件名！\n");

        printf("\n    方法1：在cmd窗口输入： demo  xxxx.bmp　后回车执行！\n");

        printf("\n    方法2：在VC的工程设置中添加参数： xxxx.bmp　后编译运行！\n");

        printf("\n    功能： 根据设定红绿蓝三色分量的值，控制显示不同的彩色条纹！\n\n");

        exit(0);

    }

    printf("\n    ******************************************************************\n");

    printf("\n         感谢您使用BMP图片文件制作DEMO程序                 \n");

    printf("\n             作者：张三                 \n");

    printf("\n             日期：2020年6月12日                 \n");

    printf("\n             目的：编制印章生成程序时，供参考！       \n");

    printf("\n             功能：根据设定红绿蓝三色分量的值，控制显示不同的彩色条纹！\n\n");

    printf("\n    ******************************************************************\n\n");

//第一步：用命令行中给出的文件名新建一BMP文件，此时还是一个空文件

//打开用windows + R ，cmd 打开两个的两个命令参数argv[1],argv[2]
    if(!(fp1 = fopen(argv[1], "wb+")))
    {
        printf("Cannot open BMP file!");
        exit(0);
    }

    if(!(fp2 = fopen(argv[2], "r")))
    {
        printf("Cannot open 字体.txt file!");
        exit(0);
    }
    //将编码转化为字符并显示,将汉字的编码转到str数组里，用于后续查找
    printf("请输入你想制作印章的汉字: ");
    scanf("%s",BM);
    int len;
    for(len = 0; BM[len] != '\0'; len++);
    for(i = 0; i < len; i++)
        printf("BM[%d] = %x\n",i,BM[i]);

    for(i = 0; i < len; i++)
        sprintf(str+2*i,"%x",BM[i]);

    printf("将编码转化为字符并显示 ：%s\n",str);

//第二步：置文件头数据并写入BMP文件

    bmfHeader.bfType=0x4d42;

    bmfHeader.bfSize=14+40+width*height*3;

    bmfHeader.bfReserved1=0;

    bmfHeader.bfReserved2=0;

    bmfHeader.bfoffBits=0x36;

    fwrite(&bmfHeader, sizeof(BITMAPFILEHEADER), 1, fp1);



//第三步：置信息头数据并写入BMP文件

    bmiHeader.biSize=40;

    bmiHeader.biWidth=width;

    bmiHeader.biHeight=height;

    bmiHeader.biPlanes=1;

    bmiHeader.biBitCount=24;

    bmiHeader.biCompress=0;

    bmiHeader.biSizeImage=width*height*3;

    bmiHeader.biXPeIsPerMeter=0;

    bmiHeader.biYPeIsPerMeter=0;

    bmiHeader.biCIrUsed=0;

    bmiHeader.biClrImprotant=0;

    fwrite(&bmiHeader, sizeof(BITMAPINFOHEADER), 1, fp1);



//第四步：置图像数据并写入BMP文件

//分配足够内存，让bmpData指向这块内存，用于存放图像各象素点的RGB分量值
    if((bmpData=(RGBDATA*)malloc(width*height*3))==NULL)
    {
        printf("bmpData memory malloc error!");
    }

//先在bmpData所指内存中置图像RGB数据，然后将所有数据写入BMP文件

    for(i=0; i<height; i++) //边框设置为红色
    {
        for(j=0; j<width; j++)
        {
            int k=(height-i-1)*width + j;//计算bmp图片中第i行第j列图像数据在bmpData[]数组中的位置
            if((i >= 0 && i <= 3)||(i >= 116 && i <= 119) || (j >= 0 && j <= 3) || (j >= 116 && j <= 119))
            {
                bmpData[k].rgbBlue = 0;
                bmpData[k].rgbGreen = 0;
                bmpData[k].rgbRed = 255;
            }
            else
            {
                bmpData[k].rgbBlue = 255;
                bmpData[k].rgbGreen = 255;
                bmpData[k].rgbRed = 255;
            }
        }
    }


    int dx[4] = {4,56,4,56};//为了安排四个字的位置，采用每个字做不同的偏移
    int dy[4] = {56,56,4,4};//(4,56)(56,56)(4,4)(56,4) 分别是第一二三四个字

    for(i = 0 ; i < 16; i += 4)
    {
        strncpy(str_key, str + i, 4);   //每次从str数组中截取4个字符串，进行匹配，在表中找到汉字
        rewind(fp2);   //将指针置于文件头，从头开始寻找。
        while( !feof(fp2) )
        {
            fgets(str_col, sizeof(str_col)-1, fp2 );  //每次从汉字表中读取一行，放入stri中一定要-1把、0去掉

            if( strstr(str_col, str_key ))   //匹配到汉字的编码
            {
                for(int w = 0; w < 56; ++w)
                {
                    fgets(str_col, sizeof(str_col)-1, fp2 );  //每次从汉字表中读取一行，放入stri中一定要-1把、0去掉
                    int char_irl = 0; //标记不合法字符，遇到，跳过
                    for( j = 0; j < 63; ++j )
                    {
                        int k = (height-w-1-dx[i/4])*width + j +dy[i/4]-char_irl;
                        if(str_col[j] == ',')
                        {
                            char_irl++;
                            continue;
                        }
                        if(str_col[j] == 'X')
                        {
                            bmpData[k].rgbBlue = 0;
                            bmpData[k].rgbGreen = 0;
                            bmpData[k].rgbRed = 255;
                        }
                        else
                        {
                            bmpData[k].rgbBlue = 255;
                            bmpData[k].rgbGreen = 255;
                            bmpData[k].rgbRed = 255;
                        }
                    }
                }
                break;//找到了一个字，得跳出循环重新从第一行找起，省时间
            }
        }
    }

    fwrite(bmpData,sizeof(RGBDATA),dataSize,fp1);//将bmpData所指的RGB数据一次性写入BMP文件

    printf("\n    恭喜您！BMP文件已经成功生成！\n");

    printf("\n    请在当前目录下查看生成的BMP文件%s\n\n",argv[1]);

    free(bmpData); //释放bmpData所指的内存空间

    bmpData=NULL; //置bmpData为空指针

    fclose(fp1); //关闭fp所指文件
    fclose(fp2);

}

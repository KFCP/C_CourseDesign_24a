/****************************************************************************

 ****  FileName:  demo.c

 ****  Function:  ���ɫbmpͼƬ�ļ��Ĵ���

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



/****  The file header of bmp file �ļ�ͷ*****/

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



/****  The information header of bmp file ��Ϣͷ*****/

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



/****  The RGB data of bmp file ͼ��RGB����*****/

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
    RGBDATA *bmpData=NULL; //ͼ������ָ��

    FILE *fp1,*fp2; //BMP�ļ�ָ��

    unsigned char BM[100];

    char str[200];

    long i,j,k;

    long width=120; //ͼ����

    long height=120; //ͼ��߶�

    long dataSize=width*height;

    BITMAPFILEHEADER bmfHeader;

    BITMAPINFOHEADER bmiHeader;

    if(argc<2)

    {

        printf("\n    ��ָ����Ҫ���ɵ�BMP�ļ�����\n");

        printf("\n    ����1����cmd�������룺 demo  xxxx.bmp����س�ִ�У�\n");

        printf("\n    ����2����VC�Ĺ�����������Ӳ����� xxxx.bmp����������У�\n");

        printf("\n    ���ܣ� �����趨��������ɫ������ֵ��������ʾ��ͬ�Ĳ�ɫ���ƣ�\n\n");

        exit(0);

    }

    printf("\n    ******************************************************************\n");

    printf("\n         ��л��ʹ��BMPͼƬ�ļ�����DEMO����                 \n");

    printf("\n             ���ߣ�����                 \n");

    printf("\n             ���ڣ�2020��6��12��                 \n");

    printf("\n             Ŀ�ģ�����ӡ�����ɳ���ʱ�����ο���       \n");

    printf("\n             ���ܣ������趨��������ɫ������ֵ��������ʾ��ͬ�Ĳ�ɫ���ƣ�\n\n");

    printf("\n    ******************************************************************\n\n");

//��һ�������������и������ļ����½�һBMP�ļ�����ʱ����һ�����ļ�

//����windows + R ��cmd �������������������argv[1],argv[2]
    if(!(fp1 = fopen(argv[1], "wb+")))
    {
        printf("Cannot open BMP file!");
        exit(0);
    }

    if(!(fp2 = fopen(argv[2], "r")))
    {
        printf("Cannot open ����.txt file!");
        exit(0);
    }
    //������ת��Ϊ�ַ�����ʾ,�����ֵı���ת��str��������ں�������
    printf("��������������ӡ�µĺ���: ");
    scanf("%s",BM);
    int len;
    for(len = 0; BM[len] != '\0'; len++);
    for(i = 0; i < len; i++)
        printf("BM[%d] = %x\n",i,BM[i]);

    for(i = 0; i < len; i++)
        sprintf(str+2*i,"%x",BM[i]);

    printf("������ת��Ϊ�ַ�����ʾ ��%s\n",str);

//�ڶ��������ļ�ͷ���ݲ�д��BMP�ļ�

    bmfHeader.bfType=0x4d42;

    bmfHeader.bfSize=14+40+width*height*3;

    bmfHeader.bfReserved1=0;

    bmfHeader.bfReserved2=0;

    bmfHeader.bfoffBits=0x36;

    fwrite(&bmfHeader, sizeof(BITMAPFILEHEADER), 1, fp1);



//������������Ϣͷ���ݲ�д��BMP�ļ�

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



//���Ĳ�����ͼ�����ݲ�д��BMP�ļ�

//�����㹻�ڴ棬��bmpDataָ������ڴ棬���ڴ��ͼ������ص��RGB����ֵ
    if((bmpData=(RGBDATA*)malloc(width*height*3))==NULL)
    {
        printf("bmpData memory malloc error!");
    }

//����bmpData��ָ�ڴ�����ͼ��RGB���ݣ�Ȼ����������д��BMP�ļ�

    for(i=0; i<height; i++) //�߿�����Ϊ��ɫ
    {
        for(j=0; j<width; j++)
        {
            int k=(height-i-1)*width + j;//����bmpͼƬ�е�i�е�j��ͼ��������bmpData[]�����е�λ��
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


    int dx[4] = {4,56,4,56};//Ϊ�˰����ĸ��ֵ�λ�ã�����ÿ��������ͬ��ƫ��
    int dy[4] = {56,56,4,4};//(4,56)(56,56)(4,4)(56,4) �ֱ��ǵ�һ�����ĸ���

    for(i = 0 ; i < 16; i += 4)
    {
        strncpy(str_key, str + i, 4);   //ÿ�δ�str�����н�ȡ4���ַ���������ƥ�䣬�ڱ����ҵ�����
        rewind(fp2);   //��ָ�������ļ�ͷ����ͷ��ʼѰ�ҡ�
        while( !feof(fp2) )
        {
            fgets(str_col, sizeof(str_col)-1, fp2 );  //ÿ�δӺ��ֱ��ж�ȡһ�У�����stri��һ��Ҫ-1�ѡ�0ȥ��

            if( strstr(str_col, str_key ))   //ƥ�䵽���ֵı���
            {
                for(int w = 0; w < 56; ++w)
                {
                    fgets(str_col, sizeof(str_col)-1, fp2 );  //ÿ�δӺ��ֱ��ж�ȡһ�У�����stri��һ��Ҫ-1�ѡ�0ȥ��
                    int char_irl = 0; //��ǲ��Ϸ��ַ�������������
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
                break;//�ҵ���һ���֣�������ѭ�����´ӵ�һ������ʡʱ��
            }
        }
    }

    fwrite(bmpData,sizeof(RGBDATA),dataSize,fp1);//��bmpData��ָ��RGB����һ����д��BMP�ļ�

    printf("\n    ��ϲ����BMP�ļ��Ѿ��ɹ����ɣ�\n");

    printf("\n    ���ڵ�ǰĿ¼�²鿴���ɵ�BMP�ļ�%s\n\n",argv[1]);

    free(bmpData); //�ͷ�bmpData��ָ���ڴ�ռ�

    bmpData=NULL; //��bmpDataΪ��ָ��

    fclose(fp1); //�ر�fp��ָ�ļ�
    fclose(fp2);

}

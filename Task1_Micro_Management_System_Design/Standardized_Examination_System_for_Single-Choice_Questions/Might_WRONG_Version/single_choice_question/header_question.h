#ifndef HEADER_QUESTION_H_INCLUDED
#define HEADER_QUESTION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ������Ŀ�ṹ��
typedef struct {
	char question[256]; // ���
	char choices[4][256]; // 4����ѡ��
	int answer; // ��׼��
} Question;

// �����������
    Question questions[1000];
    static int num_questions = 0;

void add_question();
void show_questions();
void save_questions();
void load_questions();



#endif // HEADER_QUESTION_H_INCLUDED

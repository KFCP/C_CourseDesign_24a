#ifndef HEADER_QUESTION_H_INCLUDED
#define HEADER_QUESTION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义题目结构体
typedef struct {
	char question[256]; // 题干
	char choices[4][256]; // 4个备选答案
	int answer; // 标准答案
} Question;

// 定义题库数组
    Question questions[1000];
    static int num_questions = 0;

void add_question();
void show_questions();
void save_questions();
void load_questions();



#endif // HEADER_QUESTION_H_INCLUDED

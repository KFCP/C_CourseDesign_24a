#include "header_question.h"
// 显示所有题目函数
void show_questions() {
	for (int i = 0; i < num_questions; i++) {
		printf("题目%d：%s", i+1, questions[i].question);
		for (int j = 0; j < 4; j++) {
			printf("选项%d：%s", j+1, questions[i].choices[j]);
		}
		printf("答案：%d\n", questions[i].answer);
	}
}

#include "header_question.h"
// 题目录入函数
void add_question() {
	printf("请输入题干：\n");
	fgets(questions[num_questions].question, 256, stdin);

	printf("请输入4个备选答案：\n");
	for (int i = 0; i < 4; i++) {
		fgets(questions[num_questions].choices[i], 256, stdin);
	}

	printf("请输入标准答案（0-3）：\n");
	scanf("%d", &questions[num_questions].answer);
	getchar(); // 清除缓冲区的换行符

	num_questions++;
}

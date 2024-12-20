#include "header_question.h"
// 从题库中随机抽取N道题并判卷
void draw_and_answer_questions() {
	printf("请输入抽取题目的数量：\n");
	int N;
	scanf("%d", &N);
	getchar(); // 清除缓冲区的换行符

	if (N > num_questions) {
		printf("题库中只有%d道题，无法抽取%d道题\n", num_questions, N);
		return;
	}

	srand(time(NULL)); // 初始化随机数生成器

	int score = 0;
	for (int i = 0; i < N; i++) {
		int index = rand() % num_questions; // 生成一个随机索引

		printf("题目%d：%s", i+1, questions[index].question);
		for (int j = 0; j < 4; j++) {
			printf("选项%d：%s", j+1, questions[index].choices[j]);
		}

		printf("请输入你的答案（0-3）：\n");
		int user_answer;
		scanf("%d", &user_answer);
		getchar(); // 清除缓冲区的换行符

		if (user_answer == questions[index].answer) {
			printf("答案正确！\n");
			score++;
		} else {
			printf("答案错误，正确答案是：%d\n", questions[index].answer);
		}
	}

	printf("你的成绩是：%d/%d\n", score, N);
}

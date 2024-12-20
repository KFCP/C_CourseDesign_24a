#include "header_question.h"
// 从文件中读取题目
void load_questions() {
	FILE *file = fopen("questions.txt", "r");
	if (file == NULL) {
		printf("无法打开文件\n");
		return;
	}

	while (!feof(file) && num_questions < 1000) {
		fgets(questions[num_questions].question, 256, file);
		for (int i = 0; i < 4; i++) {
			fgets(questions[num_questions].choices[i], 256, file);
		}
		fscanf(file, "%d\n", &questions[num_questions].answer);

		num_questions++;
	}

	fclose(file);
}

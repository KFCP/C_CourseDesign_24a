#include "header_question.h"
// ���ļ��ж�ȡ��Ŀ
void load_questions() {
	FILE *file = fopen("questions.txt", "r");
	if (file == NULL) {
		printf("�޷����ļ�\n");
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

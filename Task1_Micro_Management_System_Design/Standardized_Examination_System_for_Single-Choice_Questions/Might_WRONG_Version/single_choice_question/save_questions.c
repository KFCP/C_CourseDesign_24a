#include "header_question.h"
// ������Ŀ���ļ�
void save_questions() {
	FILE *file = fopen("questions.txt", "w");
	if (file == NULL) {
		printf("�޷����ļ�\n");
		return;
	}

	for (int i = 0; i < num_questions; i++) {
		fprintf(file, "%s", questions[i].question);
		for (int j = 0; j < 4; j++) {
			fprintf(file, "%s", questions[i].choices[j]);
		}
		fprintf(file, "%d\n", questions[i].answer);
	}

	fclose(file);
}

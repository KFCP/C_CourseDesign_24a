#include "header_question.h"
// ��ʾ������Ŀ����
void show_questions() {
	for (int i = 0; i < num_questions; i++) {
		printf("��Ŀ%d��%s", i+1, questions[i].question);
		for (int j = 0; j < 4; j++) {
			printf("ѡ��%d��%s", j+1, questions[i].choices[j]);
		}
		printf("�𰸣�%d\n", questions[i].answer);
	}
}

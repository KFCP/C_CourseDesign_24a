#include "header_question.h"
// ��Ŀ¼�뺯��
void add_question() {
	printf("��������ɣ�\n");
	fgets(questions[num_questions].question, 256, stdin);

	printf("������4����ѡ�𰸣�\n");
	for (int i = 0; i < 4; i++) {
		fgets(questions[num_questions].choices[i], 256, stdin);
	}

	printf("�������׼�𰸣�0-3����\n");
	scanf("%d", &questions[num_questions].answer);
	getchar(); // ����������Ļ��з�

	num_questions++;
}

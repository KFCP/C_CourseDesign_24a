#include "header_question.h"
// ������������ȡN���Ⲣ�о�
void draw_and_answer_questions() {
	printf("�������ȡ��Ŀ��������\n");
	int N;
	scanf("%d", &N);
	getchar(); // ����������Ļ��з�

	if (N > num_questions) {
		printf("�����ֻ��%d���⣬�޷���ȡ%d����\n", num_questions, N);
		return;
	}

	srand(time(NULL)); // ��ʼ�������������

	int score = 0;
	for (int i = 0; i < N; i++) {
		int index = rand() % num_questions; // ����һ���������

		printf("��Ŀ%d��%s", i+1, questions[index].question);
		for (int j = 0; j < 4; j++) {
			printf("ѡ��%d��%s", j+1, questions[index].choices[j]);
		}

		printf("��������Ĵ𰸣�0-3����\n");
		int user_answer;
		scanf("%d", &user_answer);
		getchar(); // ����������Ļ��з�

		if (user_answer == questions[index].answer) {
			printf("����ȷ��\n");
			score++;
		} else {
			printf("�𰸴�����ȷ���ǣ�%d\n", questions[index].answer);
		}
	}

	printf("��ĳɼ��ǣ�%d/%d\n", score, N);
}

#include "header_question.h"

// ������
int main() {

	while (1) {
		printf("��ѡ�������1-��Ŀ¼�룬2-��ʾ������Ŀ��3-������Ŀ���ļ���4-���ļ��ж�ȡ��Ŀ��5-�����ȡ��Ŀ�������з֣�0-�˳�\n");
		/*���û�����3ʱ��save_questions�����ᱻ���ã�����ǰ����е���Ŀ���浽�ļ��С�
		  ���û�����4ʱ��load_questions�����ᱻ���ã����ļ��ж�ȡ��Ŀ����ӵ�����С�*/
		int choice;
		scanf("%d", &choice);
		getchar(); // ����������Ļ��з�

		if (choice == 1) {
			add_question();
		} else if (choice == 2) {
			show_questions();
		} else if (choice == 3) {
			save_questions();
		} else if (choice == 4) {
			load_questions();
		} else if(choice == 5){
			draw_and_answer_questions();
		} if (choice == 0) {
			break;
		}
	}

	return 0;
}

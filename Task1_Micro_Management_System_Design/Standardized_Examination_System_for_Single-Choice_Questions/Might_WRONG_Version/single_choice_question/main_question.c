#include "header_question.h"

// 主函数
int main() {

	while (1) {
		printf("请选择操作：1-题目录入，2-显示所有题目，3-保存题目到文件，4-从文件中读取题目，5-随机抽取题目并答题判分，0-退出\n");
		/*当用户输入3时，save_questions函数会被调用，将当前题库中的题目保存到文件中。
		  当用户输入4时，load_questions函数会被调用，从文件中读取题目并添加到题库中。*/
		int choice;
		scanf("%d", &choice);
		getchar(); // 清除缓冲区的换行符

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

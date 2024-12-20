#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义题目结构体
typedef struct {
	char question[256]; // 题干
	char choices[4][256]; // 4个备选答案
	int answer; // 标准答案
} Question;

// 定义题库数组
Question questions[1000];
int num_questions = 0;

//验证密码
int password_verification() {
	int password;
	printf("请输入密码：\n");
	scanf("%d", &password);
	if (password == 2024) {
		printf("密码正确，欢迎您的使用！请您根据主菜单继续操作\n");
		return 1;
	} else {
		printf("密码错误，本系统拒绝了您的访问！\n");
		return 0;
	}
}

// 题目录入函数
void add_question() {
	printf("请输入题干：\n");
	fgets(questions[num_questions].question, 256, stdin);

	printf("请输入4个备选答案：\n");
	for (int i = 0; i < 4; i++) {
		fgets(questions[num_questions].choices[i], 256, stdin);
	}

	printf("请输入标准答案：\n");
	scanf("%d", &questions[num_questions].answer);
	getchar();

	num_questions++;
}

// 显示所有题目函数
void show_questions() {
	for (int i = 0; i < num_questions; i++) {
		printf("题目%d：%s", i + 1, questions[i].question);
		for (int j = 0; j < 4; j++) {
			printf("选项%d：%s", j + 1, questions[i].choices[j]);
		}
		printf("答案：%d\n", questions[i].answer);
	}
}

// 保存题目到文件
void save_questions() {
	FILE *file = fopen("questions.txt", "w");
	if (file == NULL) {
		printf("无法打开文件\n");
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

	printf("题目已保存到文件\n");
}

// 从文件中载入题目
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
	printf("文件载入成功！\n");
}

// 从题库中随机抽取N道题并判卷
void draw_and_answer_questions() {
	printf("请输入抽取题目的数量：\n");
	int N;
	scanf("%d", &N);
	getchar();

	if (N > num_questions) {
		printf("题库中只有%d道题，无法抽取%d道题\n", num_questions, N);
		return;
	}

	srand(time(NULL)); // 随机

	int score = 0;
	for (int i = 0; i < N; i++) {
		int index = rand() % num_questions;

		printf("题目%d：%s", i + 1, questions[index].question);
		for (int j = 0; j < 4; j++) {
			printf("选项%d：%s", j + 1, questions[index].choices[j]);
		}

		printf("请输入你的答案：\n");
		int user_answer;
		scanf("%d", &user_answer);
		getchar();

		if (user_answer == questions[index].answer) {
			printf("答案正确！\n");
			score++;
		} else {
			printf("答案错误，正确答案是：%d\n", questions[index].answer);
		}
	}

	printf("你的成绩是：%d/%d\n", score, N);
}


//显示已保存到文件的所有题目
void read_questions() {
	FILE *file = fopen("questions.txt", "r");
	if (file == NULL) {
		printf("无法打开文件\n");
		return;
	}
	
	char line[25600];
	while (fgets(line, sizeof(line), file) != NULL) {
		printf("%s", line);
	}
	
	fclose(file);
}


// 主函数
int main() {
	if (!password_verification())
	{
		return 0;
	}
	while (1) {
		printf("\n         ***************主菜单**************\n");
		printf("             1-题目录入\n");
		printf("             2-显示本次录入的所有题目\n");
		printf("             3-保存题目到文件\n");
		printf("             4-从文件中载入题目\n");
		printf("             5-随机抽取题目并答题判分\n");
		printf("             6-显示已保存到文件的所有题目\n");
		printf("             0-退出\n");
		printf("         ***********************************\n\n");
		/*当用户输入3时，save_questions函数会被调用，将当前题库中的题目保存到文件中。
		  当用户输入4时，load_questions函数会被调用，从文件中读取并载入题目。*/
		
		int choice;
		scanf("%d", &choice);
		getchar();

		if (choice == 1) {
			add_question();//题目录入
		} else if (choice == 2) {
			show_questions();//显示本次录入的所有题目
		} else if (choice == 3) {
			save_questions();//保存题目到文件
		} else if (choice == 4) {
			load_questions();//从文件中载入题目
		} else if (choice == 5) {
			draw_and_answer_questions();//随机抽取题目并答题判分
		} else if (choice == 6) {
			read_questions();//显示已保存到文件的所有题目
		}
		if (choice == 0) {
			printf("程序已退出！\n");
			break;
		}
	}

	return 0;
}


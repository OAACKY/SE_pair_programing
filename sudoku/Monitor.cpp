/*
软件工程结对作业 解数独程序
文件说明：命令行处理函数文件
*/
#include "Monitor.h"
#include "Generator.h"
#include "Solver.h"


Monitor::Monitor(int argc1, char *argv1[]) :argc(argc1), argv(argv1) {
}
/*
-c 解的终盘数量
-s 解的文件路径
-n 需要游戏数量
-m 生成游戏难度
-r 生成游戏挖空范围
-u 生成游戏解唯一
*/
void Monitor::Operation() {
	if (strcmp(argv[1], "-s") == 0) {
		string parameter1 = argv[1];
		string parameter2 = argv[2];
		ifstream in(parameter2);
		if (!in.is_open()) {
			cout << parameter2 + "无法打开！" << endl;
			return;
		}
		char ch[81];
		char c;
		int count = 0;
		Solver ss;
		FILE* out = fopen("sudoku.txt", "wt");
		while (in.get(c)) {	//in >> c 会忽略空白回车符
			if (isdigit(c)||c=='$') {
				if (c == '$')
					ch[count++] = '0';
				else
					ch[count++] = c;
			}
			if (count == 81) {
				count = 0;
				fputs(ss.solve(ch,1), out);
			}
		}
		in.close();
		if (count != 0) {
			const char* str = "存在错误格式！";
			fputs(str, out);
			cout << str << endl;
		}
		else
			cout << "已解出" + parameter2 + "里的数独" << endl;
		fclose(out);
	}
	else if (strcmp(argv[1], "-c") == 0) {
		Generator generator(atoi(argv[2]));
		generator.Getfinal();
		cout << "已生成" << argv[2] << "个终盘(相对路径为final.txt)" << endl;
		return;
	}
	else if (strcmp(argv[1], "-n") == 0) {
		Generator generator(atoi(argv[2]));
		if (argc == 3) {
			generator.Getgame(nullptr);
		}
		else {
			if (strcmp(argv[3], "-m") == 0) {
				generator.Setdifficulty(atoi(argv[4]));
			}
			else if (strcmp(argv[3], "-r") == 0) {
				generator.Setscope(argv[4]);
			}
			else {
				generator.Setunique();
			}
			generator.Getgame(argv[3]);
		}
		cout << "已生成" << argv[2] << "个游戏(相对路径为game.txt)" << endl;
		return;
	}
	else {
		cout << "错误的输入！" << endl;
	}
}
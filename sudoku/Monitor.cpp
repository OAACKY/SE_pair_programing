/*
软件工程结对作业 解数独程序
文件说明：命令行处理函数文件
*/
#include "Monitor.h"
#include "Generator.h"
#include "Solver.h"


Monitor::Monitor(int argc1, char *argv1[]):argc(argc1),argv(argv1){
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
		Solver solver(argv[1]);
		return;
	}
	else if (strcmp(argv[1], "-c") == 0) {
		Generator generator(atoi(argv[1]));
		generator.Getfinal();
		cout << "已生成" << argv[1] << "个终盘(相对路径为final.txt)" << endl;
		return;
	}
	else if (strcmp(argv[1], "-n") == 0) {
		Generator generator(atoi(argv[2]));
		if (argc == 2) {
			generator.Getgame(nullptr);
		}
		else {
			if (strcmp(argv[3], "-m") == 0) {
				generator.Setdifficulty(atoi(argv[3]));
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
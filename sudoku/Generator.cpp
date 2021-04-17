/*
软件工程结对作业 解数独程序
文件说明：数独生成函数文件
*/
#include "Generator.h"
#include "Genefinal.h"
#include "Genegame.h"

Generator::Generator(int n) :number(n) {
}

void Generator::Setdifficulty(int dif) {
	difficulty = dif;
}

void Generator::Setscope(char *scope) {
	char *left = strtok(scope, "~");
	begin = atoi(left);
	char *right = strtok(NULL, "~");
	end = atoi(right);
}

void Generator::Setunique() {
	isUnique = true;
}

//默认生成终局的路径为相对路径："final.txt"
void Generator::Getfinal() {
	Genefinal geneFinal(number);
	geneFinal.Generate();
}

//默认生成游戏的路径为相对路径："game.txt"
void Generator::Getgame(char *func) {
	//难度的判定？解唯一的判定？
	Genegame genegame(number);
	if (func == nullptr) {
		genegame.getGame(20, 55);
	}
	else if (strcmp(func, "-m") == 0) {
		if (difficulty == 1)
			genegame.getGame(20, 21);
		else if (difficulty == 2)
			genegame.getGame(35, 40);
		else {
			genegame.getGame(54, 55);
		}
	}
	else if (strcmp(func, "-r") == 0) {
		genegame.getGame(begin, end);
	}
	else {
		//unique情况
	}

}
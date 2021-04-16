/*
软件工程结对作业 解数独程序
文件说明：数独生成函数文件
*/
#include "Generator.h"

Generator::Generator(int n) :number(n) {
}

void Generator::Setdifficulty(int dif) {
	difficulty = dif;
}

void Generator::Setscope(char *scope) {

}

void Generator::Setunique() {
	isUnique = true;
}

//默认生成终局的路径为相对路径："final.txt"
void Generator::Getfinal() {

}

//默认生成游戏的路径为相对路径："game.txt"
void Generator::Getgame(char *func) {
	//难度的判定？解唯一的判定？

}
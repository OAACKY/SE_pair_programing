/*
软件工程结对作业 解数独程序
文件说明：数独生成头文件
*/
#pragma once
#pragma warning(disable : 4996) 
#include <fstream>

class Generator {
public:
	Generator(int n);
	void Getfinal();
	void Getgame(char*);
	void Setdifficulty(int);
	void Setscope(char*);
	void Setunique();
private:
	int number;
	int difficulty;
	int begin,end;
	bool isUnique;
};
/*
软件工程结对作业 解数独程序
文件说明：数独游戏生成头文件
*/
#pragma once
#include <algorithm>
#include <fstream>
#include <ctime>
using namespace std;
class Genegame {
public:
	Genegame(int);
	void getGame(const int &l,const int &r);
	void initial(int[]);
private:
	int num;
	int table[9][9];
};
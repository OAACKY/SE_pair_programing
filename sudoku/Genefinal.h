/*
软件工程结对作业 解数独程序
文件说明：数独终盘生成头文件
*/
#pragma once
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;
class Genefinal {
public:
	Genefinal(int);
	void Generate();
	void initial(int []);
	void Myswap(int&, int&, int&, int&, int&, int&);
	void ExchangeRow(const int&,const int&);
	void ExchangeColumn(const int&,const int&);
//private:
	int n;
	int tempNum;
	int beginTable[9][9] = {};
	int localTable[9][9] = {};
};
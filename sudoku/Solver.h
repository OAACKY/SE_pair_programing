/*
软件工程结对作业 解数独程序
文件说明：数独求解头文件
*/
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxrow = 9 * 9 * 9;//9*9个空，每个空有9个可能
const int maxcol = 1 + 9 * 9 * 4;//head占一列，9*9个空每个空要符合四个条件（每行每列每空位1-9，且不为空）
const int num = maxcol + maxrow * 4;	// 01阵的总元素个数,  第一个为Head元素,接着9*9*4个为列标元素,最后9*9*9*4个为“1”元素（因为每行有4个1）

class Solver {
public:
	Solver();
	char* solve(char ch[],int);
	bool checkUnique();
private:
	int table[9][9];	// 数独
	int tempTable[9][9];
	int soluTime;
	int no;				// 元素编号
	void transform(int table[][9], char ch[]);
	void link();
	void insertNode(int col, int no);
	void remove(int col);
	void restore(int col);
	bool dfs(int k);
};
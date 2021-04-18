/*
������̽����ҵ ����������
�ļ�˵�����������ͷ�ļ�
*/
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

const int maxrow = 9 * 9 * 9;//9*9���գ�ÿ������9������
const int maxcol = 1 + 9 * 9 * 4;//headռһ�У�9*9����ÿ����Ҫ�����ĸ�������ÿ��ÿ��ÿ��λ1-9���Ҳ�Ϊ�գ�
const int num = maxcol + maxrow * 4;	// 01�����Ԫ�ظ���,  ��һ��ΪHeadԪ��,����9*9*4��Ϊ�б�Ԫ��,���9*9*9*4��Ϊ��1��Ԫ�أ���Ϊÿ����4��1��

class Solver {
public:
	Solver();
	char* solve(char ch[],int);
	bool checkUnique();
private:
	int table[9][9];	// ����
	int tempTable[9][9];
	int soluTime;
	int no;				// Ԫ�ر��
	void transform(int table[][9], char ch[]);
	void link();
	void insertNode(int col, int no);
	void remove(int col);
	void restore(int col);
	bool dfs(int k);
};
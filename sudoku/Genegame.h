/*
������̽����ҵ ����������
�ļ�˵����������Ϸ����ͷ�ļ�
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
/*
������̽����ҵ ����������
�ļ�˵������������ͷ�ļ�
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
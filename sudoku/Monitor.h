/*
������̽����ҵ ����������
�ļ�˵���������д���ͷ�ļ�
*/
#pragma once
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
class Monitor {
public:
	Monitor(int argc, char* argv[]);
	void Operation();
private:
	int argc;
	char **argv;
};
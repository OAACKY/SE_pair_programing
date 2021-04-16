/*
软件工程结对作业 解数独程序
文件说明：命令行处理头文件
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
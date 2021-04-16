/*
软件工程结对作业 解数独程序
文件说明：数独求解头文件
*/
#pragma once
class Solver {
public:
	Solver(char*);
	void Getans();
private:
	char* path;
};
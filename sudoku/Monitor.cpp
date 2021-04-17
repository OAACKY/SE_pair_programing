/*
������̽����ҵ ����������
�ļ�˵���������д������ļ�
*/
#include "Monitor.h"
#include "Generator.h"
#include "Solver.h"


Monitor::Monitor(int argc1, char *argv1[]):argc(argc1),argv(argv1){
}
/*
-c �����������
-s ����ļ�·��
-n ��Ҫ��Ϸ����
-m ������Ϸ�Ѷ�
-r ������Ϸ�ڿշ�Χ
-u ������Ϸ��Ψһ
*/
void Monitor::Operation() {
	if (strcmp(argv[1], "-s") == 0) {
		Solver solver(argv[1]);
		return;
	}
	else if (strcmp(argv[1], "-c") == 0) {
		Generator generator(atoi(argv[2]));
		generator.Getfinal();
		cout << "������" << argv[2] << "������(���·��Ϊfinal.txt)" << endl;
		return;
	}
	else if (strcmp(argv[1], "-n") == 0) {
		Generator generator(atoi(argv[2]));
		if (argc == 3) {
			generator.Getgame(nullptr);
		}
		else {
			if (strcmp(argv[3], "-m") == 0) {
				generator.Setdifficulty(atoi(argv[4]));
			}
			else if (strcmp(argv[3], "-r") == 0) {
				generator.Setscope(argv[4]);
			}
			else {
				generator.Setunique();
			}
			generator.Getgame(argv[3]);
		}
		cout << "������" << argv[2] << "����Ϸ(���·��Ϊgame.txt)" << endl;
		return;
	}
	else {
		cout << "��������룡" << endl;
	}
}
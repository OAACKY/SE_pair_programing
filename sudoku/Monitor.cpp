/*
������̽����ҵ ����������
�ļ�˵���������д������ļ�
*/
#include "Monitor.h"
#include "Generator.h"
#include "Solver.h"


Monitor::Monitor(int argc1, char *argv1[]) :argc(argc1), argv(argv1) {
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
		string parameter1 = argv[1];
		string parameter2 = argv[2];
		ifstream in(parameter2);
		if (!in.is_open()) {
			cout << parameter2 + "�޷��򿪣�" << endl;
			return;
		}
		char ch[81];
		char c;
		int count = 0;
		Solver ss;
		FILE* out = fopen("sudoku.txt", "wt");
		while (in.get(c)) {	//in >> c ����Կհ׻س���
			if (isdigit(c)||c=='$') {
				if (c == '$')
					ch[count++] = '0';
				else
					ch[count++] = c;
			}
			if (count == 81) {
				count = 0;
				fputs(ss.solve(ch,1), out);
			}
		}
		in.close();
		if (count != 0) {
			const char* str = "���ڴ����ʽ��";
			fputs(str, out);
			cout << str << endl;
		}
		else
			cout << "�ѽ��" + parameter2 + "�������" << endl;
		fclose(out);
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
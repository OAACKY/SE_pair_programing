/*
������̽����ҵ ����������
�ļ�˵�����������ɺ����ļ�
*/
#include "Generator.h"
#include "Genefinal.h"
#include "Genegame.h"

Generator::Generator(int n) :number(n) {
}

void Generator::Setdifficulty(int dif) {
	difficulty = dif;
}

void Generator::Setscope(char *scope) {
	char *left = strtok(scope, "~");
	begin = atoi(left);
	char *right = strtok(NULL, "~");
	end = atoi(right);
}

void Generator::Setunique() {
	isUnique = true;
}

//Ĭ�������վֵ�·��Ϊ���·����"final.txt"
void Generator::Getfinal() {
	Genefinal geneFinal(number);
	geneFinal.Generate();
}

//Ĭ��������Ϸ��·��Ϊ���·����"game.txt"
void Generator::Getgame(char *func) {
	//�Ѷȵ��ж�����Ψһ���ж���
	Genegame genegame(number);
	if (func == nullptr) {
		genegame.getGame(20, 55);
	}
	else if (strcmp(func, "-m") == 0) {
		if (difficulty == 1)
			genegame.getGame(20, 21);
		else if (difficulty == 2)
			genegame.getGame(35, 40);
		else {
			genegame.getGame(54, 55);
		}
	}
	else if (strcmp(func, "-r") == 0) {
		genegame.getGame(begin, end);
	}
	else {
		//unique���
	}

}
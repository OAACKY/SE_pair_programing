/*
软件工程结对作业 解数独程序
文件说明：数独游戏生成函数文件
*/
#include"Genegame.h"
Genegame::Genegame(int t):num(t) {
}

void Genegame::getGame(const int &l,const int &r) {
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	srand(time(NULL));
	int scope = r - l;
	int tempNum;
	ofstream myOut("game.txt");
	while (num--) {
		initial(a);
		tempNum = 0;
		int nums = rand() % scope + l;
		while (tempNum < nums) {
			int tempDelete = rand() % 81;
			if (table[tempDelete / 9][tempDelete % 9] != 0) {
				table[tempDelete / 9][tempDelete % 9] = 0;
				tempNum++;
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 8; j++) {
				myOut << table[i][j] << " ";
			}
			myOut << table[i][8] << endl;
		}
		myOut << endl;
		next_permutation(a, a + 9);
	}
	myOut.close();
}

void Genegame::initial(int a[]) {
	int temp[9][9] = { {a[5],a[3],a[4],a[2],a[0],a[1],a[8],a[6],a[7]},{a[8],a[6],a[7],a[5],a[3],a[4],a[2],a[0],a[1]},{a[2],a[0],a[1],a[8],a[6],a[7],a[5],a[3],a[4]},
				       {a[3],a[4],a[5],a[0],a[1],a[2],a[6],a[7],a[8]},{a[6],a[7],a[8],a[3],a[4],a[5],a[0],a[1],a[2]},{a[0],a[1],a[2],a[6],a[7],a[8],a[3],a[4],a[5]},
				       {a[4],a[5],a[3],a[1],a[2],a[0],a[7],a[8],a[6]},{a[7],a[8],a[6],a[4],a[5],a[3],a[0],a[1],a[2]},{a[1],a[2],a[0],a[7],a[8],a[6],a[4],a[5],a[3]} };
	memcpy(table, temp, sizeof(temp));
}
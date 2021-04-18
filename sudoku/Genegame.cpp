/*
软件工程结对作业 解数独程序
文件说明：数独游戏生成函数文件
*/
#include"Genegame.h"
#include"Solver.h"
Genegame::Genegame(int t):num(t) {
}

void Genegame::getGame(const int &l,const int &r) {
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	srand(static_cast<unsigned int>(time(NULL)));
	int scope = r - l;
	int tempNum;
	ofstream myOut("game.txt");
	while (num--) {
		initial(a);
		tempNum = 0;
		int nums = rand() % scope + l;
		while (tempNum < nums) {    //随机生成在scope内的空，然后判断并删除
			int tempDelete = rand() % 81;
			if (table[tempDelete / 9][tempDelete % 9] != 0) {
				table[tempDelete / 9][tempDelete % 9] = 0;
				tempNum++;
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 8; j++) {
				if (table[i][j] == 0)
					myOut << '$' << " ";
				else
					myOut << table[i][j] << " ";
			}
			if (table[i][8] == 0)
				myOut << '$' << endl;
			else
				myOut << table[i][8] << endl;
		}
		myOut << endl;
		next_permutation(a, a + 9);//更换随机种子
	}
	myOut.close();
}
//
void Genegame::getUniqueGame() {
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	srand(static_cast<unsigned int>(time(NULL)));
	int tempNum;
	ofstream myOut("game.txt");
	while (num--) {
		initial(a);
		tempNum = 0;
		int nums = rand() % 10 + 20;
		char *tempAns;
		while (tempNum < nums) {    //随机生成在scope内的空，然后判断并删除
			int tempDelete = rand() % 81;
			if (table[tempDelete / 9][tempDelete % 9] != 0) {
				int tableTemp = table[tempDelete / 9][tempDelete % 9];
				table[tempDelete / 9][tempDelete % 9] = 0;
				char ch[81];
				for (int i = 0; i < 81; i++)
					ch[i] = table[i / 9][i % 9] + '0';
				Solver solver;
				tempAns=solver.solve(ch, 0);
				if (solver.checkUnique()) {
					tempNum++;
					//cout << "已挖" << tempNum << "个洞" << endl;
				}
					
				else {
					table[tempDelete / 9][tempDelete % 9] = tableTemp;
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 8; j++) {
				if (table[i][j] == 0)
					myOut << '$' << " ";
				else
					myOut << table[i][j] << " ";
			}
			if (table[i][8] == 0)
				myOut << '$' << endl;
			else
				myOut << table[i][8] << endl;
		}
		myOut << endl;
		next_permutation(a, a + 9);//更换随机种子
	}
	myOut.close();
}
//与终局生成方式相同，先按照种子生成5宫，然后交换行列，生成完整的终盘
void Genegame::initial(int a[]) {
	int temp[9][9] = { {a[5],a[3],a[4],a[2],a[0],a[1],a[8],a[6],a[7]},{a[8],a[6],a[7],a[5],a[3],a[4],a[2],a[0],a[1]},{a[2],a[0],a[1],a[8],a[6],a[7],a[5],a[3],a[4]},
				       {a[3],a[4],a[5],a[0],a[1],a[2],a[6],a[7],a[8]},{a[6],a[7],a[8],a[3],a[4],a[5],a[0],a[1],a[2]},{a[0],a[1],a[2],a[6],a[7],a[8],a[3],a[4],a[5]},
				       {a[4],a[5],a[3],a[1],a[2],a[0],a[7],a[8],a[6]},{a[7],a[8],a[6],a[4],a[5],a[3],a[1],a[2],a[0]},{a[1],a[2],a[0],a[7],a[8],a[6],a[4],a[5],a[3]} };
	memcpy(table, temp, sizeof(temp));
}
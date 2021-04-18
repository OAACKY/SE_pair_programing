/*
软件工程结对作业 解数独程序
文件说明：数独终盘生成函数文件
*/
#include "Genefinal.h"
/*
123456789
abcdefghi
-----------
fde|cab|igh
igh|fde|cab
cab|igh|fde
-----------
def|abc|ghi
ghi|def|abc
abc|ghi|def
-----------
efd|bca|hig
hig|efd|bca
bca|hig|efd
-----------
初始按照种子顺序依次填满中间5宫，然后交换行填满4,6宫
最后对于4-6宫按照同样交换列方式填满其他宫
*/
Genefinal::Genefinal(int t) :n(t) {
	tempNum = 0;
	//int temp[9][9] = { {6,4,5,3,1,2,9,7,8},{9,7,8,6,4,5,3,1,2},{3,1,2,9,7,8,6,4,5},
	//				   {4,5,6,1,2,3,7,8,9},{7,8,9,4,5,6,1,2,3},{1,2,3,7,8,9,4,5,6},
	//				   {5,6,4,2,3,1,8,9,7},{8,9,7,5,6,4,1,2,3},{2,3,1,8,9,7,5,6,4}};
	//memcpy(beginTable, temp, sizeof(temp));
}

void Genefinal::initial(int a[]) {
	int temp[9][9] = { {a[5],a[3],a[4],a[2],a[0],a[1],a[8],a[6],a[7]},{a[8],a[6],a[7],a[5],a[3],a[4],a[2],a[0],a[1]},{a[2],a[0],a[1],a[8],a[6],a[7],a[5],a[3],a[4]},
					   {a[3],a[4],a[5],a[0],a[1],a[2],a[6],a[7],a[8]},{a[6],a[7],a[8],a[3],a[4],a[5],a[0],a[1],a[2]},{a[0],a[1],a[2],a[6],a[7],a[8],a[3],a[4],a[5]},
					   {a[4],a[5],a[3],a[1],a[2],a[0],a[7],a[8],a[6]},{a[7],a[8],a[6],a[4],a[5],a[3],a[1],a[2],a[0]},{a[1],a[2],a[0],a[7],a[8],a[6],a[4],a[5],a[3]} };
	memcpy(beginTable, temp, sizeof(temp));
}

void Genefinal::Generate() {
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	ofstream myOut("final.txt");
	while (true) {
		initial(a);
		//2(4,6宫不同情况)*3!(1-3行)*3!(7-9行)*2(2,8宫不同情况)*3!(1-3列)*3!(7-9列)
		for (int cc = 1; cc <= 2; cc++) {
			for (int c1 = 1; c1 <= 6; c1++) {
				for (int c3 = 1; c3 <= 6; c3++) {
					for (int rr = 1; rr <= 2; rr++) {
						for (int r1 = 1; r1 <= 6; r1++) {
							for (int r3 = 1; r3 <= 6; r3++) {
								Myswap(cc, c1, c3, rr, r1, r3);
								for (int i = 0; i < 9; i++) {
									for (int j = 0; j < 8; j++) {
										myOut << localTable[i][j] << " ";
									}
									myOut << localTable[i][8] << endl;
								}
								myOut <<tempNum+1<< endl;
								if (++tempNum == n)
									return;
							}
						}
					}
				}
			}
		}
		next_permutation(a,a+9);
	}
	myOut.close();
}

void Genefinal::Myswap(int&cc,int&c1,int&c3,int&rr,int&r1,int&r3) {
	memcpy(localTable, beginTable, sizeof(beginTable));
	if (rr == 2) {
		ExchangeColumn(0, 6);
		ExchangeColumn(1, 7);
		ExchangeColumn(2, 8);
	}
	switch (r1) {
		case 0:
			break;
		case 1:
			ExchangeRow(0, 1);
			break;
		case 2:
			ExchangeRow(0, 2);
			break;
		case 3:
			ExchangeRow(1, 2);
			break;
		case 4:
			ExchangeRow(0, 1);
			ExchangeRow(1, 2);
			break;
		case 5:
			ExchangeRow(0, 2);
			ExchangeRow(1, 2);
			break;
	}
	switch (r3) {
		case 0:
			break;
		case 1:
			ExchangeRow(6, 7);
			break;
		case 2:
			ExchangeRow(6, 8);
			break;
		case 3:
			ExchangeRow(7, 8);
			break;
		case 4:
			ExchangeRow(6, 7);
			ExchangeRow(7, 8);
			break;
		case 5:
			ExchangeRow(6, 8);
			ExchangeRow(7, 8);
			break;
	}
	if (cc == 2) {
		ExchangeRow(0, 6);
		ExchangeRow(1, 7);
		ExchangeRow(2, 8);
	}
	switch (c1) {
		case 0:
			break;
		case 1:
			ExchangeColumn(0, 1);
			break;
		case 2:
			ExchangeColumn(0, 2);
			break;
		case 3:
			ExchangeColumn(1, 2);
			break;
		case 4:
			ExchangeColumn(0, 1);
			ExchangeColumn(1, 2);
			break;
		case 5:
			ExchangeColumn(0, 2);
			ExchangeColumn(1, 2);
			break;
	}
	switch (c3) {
		case 0:
			break;
		case 1:
			ExchangeColumn(6, 7);
			break;
		case 2:
			ExchangeColumn(6, 8);
			break;
		case 3:
			ExchangeColumn(7, 8);
			break;
		case 4:
			ExchangeColumn(6, 7);
			ExchangeColumn(7, 8);
			break;
		case 5:
			ExchangeColumn(6, 8);
			ExchangeColumn(7, 8);
			break;
	}
}



void Genefinal::ExchangeRow(const int &a,const int&b) {
	int temp;
	for (int i = 0; i < 9; i++) {
		temp = localTable[a][i];
		localTable[a][i] = localTable[b][i];
		localTable[b][i] = temp;
	}
}

void Genefinal::ExchangeColumn(const int &a,const int &b) {
	int temp;
	for (int i = 0; i < 9; i++) {
		temp = localTable[i][a];
		localTable[i][a] = localTable[i][b];
		localTable[i][b] = temp;
	}
}
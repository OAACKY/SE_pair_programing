#include "pch.h"
#include "CppUnitTest.h"
//下方更改为自己电脑的路径
#include"../SE_pair_programing/sudoku/Genefinal.h"
#include"../SE_pair_programing/sudoku/Genegame.h"
#include"../SE_pair_programing/sudoku/Generator.h"
#include"../SE_pair_programing/sudoku/Monitor.h"
#include"../SE_pair_programing/sudoku/Solver.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		static void MyClassInitialize(Genefinal ls) {}
		TEST_METHOD(Genefinal_initial)
		{
			Genefinal gf(1);
			int a[9] = { 1,2,3,4,5,6,7,8,9 };
			gf.initial(a);
			int temp[9][9] = { {a[5],a[3],a[4],a[2],a[0],a[1],a[8],a[6],a[7]},{a[8],a[6],a[7],a[5],a[3],a[4],a[2],a[0],a[1]},{a[2],a[0],a[1],a[8],a[6],a[7],a[5],a[3],a[4]},
					   {a[3],a[4],a[5],a[0],a[1],a[2],a[6],a[7],a[8]},{a[6],a[7],a[8],a[3],a[4],a[5],a[0],a[1],a[2]},{a[0],a[1],a[2],a[6],a[7],a[8],a[3],a[4],a[5]},
					   {a[4],a[5],a[3],a[1],a[2],a[0],a[7],a[8],a[6]},{a[7],a[8],a[6],a[4],a[5],a[3],a[1],a[2],a[0]},{a[1],a[2],a[0],a[7],a[8],a[6],a[4],a[5],a[3]} };
			for(int i=0;i<9;i++)
				for (int j = 0; j < 9; j++)
					Assert::AreEqual(gf.beginTable[i][j], temp[i][j]);
		}
		TEST_METHOD(Genefinal_Genefinal)
		{
			Genefinal gf(3);

			Assert::AreEqual(gf.n, 3);
		};
		TEST_METHOD(Genefinal_Myswap1)
		{
			Genefinal gf(3);
			int a[9] = { 1,2,3,4,5,6,7,8,9 };
			gf.initial(a);
			int cc = 2, c1 = 1, c3 = 1, rr = 2, r1 = 1, r3 = 1;
			gf.Myswap(cc, c1, c3, rr, r1, r3);
			int test[9][9] = { 3,2,1,5,6,4,9,8,7,
							   9,8,7,2,3,1,6,5,4,
							   6,5,4,8,9,7,3,2,1,
							   8,7,9,1,2,3,5,4,6,
							   2,1,3,4,5,6,8,7,9,
							   5,4,6,7,8,9,2,1,3,
							   1,3,2,6,4,5,7,9,8,
							   7,9,8,3,1,2,4,6,5,
							   4,6,5,9,7,8,1,3,2 };
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					Assert::AreEqual(gf.localTable[i][j], test[i][j]);
			
		};
		TEST_METHOD(Genefinal_Myswap2)
		{
			Genefinal gf(3);
			int a[9] = { 1,2,3,4,5,6,7,8,9 };
			gf.initial(a);
			int cc = 0, c1 = 1, c3 = 1, rr = 0, r1 = 1, r3 = 1;
			gf.Myswap(cc, c1, c3, rr, r1, r3);
			int test[9][9] = { 7,9,8,6,4,5,1,3,2,
							   4,6,5,3,1,2,7,9,8,
							   1,3,2,9,7,8,4,6,5,
							   5,4,6,1,2,3,8,7,9,
							   8,7,9,4,5,6,2,1,3,
							   2,1,3,7,8,9,5,4,6,
							   9,8,7,5,6,4,3,2,1,
							   6,5,4,2,3,1,9,8,7,
							   3,2,1,8,9,7,6,5,4 };
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					Assert::AreEqual(gf.localTable[i][j], test[i][j]);
		};
		TEST_METHOD(Genefinal_Myswap3)
		{
			Genefinal gf(3);
			int a[9] = { 1,2,3,4,5,6,7,8,9 };
			gf.initial(a);
			int cc = 0, c1 = 4, c3 = 4, rr = 0, r1 = 4, r3 = 4;
			gf.Myswap(cc, c1, c3, rr, r1, r3);
			int test[9][9] = { 7,8,9,6,4,5,1,2,3,
							   1,2,3,9,7,8,4,5,6,
							   4,5,6,3,1,2,7,8,9,
							   5,6,4,1,2,3,8,9,7,
							   8,9,7,4,5,6,2,3,1,
							   2,3,1,7,8,9,5,6,4,
							   9,7,8,5,6,4,3,1,2,
							   3,1,2,8,9,7,6,4,5,
							   6,4,5,2,3,1,9,7,8 };
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					Assert::AreEqual(gf.localTable[i][j], test[i][j]);
		};
		TEST_METHOD(Genefinal_Myswap4)
		{
			Genefinal gf(3);
			int a[9] = { 1,2,3,4,5,6,7,8,9 };
			gf.initial(a);
			int cc = 2, c1 = 4, c3 = 4, rr = 2, r1 = 4, r3 = 4;
			gf.Myswap(cc, c1, c3, rr, r1, r3);
			int test[9][9] = { 3,1,2,5,6,4,9,7,8,
							   6,4,5,8,9,7,3,1,2,
							   9,7,8,2,3,1,6,4,5,
							   8,9,7,1,2,3,5,6,4,
							   2,3,1,4,5,6,8,9,7,
							   5,6,4,7,8,9,2,3,1,
							   1,2,3,6,4,5,7,8,9,
							   4,5,6,9,7,8,1,2,3,
							   7,8,9,3,1,2,4,5,6 };
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					Assert::AreEqual(gf.localTable[i][j], test[i][j]);
		};
		TEST_METHOD(Genegame_initial)
		{
			Genegame gg(1);
			int a[9] = { 1,2,3,4,5,6,7,8,9 };
			gg.initial(a);
			int temp[9][9] = { {a[5],a[3],a[4],a[2],a[0],a[1],a[8],a[6],a[7]},{a[8],a[6],a[7],a[5],a[3],a[4],a[2],a[0],a[1]},{a[2],a[0],a[1],a[8],a[6],a[7],a[5],a[3],a[4]},
					   {a[3],a[4],a[5],a[0],a[1],a[2],a[6],a[7],a[8]},{a[6],a[7],a[8],a[3],a[4],a[5],a[0],a[1],a[2]},{a[0],a[1],a[2],a[6],a[7],a[8],a[3],a[4],a[5]},
					   {a[4],a[5],a[3],a[1],a[2],a[0],a[7],a[8],a[6]},{a[7],a[8],a[6],a[4],a[5],a[3],a[1],a[2],a[0]},{a[1],a[2],a[0],a[7],a[8],a[6],a[4],a[5],a[3]} };
			
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					Assert::AreEqual(gg.table[i][j], temp[i][j]);
		};
		TEST_METHOD(Generator_Generator)
		{
			Generator gr(3);
			int d = 0;
			int b = 0;
			int e = 0;
			bool i = 0;
			Assert::AreEqual(gr.difficulty, d);
			Assert::AreEqual(gr.begin, b);
			Assert::AreEqual(gr.end, e);
			Assert::AreEqual(gr.isUnique, i);
			Assert::AreEqual(gr.number, 3);
		};
		TEST_METHOD(Generator_Setunique)
		{
			Generator gr(3);
			gr.Setunique();
			Assert::IsTrue(gr.isUnique);
		};
		TEST_METHOD(Solver_checkUnique)
		{
			char ch[] = {
				6,0,5,3,1,2,0,8,7,
				9,8,0,0,4,0,3,1,2,
				3,1,2,9,0,0,0,4,5,
				4,5,6,0,2,3,8,0,9,
				8,7,9,4,5,6,1,0,3,
				1,2,3,8,0,9,4,5,6,
				5,6,4,2,3,0,7,0,8,
				7,9,0,5,6,4,0,3,1,
				0,3,0,7,9,0,0,6,4 };
			for (int i = 0; i < 81; i++)
				ch[i] = ch[i] + '0';
			Solver s;
			int t[9][9] = { 6,4,5,3,1,2,9,8,7,
							9,8,7,6,4,5,3,1,2,
							3,1,2,9,8,7,6,4,5,
							4,5,6,1,2,3,8,7,9,
							8,7,9,4,5,6,1,2,3,
							1,2,3,8,7,9,4,5,6,
							5,6,4,2,3,1,7,9,8,
							7,9,8,5,6,4,2,3,1,
							2,3,1,7,9,8,5,6,4 };
			s.solve(ch, 0);
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					Assert::AreEqual(s.table[i][j], t[i][j]);
		}
	};
}

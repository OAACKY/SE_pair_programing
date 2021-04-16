#include "Monitor.h"
/*
1.生成不重复的数独终局至文件
2.读取文件中数独问题，求解并将结果输出至文件
*/
int main(int argc, char *argv[])
{
	Monitor monitor(argc, argv);
	monitor.Operation();
	return 0;
}



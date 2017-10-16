//---------------------------------------------------------------------------------------
//     HUX旭
//     windows10 vs2017
//          sudoku
//---------------------------------------------------------------------------------------


//头文件、命名空间
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include "Genrarato.h"
using namespace std;

//主函数
int main(int argc, char* args[])
{
	freopen("sudoku.txt", "w", stdout);
	if (argc != 3 || strcmp(args[1], "-c") != 0)
	{
		printf("error:请输入正确参数!");
		return 0;
	}
	for (int i = 0; i < strlen(args[2]); i++)
	{
		if (args[2][i] <= '9' && args[2][i] >= '0')
			continue;
		else
		{
			printf("error:请输入正确参数!");
			return 0;
		}
	}
	string str(args[2]);
	int number = std::atoi(str.c_str());
	//printf("参数正确，开始生成%d个数独\n", number);
	/*string n;
	cin >> n;
	for(int i=0;i<n.size();i++)
	{
	if (n[i] > '9' || n[i] < '0')
	{
		printf("请输入正确参数");
	return 0;
	}
	}
	int number = atoi(n.c_str());*/
	srand(unsigned char(time(NULL)));//初始化随机数种子
	while (number) {
		ass();
		Switch();
		prin(sudoku);
		number--;
		memset(sudoku, 0, sizeof(sudoku));
		memset(record, 0, sizeof(record));
	}

	//system("pause");
	return 0;
}
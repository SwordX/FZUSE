#pragma once
//宏定义
int first = (1 + 1) % 9 + 1;//左上角第一个数字，学号尾号为311
int sudoku[10][10] = { 0 };//数独数组，初始值为0
int record[11] = { 0 };//用于记录第一个九宫格的数字

#include<iostream>
using namespace std;

//左上角第一个3x3九宫格赋值
void ass() {
	record[0] = first;//将左上角第一个数字记录
	sudoku[0][0] = first;//左上角第一个数字赋值进Sudoku数组内
	int k = 1, i = 0, j, q, temp;

	for (j = 1; j < 3;) {                   //第一行赋值
		temp = rand() % 10;//随机生成10以内的随机数
						   //cout << temp << endl;
		for (q = 0; q < 11; q++) {
			if (temp == 0 || temp == record[q])
				break;
			else
				continue;
		}
		if (q < 9)
			continue;
		else {
			sudoku[i][j] = temp;
			record[k] = temp;
			k++;
			j++;
		}
	}
	i++;

	for (j = 0; j < 3;) {                   //第二行赋值
		temp = rand() % 10;//随机生成10以内的随机数
						   //cout << temp << endl;
		for (q = 0; q < 11; q++) {
			if (temp == record[q])
				break;
			else
				continue;
		}
		if (q < 9)
			continue;
		else {
			sudoku[i][j] = temp;
			record[k] = temp;
			k++;
			j++;
		}
	}
	i++;

	for (j = 0; j < 3;) {                   //第三行赋值
		temp = rand() % 10;//随机生成10以内的随机数
						   //cout << temp << endl;
		for (q = 0; q < 11; q++) {
			if (temp == 0 || temp == record[q])
				break;
			else
				continue;
		}
		if (q < 9)
			continue;
		else {
			sudoku[i][j] = temp;
			record[k] = temp;
			k++;
			j++;
		}
	}
}

//行交换
void HS(int a, int b, int c, int d)
{
	for (int j = 0; j < 3; j++)
	{
		sudoku[c][d + j] = sudoku[a + 1][b + j];
		sudoku[c + 1][d + j] = sudoku[a + 2][b + j];
		sudoku[c + 2][d + j] = sudoku[a][b + j];
	}
}

//列交换函数
void LS(int a, int b, int c, int d)
{
	for (int j = 0; j < 3; j++)
	{
		sudoku[c + j][d] = sudoku[a + j][b + 2];
		sudoku[c + j][d + 1] = sudoku[a + j][b];
		sudoku[c + j][d + 2] = sudoku[a + j][b + 1];
	}
}

//交换方法 36种
void Switch()
{
	int k = rand() % 4;
	if (k == 0)
	{
		HS(0, 0, 0, 3); HS(0, 3, 0, 6);               //第一行行交换以及列交换(1)
		LS(0, 0, 3, 0); LS(3, 0, 6, 0);
	}
	if (k == 1)
	{
		HS(0, 0, 0, 3); HS(0, 3, 0, 6);               //第一行行交换以及列交换(2)
		LS(0, 0, 6, 0); LS(6, 0, 3, 0);
	}
	if (k == 2)
	{
		HS(0, 0, 0, 6); HS(0, 6, 0, 3);               //第一行行交换以及列交换(2)
		LS(0, 0, 3, 0); LS(3, 0, 6, 0);
	}

	if (k == 3)
	{
		HS(0, 0, 0, 6); HS(0, 6, 0, 3);               //第一行行交换以及列交换(3)
		LS(0, 0, 6, 0); LS(6, 0, 3, 0);
	}
	int d = rand() % 2;
	int o = rand() % 4;
	//cout << k << " " << d << " " << o << endl;
	if (d == 0 && o == 0)
	{
		LS(0, 3, 3, 3); LS(3, 3, 6, 3);
		LS(0, 6, 3, 6); LS(3, 6, 6, 6);
	}

	if (d == 0 && o == 1)
	{
		LS(0, 3, 6, 3); LS(6, 3, 3, 3);
		LS(0, 6, 3, 6); LS(3, 6, 6, 6);
	}

	if (d == 0 && o == 2)
	{
		LS(0, 3, 3, 3); LS(3, 3, 6, 3);
		LS(0, 6, 6, 6); LS(6, 6, 3, 6);
	}

	if (d == 0 && o == 3)
	{
		LS(0, 3, 6, 3); LS(6, 3, 3, 3);
		LS(0, 6, 6, 6); LS(6, 6, 3, 6);
	}

	if (d == 1 && o == 0)
	{
		HS(3, 0, 3, 3); HS(3, 3, 3, 6);
		HS(6, 0, 6, 3); HS(6, 3, 6, 6);
	}

	if (d == 1 && o == 1)
	{
		HS(3, 0, 3, 6); HS(3, 6, 3, 3);
		HS(6, 0, 6, 3); HS(6, 3, 6, 6);
	}

	if (d == 1 && o == 2)
	{
		HS(3, 0, 3, 3); HS(3, 3, 6, 3);
		HS(6, 0, 6, 6); HS(6, 6, 6, 3);
	}

	if (d == 1 && o == 3)
	{
		HS(3, 0, 3, 6); HS(3, 6, 3, 3);
		HS(6, 0, 6, 6); HS(6, 6, 6, 3);
	}
}

//输出
void prin(int array[][10])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
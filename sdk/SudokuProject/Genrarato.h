#pragma once
//�궨��
int first = (1 + 1) % 9 + 1;//���Ͻǵ�һ�����֣�ѧ��β��Ϊ311
int sudoku[10][10] = { 0 };//�������飬��ʼֵΪ0
int record[11] = { 0 };//���ڼ�¼��һ���Ź��������

#include<iostream>
using namespace std;

//���Ͻǵ�һ��3x3�Ź���ֵ
void ass() {
	record[0] = first;//�����Ͻǵ�һ�����ּ�¼
	sudoku[0][0] = first;//���Ͻǵ�һ�����ָ�ֵ��Sudoku������
	int k = 1, i = 0, j, q, temp;

	for (j = 1; j < 3;) {                   //��һ�и�ֵ
		temp = rand() % 10;//�������10���ڵ������
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

	for (j = 0; j < 3;) {                   //�ڶ��и�ֵ
		temp = rand() % 10;//�������10���ڵ������
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

	for (j = 0; j < 3;) {                   //�����и�ֵ
		temp = rand() % 10;//�������10���ڵ������
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

//�н���
void HS(int a, int b, int c, int d)
{
	for (int j = 0; j < 3; j++)
	{
		sudoku[c][d + j] = sudoku[a + 1][b + j];
		sudoku[c + 1][d + j] = sudoku[a + 2][b + j];
		sudoku[c + 2][d + j] = sudoku[a][b + j];
	}
}

//�н�������
void LS(int a, int b, int c, int d)
{
	for (int j = 0; j < 3; j++)
	{
		sudoku[c + j][d] = sudoku[a + j][b + 2];
		sudoku[c + j][d + 1] = sudoku[a + j][b];
		sudoku[c + j][d + 2] = sudoku[a + j][b + 1];
	}
}

//�������� 36��
void Switch()
{
	int k = rand() % 4;
	if (k == 0)
	{
		HS(0, 0, 0, 3); HS(0, 3, 0, 6);               //��һ���н����Լ��н���(1)
		LS(0, 0, 3, 0); LS(3, 0, 6, 0);
	}
	if (k == 1)
	{
		HS(0, 0, 0, 3); HS(0, 3, 0, 6);               //��һ���н����Լ��н���(2)
		LS(0, 0, 6, 0); LS(6, 0, 3, 0);
	}
	if (k == 2)
	{
		HS(0, 0, 0, 6); HS(0, 6, 0, 3);               //��һ���н����Լ��н���(2)
		LS(0, 0, 3, 0); LS(3, 0, 6, 0);
	}

	if (k == 3)
	{
		HS(0, 0, 0, 6); HS(0, 6, 0, 3);               //��һ���н����Լ��н���(3)
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

//���
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
//---------------------------------------------------------------------------------------
//     HUX��
//     windows10 vs2017
//          sudoku
//---------------------------------------------------------------------------------------


//ͷ�ļ��������ռ�
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include "Genrarato.h"
using namespace std;

//������
int main(int argc, char* args[])
{
	freopen("sudoku.txt", "w", stdout);
	if (argc != 3 || strcmp(args[1], "-c") != 0)
	{
		printf("error:��������ȷ����!");
		return 0;
	}
	for (int i = 0; i < strlen(args[2]); i++)
	{
		if (args[2][i] <= '9' && args[2][i] >= '0')
			continue;
		else
		{
			printf("error:��������ȷ����!");
			return 0;
		}
	}
	string str(args[2]);
	int number = std::atoi(str.c_str());
	//printf("������ȷ����ʼ����%d������\n", number);
	/*string n;
	cin >> n;
	for(int i=0;i<n.size();i++)
	{
	if (n[i] > '9' || n[i] < '0')
	{
		printf("��������ȷ����");
	return 0;
	}
	}
	int number = atoi(n.c_str());*/
	srand(unsigned char(time(NULL)));//��ʼ�����������
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
#pragma once
#include "member.h"
#include "Myjson.h"
#include<iostream>

using namespace std;

void mrank()         //��������
{
	//���ȼ�¼����������ѧ������
	int Scount = 0, Dcount = 0;   //ScountΪ���������ѧ������DcountΪ��������Ĳ�����
	int i = 0;
	while (!stu[i].student_num._Equal("NULL"))
	{
		Scount++;
		i++;
	}
	//cout << Scount << endl;
	int j = 0;
	while (dep[j].departments_num != "NULL")
	{
		Dcount++;
		j++;
	}
	//cout << Dcount << endl;

	//��ƽ�����Ϊ�˲��ú������Ϊ˳��ԭ��ѡ�������Ȱ��ռ����������
	double temp = 0; //  ��ʱ��ųɼ�
	int mhigh;    //��¼��ǰ��߷ֵı��
	int mrank = 1; //��ǰ����
	for (i = 0; i < Scount; i++)
	{
		for (j = 0; j < Scount; j++)
		{
			if (stu[j].rank == 0 && stu[j].student_name != "NULL" && stu[j].student_gap > temp)
			{
				temp = stu[j].student_gap;
				mhigh = j;
			}
		}
		stu[mhigh].rank = mrank;
		mrank++;
		temp = 0;
	}

	/*i = 0;
	while (stu[i].student_name != "NULL")
	{
	cout << stu[i].student_name << ".rank is :" << stu[i].rank << endl;
	i++;
	}*/
}
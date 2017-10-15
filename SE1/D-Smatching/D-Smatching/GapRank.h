#pragma once
#include "member.h"
#include "Myjson.h"
#include<iostream>

using namespace std;

void mrank()         //绩点排名
{
	//首先记录部门数量和学生数量
	int Scount = 0, Dcount = 0;   //Scount为本次输入的学生数，Dcount为本次输入的部门数
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

	//公平起见，为了不让后面的因为顺序原因选不到，先按照绩点进行排名
	double temp = 0; //  暂时存放成绩
	int mhigh;    //记录当前最高分的编号
	int mrank = 1; //当前排名
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
#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include "member.h"
#include "Myjson.h"
#include "GapRank.h"
#include "mtime.h"
using namespace std;

void TDSmatching()  
{
	int i = 0;
	int j = 0;

	//�Լ���������ÿһ��ѧ������������
	int rank = 1;
	for (i = 0;; i++)
	{
		if (stu[i].rank == 0)
			break;
		else if (stu[i].rank == rank)
		{
			j = 0;
			while (dep[j].departments_name != "NULL")
			{
				int k = 0;
				while (stu[i].intention_dep[k] == dep[j].departments_name && dep[j].member_limit!=0)    //��ѧ�����������벿��������ͬ
				{
					bool flag = true;
					int l = 0;
					while (stu[i].match[l] == dep[j].departments_name)   //����������ѧ������Ĳ����б�ʱ
					{
						flag = false;
						l++;
					}
					if (flag == true)
					{
						//�жϱ�ǩ�Ƿ���һ������
						bool tflag = false;
						int a = 0;
						while (dep[j].tags[a] != "NULL")
						{
							int b = 0;
							while (stu[i].interest[b] != "NULL")
							{
								if (dep[j].tags[a] == stu[i].interest[b])  //��һ����ǩ���Ͼͷ�����ȷ
									tflag = true;
								b++;
							}
							a++;
						}
						if (tflag == true)
						{
							//����ѧ����Ϣ
							stu[i].match[stu[i].matching] = dep[j].departments_name;
							stu[i].matching++;
							//������Ϣ����
							dep[j].member_limit--;
							dep[j].member[dep[j].matching] = stu[i].student_name;
							dep[j].matching++;
						}
					}
					k++;
				}
				j++;
			}
			rank++;         //��������һλ
			i = -1;         //�ó���ص���һ��ѧ�����¿�ʼ����
		}
		else continue;
	}
}
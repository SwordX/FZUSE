#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include "member.h"
#include "Myjson.h"
#include "GapRank.h"
using namespace std;

void SDSmatching()
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
				int k = stu[i].matching;
				while (stu[i].intention_dep[k] != "NULL")
				{
					j = 0;
					while (dep[j].departments_name != "NULL")
					{
						if (stu[i].intention_dep[k] == dep[j].departments_name && dep[j].member_limit != 0)
						{
							//�ж�ʱ���Ƿ��ͻ
							bool flag = false;
							int e = 0;
							while (dep[j].available_time[e] != "NULL")
							{
								int q = 0;
								while (stu[i].available_time[q] != "NULL")
								{
									if (mtime(dep[j].available_time[e], stu[i].available_time[q]))  //�����һ��ʱ��β����Ͼͱ���̭
										flag = true;
									q++;
								}
								e++;
							}

							if (flag == true)
							{
								bool tflag = false;
								int a = 0;
								while (stu[i].interest[a] != "NULL")
								{
									int b = 0;
									while (dep[j].tags[b] != "NULL")
									{
										if (stu[i].interest[a] == dep[j].tags[b])
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
									break;
								}
							}
						}
						j++;
					}
					k++;
				}
			i = -1;
			rank++;
		}
		else continue;
	}
}
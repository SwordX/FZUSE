#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include "member.h"
#include "Myjson.h"
#include "GapRank.h"
#include "mtime.h"
using namespace std;

void FDSmatching()           //��һ־Ը�����Ұ��ձ�ǩ����ƥ��
{	
	int i = 0;
	int j = 0;

	//��һ־Ը���ȣ���ѧ����������Ⱥ�
	int rank = 1;
	for (i = 0;;i++)
	{
		if (stu[i].rank == 0)
			break;
		else if (stu[i].rank == rank)             //�ҵ���ǰ������ѧ��
		{
			j = 0;
			while (dep[j].departments_name != "NULL")
			{
				if (dep[j].departments_name == stu[i].intention_dep[0] && dep[j].member_limit!=0)
				{
					//�ж�ʱ���Ƿ��ͻ
					bool flag = false;
					int e = 0;
					while (dep[j].available_time[e] != "NULL")
					{
						int q = 0;
						while (stu[i].available_time[q] != "NULL")
						{
							if (mtime(dep[j].available_time[e], stu[i].available_time[q]))  //�����һ��ʱ��η��Ͼͱ�¼ȡ
								flag = true;
							q++;
						}
						e++;
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
							break;
						}

					}
				}
				j++;
			}
	     	rank++;         //��������һλ
			i = -1;         //�ó���ص���һ��ѧ�����¿�ʼ����
		}
		else continue;   
	}
}

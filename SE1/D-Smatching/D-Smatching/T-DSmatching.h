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

	//以绩点排名，每一个学生的所有意向
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
				while (stu[i].intention_dep[k] == dep[j].departments_name && dep[j].member_limit!=0)    //当学生的意向部门与部门名字相同
				{
					bool flag = true;
					int l = 0;
					while (stu[i].match[l] == dep[j].departments_name)   //当部门已在学生加入的部门列表时
					{
						flag = false;
						l++;
					}
					if (flag == true)
					{
						//判断便签是否有一个符合
						bool tflag = false;
						int a = 0;
						while (dep[j].tags[a] != "NULL")
						{
							int b = 0;
							while (stu[i].interest[b] != "NULL")
							{
								if (dep[j].tags[a] == stu[i].interest[b])  //有一个标签符合就返回正确
									tflag = true;
								b++;
							}
							a++;
						}
						if (tflag == true)
						{
							//更新学生信息
							stu[i].match[stu[i].matching] = dep[j].departments_name;
							stu[i].matching++;
							//部门信息更新
							dep[j].member_limit--;
							dep[j].member[dep[j].matching] = stu[i].student_name;
							dep[j].matching++;
						}
					}
					k++;
				}
				j++;
			}
			rank++;         //排名到下一位
			i = -1;         //让程序回到第一个学生重新开始遍历
		}
		else continue;
	}
}
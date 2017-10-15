#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include "member.h"
#include "Myjson.h"
#include "GapRank.h"
#include "mtime.h"
using namespace std;

void FDSmatching()           //第一志愿优先且按照便签进行匹配
{	
	int i = 0;
	int j = 0;

	//第一志愿优先，按学生绩点进行先后
	int rank = 1;
	for (i = 0;;i++)
	{
		if (stu[i].rank == 0)
			break;
		else if (stu[i].rank == rank)             //找到当前排名的学生
		{
			j = 0;
			while (dep[j].departments_name != "NULL")
			{
				if (dep[j].departments_name == stu[i].intention_dep[0] && dep[j].member_limit!=0)
				{
					//判断时间是否冲突
					bool flag = false;
					int e = 0;
					while (dep[j].available_time[e] != "NULL")
					{
						int q = 0;
						while (stu[i].available_time[q] != "NULL")
						{
							if (mtime(dep[j].available_time[e], stu[i].available_time[q]))  //如果有一个时间段符合就被录取
								flag = true;
							q++;
						}
						e++;
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
							break;
						}

					}
				}
				j++;
			}
	     	rank++;         //排名到下一位
			i = -1;         //让程序回到第一个学生重新开始遍历
		}
		else continue;   
	}
}

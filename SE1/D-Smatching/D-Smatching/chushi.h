#pragma once
#include<iostream>
#include<stdlib.h>
#include "member.h"
using namespace std;

void chushi()
{
	for(int j=0;j<10000;j++)
	{
		for (int i = 0; i < 100; i++)
		{
			stu[j].available_time[i] = stu[j].intention_dep[i] = stu[j].interest[i] = stu[j].match[i] = "NULL";
		}
	}
	
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			dep[i].available_time[j] = dep[i].member[j] = dep[i].tags[j] = "NULL";
		}
	}
}
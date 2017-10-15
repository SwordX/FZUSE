#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class students
{
public:
	string available_time[100]; //可用时间
	string intention_dep[100];      //意向部门
	string interest[100];             //兴趣
	double student_gap;                           //绩点
	int matching = 0;    //已加入部门数
	int rank = 0;      //用于绩点排名
	string student_name = "NULL";
	string match[100];     //   已加入的部门
	string student_num = "NULL";
}stu[10000];

class departments
{
public:
	string available_time[100];       //可用时间
	string tags[100];                 //部门标签
	int member_limit;               //人数限制
	string departments_name = "NULL";       //部门名称
	string departments_num = "NULL";        //部门编号
	int matching = 0;               //已招收人数
	string member[100];              //成员数组   
}dep[1000];
#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class students
{
public:
	string available_time[100]; //����ʱ��
	string intention_dep[100];      //������
	string interest[100];             //��Ȥ
	double student_gap;                           //����
	int matching = 0;    //�Ѽ��벿����
	int rank = 0;      //���ڼ�������
	string student_name = "NULL";
	string match[100];     //   �Ѽ���Ĳ���
	string student_num = "NULL";
}stu[10000];

class departments
{
public:
	string available_time[100];       //����ʱ��
	string tags[100];                 //���ű�ǩ
	int member_limit;               //��������
	string departments_name = "NULL";       //��������
	string departments_num = "NULL";        //���ű��
	int matching = 0;               //����������
	string member[100];              //��Ա����   
}dep[1000];
#pragma once
#include<iostream>
using namespace std;

int FZ(string a)
{
	string temp1 = " ";
	string temp2 = " ";
	//��ǰһ��ʱ��θ�ֵ
	int k=0;
	int l=0;
	int i, j;
	for (i = 0; i < a.size(); i++)
	{
		if (a[i] == '.')
		{
			k = i+1;
			break;
		}
	}

	for (i = 0; i < a.size(); i++)
	{
		if (a[i] == ':')
		{
			l = i + 1;
			break;
		}
	}

	for (i = k;k<20; i++)
	{
		if (a[i] <= '9' && a[i] >= '0')
		{
			temp1 = temp1 + a[i];
		}
		else
			break;
	}

	for (i = l;i<20; i++)
	{
		if (a[i] <= '9' && a[i] >= '0')
		{
			temp2 = temp2 + a[i];
		}
		else
			break;
	}
	int q1 = atoi(temp1.c_str());
	int q2 = atoi(temp2.c_str());
	int FZ1 = q1 * 60 + q2;
	return FZ1;
}

int BZ(string a)
{
	//����һ��ʱ�丳ֵ
	string temp3 = " ", temp4 = " ";
	int w=0;
	int e=0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '-')
		{
			w = i + 1;
		}
	}
	for (int i = w; i < a.size(); i++)
	{
		if (a[i] == ':')
		{
			e = i + 1;
		}
	}
	for (int i = w;; i++)
	{
		if (a[i] <= '9' && a[i] >= '0')
		{
			temp3 = temp3 + a[i];
		}
		else
			break;
	}
	for (int i = e;; i++)
	{
		if (a[i] <= '9' && a[i] >= '0')
		{
			temp4 = temp4 + a[i];
		}
		else
			break;
	}
	int q3 = atoi(temp3.c_str());
	int q4 = atoi(temp4.c_str());
	int BZ = q3 * 60 + q4;
	return BZ;
}

bool mtime(string a, string b)
{
	//�ж�����ʱ��������Ƿ�һ��
	string temp1 = " ";
	string temp2 = " ";
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]<'0' || a[i]>'9')
		{
			temp1 = temp1 + a[i];
		}
	}
	for (int j = 0; j < b.size(); j++)
	{
		if (b[j]<'0' || b[j]>'9')
		{
			temp2 = temp2 + b[j];
		}
	}
	bool flag1;
	if (temp1 == temp2)
		flag1 = true;
	else
		flag1 = false;

	//�Ƚϸ�ֵ
	int FL1 = FZ(a);
	int BL1 = BZ(a);
	int FL2 = FZ(b);
	int BL2 = BZ(b);
	bool flag2;
	if (FL1 >= FL2 && BL1 <= BL2)
		flag2 = true;
	else if (FL1 <= FL2 && BL1 >= BL2)
		flag2 = true;
	else
		flag2 = false;

	//�ж��Ƿ���ϵ����
	if (flag1 == true && flag2 == true)
		return true;
	else
		return false;
}

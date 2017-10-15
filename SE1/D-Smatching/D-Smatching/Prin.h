#pragma once
#include "member.h"
#include<iostream>
#include<stdlib.h>
#include <string>

using namespace std;

void Prin()
{
	Json::Value root;//根节点
	Json::Value students;//学生结点
	Json::Value departments;//部门节点
	root["matched_department_view"] = Json::Value(departments);
	root["matched_students_view"] = Json::Value(students);
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
	int Ssum = 0;
	int Dsum = 0;
	/*cout << "“" << "matched_departmant_view" << "”" << ":" << endl;
	cout << "{" << endl;*/
	for (i = 0; i < Dcount; i++)
	{
		Json::Value dept;
		if (dep[i].matching != 0)
		{
			Dsum++;
			dept["department_name"] = Json::Value(dep[i].departments_name);
			//cout << dep[i].departments_num << " " << dep[i].departments_name << "." << "this departmanr has matched :";
            j = 0;
		    while (dep[i].member[j] != "NULL")
		    {
				dept["department_member"].append(dep[i].member[j]);
			//cout << dep[i].member[j] << " ";
			j++;
		    }
		//cout << endl;
		}	
		root["matched_department_view"].append(dept);
	}
	/*cout << "}," << endl << endl;
	
	cout << "“" <<"matched_student_view"  << "”" << ":" << endl;
	cout << "{" << endl;
	*/
	for (i = 0; i < Scount; i++)
	{
		Json::Value stud;
		if (stu[i].matching != 0)
		{
			Ssum++;
			stud["student_name"] = Json::Value(stu[i].student_name);
			//cout << stu[i].student_num << " " << stu[i].student_name << "." << " this student has been matched by :";
			j = 0;
			while (stu[i].match[j] != "NULL")
			{
				stud["student_department"].append(stu[i].match[j]);
				//cout << stu[i].match[j] << " ";
				j++;
				root["matched_students_view"].append(stud);
			}
			//cout << endl;
		}
		
	}
	/*cout << "}," << endl << endl;
	
	cout << "“" << "standalone_departments" << "”" << ":" << endl;
	cout << "{" << endl;*/
	for (i = 0; i < Dcount; i++)
	{
		if (dep[i].matching == 0)
		{
			root["standalone_departments"].append(dep[i].departments_name);
		}
			//cout << dep[i].departments_num << " " << dep[i].departments_name << "." << "this departmanr has been standalone." << endl;
	}
	/*cout << "}," << endl << endl;

	cout << "“" << "standalone_students" << "”" << ":" << endl;
	cout << "{" << endl;*/
	for (i = 0; i < Scount; i++)
	{
		if (stu[i].matching == 0)
		{
			root["standalone_students"].append(stu[i].student_name);
		}
			//cout << stu[i].student_num << " " << stu[i].student_name << "." << " this student has been standalone." << endl;
	}
	Json::StyledWriter sw;

	std::cout << "StyledWriter:" << endl;
	std::cout << sw.write(root) << endl << endl;



	//输出到文件

	ofstream os("s5000-d100-out.json", ios::app);
	os << sw.write(root);
	os.close();
	/*cout << "}," << endl << endl;


	cout << "本次共有" << Dcount << "个部门，" << Scount << "个学生" << endl;
	cout << "共有" << Ssum << "个学生加入部门" << endl;
	cout << "共有" << Dsum << "个部门收到部员" << endl;*/

//	for (i = 0; i < Dcount; i++)
	//{
		//cout << dep[i].matching << " " << dep[i].member_limit << endl;
	//}

}

void k()
{
	int Scount = 0, Dcount = 0;   //Scount为本次输入的学生数，Dcount为本次输入的部门数
	int i = 0;
	while (stu[i].student_name != "NULL")
	{
		Scount++;
		i++;
	}
	cout << Scount << endl;
	int j = 0;
	while (dep[j].departments_num != "NULL")
	{
		Dcount++;
		j++;
	}
	cout << Dcount << endl;

	for (i = 0; i < Scount; i++)
	{
		cout << stu[i].student_num << " " << stu[i].student_name << " " << stu[i].rank << endl;
	}

	for (j = 0; j < Dcount; j++)
	{
		cout << dep[j].departments_num << " " << dep[j].departments_name << " " << endl;
	}

}
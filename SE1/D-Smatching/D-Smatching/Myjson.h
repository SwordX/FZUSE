#pragma once
#include <iostream>
#include <fstream>
#include "json/json.h"
#include <iostream>
#include <CTIME>
#include<string>
#include <cstdlib>
#include <sstream>
#include "member.h"
using namespace std;

void MyJson()
{
	ifstream stream;
	Json::Reader reader;
	Json::Value root;
	stream.open("s5000-d100-in.json", ios::binary);

	if (reader.parse(stream, root)) {
		for (int i = 0; i < root["students"].size(); i++) {
			stu[i].student_num = root["students"][i]["student_num"].asString();

			for (int j = 0; j < 2; j++)
			{
				stu[i].intention_dep[j] = root["students"][i]["intention_dep"][j].asString();
			}

			/*stu[i].intention_dep[0] = root["students"][i]["intention_dep"].asString();*/

			stu[i].student_name = root["students"][i]["student_name"].asString();

			stu[i].student_gap = root["students"][i]["student_gap"].asInt();

			for (int j = 0; j < 2; j++)
			{
				stu[i].available_time[j] = root["students"][i]["available_time"][j].asString();
			}

			for (int j = 0; j < 2; j++)
			{
				stu[i].interest[j] = root["students"][i]["interest"][j].asString();
			}
			//stu[i].stu_printf();
		}

		for (int i = 0; i < root["departments"].size(); i++) {
			dep[i].departments_num = (root["departments"][i]["department_num"].asString());

			dep[i].departments_name = root["departments"][i]["department_name"].asString();

			dep[i].member_limit = root["departments"][i]["member_limit"].asInt();

			for (int j = 0; j < 2; j++)
			{
				dep[i].available_time[j] = root["departments"][i]["available_time"][j].asString();
			}

			for (int j = 0; j < 2; j++)
			{
				dep[i].tags[j] = root["departments"][i]["tags"][j].asString();
			}
			//dep[i].dep_printf();
		}
	}
}

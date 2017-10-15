#pragma once
#include "member.h"
#include<iostream>

using namespace std;

void l()
{
	stu[0].available_time[0] = "Thu.20:00-22:00";
	stu[0].available_time[1] = "Thu.20:00-22:00";
	stu[0].available_time[2] = "Thu.20:00-22:00";
	stu[0].intention_dep[0] = "WL";
	stu[0].intention_dep[1] = "ZZ";
	stu[0].interest[0] = "singing";
	stu[0].interest[1] = "dancing";
	stu[0].interest[2] = "high";
	stu[0].student_gap = 4;
	stu[0].student_name = "zhangsan";
	stu[0].student_num = "001";

	stu[1].available_time[0] = "Thu.20:00-22:00";
	stu[1].available_time[1] = "Wed.20:00-22:00";
	stu[1].available_time[2] = "Thu.20:00-22:00";
	stu[1].intention_dep[0] = "ZZ";
	stu[1].intention_dep[1] = "WL";
	stu[1].intention_dep[2] = "LL";
	stu[1].interest[0] = "speaking";
	stu[1].interest[1] = "dancing";
	stu[1].interest[2] = "singing";
	stu[1].student_gap = 5;
	stu[1].student_name = "lisi";
	stu[1].student_num = "002";

	stu[2].available_time[0] = "Sat.20:00-22:00";
	stu[2].available_time[1] = "Sat.20:00-22:00";
	stu[2].available_time[2] = "Sat.20:00-22:00";
	stu[2].intention_dep[0] = "ZZ";
	stu[2].intention_dep[1] = "LL";
	stu[2].interest[0] = "speaking";
	stu[2].interest[1] = "dancing";
	stu[2].interest[2] = "singing";
	stu[2].student_gap = 3;
	stu[2].student_name = "wangwu";
	stu[2].student_num = "003";

	dep[0].available_time[0] = "Thu.20:00-22:00";
	dep[0].available_time[1] = "Thu.20:00-22:00";
	dep[0].available_time[2] = "Thu.20:00-22:00";
	dep[0].member_limit = 20;
	dep[0].departments_name = "WL";
	dep[0].departments_num = "001";
	dep[0].tags[0] = "singing";
	dep[0].tags[1] = "dancing";
	dep[0].tags[2] = "high";

	dep[1].available_time[0] = "Thu.20:00-22:00";
	dep[1].available_time[1] = "Thu.20:00-22:00";
	dep[1].available_time[2] = "Thu.20:00-22:00";
	dep[1].member_limit = 20;
	dep[1].departments_name = "ZZ";
	dep[1].departments_num = "002";
	dep[1].tags[0] = "speaking";
	dep[1].tags[1] = "dancing";
	dep[1].tags[2] = "singing";

	dep[2].available_time[0] = "Wed.20:00-22:00";
	dep[2].available_time[1] = "Thu.20:00-22:00";
	dep[2].available_time[2] = "Thu.20:00-22:00";
	dep[2].member_limit = 20;
	dep[2].departments_name = "LL";
	dep[2].departments_num = "002";
	dep[2].tags[0] = "speaking";
	dep[2].tags[1] = "dancing";
	dep[2].tags[2] = "singing";
}

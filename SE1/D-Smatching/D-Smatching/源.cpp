#include <iostream>
#include <fstream>
#include "json/json.h"
#include <iostream>
#include <CTIME>
#include<string>
#include <cstdlib>
#include <sstream>
#include "member.h"
#include "F-DSmatching.h"
#include "Myjson.h"
#include "S-DSmatching.h"
#include "赋值.h"
#include "Prin.h"
#include "mtime.h"
#include "chushi.h"
#include "T-DSmatching.h"
//ofstream file("output.json", ios::app);
using namespace std;

int main()
{
	chushi();            //初始化数组
	MyJson();
	//l();
	mrank();           
	FDSmatching();     
	SDSmatching();
	TDSmatching();
	//k();
	Prin();
	//system("pause");
	return 0;
}
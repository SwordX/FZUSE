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
#include "��ֵ.h"
#include "Prin.h"
#include "mtime.h"
#include "chushi.h"
#include "T-DSmatching.h"
//ofstream file("output.json", ios::app);
using namespace std;

int main()
{
	chushi();            //��ʼ������
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
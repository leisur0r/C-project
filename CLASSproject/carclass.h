#pragma once
#include<bits/stdc++.h>
using namespace std;
class car{
public:
	string car_ID;
	string car_color;
	string car_style;
	int used_time; 
	double cost;double per_cost;//µ¥¼Û 
	time_t start_time;
	time_t end_time;
	car(time_t start);
	~car();
	car();
	void SetEnd(); 
	string formatInfo();
	void ShowStart();
	void ShowEnd();
	void ShowProcess();
};

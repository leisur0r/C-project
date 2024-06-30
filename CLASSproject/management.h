#pragma once
#include<bits/stdc++.h>
#include<memory>
#include"window.h"
#include"Pushbutton.h"
#include"carclass.h"
#include"table.h"
using namespace std;
class Management{
private:
	enum mod
	{
		Display,
		Add,
		Erase,
		Search,
		Cut, 
		Menu = 22
	}; 
	string m_header;
	ExMessage m_msg; 
	IMAGE m_ph;
	vector<PushButton*> menu_btns;
	vector<car> vec_car;
	vector<car> in_car;
	table* m_showtable; 
	unique_ptr<PushButton> m_addbtn;	
	unique_ptr<PushButton> m_erasebtn;
	unique_ptr<PushButton> m_cutbtn;
	unique_ptr<PushButton> m_sbtn;
	unique_ptr<PushButton> m_disbtn;
public:
	Management();
	void run();//启动
	
	void display();//展示 
	void add();//车辆停入 
	void erase();//车辆离开 
	void search();//查询车辆 
	void cut();//删除数据 
	void drawbackground();//背景
	void eventloop(); 
	
	void readfile(string filename);
	void savefile(string filename);
	int menu();//菜单 
};

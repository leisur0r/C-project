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
	void run();//����
	
	void display();//չʾ 
	void add();//����ͣ�� 
	void erase();//�����뿪 
	void search();//��ѯ���� 
	void cut();//ɾ������ 
	void drawbackground();//����
	void eventloop(); 
	
	void readfile(string filename);
	void savefile(string filename);
	int menu();//�˵� 
};

#include<bits/stdc++.h>
#include<easyx.h>
#include"carclass.h"
using namespace std;

car::car(){}
car::car(time_t start):start_time(start){
	end_time=0;used_time=0;cost=0;
	char mes[128];
	string color,id;
	int S;
	InputBox(mes,100,"���������룺���ơ���ɫ"); 
	stringstream ss(mes);
	ss>>id>>color;
	car_ID=id;
	car_color=color;
	cout<<id<<" "<<color<<endl;
	char m_i[5];
	InputBox(m_i,100,"��ѡ�����Ĵ�С:(1.С����/2.С��/3.�п�/4.��)");
	
	switch(m_i[0]){
		case '1':
			car_style="С����";
			this->per_cost=10.0; 
			break;
		case '2':
			car_style="С��";
			this->per_cost=15.0; 
			break;
		case '3':
			car_style="�п�";
			this->per_cost=20.0; 
			break;
		case '4':
			car_style="��";
			this->per_cost=25.0; 
			break;
	} 
	//cout<<this->car_style;
};
car::~car(){};

void car::SetEnd(){
	time_t end=time(0);
	end_time=end;
	used_time=difftime(end_time,start_time); 
	cost=used_time*per_cost;
}; 
	
void car::ShowStart(){
	string dt=ctime(&start_time);
	cout<<dt<<endl;
};
void car::ShowEnd(){
	if(end_time)
	{
		string dt=ctime(&end_time);
		cout<<dt<<endl;
	} 
	else
	{
		cout<<"δ�˳�ͣ����"<<endl;
	}
};
void car::ShowProcess(){
	if(end_time)
	{
		cout<<"������"<<this->used_time<<"��"<<endl;
	}
	else
	{
		cout<<"δ�˳�ͣ����"<<endl; 
	}
};
string car::formatInfo(){
	stringstream ss;
	ss<<car_ID<<"\t"<<car_color<<"\t"<<car_style<<"\t"<<start_time<<"\t"
		     <<end_time<<"\t"<<cost<<endl;
	
	return ss.str();
}
	


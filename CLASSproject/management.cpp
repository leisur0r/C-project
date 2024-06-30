#include"management.h"
#include"window.h"
#include"carclass.h"
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
Management::Management(){
	readfile("data.txt");
	m_header="�����ƺ�	 ������ɫ	�����ͺ�	����ʱ��	�˳�ʱ��	Ӧ�ɷ���"; 
	::loadimage(&m_ph,"park.png",Window::width(),Window::height());
	::settextstyle(25,0,"����");
	
	menu_btns.push_back(new PushButton("�޸�����"));
	menu_btns.push_back(new PushButton("��������"));	
	menu_btns.push_back(new PushButton("�����˳�"));	
	menu_btns.push_back(new PushButton("���ҳ���"));	
	menu_btns.push_back(new PushButton("ɾ����¼")); 
	menu_btns.push_back(new PushButton("�˳�ϵͳ")); 
	
	for(int i=0;i<menu_btns.size();i++)
	{
		menu_btns[i]->setFixedSize(250,50);
		int bx=(Window::width()-menu_btns[i]->width())/2;
		int space=(Window::height()-menu_btns[i]->height()*5)/2;
		int by=space+i*menu_btns[i]->height();
		menu_btns[i]->move(bx,by);
	} 
	m_showtable=new table; 
	m_showtable->setRowcount(1);
	m_showtable->setHeader(m_header);

	/*for(auto& val:vec_car)
	{
		m_showtable->insertData(val.formatInfo());
	}*/
	m_showtable->move((Window::width()-m_showtable->width())/2,200);
	
	m_addbtn.reset(new PushButton("���",440,180)); 
	m_erasebtn.reset(new PushButton("�˳�",440,180)); 
	m_cutbtn.reset(new PushButton("ɾ��",440,180));
	m_sbtn.reset(new PushButton("��ѯ",240,150));
	m_disbtn.reset(new PushButton("�޸�",640,150));
} 
void Management::run(){
	int m=22;
	Window::beginDraw();
	while(1)
	{	
		Window::clear();
		drawbackground();
		//eventloop();
		//��esc�˳���
		if(Window::hasMsg())
		{
			m_msg=Window::getMsg();
			switch(m_msg.message)
			{
			case WM_KEYDOWN:
				if(m_msg.vkcode==VK_ESCAPE)
				{
					m=Menu;
				}
				break;
			default://������ 
				break;
			}
		}
 
		
		switch(m)
		{
		case Menu:
			::settextstyle(25,0,"����");
			m=menu();
			break;
		case Management::Add:
			add();
			break;
		case Management::Display:
			display();
			break;
		case Management::Erase:
			erase();
			break;
		case Management::Search:
			search();
			break;
		case Management::Cut:
			cut();
			break;
		default:
			savefile("test.txt");
			exit(1);
			break;
		}
		Window::flushDraw();
		Window::getMsg().message=0;
	}
	Window::endDraw();
};
int Management::menu(){
	
	for(int i=0;i<menu_btns.size();i++)
	{
		menu_btns[i]->show();
		menu_btns[i]->eventLoop(m_msg);  
		if(menu_btns[i]->isClicked())
		{
			return i;
		}
	}
	
	return 22;
};
void Management::add(){
	const char* title1 ="�����·���ť����������";
	settextstyle(36,0,"����"); 
	bool is_in=false;
	char mes[100];
	
	outtextxy((Window::width()-textwidth(title1))/2,100,title1);
	m_addbtn->show();
	m_addbtn->eventLoop(m_msg);

	if(m_addbtn->isClicked())
	{
		//cout<<"hello"<<endl;
		time_t now=time(0);
		car a(now);
		
		for(car& val:in_car){
			if(val.car_ID==a.car_ID){
				is_in=true;
				InputBox(mes,100,"�����Ѿ�ͣ��");
			}
		}
		if(!is_in){
			in_car.push_back(a); 
			InputBox(mes,100,"�����ɹ�ͣ��");
		}
	}
	
};
void Management::erase(){
	//cout<<"erase"<<endl;
	const char* title1 ="�����·���ť�����복��";
	settextstyle(36,0,"����"); 
	outtextxy((Window::width()-textwidth(title1))/2,100,title1);
	bool is_in=false;
	char mes[100];
	string id;
	m_erasebtn->show();
	m_erasebtn->eventLoop(m_msg);
	if(m_erasebtn->isClicked()){
		InputBox(mes,100,"�������˳��ĳ��ƺ�");
		stringstream ss(mes);
		ss>>id;
		for(auto it=in_car.begin();it!=in_car.end();++it){
	        if (it->car_ID == id) {
	            is_in = true;
	            it->SetEnd();
	            vec_car.push_back(*it); 
				in_car.erase(it);
				InputBox(mes,100,"�����ɹ��˳�");
				break;
	        }
    	}
		
		if(is_in==false)
		{
			InputBox(mes,100,"��������ϵͳ��");
		}
		
	}
	
};
void Management::display(){
	const char* title1 ="�����·���ť���в�ѯ���޸�";
	settextstyle(25,0,"����"); 
	outtextxy((Window::width()-textwidth(title1))/2,100,title1);
	bool is_in=false;
	char mes[100];
	car a;
	string id,color,style;
	eventloop();
	m_sbtn->show();
	m_sbtn->eventLoop(m_msg);
	m_disbtn->show();
	m_disbtn->eventLoop(m_msg); 
	eventloop();
	if(m_sbtn->isClicked()){
		InputBox(mes,100,"������Ҫ��ѯ�ĳ��ƺ�");
		stringstream ss1(mes);
		ss1>>id;
		
		for(auto it=in_car.begin();it!=in_car.end();++it){
	        if (it->car_ID==id){
	            is_in = true;
	            a=*it;
	            m_showtable->clear();
	            m_showtable->insertData(a.formatInfo());
				break;
	        }
    	}
		if(is_in==false)
		{
			InputBox(mes,100,"��������ϵͳ��");
		}
	}
	if(m_disbtn->isClicked()){
		m_showtable->clear();
		InputBox(mes,100,"������Ҫ�޸ĵĳ��ƺ�");
		stringstream ss1(mes);
		ss1>>id;
		
		
		for(auto it=in_car.begin();it!=in_car.end();++it){
	        if (it->car_ID == id) {
	            is_in = true;
	            it->car_color=color;
	            InputBox(mes,100,"�������µ���ɫ");
				stringstream ss2(mes);
				ss2>>color;
				it->car_color=color;
				InputBox(mes,100,"�������µ��ͺ�(1.С����/2.С��/3.�п�/4.��)");
				stringstream ss3(mes);
				ss3>>style;
				switch(mes[0]){
					case '1':
						it->car_style="С����";
						it->per_cost=10.0; 
						break;
					case '2':
						it->car_style="С��";
						it->per_cost=15.0; 
						break;
					case '3':
						it->car_style="�п�";
						it->per_cost=20.0; 
						break;
					case '4':
						it->car_style="��";
						it->per_cost=25.0; 
						break;
				}
				InputBox(mes,100,"�޸ĳɹ�");
				a=*it;
	            m_showtable->insertData(a.formatInfo());
				break;
	        }
    	}
    	if(is_in==false)
		{
			InputBox(mes,100,"��������ϵͳ��");
		}
	}
};
void Management::search(){
	//outtextxy(0,0,"search");
	//cout<<"search"<<endl;
	const char* title1 ="�����·���ť�����복��";
	settextstyle(25,0,"����"); 
	outtextxy((Window::width()-textwidth(title1))/2,100,title1);
	bool is_in=false;
	char mes[100];
	car a;
	string id;
	m_sbtn->show();
	m_sbtn->eventLoop(m_msg);
	eventloop();
	if(m_sbtn->isClicked()){
		InputBox(mes,100,"������Ҫ��ѯ�ĳ��ƺ�");
		stringstream ss1(mes);
		ss1>>id;
		
		for(auto it=in_car.begin();it!=in_car.end();++it){
	        if (it->car_ID==id){
	            is_in = true;
	            a=*it;
	            m_showtable->clear();
	            m_showtable->insertData(a.formatInfo());
				break;
	        }
    	}
		
		if(is_in==false)
		{
			InputBox(mes,100,"��������ϵͳ��");
		}
	}
	
};
void Management::cut(){
	const char* title1 ="�����·���ť�����복��";
	settextstyle(36,0,"����"); 
	outtextxy((Window::width()-textwidth(title1))/2,100,title1);
	bool is_in=false;
	char mes[100];
	string id,start;
	m_cutbtn->show();
	m_cutbtn->eventLoop(m_msg);
	if(m_cutbtn->isClicked()){
		InputBox(mes,100,"������Ҫɾ���ĳ��ƺ�");
		stringstream ss1(mes);
		ss1>>id;
		InputBox(mes,100,"�������¼�Ŀ�ʼʱ��");
		stringstream ss2(mes);
		ss2>>start;
		for(auto it=vec_car.begin();it!=vec_car.end();++it){
	        if (it->car_ID==id&&to_string(it->start_time)==start){
	            is_in = true;
				vec_car.erase(it);
				InputBox(mes,100,"��¼�ѳɹ�ɾ��");
				break;
	        }
    	}
		
		if(is_in==false)
		{
			InputBox(mes,100,"��������ϵͳ��");
		}
	}
}
void Management::drawbackground(){
	::putimage(0,0,&m_ph);
}
void Management::readfile(string filename){
	ifstream ifile(filename,ios::in);
	if (!ifile.is_open()) 
	{
	    cout<<"Failed to open the file."<<endl;
	    return ;
	}
	while(!ifile.eof()){
		char data[1024]={0};
		ifile.getline(data,1024);
		bool isEmptyLine = true;//�ж����Ƿ�Ϊ�� 
    	for (int i = 0; data[i] != '\0'; ++i) {
        	if (data[i] != ' ' && data[i] != '\t' && data[i] != '\n' && data[i] != '\r') {
            	isEmptyLine = false;
            	break;
        	}
    	}	
    	if(isEmptyLine){
    		continue;
		}
		car a;
		stringstream ss(data);
		
		ss>>a.car_ID>>a.car_color>>a.car_style>>a.start_time>>a.end_time>>a.cost;
		vec_car.push_back(a); 
		cout<<a.car_ID<<a.car_color<<a.car_style<<a.start_time<<a.end_time<<a.cost<<endl;
	}
	
	ifile.close();
}
void Management::savefile(string filename){
	ofstream ofile(filename,ios::out |ios::trunc);
	if(!ofile.is_open())
	{
		cout<<"Failed to open the file."<<endl;
	       return ;
	}
	
	for(auto& val:vec_car){
		cout<<val.formatInfo();
		string info =val.formatInfo();
		ofile<<info;
	}
	ofile.close();
}
void Management::eventloop(){
	m_showtable->show();
	
}

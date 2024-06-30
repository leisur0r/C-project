#include"management.h"
#include"window.h"
#include"carclass.h"
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
Management::Management(){
	readfile("data.txt");
	m_header="车辆牌号	 车辆颜色	车辆型号	进入时间	退出时间	应缴费用"; 
	::loadimage(&m_ph,"park.png",Window::width(),Window::height());
	::settextstyle(25,0,"宋体");
	
	menu_btns.push_back(new PushButton("修改数据"));
	menu_btns.push_back(new PushButton("车辆进入"));	
	menu_btns.push_back(new PushButton("车辆退出"));	
	menu_btns.push_back(new PushButton("查找车辆"));	
	menu_btns.push_back(new PushButton("删除记录")); 
	menu_btns.push_back(new PushButton("退出系统")); 
	
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
	
	m_addbtn.reset(new PushButton("添加",440,180)); 
	m_erasebtn.reset(new PushButton("退出",440,180)); 
	m_cutbtn.reset(new PushButton("删除",440,180));
	m_sbtn.reset(new PushButton("查询",240,150));
	m_disbtn.reset(new PushButton("修改",640,150));
} 
void Management::run(){
	int m=22;
	Window::beginDraw();
	while(1)
	{	
		Window::clear();
		drawbackground();
		//eventloop();
		//按esc退出。
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
			default://鼠标操作 
				break;
			}
		}
 
		
		switch(m)
		{
		case Menu:
			::settextstyle(25,0,"宋体");
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
	const char* title1 ="请点击下方按钮并输入数据";
	settextstyle(36,0,"楷体"); 
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
				InputBox(mes,100,"车辆已经停入");
			}
		}
		if(!is_in){
			in_car.push_back(a); 
			InputBox(mes,100,"车辆成功停入");
		}
	}
	
};
void Management::erase(){
	//cout<<"erase"<<endl;
	const char* title1 ="请点击下方按钮并输入车牌";
	settextstyle(36,0,"楷体"); 
	outtextxy((Window::width()-textwidth(title1))/2,100,title1);
	bool is_in=false;
	char mes[100];
	string id;
	m_erasebtn->show();
	m_erasebtn->eventLoop(m_msg);
	if(m_erasebtn->isClicked()){
		InputBox(mes,100,"请输入退出的车牌号");
		stringstream ss(mes);
		ss>>id;
		for(auto it=in_car.begin();it!=in_car.end();++it){
	        if (it->car_ID == id) {
	            is_in = true;
	            it->SetEnd();
	            vec_car.push_back(*it); 
				in_car.erase(it);
				InputBox(mes,100,"车辆成功退出");
				break;
	        }
    	}
		
		if(is_in==false)
		{
			InputBox(mes,100,"车辆不在系统内");
		}
		
	}
	
};
void Management::display(){
	const char* title1 ="请点击下方按钮进行查询和修改";
	settextstyle(25,0,"楷体"); 
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
		InputBox(mes,100,"请输入要查询的车牌号");
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
			InputBox(mes,100,"车辆不在系统内");
		}
	}
	if(m_disbtn->isClicked()){
		m_showtable->clear();
		InputBox(mes,100,"请输入要修改的车牌号");
		stringstream ss1(mes);
		ss1>>id;
		
		
		for(auto it=in_car.begin();it!=in_car.end();++it){
	        if (it->car_ID == id) {
	            is_in = true;
	            it->car_color=color;
	            InputBox(mes,100,"请输入新的颜色");
				stringstream ss2(mes);
				ss2>>color;
				it->car_color=color;
				InputBox(mes,100,"请输入新的型号(1.小汽车/2.小卡/3.中卡/4.大卡)");
				stringstream ss3(mes);
				ss3>>style;
				switch(mes[0]){
					case '1':
						it->car_style="小汽车";
						it->per_cost=10.0; 
						break;
					case '2':
						it->car_style="小卡";
						it->per_cost=15.0; 
						break;
					case '3':
						it->car_style="中卡";
						it->per_cost=20.0; 
						break;
					case '4':
						it->car_style="大卡";
						it->per_cost=25.0; 
						break;
				}
				InputBox(mes,100,"修改成功");
				a=*it;
	            m_showtable->insertData(a.formatInfo());
				break;
	        }
    	}
    	if(is_in==false)
		{
			InputBox(mes,100,"车辆不在系统内");
		}
	}
};
void Management::search(){
	//outtextxy(0,0,"search");
	//cout<<"search"<<endl;
	const char* title1 ="请点击下方按钮并输入车牌";
	settextstyle(25,0,"楷体"); 
	outtextxy((Window::width()-textwidth(title1))/2,100,title1);
	bool is_in=false;
	char mes[100];
	car a;
	string id;
	m_sbtn->show();
	m_sbtn->eventLoop(m_msg);
	eventloop();
	if(m_sbtn->isClicked()){
		InputBox(mes,100,"请输入要查询的车牌号");
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
			InputBox(mes,100,"车辆不在系统内");
		}
	}
	
};
void Management::cut(){
	const char* title1 ="请点击下方按钮并输入车牌";
	settextstyle(36,0,"楷体"); 
	outtextxy((Window::width()-textwidth(title1))/2,100,title1);
	bool is_in=false;
	char mes[100];
	string id,start;
	m_cutbtn->show();
	m_cutbtn->eventLoop(m_msg);
	if(m_cutbtn->isClicked()){
		InputBox(mes,100,"请输入要删除的车牌号");
		stringstream ss1(mes);
		ss1>>id;
		InputBox(mes,100,"请输入记录的开始时间");
		stringstream ss2(mes);
		ss2>>start;
		for(auto it=vec_car.begin();it!=vec_car.end();++it){
	        if (it->car_ID==id&&to_string(it->start_time)==start){
	            is_in = true;
				vec_car.erase(it);
				InputBox(mes,100,"记录已成功删除");
				break;
	        }
    	}
		
		if(is_in==false)
		{
			InputBox(mes,100,"车辆不在系统内");
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
		bool isEmptyLine = true;//判断行是否为空 
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

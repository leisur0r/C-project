#pragma once
#include"BasicWidget.h"
#include<bits/stdc++.h>
#include<graphics.h>
#include<easyx.h> 
using namespace std;
class PushButton:public BasicWidget{
protected:
	string m_text;
	ExMessage m_msg;
	COLORREF cur_c=RGB(232,232,233);
	COLORREF normal_c=RGB(232,232,233);
	COLORREF hover_c=BLUE;
public:
	PushButton(const string &text="Button",int x=0,int y=0,int w=100,int h=30);
	void show() override;
	bool isin();//判断是否在按钮上 
	bool isClicked();//判断是否点击 
	void eventLoop(const ExMessage& msg);
};



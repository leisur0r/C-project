#pragma once
#include<bits/stdc++.h>
#include"BasicWidget.h"
#include<easyx.h>
using namespace std;
class Lineedit:public BasicWidget{
public:
	Lineedit(int x=0,int y=0,int w=150,int h=30);
	void show() override;
	inline void setTitle(const string title){m_title=title;}; 
private:
	string m_text;
	COLORREF cur_c=RGB(232,232,233);
	string m_title;
	bool isin();//判断是否在按钮上 
	bool isClicked();//判断是否点击 
};

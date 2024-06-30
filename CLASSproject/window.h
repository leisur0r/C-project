#pragma once
#include<bits/stdc++.h>
#include"Configure.h"
#include<easyx.h> 
using namespace std;
class Window{
public:
	Window(int w,int h,int flag);
	void setWindowTitle(const string& title);
	int exec();
	static int width();
	static int height();
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();
	//按键操作和鼠标操作
	//判断有没有消息
	inline static bool hasMsg() {return ::peekmessage(&m_msg,EX_MOUSE | EX_KEY); }
	inline static ExMessage& getMsg(){ return m_msg; }
private:
	HWND m_handle;  //窗口句柄 
	static ExMessage m_msg;//消息 
};

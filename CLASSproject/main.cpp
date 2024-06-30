#include<graphics.h>
#include<easyx.h> 
#include <conio.h>
#include<bits/stdc++.h>
#include"carclass.h"
#include"management.h"
#include"Window.h"
#include"table.h"
int main()
{
	Window w(960,640,EW_SHOWCONSOLE);
	w.setWindowTitle("停车场管理系统");
	
	Management m;
	m.run();
	return w.exec();
}



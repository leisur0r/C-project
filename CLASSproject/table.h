#pragma once
#include<bits/stdc++.h>
#include"BasicWidget.h"
using namespace std;
class table:public BasicWidget{
private:
	int m_rows;
	int m_cols;
	string m_header;
	//格子的宽高 
	int m_gridW;
	int m_gridH;
	//文字的宽高
	int m_tw;
	int m_th;
	
	 
	vector<string> m_datas;
	
public:
	table(int row=0,int col=0);
	void setRowcount(int row);
	void setColcount(int col);
	void show();
	void clear();
	void drawTalbeGrid();
	void drawTalbeData();
	void insertData(string data);
	void setHeader(string header);
	vector<string> split(string str,char separator ='\t');
};

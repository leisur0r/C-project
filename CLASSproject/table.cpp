#include"table.h"
#include"easyx.h"
#include<bits/stdc++.h> 
using namespace std;
table::table(int row,int col):BasicWidget(0,0,0,0),m_rows(row),m_cols(col){
	
}
void table::setRowcount(int row){
	m_rows=row;
};
void table::setColcount(int col){
	m_cols=col;
};
void table::setHeader(string header){
	
	m_header=header;
	m_cols=6;
	
	m_tw=::textwidth("1719456417");
	m_th=::textheight(m_header.c_str());
	
	m_gridW=::textwidth("1719456417 ")+5;
	m_gridH=::textheight(m_header.c_str())+10;
	
	m_w=m_gridW*m_cols;
	m_h=m_gridH*m_rows;
}
void table::show(){
	drawTalbeGrid();
	drawTalbeData();
};

void table::drawTalbeGrid(){
	setlinecolor(BLACK);
	for(size_t i=0;i<m_rows+1;i++){
		line(m_x,m_y+i*m_gridH,m_x+m_cols*m_gridW,m_y+i*m_gridH);
	}	
	for(size_t i=0;i<m_cols+1;i++){
		line(m_x+i*m_gridW,m_y,m_x+i*m_gridW,m_y+m_rows*m_gridH);
	}
};
void table::drawTalbeData(){
	for(size_t i=0;i<m_datas.size();i++)//ÐÐ 
	{
		const auto& line_data =split(m_datas[i]);
		for(size_t k=0;k<line_data.size();k++)//ÁÐ 
		{
			
			int tx=m_x+k*m_gridW+(m_gridW-::textwidth(line_data[k].c_str()))/2;
			int ty=m_y+i*m_gridH+10;
			outtextxy(tx,ty,line_data[k].c_str());
		}
	}
}

void table::insertData(string data){
	m_datas.push_back(data);
}
void table::clear(){
	m_datas.clear();
}
vector<string> table::split(string str,char separator){
	vector<string> res;
	for(size_t pos=0;pos !=string::npos; ) 
	{
		pos=str.find(separator);
		res.push_back(str.substr(0,pos));
		str=string(str.c_str()+pos+1);
	}
	return res;
}


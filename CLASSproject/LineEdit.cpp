#include"LineEdit.h"

Lineedit::Lineedit(int x,int y,int w,int h):BasicWidget(x,y,w,h){
	m_text="hello";
}
void Lineedit::show(){
	setfillcolor(cur_c);
	::fillroundrect(m_x,m_y,m_x+m_w,m_y+m_h,10,10);
	//Œƒ◊÷æ”÷–œ‘ æ
	settextcolor(BLACK);
	int tx=m_x+(m_w-textwidth(m_text.c_str()))/2;
	int ty=m_y+(m_h-textheight(m_text.c_str()))/2;
	::outtextxy(tx,ty,m_text.c_str()); 
	


}





#include<bits/stdc++.h>
using namespace std;
struct student{
	int ID;
	string name;
	double score;
};
int main()
{
	student s[4]={
		101,"wang",88,
		102,"zhang",99,
		103,"li",95,
		104,"huang",89
	};
	string filename="f1.dat";
	ofstream ofile(filename);
	if(!ofile.is_open())
	{
		cout<<"Failed to open the file."<<endl;
        return 0;
	}
	for(int i=0;i<4;i++)
	{
		ofile<<s[i].ID<<" "<<s[i].name<<" "<<s[i].score<<endl;
	}
	 
	ifstream ifile(filename);//ifstream file("student.txt");
    if (!ifile.is_open()) 
	{
        cout<<"Failed to open the file."<<endl;
        return 0;
    }
    for(int i=0;i<4;i++)
	{
		student a;
		ifile>>a.ID>>a.name>>a.score;
		cout<<a.ID<<" "<<a.name<<" "<<a.score<<endl;;
	}

    s[1].score=94;
    ofile.clear();
    for(int i=0;i<4;i++)
	{
		ofile<<s[i].ID<<" "<<s[i].name<<" "<<s[i].score<<endl;
	}
	for(int i=0;i<4;i++)
	{
		student a;
		ifile>>a.ID>>a.name>>a.score;
		cout<<a.ID<<" "<<a.name<<" "<<a.score<<endl;;
	}
	ofile.close();
	ifile.close();
    
	return 0;
} 

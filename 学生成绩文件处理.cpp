#include<bits/stdc++.h>
using namespace std;
int main()
{
	string filename="student.txt";
	 
	ifstream file(filename);//ifstream file("student.txt");
    if (!file.is_open()) 
	{
        cout<<"Failed to open the file."<<endl;
        return 0;
    }
    vector<int> scores; 
    int score;
    while(file>>score) 
	{
        scores.push_back(score);
    }
    file.close();//可以没有 
    int sum=0;
    for(int i=0;i<scores.size();i++) 
	{
        sum+=scores[i];
    }
    int average=sum/scores.size();
    
    int max= *max_element(scores.begin(),scores.end());
    int min= *min_element(scores.begin(),scores.end());
    int max_deviation=max-average;
    int min_deviation=min-average;
    cout<<average<<endl;
    cout<<max_deviation<<endl;
    cout<<min_deviation<<endl;
	return 0;
} 

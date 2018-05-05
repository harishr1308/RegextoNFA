#include<string>
#include<iostream>

using namespace std;

int main()
{
	string s="s";
	for (int i=0;i<3;i++)
	{
		// returns the characters 0,1 and 2
	   	char ch=char(i+48);

	   	// concat between string and char
	   	string text=s+ch;
		
		// this line prints s0,s1 and s2
	   	cout<<text<<endl;
	}
	return 0;
}

#include<string>
#include<iostream>
using namespace std;
int main()
{
char s="s";
for (int i=0;i<3;i++)
  {
   char ch=char(i+48);
   char text=s+ch;
   cout<<text<<endl;
  }
return 0;
}

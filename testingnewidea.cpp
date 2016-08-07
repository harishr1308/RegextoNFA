#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int sides=6;
vector<vector<int> > xycoordinates;
vector<vector<int> >transitions;
//vector<vector<char> >alpha;
int stateradius=20;
int initial_state=0,final_state=5;

void testing1()
{
 for(int j=0;j<sides;j++)
   {
    vector<int> temp;
    for(int i=0;i<sides;i++)
       temp.push_back(-2);
    transitions.push_back(temp);
    temp.erase(temp.begin(),temp.end());
   }
}


/*void testing2()
{
 for(int j=0;j<sides;j++)
   {
    vector<char> temp;
    for(int i=0;i<sides;i++)
    temp.push_back('a');
    alpha.push_back(temp);
    temp.erase(temp.begin(),temp.end());
   }
}
*/


void testing3()
{
 for(int j=0;j<sides;j++)
   {
    vector<int> temp;
    for(int i=0;i<2;i++)
       temp.push_back(0);
    xycoordinates.push_back(temp);
    temp.erase(temp.begin(),temp.end());
   }
}

void testing()
{
  int initial_state=0,final_state=5;
  transitions[0][1]=1;
  transitions[0][2]=-1;
  transitions[3][5]=-1;
  transitions[4][5]=1;
  transitions[1][3]=0;
  transitions[2][4]=0;
}


void display()
{ 
std::queue<int> myqueue;
myqueue.push(initial_state);
xycoordinates[0][0]=384;
xycoordinates[0][1]=50;
 do
  {
   int temp=myqueue.front();
   myqueue.pop();   
   for(int i=0;i<sides;i++)
    {
      if(transitions[temp][i]!=-2) 
       {
        myqueue.push(i);
        if(transitions[temp][i]==0) 
          {
            xycoordinates[i][0]=xycoordinates[temp][0]+50;
            xycoordinates[i][1]=xycoordinates[temp][1];
          }
        else if(transitions[temp][i]==-1) 
          {
            xycoordinates[i][0]=xycoordinates[temp][0]+50;
            xycoordinates[i][1]=xycoordinates[temp][1]-50;
          }
        else if(transitions[temp][i]==1) 
          {
            xycoordinates[i][0]=xycoordinates[temp][0]+50;
            xycoordinates[i][1]=xycoordinates[temp][1]+50;
          }
       }
    }
  }while(!myqueue.empty()); 
 for(int i=0;i<sides;i++)
  {
    cout<<i<<"\t"<<xycoordinates[i][0]<<"\t"<<xycoordinates[i][1]<<endl;
  }
}

void test()
{
 testing1();
// testing2();
 testing3();
 testing();
}


int main()
{
 test();
 display();
}

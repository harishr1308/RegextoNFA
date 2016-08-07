#include<iostream>
#include<stack.h>
#include <string.h>
using namespace std;

vector<char> postfix;
vector<char> infix;
vector<char> temp;
int priority(char a) 
{
     int temp;
     if( a=='^')
         temp = 1;
     else
     {
         if(a=='*' || a=='/')
              temp = 2;
         else
         {
             if(a=='+' || a=='-')
                  temp = 3;
         }
     }
     return temp;
}


      
void convert()
{  
    for (int i=0; i<infix.size(); i++)
    {
       if (infix[i]!='+' || infix[i]!='-' || infix[i]!='*' || infix[i]!='/' || infix[i]!='^' || infix[i]!='(' || infix[i]!=')')
          {
            postfix.push_back(infix[i]);
            cout << postfix.top();
          }
       else
       {
           if (infix[i]=='(')
              temp.push_back(infix[i]);
           else
           {
               if (infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]!='^')
               {
                    while (priority(temp.top()) <= priority(infix[i]))
                    {
                         postfix.push(infix[i]);
                         cout << postfix.top();
                         temp.pop();
                    }
                    temp.push(infix[i]);
               }
               else if(infix[i]==')')
               {
                    while (temp.top() != '(')
                    {
                         postfix.push(infix[i]);
                         cout << postfix.top();
                         temp.pop();
                    }
                    temp.pop();
               }
                   
           }
       }
    }      
       
    getch();
    return 0;
}


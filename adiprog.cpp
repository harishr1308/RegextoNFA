#include<iostream>
#include"infixconv.cpp"
#include<vector>
using namespace std;
#define MAX 200

//string inreg="(a+b)*(a*+b*)*";
char postfix[MAX];
vector<vector<int> >transitions;
vector<vector<char> > alpha;
vector<vector<char> > dfaalpha;
int cur, initial_state, final_state;

int mmstack[MAX];
int mmtop;

void vectorinit()
{
 for(int i=0;i<MAX;i++)
 {
   vector<int> temp;
   for(int j=0;j<MAX;j++)
    {
      temp.push_back(-2);
    }
   transitions.push_back(temp);
   temp.erase(temp.begin(),temp.end());
 }
}

struct nfa_state
{
 int a, b, eps1, eps2;
}NFA[MAX];

void convert(string inreg)
{
 string postreg = regInfixToRegPostfix(inreg);
 for (int i=0;i<postreg.length();i++)
  {
    postfix[i]=postreg[i];
  }
}

struct dfa_state
{
 int state[MAX],a[MAX],b[MAX];
}DFA[MAX];


void mmpush(int val)
{
 mmstack[++mmtop]=val;
}

int mmpop()
{
 return mmstack[mmtop--];
}

void initvector()
{
 for(int j=0;j<=cur;j++)
 {
  vector<char> temp;
  for(int i=0;i<=cur;i++)
     temp.push_back(' ');
  alpha.push_back(temp);
  temp.erase(temp.begin(),temp.end());
 } 
}

int priority(char op)
{
 switch(op)
  {
   case '+': return 1;
   case '.': return 2;
   case '*': return 3;
  }
 return 0;
}

void init_nfa_table()
{
 int i;
  for(i=0; i<MAX; i++)
   {
     NFA[i].a = NFA[i].b = -1;
     NFA[i].eps1 = NFA[i].eps2 = -1;
   }
}

void symbol(char c)
{
  if(c=='a')
     NFA[cur].a = cur+1;

  if(c=='b')
     NFA[cur].b = cur+1;

  mmpush(cur);
  mmpush(cur+1);

  cur += 2;
}

void concat()
{
 int first1, first2, last1, last2;

 last2 = mmpop();
 first2 = mmpop();
 last1 = mmpop();
 first1 = mmpop();
 NFA[last1].eps1 = first2;
 transitions[first1][last1]=0;
 transitions[last1][first2]=0;
 transitions[first2][last2]=0;

 mmpush(first1);
 mmpush(last2);
}

void parallel()
{
 int first1, first2, last1, last2;
 
 last2 = mmpop();
 first2 = mmpop();
  
 last1 = mmpop();
 first1 = mmpop();
 
 NFA[cur].eps1 = first1;
 NFA[cur].eps2 = first2;
 transitions[cur][first1]=-1;
 transitions[cur][first2]=1;

 NFA[last1].eps1 = cur+1;
 NFA[last2].eps1 = cur+1;
 transitions[last1][cur+1]=1;
 transitions[last2][cur+1]=-1;
 
 transitions[first1][last1]=0;
 transitions[first2][last2]=0;

 
 mmpush(cur);
 mmpush(cur+1);
 cur += 2;
}

void closure()
{
 int first,last;

 last = mmpop();
 first = mmpop();
 transitions[cur][first]=0;
 transitions[cur][cur+1]=3;
 NFA[cur].eps1 = first;
 NFA[cur].eps2 = cur+1;
 NFA[last].eps1 = first;
 NFA[last].eps2 = cur+1;
 transitions[first][last]=0;
 transitions[last][first]=2;
 transitions[last][cur+1]=0;
 mmpush(cur);
 mmpush(cur+1);
 cur += 2;
}

void construct_nfa(char *postfix)
{
 int i=0;

 mmtop=-1;

 for(i=0; postfix[i]!='\0'; i++)
  {
   switch(postfix[i])
    {
      case 'a':case 'b': symbol(postfix[i]);break;
      case '.': concat();break;
      case '+': parallel();break;
      case '*': closure();
    }
  }
 final_state = mmpop();
 initial_state = mmpop();
}

void disp_NFA()
{
 int i;
 cout<<"\nstate\ta\tb\tî";
  for(i=0;i<cur;i++)
   {
     if(i==initial_state)
        cout<<"\n->"<<i;
     else
         if(i==final_state)
              cout<<"\n* "<<i;
         else
              cout<<"\n "<<i;

     if(NFA[i].a==-1)
        cout<<"\t-";
     else
        {
         cout<<"\t{"<<NFA[i].a<<"}";
         alpha[i][NFA[i].a]='a';
        }

     if(NFA[i].b==-1)
        cout<<"\t-";
     else
        {
         cout<<"\t{"<<NFA[i].b<<"}";
         alpha[i][NFA[i].b]='b';
        }
     if(NFA[i].eps1!=-1)
      {
        cout<<"\t{"<<NFA[i].eps1;
	alpha[i][NFA[i].eps1]='#';
        if(NFA[i].eps2!=-1)
         {
           cout<<","<<NFA[i].eps2;
           alpha[i][NFA[i].eps2]='#';
         }
        cout<<"}";
      }
     else
        cout<<"\t-";
   }
  cout<<endl;
}

void init_dfa_table()
{
 int i,j;
  for(i=0;i<20;i++)
   {
    for(j=0;j<20;j++) 
     {
       DFA[i].state[j]=-1;
       DFA[i].a[j]=-1;
       DFA[i].b[j]=-1;
     }
    }
}

void print_state(int t[])
{
 int i=0;
 cout<<"[";
 for(i=0;t[i]!=-1;i++)
    cout<<t[i]<<",";
 cout<<"\b]";
}

int isPresent(int T[], int v)
{
 int i;
 for(i=0;T[i]!=-1;i++)
   if(T[i]==v) return 1;
   else return 0;
}

void disp_DFA(int n)
{
 int i;
 cout<<"\nstate\t\t\ta\t\t\tb";
   for(i=0;i<=n;i++)  
    {
     cout<<"\n";
     if(i==0)
        cout<<"->";

     if(isPresent(DFA[i].state,final_state))
        cout<<"*";

     print_state(DFA[i].state);
     cout<<"\t\t";

     if(DFA[i].a[0]!=-1)
        print_state(DFA[i].a);
     else
        cout<<"\t-";
     cout<<"\t\t";
     if(DFA[i].b[0]!=-1)
        print_state(DFA[i].b);
     else
        cout<<"\t-";
    }
    cout<<endl;
}

void ep_clos(int T[], int t[])
{
 int i,v;
 mmtop=-1;

 for(i=0;t[i]!=-1;i++)
    mmpush(t[i]);

 i=0;

 while(mmtop!=-1)
  { 
    v = mmpop();

    if(isPresent(T,v)==0)
      {
       T[i++]=v; 
      }

    if(NFA[v].eps1!=-1)
      {
       mmpush(NFA[v].eps1);
      }

    if(NFA[v].eps2!=-1)
      {
       mmpush(NFA[v].eps2);
      }
  }
}

void init_t(int t[])
{
 int i;
 for(i=0;i<MAX;i++)
    t[i]=-1; 
}

int search(int n,int t2[])
{
 int i,j;
 for(i=0;i<=n;i++)
   {
     for(j=0;t2[j]!=-1;j++)
     if(isPresent(DFA[i].state,t2[j])==0)
         break;
     if(t2[j]==-1)
         return 1;
   }
 return 0;
}

void copy(int t1[], int t2[])
{
 int i;
 for(i=0;t2[i]!=-1;i++)
    t1[i]=t2[i];
}

void retonfa(string inreg)
{
 
 int t[MAX],v;
 int n=0,i=0,j,k;
 vectorinit();
 convert(inreg);

 init_nfa_table();
 construct_nfa(postfix);
 initvector();
 disp_NFA();

 init_dfa_table();
 init_t(t);

 t[0]=initial_state;
 ep_clos(DFA[0].state,t);
 init_t(t);

 for(j=0,k=0; DFA[0].state[j]!=-1 ; j++)
  {
   v = DFA[0].state[j];

   if(NFA[v].a!=-1)
    {
      if(isPresent(t,NFA[v].a)==0)
         t[k++]=NFA[v].a;
    }
  }

 ep_clos(DFA[0].a,t);

 init_t(t);

 for(j=0,k=0;DFA[0].state[j]!=-1;j++)
   {
    v = DFA[0].state[j];
    if(NFA[v].b!=-1) 
     {
      if(isPresent(t,NFA[v].b)==0)
          t[k++]=NFA[v].b;
     }
   }
 ep_clos(DFA[0].b,t);

 for(i=0;i<=n;i++)
   {
     if( search( n , DFA[i].a)==0 )
       {
         n++;
         copy(DFA[n].state,DFA[i].a);

         init_t(t);

         for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
           {
             v = DFA[n].state[j];

             if(NFA[v].a!=-1)
               {
                 if(isPresent(t,NFA[v].a)==0)
                    t[k++]=NFA[v].a;
               }
           }

          ep_clos(DFA[n].a,t);

          init_t(t);

          for(j=0,k=0;DFA[n].state[j]!=-1;j++)
           {
             v = DFA[n].state[j];
             if(NFA[v].b!=-1)
               {
                 if(isPresent(t,NFA[v].b)==0)
                     t[k++]=NFA[v].b;
               }
           }
          ep_clos(DFA[n].b,t);

        }

       if( search( n , DFA[i].b ) ==0)
         {
           n++;
           copy(DFA[n].state,DFA[i].b);

           init_t(t);
           for( j=0,k=0; DFA[n].state[j]!=-1 ; j++)
             {
               v = DFA[n].state[j];

               if( NFA[v].a!=-1)
                 {
                   if(isPresent(t,NFA[v].a)==0)
                      t[k++]=NFA[v].a;
                 }
             }
           ep_clos(DFA[n].a,t);

           init_t(t);
           for(j=0,k=0;DFA[n].state[j]!=-1;j++)
               {
                 v = DFA[n].state[j];
                 if(NFA[v].b!=-1)
                   {
                      if(isPresent(t,NFA[v].b)==0)
                            t[k++]=NFA[v].b;
                   }
               }
           ep_clos(DFA[n].b,t);
         }
    }
 //disp_DFA(n);
}

int print()
{
//retonfa(inreg);
cout<<"  ";
for(int i=0;i<=cur;i++)
 cout<<i<<" ";
cout<<endl; 
for(int i=0;i<=cur;i++)
 {
  cout<<i<<" ";
  for(int j=0;j<=cur;j++)
   cout<<alpha[i][j]<<" ";
  cout<<endl;
 }
return 0;
}

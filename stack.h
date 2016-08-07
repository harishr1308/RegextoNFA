#include<iostream>
using namespace std;

struct node
{
    char info;
    struct node *link;    
}*top;
 
/*
 * Class Declaration
 */
class stack_list
{
    public:
        node *push(node *, char);
        node *pop(node *);
        void traverse(node *);
	node *top(node *);
        stack_list()
        {
            top = NULL;
        }               
};

node *stack_list::push(node *top, char item)
{
    node *tmp;
    tmp = new (struct node);
    tmp->info = item;
    tmp->link = top;
    top = tmp;
    return top;
}

node *stack_list::pop(node *top)
{
    node *tmp;
    if (top == NULL)
        return false;
    else
    {       
        tmp = top;
        cout<<"Element Popped: "<<tmp->info<<endl;
        top = top->link;
        free(tmp);
    }
    return top;
}

node *stack_list::top(node *top)
{
    node *tmp;
    if(top==NULL)
	return false;
    else 
    {
	return top;
    }
}

int stack_list::size(node *top)
{
   node *ptr;
   int s=0;
   ptr = top;
   if (top == NULL)
	return s;
   else
    {
       while(ptr!=NULL)
        {  
           s++;
           ptr = ptr->link;  
        }
       return s;
    }
}

void stack_list::traverse(node *top)
{       
    node *ptr;
    ptr = top;
    if (top == NULL)
        cout<<"Stack is empty"<<endl;
    else
    {
        cout<<"Stack elements :"<<endl;
        while (ptr != NULL)
        {
            cout<<ptr->info<<endl;
            ptr = ptr->link;
        }
    }
}

#include<iostream>
#include<stack>
#include<string>

using namespace std;

// Function to convert Infix expression to postfix 
string InfixToPostfix(string expression);

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not. 
bool IsOperand(char C);

int main() 
{
	string expression; 
	cout<<"Enter Infix Expression \n";
	cin>>expression;
	string postfix = InfixToPostfix(expression);
	cout<<"Output = "<<postfix<<"\n";
}

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
	stack<char> S;
	string postfix = ""; 
	for(int i = 0;i< expression.length();i++) 
        {
          	if(expression[i] == ' ') continue; 
		// If character is operator, pop two elements from stack, perform operation and push the result back. 
	  	else if(IsOperator(expression[i])) 
		{
			while(!S.empty() && S.top() != '(')
			{
				postfix+= S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		// Else if character is an operand
		else if(IsOperand(expression[i]))
		{
			postfix +=expression[i];
		}

		else if (expression[i] == '(') 
		{
			S.push(expression[i]);
		}

		else if(expression[i] == ')') 
		{
			while(!S.empty() && S.top() !=  '(') 
			{
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) 
	{
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

// Function to verify whether a character is english letter or numeric digit. 
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C)
{
	if(C == '+' || C == '*' || C == '.' || C== '$' || C== '|')
		return true;
	// $ is for end of string and | is used as or operator and + is used as +closure
	return false;
}


// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '$': weight = 1;
	case '.': weight = 2;
 	case '|': weight = 3;
	case '+':
	case '*':
		weight = 4;
	}
	return weight;
}


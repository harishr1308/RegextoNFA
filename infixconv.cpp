#include<iostream>
#include<stack>
#include<cstring>
#include<cctype>

using namespace std;

string regInfixToRegPostfix(string exp)
{
	stack<char>myStack;
	string postfix = "";

	for(int i = 0; i < exp.length(); i++){
		if(isalpha(exp[i]) || exp[i] == '*')
			postfix = postfix + exp[i];
		else if(myStack.empty())
			myStack.push(exp[i]);
		else{
			switch(exp[i]){
				case '(': 
					myStack.push(exp[i]);
					break;
				case ')':
					while(myStack.top() != '('){
						postfix = postfix + myStack.top();
						myStack.pop();
					}
					myStack.pop();
					break;
				case '.':
					while(myStack.top() == '.'){
						postfix = postfix + myStack.top();
						myStack.pop();
						if(myStack.empty())
							break;
					}
					myStack.push(exp[i]);
					break;
				case '+':
					while(myStack.top() == '.' || myStack.top() == '+'){
						postfix = postfix + myStack.top();
						myStack.pop();
						if(myStack.empty())
							break;
					}
					myStack.push(exp[i]);
					break;
			}
		}
	}

	while(!myStack.empty()){
		postfix = postfix + myStack.top();
		myStack.pop();
	}

	return postfix;
}

/*int main(){
	string inreg;
	string postreg;

	cout << "Enter a valid regular expression: ";
	cin >> inreg;

	postreg = regInfixToRegPostfix(inreg);

	cout << "Postfix form: " << postreg << endl;
	return 0;
}*/

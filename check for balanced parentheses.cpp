//check for balanced parentheses using stack
#include<iostream>
#include<stack>
using namespace std;

ispair(char ch,char top)
{
	if(ch==')'&&top=='(')
	{
		return true;
	}
	else if	(ch=='}'&&top=='{')
	{
		return true;
	}
	else if(ch==']'&&top=='[')
	{
		return true;
	}
	else 
	{
		return false;
	}
}

check(char str[])
{
	stack<char>mystack;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='('||str[i]=='{'||str[i]=='[')
		{
			mystack.push(str[i]);
		}
		else if(str[i]==')'||str[i]=='}'||str[i]==']')
		{
			if(mystack.empty()||!ispair(str[i],mystack.top()))
			{
				return false;
			}
			else
			{
				mystack.pop();
			}
		}
	}
	if(mystack.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char str[100];
	gets(str);
	if(check(str))
	{
		cout<<"yes balanced"<<endl;
	}
	else
	{
		cout<<"not balanced"<<endl;
	}
	
	return 0;
}

// Valid Parantheses
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cassert>

// O(1) Space complexity challenge
// This can be made simple using hashmap but we dont have space !
bool validParanthesesTraverseTillClose(std::string expression)
{
	int n = expression.length();
	while(expression != "")
	{
		for(int i=1; i<n; i++)
		{	
			if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
			{
				char corresponding;
				switch(expression[i])
				{
					case ')':
						corresponding = '(';
						break;
					
					case ']':
						corresponding = '[';
						break;
						
					case '}':
						corresponding = '{';
						break;
						
					default:
						break;
						
				}
				if(expression[i-1] == corresponding)
				{
					expression = expression.substr(0, n-i-1) + expression.substr(i+1, n-i);
				}
				else
				{
					return false;	
				}
			}
		}
	}
	return true;
}

bool validParanthesesPostfixStack(std::string expression)
{
	std::stack<char> charStack;
	for(char &c: expression)
	{
		char corresponding;
		if(c == '(' || c == '{' || c == '[')
		{
			charStack.push(c);
		}
		else
		{
			switch(c){
					case ')':
						corresponding = '(';
						break;
					
					case ']':
						corresponding = '[';
						break;
						
					case '}':
						corresponding = '{';
						break;
						
					default:
						break;
			}
			if(corresponding == charStack.top())
			{
				charStack.pop();
			}
			else
			{
				charStack.push(c);
			}
		}
	}
	if(charStack.size() > 0)
	{
		return false;
	}
	else return true;
}

int main(int argc, char *argv[])
{
	std::vector<std::pair<std::string, bool>> testcases = 
	{
		{"[()]", true}, {"[(])]", false}, {"[([)]", false}, {"[([])]", true},
		{"[()]{}", true}, {"[()]{]}", false}, {"[(])", false}
	};
	//std::cout << validParanthesesTraverseTillClose("[()]") << std::endl ;
	for(auto& x: testcases)
	{
		assert(validParanthesesPostfixStack(x.first) == x.second);
		std::cout << "Testcase: " <<  x.first << " [Passed] " << std::endl; 
	}
	return 0;
}

#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>

//Implementing stack to generate prefix expression

class PostfixGenerator{
	public :
		PostfixGenerator() ;
		std::string generatePostfixExpr(std::string infixExpr) ;

	private :
		std::stack<char> plates ;
		
		int precedence(char op){
			if(op == '^')
				return 3 ;
			else if(op == '/' || op == '*')
				return 2 ;
			else if(op == '+' || op == '-')
				return 1 ;
			else
				return 0 ;
		}

		bool isOperator(char op){
			if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
				return true ; 
			else 
				return false ;
		}				
};

PostfixGenerator::PostfixGenerator(){}

std::string PostfixGenerator::generatePostfixExpr(std::string infixExpr){
	std::string postfixExpr ;
	for(int i=0; i<infixExpr.length(); i++){
		if(infixExpr[i] == '(')
			plates.push(infixExpr[i]) ;
		else if(infixExpr[i] == ')'){
			while((plates.top() != '(') && !plates.empty()){
				char getOut = plates.top() ;
				postfixExpr += getOut ;
				plates.pop() ;
			}
			if(plates.top() == '(')
				plates.pop() ;
			
		}	
		else if((infixExpr[i] >= 'A' && infixExpr[i] <= 'Z') || (infixExpr[i] >= 'a' && infixExpr[i] <= 'z'))
			postfixExpr += infixExpr[i] ;
		else if(isOperator(infixExpr[i])){
			if(plates.empty())
				plates.push(infixExpr[i]) ;
			else{
				if(precedence(infixExpr[i]) > precedence(plates.top()) )
					plates.push(infixExpr[i]) ; 
				else if(precedence(infixExpr[i]) == precedence(plates.top()) && (infixExpr[i] == '^') )
					plates.push(infixExpr[i]) ;
				else{
					while(precedence(infixExpr[i]) <= precedence(plates.top()) && !plates.empty() ){
						postfixExpr += plates.top() ;
						plates.pop() ;
					}	
					plates.push(infixExpr[i]) ;	
				}
			}
		}
	}
	
	while(!plates.empty()){
		postfixExpr += plates.top() ;
		plates.pop() ;
	}		
	
	return postfixExpr ;
}

std::string& reverseStr(std::string& str){
	for(int i=0; i<str.length()/2; i++){
		std::swap(str[i], str[str.length() - i - 1]) ;
	}
	return str ;
}

std::string prefixGenerator(std::string infixExpr){
	PostfixGenerator *pg = nullptr ;
	pg = new PostfixGenerator() ;
	std::string prefixExpr, revInfix ;
	std::cout << infixExpr << std::endl ;
	revInfix = reverseStr(infixExpr) ;
	std::cout << revInfix << std::endl ;
	for(int i=0; i<revInfix.length(); i++){
		if(revInfix[i] == '(') revInfix[i] = ')' ; 
		else if(revInfix[i] == ')') revInfix[i] = '(' ; 
	}
	std::cout << revInfix << std::endl ;
	prefixExpr = pg->generatePostfixExpr(revInfix) ;
	std::cout << prefixExpr << std::endl ;
	prefixExpr = reverseStr(prefixExpr) ;
	delete pg ;	
	return prefixExpr ;
}

int main(int argc, char *argv[]){
	
	std::string prefix ;
	prefix =  prefixGenerator("(A+B^C)*D+E^F") ;
	std::cout << prefix << std::endl ;
	return 0 ;
}

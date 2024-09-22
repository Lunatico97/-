
#include <iostream>
#include <stack>
#include <cstring>

//Implementing stack to generate postfix expression

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


int main(int argc, char *argv[]){
	
	PostfixGenerator *pg = nullptr ;
	pg = new PostfixGenerator() ;
	std::string postfixExpr = pg->generatePostfixExpr("A+B-C*(D-E+F/G)/H") ;
	std::cout << postfixExpr << std::endl ;
	delete pg ;	
	
	return 0 ;
}

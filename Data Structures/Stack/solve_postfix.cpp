
#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>

//Implementing stack to generate postfix expression

class PostfixSolver{
	public :
		PostfixSolver() ;
		int getAns(std::string postfixExpr) ;

	private :
		std::stack<int> plates ;

		bool isOperator(char op){
			if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
				return true ; 
			else 
				return false ;
		}		
		
		bool isOperand(char op){
			if(op >= '0' && op <= '9')
				return true ; 
			else 
				return false ;
		}	
		
		int operate(int a, int b, char op){
			if(op == '+') return b+a ;
			else if(op == '-') return b-a ;
			else if(op == '*') return b*a ;
			else if(op == '/') return b/a ;
			else if(op == '^') return pow(b,a) ;
			else return -1 ;
		}			
};

PostfixSolver::PostfixSolver(){}

int PostfixSolver::getAns(std::string postfixExpr){
	int tempA, tempB, temp ;
	for(int i=0; i<postfixExpr.length(); i++){
		if(isOperand(postfixExpr[i]))
			plates.push(postfixExpr[i]-'0') ; //Deduce ASCII to integer
		if(isOperator(postfixExpr[i])){
			tempA = plates.top() ;
			plates.pop() ;
			tempB = plates.top() ;
			plates.pop() ;
			temp = operate(tempA, tempB, postfixExpr[i]) ;
			plates.push(temp) ;
		}
	}

	return plates.top() ;
}
 

int main(int argc, char *argv[]){
	
	PostfixSolver *ps = nullptr ;
	ps = new PostfixSolver() ;
	float ans = ps->getAns("456*+") ;
	std::cout << ans << std::endl ;
	delete ps ;	
	
	return 0 ;
}/

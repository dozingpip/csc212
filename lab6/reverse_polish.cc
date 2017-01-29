#include "stack.h"
#include <iostream>
using namespace std;
/////////////////DO NOT ADD ADDITIONAL HEADERS
/////////////////
int reverse_polish(const char *equation) {
    //
    //DO NOT CHANGE ABOVE THIS LINE
    //DO NOT PRINT FROM THIS FUNCTION
    //TO CALL THIS FUNCTION FROM MAIN USE
    //reverse_polish("345-*")
    //THIS SHOULD EQUAL -3
    //YOU CAN CHANGE THE STRING INPUT
    //
    
    //YOUR CODE HERE
    //YOUR CODE HERE
    
    //FOR EVERY CHAR IN EQUATION
    //CHECK IF IT IS +,-,*,/
    //IF IT IS POP TWO OFF STACK
    //APPLY SPECIFIC OPERATOR
    //If IT IS NOT AN OPERATOR
    //PUSH IT ON THE STACK
    
    
    //CHANGE THE RETURN VALUE TO THE RESULT
    //SET TO DEFAULT -1
    Stack stack;
    for(int i = 0; equation[i]; i++){
        int first = 0;
        int sec = 0;
        if(equation[i]=='+'){
            first = stack.pop();
            sec = stack.pop();
            stack.push(first + sec);
        }else if(equation[i]=='-'){
            first = stack.pop();
            sec = stack.pop();
            stack.push(sec - first);
        }else if(equation[i]=='/'){
            first = stack.pop();
            sec = stack.pop();
            stack.push(sec / first);
        }else if(equation[i]=='*'){
            first = stack.pop();
            sec = stack.pop();
            stack.push(first * sec);
        }else{
            int number = equation[i]-'0';
            stack.push(number);
        }
    }
   return stack.pop();
}
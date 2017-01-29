#include <iostream>
#include "stack.h"

using namespace std;

int reverse_polish(const char*);

int main() {

   Stack myStack;
   
   myStack.push(1);
   myStack.pop();

   const char *charray = "333/*7+23*-";

   cout << reverse_polish(charray) << endl;
   
   return 0;

}
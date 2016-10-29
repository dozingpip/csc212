#include <iostream>
using namespace std;




int main (int argc, char** argv) {

    //Declare an int variable, assign it the value 5
    int number = 5;
    //Declare a pointer to an int and set it to the address of i
    int *numberPtr = &number;
	//Prints the value of number and its memory address
	cout << "The variable number is set to: " << number << endl;
	cout << "The address of number is: " << numberPtr << endl;
	//Change the value of number using the pointer
	*numberPtr = 10;
	//Declare an int array on the stack
	int array_on_stack[number];
	cout << "The address of array_on_stack is: " << array_on_stack << endl;
    //Declare an int array on the heap
	int *array_on_heap = new int[number];
	cout << "The address of array_on_heap is: " << array_on_heap << endl;
	//Set each element of array_on_heap
	for (int i = 0; i < number; i++) {
		array_on_heap[i] = i;		
	}
	//Make numberPtr point to array_on_heap
	numberPtr = array_on_heap;
	//Dereference the first element of the array
	number = numberPtr[0];
	//Dereference the first element of the array
	number = *numberPtr;
	//Dereference the third element of the array
	number = numberPtr[2];
	//Dereference the third element of the array
	number = *(numberPtr+2);
	//Advance numberPtr by three
	numberPtr = numberPtr+3;
	//Dereference numberPtr at its new location
	number = *numberPtr;
	//Make numberPtr point to array_on_stack
	numberPtr = array_on_stack;
	//Set number to 10
	number = 10;
	//Set each element of array_on_stack
	for (int i = 0; i < number; i++) {
		*numberPtr++ = i;
	}
	//Delete array_on_heap
	delete [] array_on_heap;
	
    return 0;
}

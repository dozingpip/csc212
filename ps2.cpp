#include <string>
#include <iostream>
using namespace std;

long int tribonacci(int n) {
    long int current = 0;
    long int prev= 0;
    long int prev_prev = 0;
    int num =n;
    for(int i = 0; i<n; i++){
        current = num;
        num = current + prev + prev_prev;
        prev  = num;
        prev_prev = num - prev;
    }
}
long int tribonacci(int n){
	if(){
		
	}
}
void reverse(char *str, int n) {
    for(int i = 0; i<n/2; i++){
        char temp = *str;
        *str = *(str-i)
        *(str-i) = temp;
    }
}
int palindrome(char *str, int n){
	n--;
	if((str == str[n]) && (n == 2)){
		return 1;
	}else if(str == str[n]){
		pal(str+1, n);
	}else{
		return 0;
	}
}

//7
void is_sorted(int *array, int n) {
    if(){
		
    }
}
int main(int argc, char **argv){
    tribonacci(5);
}

#include <string>
#include <iostream>
using namespace std;

void q1_reverse(char *str, int n){// recursive
	char temp = NULL;
	if(n!=0){
		temp = *str;
		*str = str[n];
		str++;
		n--;
		q1_reverse(str, n);
	}
	
}

int q2_palindrome(const char *str, int n){//recursive
	n--;
	if((str == str[n]) && (n == 2)){
		return 1;
	}else if(str == str[n]){
		palindrome(str+1, n);
	}else{
		return 0;
	}
}

int q3_sorted(const int *array, int n){//recursive
	n--;
	if(n==0 && array > array[n]){
		return 0;
	}else if(array[n]>array[n-1]){
		q3_sorted(array+1, n-1);
	}else{
		return 1;
	}
}

int q4_unique(const int *A, int n, int k){
	
}

int q5_alexandrian(unsigned int A){
	
}

unsigned long int q6_hex2dec(const char *hex){
	int sum = 0;
	int len = 0;
	while(*hex != '\0'){
		len++;
		hex++;
	}
	hex-=length;
	for(int i= 0; i<len; i++){
		if(hex[i] 
	}
}

void q7_dec2hex(unsigned int d, char *hex){
	
}

int q9_virtuous(const int *A, int n){
	
}
int main(int argc, char **argv){
	return 0;
}

#include "functions.h"
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

void swap(char *str1, char *str2){
	char temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

bool palindrome(int num){
  int n = 1;
  int digits = 1;
  while(num/n >n){//999/10 >10, t; 999/100 > 100, t; 999/1000 >1000, f
    n*=10;// n=100, n = 1000
    digits+=1;
  }
  char array[digits+1];
  n*=10;
  int i = 0;
  while(n>0){
    int tempnum= num/n;
    array[i] = tempnum +'0';
    i++;
    num-=tempnum*n;
    n/=10;
    if(num<n){
      array[i] = '0';
      i++;
      n/=10;
    }
  }
  array[digits] = '\0';
  if(q2_palindrome(array, digits) ==1){
    return true;
  }else{
    return false;
  }
}

void q1_reverse(char *str, int n){// recursive
	/*if(n!=0){
		swap(str[0], str[n-2]);
		str++;
		n--;
		q1_reverse(str, n);
	}*/
}

int q2_palindrome(const char *str, int n){//recursive, good
	n--;
	if((str[0] == str[n]) && (n <= 2)){
		return 1;
	}else if(str[0] == str[n]){
		q2_palindrome(str+1, n-1);
	}else{
		return 0;
	}
}

int q3_sorted(const int *array, int n){//good
	if(n==2 && array[0] <= array[n-1]){
		return 1;
	}else if(array[0]<=array[1]){
		q3_sorted(array+1, n-1);
	}else{
		return 0;
	}
}

long int q4_unique(const int *A, int n, int k){
	long int unique =0;
	/*int count =0;
	int s =0;
	int sums[n]= {0};
	int i =0;
   for(int t=1; t<n; t++){
   		if(count<k){
   			s+=*A;
   			count++;
   			A++;
   		}
   		for(int i = 0; i<n; i++){
   			if(s == sums[i]){
   				s = 0;
   			}
   		}
   		sums[i] = s;
   		i++;
   		s= 0;
   		count = 0;
	}
	for(int i = 0; i<n; i++){
		unique+=sums[i];
	}*/
	return unique;
}

int q5_alexandrian(unsigned int A){
	int p = 1;
	/*int q = 2;
	int r = 3;
	if((p*q*r)!=A){
		for(r; r<A/2; r++){
			if((p*q*r)!=A){
				for(q; q<A/3; q++){
					if((p*q*r)!=A){
						for(p; p<A/4; p++){
							if((p*q*r)==A){
								return 1;
							}else{
								return 0;
							}
						}
					}else return 1;
				}
			}else{ return 1;}
		}
	}else{ return 1; }*/
	return p;
}

unsigned long int q6_hex2dec(const char *hex){//good
	unsigned long int sum = 0;
	int len = 0;
	if(*hex =='0' && *(hex+1)== 'x'){
	  hex+=2;
	}
	while(*hex != '\0'){
		len++;
		hex++;
	}
	hex-=len;
	while(len>0){
		int a = 0;
		switch(hex[0]){
			case '1': a = 1; break;
			case '2': a = 2; break;
			case '3': a = 3; break;
			case '4': a = 4; break;
			case '5': a = 5; break;
			case '6': a = 6; break; 
			case '7': a = 7; break;
			case '8': a = 8; break;
			case '9': a = 9; break;
			case 'A': case 'a': a = 10; break;
			case 'B': case 'b': a = 11; break;
			case 'C': case 'c': a = 12; break;
			case 'D': case 'd': a = 13; break;
			case 'E': case 'e': a = 14; break;
			case 'F': case 'f': a = 15; break;
		}
		sum+=a*pow(16, len-1);
		len--;
	}
	return sum;
}

void q7_dec2hex(unsigned int d, char *hex){//good
	unsigned long int hexplace = pow(2, 32);
	int i =2;
	char hexi[d];
	hexi[0] = '0';
	hexi[1] = 'x';
	while(d>1){
		if(d/hexplace>=1){
			if(d/hexplace<=9){
				hexi[i]= d/hexplace +'0';
			}else{
				switch(d/hexplace){
					case 10: hexi[i] = 'a';
					case 11: hexi[i] = 'b';
					case 12: hexi[i] = 'c';
					case 13: hexi[i] = 'd';
					case 14: hexi[i] = 'e';
					case 15: hexi[i] = 'f';
				}
			}
			d/=hexplace;
		}else{
		  hexi[i] = '0';
		}
		hexplace/=16;
		i++;
	}
	hex = hexi;
}

unsigned long int q8_palindromic(char k){
	//go backwards from like 99 (number of 
	//9's being k)and multiply, then see if
	// that number is palindromic, otherwise 
	//keep decreasing back from 99
	int kl = 0;
	switch(k){
		case '2': kl=11; break;
		case '3': kl=111; break;
		case '4': kl=1111; break;
		case '5': kl=11111; break;
	}
	int k1 = 9*kl;
	int k2 = k1-1;
	unsigned long int arr[10] = {0};
	int p =0;
  for(int i =k1; i>k1/9; i--){
    for(int j = k2; j>k1/9; j--){
      if(palindrome(j*i)){
        arr[p] = (unsigned long int) (j * i);
        p++;
      }
    }
  }
  unsigned long int max = 0;
  for(int i = 0; i<10; i++){
    if(arr[i]>max){
      max = (unsigned long int) arr[i];
  }
	return max;
}
}

int q9_virtuous(const int *A, int n, int k){
	return 0;
}


int main(int argc, char **argv){
  cout<<q8_palindromic('2')<<endl;
	return 0;
}
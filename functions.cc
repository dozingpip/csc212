#include "functions.h"
#include <string.h> // needed by strlen
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int count_digits(int n, int count, int place){
        if(n > place){
                place = place * 10;
                count++;
                count_digits(n, count, place);
        }else{
                return count;
        }
}

int q1_armstrong(int num){
	if(num<1){
		return 0;
	}
	if(num ==1){
		return 1;
	}
        int digits = count_digits(num, 0, 1);
        int* nums = new int [digits];
        int temp = num;
	int temp_d = digits-1;
	int sum = 0;
	/*puts each digit at an index of the nums array*/
        for (int j=0; j< digits;  j++){
                nums[j] = temp / (int) pow(10, temp_d);
                temp = temp - (nums[j] *pow(10, temp_d));
                temp_d--;
		sum+= pow(nums[j], digits);
		
        }
        if (sum == num){
                return 1;
        }else{
                return 0;
        }
}

int q2_brackets(const char *e){
	bool balanced = true;
	int open = 0, close = 0;
	if (*e == ']'){
		balanced =false;
	}else{
		while(*e != '\0'){
			if(*e == '['){
				open++;
			}else if(*e == ']'){
				close++;
			}
			if (*(e+1) == '\0' and *e == '['){
				balanced = false;
			}
			e++;
		}
	}
	if((open == close) and balanced){
		return 1;
	}else{
		return 0;
	}
}

int q3_perfect(int x){
	int sum_d = 0;
	for (int i = 1; i<x; i++){
		if(x % i == 0){
                	sum_d = sum_d + i;
		}
	}
        if (sum_d == x){
                return 1;
        }else{
                return 0;
        }
}

int q4_rotate(int n, int r){
	if( n< 1){
		return n;
	}
        int digits = count_digits(n, 0, 1)-1;
        int* nums = new int [digits];
        int temp = n;
        int temp_d = digits;
	int sum = 0;
        /*puts each digit at an index of the nums array*/
        for (int j=0; j< digits+1;  j++){
                nums[j] = temp / (int) pow(10, temp_d);
                temp = temp - (nums[j] *pow(10, temp_d));
                temp_d--;
        }
        int* now_start = new int [r];
        for(int k = 0; k<r; k++){
                now_start[k] = nums[digits - k];
        }
        for(int h = digits; h>=r; h--){
                nums[h] = nums[h-r];
        }
        int h = r-1;
        for(int y = 0; y<r; y++){
                nums[y] = now_start[h];
                h--;
        }
        temp_d = digits;
        for(int x = 0; x<=digits; x++){
                sum = sum + nums[x] * (int) pow(10, temp_d);
                temp_d--;
        }
	if (sum <1){
		cout<<"n: "<<n<<" , r: "<<r<<endl;
	}
        return sum;
}

int q5_str_search(const char *pattern, const char *text){
	int found =0;
	bool text_end = false;
	const char *save = pattern;
	int success = 0;
	while(text_end == false){
		if (*pattern == '\0'){
			found++;
			pattern = save;
			text = text - success +1;
		}else if (*text == '\0'){
			text_end = true;
			return found;
		}else if (*pattern  == *text){
			pattern++;
			text++;
			success++;
		}else{
			success = 0;
			pattern = save;
			text++;
		}
	}
}

int q6_collatz_count(int n){
        int k = 0;
        int temp = n;
	if(n<1){
		return n;
	}
	int h = 0;
        while(temp != 1){
                if (temp % 2 == 0){
                        temp = temp/2;
			h++;
                }else{
                        temp = 3*temp + 1;
			h++;
                }
        }
	return h;
}

double q7_array(int n, const int *A){
        int* B = new int [n];
        for(int u=0; u<n; u++){
                B[u] = *A * 2;
                A++;
        }

        double sum =0;
        int count = 0;
        for(int y = 0; y<n; y++){
		if(count ==5){
			return sum/5;
                }else if(B[y] % 3 == 0){
                        sum = sum + B[y];
                        count++;
                }
        }
	if(count ==5){
		return sum/5;
	}else{
		return 0;
	}
}

void q8_strings(const char *s1, const char *s2, char *s3){
        const char *s1s = s1;
        const char *s2s = s2;
        int s1length = 0;
        int s2length = 0;
        while(*s1 != '\0'){
		s1length++;
		s1++;
	}
        while(*s2 != '\0'){
		s2length++;
		s2++;
	}
	s1 = s1s;
	s2 = s2s;
        if(s1length < s2length){
                while(*s1 != '\0'){
			*s3 =*s1;
			s1++;
			s3++;
	        }
                while(*s2 != '\0'){
		        *s3 = *s2;
		        s2++;
			s3++;
	        }
                s1 = s1s;
                while(*s1 != '\0'){
		        *s3 = *s1;
		        s1++;
			s3++;
	        }
        }else{
                while(*s2 != '\0'){
			*s3 = *s2;
			s2++;
			s3++;
	        }
                while(*s1 != '\0'){
		        *s3 = *s1;
		        s1++;
			s3++;
	        }
                s2 = s2s;
                while(*s2 != '\0'){
		        *s3 = *s2;
		        s2++;
			s3++;
	        }
        }
}

void q9_sort(int x, int y, int z, int *list){
        if (x<y and x<z){
                *list = x;
                list++;
                if(y<z){
                        *list = y;
                        list++;
                        *list = z;
                }else{
                        *list = z;
                        list++;
                        *list = y;
                }
        }
        if (y<x and y<z){
                *list = y;
                list++;
                if(x<z){
                        *list = x;
                        list++;
                        *list = z;
                }else{
                        *list = z;
                        list++;
                        *list = x;
                }
        }
        if (z<x and z<y){
                *list = z;
                list++;
                if(x<y){
                        *list = x;
                        list++;
                        *list = y;
                }else{
                        *list = y;
                        list++;
                        *list = x;
                }
        }
}

void q10_max_sub_sum(const int *list, int n, int *p, int *q){
	int m = 0, s = 0,  count = 0, last_index =0, first_index = 0;
        for(int t=1; t<n; t++){
                s = s + *list;
                count++;
		list++;
                if (s<0){
                        s= 0;
                        count = 0;
                }
                if (m< s){
                        m = s;
			*q =t;
			*p = *q-count;
			//cout <<first_index<<" , last: "<<last_index<<", count "<<count<<", t: "<<t<<endl;
                }
        }
        *p = first_index;
        *q = last_index-1;
}

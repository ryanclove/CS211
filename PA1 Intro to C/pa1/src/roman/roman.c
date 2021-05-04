#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int num = atoi(argv[1]); 
	if(num == 0) {
		return 0; 
	}
	while(num > 0) {
		if(num >= 1000) {
			printf("M"); 
			num = num - 1000; 
			continue; 
		}
		if(num >= 900) {
                        printf("CM"); 
                        num = num - 900; 
                        continue; 
                }
		if(num >= 500) {
                        printf("D"); 
                        num = num - 500; 
                        continue; 
                }
 		if(num >= 400) {
                        printf("CD"); 
                        num = num - 400; 
                        continue; 
                }
		if(num >= 100) {
                        printf("C"); 
                        num = num - 100; 
                        continue; 
                }
		if(num >= 90) {
                        printf("XC"); 
                        num = num - 90; 
                        continue; 
                }
		if(num >= 50) {
                        printf("L"); 
                        num = num - 50; 
                        continue; 
                }
		if(num >= 40) {
                        printf("XL"); 
                        num = num - 40; 
                        continue; 
                }
		if(num >= 10) {
                        printf("X"); 
                        num = num - 10; 
                        continue; 
                }
		if(num >= 9) {
                        printf("IX"); 
                        num = num - 9; 
                        continue; 
                }
		if(num >= 5) {
                        printf("V"); 
                        num = num - 5; 
                        continue; 
                }
		if(num >= 4) {
                        printf("IV"); 
                        num = num - 4; 
                        continue; 
                }
		if(num >= 1) {
                        printf("I"); 
                        num = num - 1; 
                        continue; 
                }
	}
 
	return 0; 
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ignoreSymbols(char *str) {
	int i, j;
	for( i = 0; str[i] != '\0'; ++i ) {
		while( ! ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '\0')) {
			for( j = i; str[j] != '\0'; ++j ) {
				str[j] = str[j + 1]; 
			}
			str[j] = '\0'; 
		}
	} 
}

void lowerCase(char *str) {
	int i;
	for( i = 0; str[i] != '\0'; i++ ) {
		if( str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32; 
		}
	}
}

int main(int argc, char *argv[])
{   

	ignoreSymbols(argv[1]); 
	lowerCase(argv[1]); 
  
	int length = strlen(argv[1]); 
	if( length % 2 == 0 )
        {
                printf("no");
                return 0;
        }
	
	
	int i, m, k; 
	m = length/2;
	k = length - 1;  
	
	for( i = 0; i < m; i++) {
		if( argv[1][i] != argv[1][k]) {
			printf("no");
			return 0; 
		}
		k--; 
	} 
	
	printf("yes"); 
	return 0; 
}



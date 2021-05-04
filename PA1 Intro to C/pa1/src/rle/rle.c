#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int containsNumbers(char *str) {
	int i; 
	for(i = 0; str[i] != '\0'; i++) {
		if( str[i] == '0' ) {
			return 1; 
		}
		if( str[i] == '1' ) {
			return 1; 	
		}
		if( str[i] == '2' ) {
			return 1;
		}
		if( str[i] == '3' ) {
			return 1; 
		}
		if( str[i] == '4' ) {
			return 1; 
		}
		if( str[i] == '5' ) {
			return 1; 
		}
		if( str[i] == '6' ) {
			return 1; 
		}
		if( str[i] == '7' ) {
			return 1; 
		}	
		if( str[i] == '8' ) {
			return 1; 
		}
		if( str[i] == '9' ) {
			return 1; 
		}
	}
	return 0; 
}

int main(int argc, char *argv[])
{
	//zero  arguements 
	if( argc < 2 )
	{
		return 0; 
	}

	//are there numbers
	if(containsNumbers(argv[1]) == 1 ){
		printf("error");
		return 0;
	}
	
	// makes a copy of arg
	int length  = strlen(argv[1]); 
	char *sifted, *numbers;	
	sifted = (char *)malloc( sizeof(char) * (length * 2 + 1) );
	int i = 0; 
	int j = 0; 
	int k; 
	int banana; 
	numbers = (char *)malloc( (2*length+1) * sizeof(char *)); 
 	
	for(i = 0; i < length*2+1; i++ ) {
		sifted[i] = *(char*)malloc( sizeof(char) * (2*length+1) ); 
		numbers[i] = *(char*)malloc( sizeof(char) * (2*length+1) );  
	}
	sifted[0] = '\0'; 
	numbers[0] = '\0'; 

	for( i = 0; i < length; i++ ) {
		sifted[j++] = argv[1][i]; 
		banana = 1; 
		while( i + 1 < length && argv[1][i] == argv[1][1 + i] ) {
			i++; 
			banana++;
		}
		sprintf(numbers, "%d", banana); 
		for( k = 0; *(numbers + k); j++, k++) {
			sifted[j] = numbers[k]; 
		}
	}
	sifted[j] = '\0'; 
	
	
	if( (int)strlen(sifted) > length ) 
	{
		printf("%s", argv[1]);
		free(sifted); 
		free(numbers);  
		return 0; 
	} 
	else
	{
		printf("%s", sifted); 
		free(sifted); 	
		free(numbers);
		return 0;  
	}

	 
}

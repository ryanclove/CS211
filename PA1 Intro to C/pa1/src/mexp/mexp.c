#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {	
	// empty arg?
	if( argc != 2 ) {
		return 0; 
	}
	FILE *f1;
	int k; 
	f1 = fopen(argv[1], "r");
	// checks if file is empty
	if( f1 == NULL ) {
		return 0; 
	} 
	fscanf(f1, "%d", &k);
	//one number 
	if( k == 1 ) {
		int number;  
		fscanf(f1, "%d", &number); 
		int exponent; 
		fscanf(f1, "%d", &exponent);
		if( exponent == 0 ) {
			printf("%d", 0); 
			fclose(f1); 
			return 0; 
		}
		int i;
		int power = 1; 
		for( i = 0; i < exponent; i++ ) {
			power = number*power; 
		}
		printf("%d", power); 
		fclose(f1); 
		return 0; 
	}
	//2 matrices and a resulting matrix
	int **M1 = (int **)malloc(k * (sizeof(int *))); 
	int **M2 = (int **)malloc(k * (sizeof(int *))); 
	int **result = (int **)malloc(k * (sizeof(int *))); 
	// places elements
	int i; 
	for( int i = 0; i < k; i++ ) {
		M1[i] = (int *)malloc((sizeof(int))*k); 	
		M2[i] = (int *)malloc((sizeof(int))*k); 
		result[i] = (int *)malloc((sizeof(int))*k); 
	}
	// file elements
	int j; 
	for( int i = 0; i < k; i++ ) {
		for( int j = 0; j < k; j++ ) {
			fscanf(f1, "%d", &M1[i][j]); 
			M2[i][j] = M1[i][j]; 
		} 
	}
	// multiplier
	int multiplier; 
	fscanf(f1, "%d", &multiplier); 
	if( multiplier == 0 ) {
		for( i = 0; i < k; i++ ) {
			for( j = 0; j < k; j++ ) {
				if( j == k-1 ) {
					printf("%d ", 0);
				}
				else {
					printf("%d ", 0);
				} 
			}
			printf("\n"); 
		}
		free(M1); 	
		free(M2); 
		free(result); 
		fclose(f1); 
		return 0; 
	}
	
	if( multiplier == 1 ) {
		for( i = 0; i < k; i++ ) {
			for( j = 0; j < k; j++ ) {
				if( j == k-1 ) {
					printf("%d", M1[i][j]);
				}
				else {
					printf("%d ", M1[i][j]); 
				}
			}
			printf("\n"); 
		}
		free(M1); 
		free(M2);	
		free(result); 
		fclose(f1); 
		return 0; 
	}
	
	int z, n; 
	//multiplies
	for( z = 0; z < multiplier - 1; z++ ) {
		for( i = 0; i < k; i++ ) {	
			for( j = 0; j < k; j++ ) {
				result[i][j] = 0; 
				for( n = 0; n < k; n++ ) {
					result[i][j] += (M1[i][n]) * (M2[n][j]); 
				}
			}
		}
		for( i = 0; i < k; i ++ ){
			for( j = 0; j < k; j++ ) {
				M2[i][j] = result[i][j]; 
			}
		}	
	}	
	//print
	for( i = 0; i < k; i++ ) {
		for( j = 0; j < k; j++ ) {
			if( j == k - 1 ) {
				printf("%d", result[i][j]);
			}
			else	{
				printf("%d ", result[i][j]); 
			}
		}
		printf("\n"); 
	}
	
	//free
	free(M1); 
	free(M2);
	free(result); 
	fclose(f1); 
	return 0; 	
}	



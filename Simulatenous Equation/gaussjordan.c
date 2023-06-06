#include <stdio.h>

int main() {
	int i,j,k,n;
	float a[10][10],x[10];
	printf("Enter number of unkowns: ");
	scanf("%d",&n); // Number of Unkowns

	for (i = 0; i < n; i++) {
		printf("Enter coefficients of equation %d: ",i+1); 
		for (j=0; j <= n; j++) scanf("%f",&a[i][j]); //Taking Inputs for Augmented Matrix
	}

	//Using loop to create a Diagonal Matrix
	for (i=0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i != j) {
				c = a[j][i]/a[i][i];
				for (k = 0; k <= n; k++) a[j][k] = a[j][k] - c*a[i][k];
			}
		}
	}
	
	//Calculating Solution by solving each equation
	printf("Solution: ");
	for (i = 0; i < n; i++) {
		x[i] = a[i][n]/a[i][i];
		printf("%.4f, ",x[i]);
	}
	
	printf("\n");
	return 0;
}

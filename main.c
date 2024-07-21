#include<stdio.h>
#include"LinerRegression.h"

int main(){
	int size = 10;
	int x[] = {3,8,9,13,3,6,11,21,1,16};
	int y[] = {30,57,64,72,36,43,59,90,20,83};
	double* intercept_and_slopes = Intercept_Slop(x, y, size);
	printf("Intercept = %f\nSlopes= %f\n", intercept_and_slopes[0], intercept_and_slopes[1]);
	double error = root_mean_square_error(intercept_and_slopes, x, y, size);
	printf("RMSE = %f\n",error);
	printf("\tx\ty\ty' \n");
	double temporary_veriable;
	intercept_and_slopes[0] += error;
	for(int i = 0; i < size;i++){
		temporary_veriable = (intercept_and_slopes[0] + ( intercept_and_slopes[1] * x[i] ));
		printf("\t%d \t%d\t%f\n", x[i], y[i], temporary_veriable);
	}

	free(intercept_and_slopes);
return 0;
}

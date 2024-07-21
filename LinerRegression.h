#include<malloc.h>
#include<math.h>
/*	Author : Pankaj Mondal
	Date: SunDay, July 21, 2024, 2:49 PM	
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/
double root_mean_square_error(double* intercept_and_slopes, int* x, int* y, int size){
	int i;
	// printf("\tx\ty\ty'\t\terror \n");
	double error = 0, temporary_veriable;
	for(i = 0; i < size; i++){
		temporary_veriable = y[i] - (intercept_and_slopes[0] + ( intercept_and_slopes[1] * x[i] ));
		// printf("\t%d \t%d\t%f\t%f\n", x[i], y[i], (intercept_and_slopes[0] + ( intercept_and_slopes[1] * x[i] )), temporary_veriable);
		error += temporary_veriable * temporary_veriable;
	}
	return sqrt(error/size);
}
double* Intercept_Slop(int* x, int* y, int size){
	int i = 0;
	double mean_x = 0, mean_y = 0, cov = 0, Var = 0, temporary_veriable;
	double* intercept_and_slopes = (double*) malloc (2 * sizeof(double));
	for(i = 0; i < size; i++){
		mean_x += x[i];
		mean_y += y[i];
	}
	// printf("sum ->\t%.0f\t%.0f\n", mean_x, mean_y);
	mean_x /= size;
	mean_y /= size;
	// printf("\tx\ty\txi - x'\t\tyi - y' \n");
	for(i = 0; i < size; i++){
		temporary_veriable = x[i] - mean_x;
		cov += temporary_veriable * ( y[i] - mean_y );
		Var += temporary_veriable * temporary_veriable;;
		// printf("\t%d\t%d\t%f\t%f\n", x[i], y[i], temporary_veriable, ( y[i] - mean_y ));
	}
	// printf("mean\tx'\ty'\n\t%.2f\t%.2f\n", mean_x, mean_y);	
	intercept_and_slopes[1] = cov / Var;
	intercept_and_slopes[0] = mean_y - (intercept_and_slopes[1] * mean_x) ;
	return intercept_and_slopes;
}

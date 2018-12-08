#include <stdio.h>
#include <math.h>

//problem 1

int mult35(int lim) {
	int sum = 0;
	int c = 1;
	for (;c < lim; c++) {
		if (c%3 == 0 || c%5 == 0)
			sum+=c;
	}
	return sum;

}

//problem 2
int evenFib(int endNum) {
	int sum = 2;
	int n1 = 1;
	int n2 = 2;
	int n3;
	while (trunc) {
		n3 = n1 + n2;
		if (n3 > endNum) break;
		if (n3 % 2 == 0) sum += n3;
		n1 = n2;
		n2 = n3;
	}

	return sum;
}

//problem 6

double sumSq(double range) {
		double sum = 0;
		for (double i = 1; i <= range; i++)
			sum += pow(i, 2);  //will not compile without -lm
		return sum;
}

double sumOfNums(double range) {
		return ((range + 1) * (range / 2));
}

double sqSum(double range) {
		return pow(sumOfNums(range), 2);
}

double squareDiff(double range) {
	double sumOfSquares = sumSq(range);
	double squareOfSum = sqSum(range);
	return squareOfSum - sumOfSquares;
}

int main() {
	printf("The answer to problem 1 is %d \n", mult35(1000) );
	printf("The answer to problem 2 is %d \n", evenFib(4000000));
	printf("The answer to problem 6 is %f \n", squareDiff(100));
}


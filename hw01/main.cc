// First C++, calculator for 2 numbers
# include <cstdio>
# include "calc.h"
# include <math.h>

int main(int argc, char** argv)
{
	double x = 0;
	double y = 0;
	char op = 'w';

	// then get user input somehow??
	// how to get user input in C, scanf()
	// https://en.wikibooks.org/wiki/C_Programming/Simple_input_and_output
	printf("Input value of x:\n");
	scanf("%lf", &x);
	printf("Input value of y:\n");
	scanf("%lf", &y);
	printf("choose the type of calculation you want to perform,\n enter the letter +, -, *, /, or ^ for exponential.\n");
	scanf(" %c", &op);
	// how to input char
	// https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c

	// then using if/switch, evaluate the operator and call functions
	// accordingly
	
	// first case
	if (op == '+'){
		printf("anser is : %lf\n", sum(x, y));
	}
	if (op == '-'){
		printf("anser is : %lf\n", sum(x, -y));
	}
	if (op == '*'){
		printf("anser is : %lf\n", mul(x, y));
	}
	if (op == '^'){
		printf("anser is : %lf\n", pow(x, y));
	}
}

#include <stdio.h>

int main() {
	int number;
	unsigned factorial = 1;

	printf("Enter an integer: ");
	scanf("%d", &number);

	if (number < 0)
		printf("Number %d is negative", number);
	else
		for (; number > 0; number--)
			factorial = factorial * number;

	printf("Factorial is %u", factorial);

	return 0;
}

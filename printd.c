#include <stdio.h>

void main() {

int number;
scanf("%d", &number);

printd(number);
}

/* printd:  print n in decimal */
void printd(int n)
{
printf("Helo %d", n);

	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
}


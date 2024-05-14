#include <unistd.h>
#include <stdio.h>

int main()
{

int n = write(1,"Hello World\n", 12);
printf("Printing the Value of n = %d",n);
printf("\n n prints the length of Hello World and one endl char\n");

}


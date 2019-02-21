#include <stdio.h>
#include <cs50.h>

int main(void)
{
	// This code is made just to run in cs50 sandbox.
	// outside of the sandbox, the compiler cannot find cs50.h:
	string name = get_string("What is your name?\n");
	printf("hello, %s\n", name);
}



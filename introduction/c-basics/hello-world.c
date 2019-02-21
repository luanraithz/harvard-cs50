/* getting user input */
#include <stdio.h>

int main(void)
{
 	char result[20];
   	fgets(result, 20, stdin);
	printf("%s", result);
	
}

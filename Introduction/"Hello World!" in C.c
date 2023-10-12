#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	
    char s[100];
    scanf("%[^\n]%*c", &s);
    printf("Hello, World!\n");

    // Print the input string on the next line
    printf("%s\n", s);
  	
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

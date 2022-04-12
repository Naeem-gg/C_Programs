#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch,s[100],x[100];
    scanf("%c",&ch);
    printf("%c",ch);
    scanf("%s",s);
    printf("\n%s",s);
    scanf("%[^\n]%*c",x);
    printf("\n%s",x);
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
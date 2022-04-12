#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *file;
    int word,chars,line;
    char ch,myfile[50],strc,strw[20],wtrl[20];
    printf("\nMYSHELL$: ");
    scanf("%s",myfile);
    file=fopen(myfile,"r");
    if(file)
    {
        while((ch=getc(file))!=EOF)
        {
            chars++;
            if(ch=='\n' || ch=='\0')
            {
                line++;
            }
            if(ch=='\n' || ch=='\0' || ch=='\t' || ch==' ')
            {
                word++;
            }
        }
        if(chars>0)
        {
            chars++;
            word++;
            line++;
        }
        printf("\nMYSHELL$:\n");
        char mystr,strC;
        scanf("%s",mystr);
        strc="count c";
        strC="Count c";
        if((mystr==strc) || (mystr==strC))
        printf("\nchars=%d",chars);
        // printf("\nwords=%d",word);
        // printf("\nlines=%d\n",line);
    
    }
    else
    {
        printf("MYSHELL$: ERROR");
        exit(EXIT_FAILURE);
    }
    fclose(file);
    return 0;
}

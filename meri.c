#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE * file;
    char ch,filename[100];
    int words=0,lines=0,chars=0;
    printf("Myshell$ ");
    scanf("%s",filename);
    file=fopen(filename,"r");
    if(file==NULL)
    {
            printf("ERROR! entered file %s doesn't exists",filename);
            exit(EXIT_FAILURE);
    }
    else
    {
            while((ch=fgetc(file)) !=EOF)
            {
                chars++;
                if(ch=='\n' || ch=='\0')
                {
                    lines++;
                }    
                if(ch=='\n' || ch=='\0' || ch=='\t' || ch==' ')
                {
                    words++;
                }
            

            }
            if(chars>0)
            {
                chars++;
                words++;
                lines++;

            }
            printf("chars=%d\n",chars);
            printf("words=%d\n",words);
            printf("lines=%d\n",lines);

    }
    fclose(file);
    return 0;
}
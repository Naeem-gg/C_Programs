#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    int myid,niceid;
    myid=fork();
    for(;;)
    {

    if(myid==0)
    {
        niceid=nice(10);
        printf("\nparent process has higher CPU prio with ID=%d",niceid);
        sleep(1);
    }
    else
    {
        niceid=nice(-5);
        printf("\nchild process has higher CPU prio with ID=%d",niceid);
        sleep(1);
    }
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int wt[20],temp,pos,bt[20],at[20],p[20],tat[20],total,n,i,j;
    float avg_wt;
    printf("\n Ente num: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("bt[%d]",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<i;j++)
        {
            if(bt[j]<bt[pos])
            {
                pos=j;
            }
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
        wt[0]=0;
        for(i=1;i<n;i++)
        {
            wt[i]=0;
            for(j=0;j<i;j++)
            {
                wt[i]+=bt[j];
            }
            total+=wt[i];
        }


    return 0;
}
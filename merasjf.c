#include<stdio.h>
int main()
{
    int time,count=0,n,i,j,sm;
    int temp[20],at[20],bt[20];
    float avg_wt,avg_tat;
    double tat,wt,end;

    printf("enter no of pross");
    scanf("%d",&n);
    printf("enter %d pros",n);
    for(i=0;i<n;i++)
    {
        printf("\n%dat: ",i+1);
        scanf("%d",&at[i]);
        printf("%dbt: ",i+1);
        scanf("%d",&bt[i]);
        temp[i]=bt[i];
    }
    bt[9]=9999;
    for(time=0;count!=n;time++)
    {
        sm=9;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && bt[i]<bt[sm] && bt[i]>0)
            {
                sm=i;
            }
        }
        bt[sm]--;
        if(bt[sm]==0)
        {
            count++;
            end=time+1;
            wt=wt+end-at[sm]-temp[sm];
            tat=tat+end-at[sm];
        }
    }
    avg_tat=tat/n;
    avg_wt=wt/n;
    printf("\n avg_wt=%lf",avg_wt);
    printf("\n avg tat=%lf",avg_tat);
    return 0;
}
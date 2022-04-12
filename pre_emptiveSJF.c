#include <stdio.h>

int main() 
{
      int at[10], bt[10], temp[10];
      int i, s, count = 0, time, n;
      double wt = 0, tat = 0, end;
      float avg_wt, avg_tat;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &n); 
      printf("\nEnter Details of %d Processes\n", n);
      for(i = 0; i < n; i++)
      {
            printf("\nEnter Arrival Time:\t");
            scanf("%d",&at[i]);
            printf("Enter Burst Time:\t");
            scanf("%d",&bt[i]); 
            temp[i]=bt[i];
      }
      bt[9]=9999;  
      for(time=0;count!=n;time++)
      {
            s=9;
            for(i=0;i<n;i++)
            {
                  if(at[i]<=time && bt[i]<bt[s] && bt[i]>0)
                  {
                        s=i;
                  }
            }
            bt[s]--;
            if(bt[s]==0)
            {
                  count++;
                  end=time+1;
                  wt=wt+end-at[s]-temp[s];
                  tat=tat+end-at[s];
            }
      }
      avg_wt = wt / n; 
      avg_tat = tat / n;
      printf("\n\nAverage Waiting Time:\t%lf\n", avg_wt);
      printf("Average Turnaround Time:\t%lf\n", avg_tat);
      return 0;
}
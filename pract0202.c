#include <stdio.h>
struct node
{
    int pno, reftime;
} frames[20];
int n;
int page_found(int pno)
{
    int fno;
    for (fno = 0; fno < n; fno++)
        if (frames[fno].pno == pno)
            return fno;
    return (-1);
}
int get_free_frame()
{
    int fno;
    for (fno = 0; fno <= n; fno++)
        if (frames[fno].pno == -1)
            return (fno);
    return (-1);
}
int get_lru_frame()
{
    int lrufno = 0, fno;
    for (fno = 1; fno < n; fno++)
        if (frames[fno].reftime < frames[lrufno].reftime)
            lrufno = fno;
    return (lrufno);
}
int main()
{
    int p_request[] = {5, 8, 10, 14, 10, 9, 5, 1, 10, 9, 12, 10};
    int currtime = 0;
    int page_falts = 0, i, j, fno;
    printf("\n How many frames:");
    scanf("%d", &n);
    // initialize frames
    for (i = 0; i < n; i++)
    {
        frames[i].pno = -1;
        frames[i].reftime = -1;
    }
    printf("\n pageNo     pageFrames      pageFault");
    printf("\n---------------------------------\n");
    // currtime=0;//initialize time
    for (i = 0; i < 15; i++)
    {
        j = page_found(p_request[i]);
        if (j == -1) // page fault occurs
        {
            j = get_free_frame();
            if (j == -1) // no free frame - do replacement
                j = get_lru_frame();
            page_falts++;
            frames[j].pno = p_request[i];
            printf("%4d:", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d", frames[fno].pno);
            printf(":YES\n\n");
        }
        else
        {
            printf("%4d: ", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d", frames[fno].pno);
            printf(" :NO\n\n");
        }
        frames[j].reftime = currtime;
        currtime++;
    }
    printf("\n-------------------------------------");
    printf("\n Number of page_Falts=%d", page_falts);
}
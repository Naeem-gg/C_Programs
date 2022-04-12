#include <stdio.h>
struct node
{
    int pno;
} frames[20];
int n, rfno = -1;
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
    for (fno = 0; fno < n; fno++)
        if (frames[fno].pno == -1)
            return (fno);
    return (-1);
}
int get_fifo_frame()
{
    rfno = (rfno + 1) % n;
    return rfno;
}
int main()
{
    int p_request[] = {5, 8, 10, 14, 10, 9, 5, 10, 8, 5, 1, 10, 9, 12, 10};
    int size = 15;
    int page_faults = 0, i, j, fno;
    printf("\n How many frames:");
    scanf("%d", &n);
    // initialize frames
    for (i = 0; i < n; i++)
        frames[i].pno = -1;
    printf("\n PageNo    Page Frames   Page Fault");
    printf("\n-------------------------------------\n");
    for (i = 0; i < size; i++)
    {
        j = page_found(p_request[i]);
        if (j == -1) // page fault occurs
        {
            j = get_free_frame();
            if (j == -1) // no free frame-do replacement
                j = get_fifo_frame();
            page_faults++;
            frames[j].pno = p_request[i];
            printf("%4d:", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d", frames[fno].pno);
            printf(": YES\n\n");
        }
        else
        {
            printf("%4d", p_request[i]);
            for (fno = 0; fno < n; fno++)
                printf("%4d", frames[fno].pno);
            printf(":NO\n\n");
        }
    }
    printf("\n-----------------------------------------");
    printf("\n Number of page_faults=%d\n", page_faults);
}
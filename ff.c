#include<stdio.h>

struct process
{
    int ps;
    int flag;
} p[50];

struct sizes
{
    int size;
    int alloc;
} s[5];

int main ()
{
    int i=0, np=0, n=0, j=0;

    printf ("\nFirst Fit\n");
    printf ("Enter the number of blocks:\t");
    scanf ("%d", &n);
    
    printf ("\nEnter the size for %d blocks\n", n);
    for (i = 0; i < n; i++)
    {
        printf ("Enter the size for block %d:\t", i);
        scanf("%d", &s[i].size);
    }

    printf ("\nEnter the number of processes:\t");
    scanf ("%d", &np);
    
    printf ("\nEnter the size of %d processes:\n", np);
    for (i = 0; i < np; i++)
    {
        printf ("Enter the size of process %d:\t", i);
        scanf ("%d", &p[i].ps);
    }

    printf ("\nAllocation of blocks using First Fit:\n");
    printf ("\nProcess\t\tProcess Size\tBlocks\n");
    
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i].flag != 1)
            {
                if (p[i].ps <= s[j].size)
                {
                    if (!s[j].alloc)
                    {
                        p[i].flag = 1;
                        s[j].alloc = 1;
                        printf ("\n%d\t\t%d\t\t%d", i, p[i].ps, s[j].size);
                        break; // Exit the loop once allocation is done
                    }
                }
            }
        }

        if (p[i].flag != 1)
        {
            printf ("\nSorry! Process %d must wait as there is no sufficient memory\n", i);
        }
    }

    return 0;
}


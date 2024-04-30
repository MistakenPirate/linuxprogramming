#include <stdio.h>
#include <stdbool.h>
// using namespace std;
#define n 5
#define r 3
int main()
{
    // int n = 5;
    // int r = 3;

    int alloc[n][r] = {{0, 0, 1}, {3, 0, 0}, {1, 0, 1}, {2, 3, 2}, {0, 0, 3}}; // Allocation Matrix
    int max[n][r] = {{7, 6, 3}, {3, 2, 2}, {8, 0, 2}, {2, 1, 2}, {5, 2, 3}};   // Max Matrix

    // int avail[r] = {2, 3, 2};
    int avail[r] = {1, 1, 0};

    int need[n][r];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int f[n], ans[n], ind = 0;

    for (int k = 0; k < n; k++)
    {
        f[k] = 0;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < r; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (int y = 0; y < r; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    bool deadlock = false;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
            deadlock = true;
    }

    if (deadlock)
    {
        printf("Deadlock\n");
    }
    else
    {
        printf("Safe Sequence is:\n");
        for (int i = 0; i < n; i++)
        {
            int x = ans[i];
            printf("P%d -> ",x);
        }
        printf("\n");
    }

    return 0;
}
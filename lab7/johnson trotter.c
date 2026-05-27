#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void printPermutation(int perm[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", perm[i]);

    printf("\n");
}

int getMobile(int perm[], int dir[], int n)
{
    int mobile = 0, mobileIndex = -1;
    int i;

    for(i = 0; i < n; i++)
    {
        if(dir[i] == LEFT && i != 0 &&
           perm[i] > perm[i - 1] &&
           perm[i] > mobile)
        {
            mobile = perm[i];
            mobileIndex = i;
        }

        if(dir[i] == RIGHT && i != n - 1 &&
           perm[i] > perm[i + 1] &&
           perm[i] > mobile)
        {
            mobile = perm[i];
            mobileIndex = i;
        }
    }

    return mobileIndex;
}

int main()
{
    int n, i;

    printf("Enter value of n: ");
    scanf("%d", &n);

    int perm[n], dir[n];

    for(i = 0; i < n; i++)
    {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    while(1)
    {
        int mobileIndex = getMobile(perm, dir, n);

        if(mobileIndex == -1)
            break;

        int swapIndex;

        if(dir[mobileIndex] == LEFT)
            swapIndex = mobileIndex - 1;
        else
            swapIndex = mobileIndex + 1;

        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        mobileIndex = swapIndex;

        for(i = 0; i < n; i++)
        {
            if(perm[i] > perm[mobileIndex])
                dir[i] = -dir[i];
        }

        printPermutation(perm, n);
    }

    return 0;
}

#include <stdio.h>

int clip(int val, int min, int max)
{
    if(val < max)
    {
        if(val > min)
        {
            return val;
        }
        else
        {
            return min;
        }
    }
    else
    {
        return max;
    }
}

int main()
{
    printf("%d\n", clip(30, 40, 50));
    printf("%d\n", clip(45, 40, 50));
    printf("%d\n", clip(55, 40, 50));
    printf("%d\n", clip(12, -15, 1));
    printf("%d\n", clip(-9, -15, 1));
    printf("%d\n", clip(-20, -15, 1));
    return 0;
}
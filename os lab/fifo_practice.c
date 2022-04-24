#include <stdio.h>
int main()
{
    int rstring[10], pages, frames, pagefault=0;
    printf("Please Enter the total number of pages: ");
    scanf("%d", &pages);
    printf("\nPlease enter the reference string: ");
    for(int n=0; n<pages; n++)
    {
        printf("Enter value %d: ", n+1);
        scanf("%d", &rstring[n]);
        printf("\n");
    }
    printf("\nPlease enter the number of frames: ");
    scanf("%d", &frames);

    int temp[frames];
    for(int n=0; n<frames; n++)
    {
        temp[n] = -1;
    }

    for(int n=0; n<pages; n++)
    {
        int s=0;
        for(int m=0; m<frames; m++)
        {
            if(temp[m] == rstring[n])
            {
                s++;
                pagefault--;
            }
        }
        pagefault++;
        if(pagefault <= frames && (s==0))
        {
            temp[n] = rstring[n];
        }
        else if(s==0)
        {
            temp[(pagefault - 1) % frames] = rstring[n];
        }
        printf("\n");
        for(int m = 0; m<frames; m++)
        {
            printf("%d\t", temp[m]);
        }
        
    }
    printf("\nThe total number of page faults is: %d\n", pagefault);
    
    return 0;
}
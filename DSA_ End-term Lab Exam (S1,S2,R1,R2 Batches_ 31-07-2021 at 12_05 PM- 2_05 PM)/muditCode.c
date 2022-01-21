#include <stdio.h>

int main() {
    
    int N, K;
    printf("Enter number of elements in the array: ");
    scanf("%d", &N);
    printf("Enter number of right rotations: ");
    scanf("%d", &K);
    
    K%=N;
    printf("%d %d", N, K);
    
    
    return 0;
}
#include <stdio.h>

int main() {
    
    int N, K;
    printf("Enter number of elements in the array: ");
    scanf("%d", &N);
    printf("Enter number of right rotations: ");
    scanf("%d", &K);
    
    int arr[N];
    printf("Enter the values in the array: ");
    for(int i=0; i<N; i++){
        scanf("%d ", &arr[i]);
    }
    
    for(int i=N-K; i<N; i++){
        printf("%d ", i);
    }
    for(int i=0; i<N-K; i++){
        printf("%d ", i);
    }
    
    return 0;
}
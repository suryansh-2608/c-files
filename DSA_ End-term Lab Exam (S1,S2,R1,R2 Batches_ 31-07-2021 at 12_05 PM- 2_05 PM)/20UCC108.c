//Suryansh Bhardwaj
//20UCC108
//S2
//30-07-2021

#include <stdio.h>

int inarr[7];
int outarr[7];
int V, E;

void createAdjMatrix(int Adjmat[][V + 1],int arr[][2])
{
    for (int i = 0; i < V + 1; i++) {
  
        for (int j = 0; j < V + 1; j++) {
            Adjmat[i][j] = 0;
        }
    }
    for (int i = 0; i < E; i++) {
        int x = arr[i][0];
        int y = arr[i][1];
        Adjmat[x][y] = 1;
    }
}

void printAdjMatrix(int Adj[][V + 1])
{
  
    for (int i = 1; i < V + 1; i++) {
        for (int j = 1; j < V + 1; j++) {
            printf("%d ", Adj[i][j]);
        }
        printf("\n");
    }
}

int outdegree(int Adjmat[][7],int V)
{
    for (int i = 1; i < V + 1; i++){
        int outd = 0 ;
        for (int j = 1; j < V + 1; j++){
            if(Adjmat[i][j]){
                outd++;
            }
        }
        outarr[i]=outd;
        printf("Out Degree of Vertex %d = %d \n",i,outd);
    }
    printf("\n");
    return 0;
}

int indegree(int Adjmat[][7],int V)
{
    for (int j = 1; j < V + 1; j++){
        int ind = 0 ;
        for (int i = 1; i < V + 1; i++){
            if(Adjmat[i][j]){
                ind++;
            }
        }
        inarr[j]=ind;
        printf("In Degree of Vertex %d = %d \n",j,ind);
    }
    printf("\n");
    return 0;
}

void Is_Connected(int N ){
    for(int index=1 ; index<N+1 ; index++){
        if(inarr[index]==0 && outarr[index]==0){
            printf("Graph is isolated at vertex : (%d) hence disconnected graph due to break \n" ,index);
        }
        else if(outarr[index] == 0 ){
            printf("Graph is disconnected at  vertex : (%d) as it can not access anyother point \n",index);
        }
        else {
            printf("Graph is connected at vertex : (%d) \n",index) ;
        }
    }
}

int display_indegree(int a)
{
    printf("In Degree of Vertex %d = %d \n",a,inarr[a]);
    return 0;
}

int main()
{
    int v;
    int inarr[V+1] , outarr[V+1] ;
    inarr[0]=-1 ; outarr[0]=-1 ;
    V=6;
    int arr[][2] = { { 1, 2 }, {1,3}, { 2, 3 }, {2,4}, {2,5}, {3,4}, {3,6}, { 4, 5 }, {4,6}, { 5,6 } };
    E = sizeof(arr) / sizeof(arr[0]);
    int Adjmat[V + 1][V + 1];
    createAdjMatrix(Adjmat, arr);
    printf("\n Ajacency matrix is: \n\n");
    printAdjMatrix(Adjmat);
    printf("\n Indegreee is: \n\n");
    indegree(Adjmat, V);
    printf("\n Outdegree is: \n\n");
    outdegree(Adjmat, V);
    printf("\n Verifying whether graph is connected or not: \n\n");
    Is_Connected(V);
    printf("\n");
    printf("\n Please enter the vertex to find it's indegree: ");
    scanf(" %d", &v);
    printf("\n");
    display_indegree(v);
    printf("\n");
    return 0;
}

//gcc 20UCC108.c -o 20UCC108
//./20UCC108
#include<stdio.h>

void prin_array(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d  ",A[i]);
    }
    printf("\n");
}

int main () {
    int A[] = {101,23,57,13,25,121,87,36,13,204,111,89,59 };
    int n= sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(A[j]<A[j-1]){
                int temp= A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
            }
        }
        prin_array(A,n);
    }
}
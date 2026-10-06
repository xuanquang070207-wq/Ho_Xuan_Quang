#include<stdio.h>

void prin_array(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d  ",A[i]);
    }
    printf("\n");
}
int main() {
    int A[] = {101,23,57,13,25,121,87,36,13,204,111,89,59 };
    int n= sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n-1;i++){
        int min=A[i],k=0;
        int temp=A[i];
        for(int j=i+1;j<n;j++){
            if(A[j]<=min){
                min=A[j];
                k=j;
            }
        }
        if(min != A[i]){
            A[i]=A[k];
            A[k]=temp;
            prin_array(A,n);
        }
    }
}
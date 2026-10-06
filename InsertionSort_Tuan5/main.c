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
    for (int i=1;i<n;i++){
        int value= A[i],k=0;
        for(int j=i;j>0;j--){
            if(A[j-1]> value) {
                A[j]=A[j-1];
                A[j-1]=value;
            }
        }
        prin_array(A,n);
    }
}
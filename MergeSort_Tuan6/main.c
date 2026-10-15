#include<stdio.h>

void prin_array(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d  ",A[i]);
    }
    printf("\n");
}
void merge(int A[],int m,int n, int p){
        int i= m, j=n+1;
        while(i<j && j<=p) {
            if(A[i]<=A[j]){
                i++;
            } else {
                int x= A[j];
                for (int k=j-1;k>=i;k--){
                    A[k+1]=A[k];
                }
                A[i]=x;
                i++;j++;
            }
        }
    }
void merge_sort(int A[],int first,int last,int n){
    if(last>first) {
        int m=(last+first)/2;
        merge_sort(A,first,m,n);
        merge_sort(A,m+1,last,n);
        merge(A,first,m,last);
        prin_array(A,n);
    }
}

int main () {
    int A[] = {101,23,57,13,25,121,87,36,13,204,111,89,59 };
    int n= sizeof(A)/sizeof(A[0]);
    prin_array(A,n);
    merge_sort(A,0,n-1,n);
}
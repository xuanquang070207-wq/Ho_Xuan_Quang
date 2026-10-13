#include<stdio.h>

void prin_array(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d  ",A[i]);
    }
    printf("\n");
}
void swap(int *a,int *b){
    int temp=*a;
    *a = *b;
    *b = temp;
}
void quick_sort(int A[],int first,int last,int n) {
    if(last>first){
        int* p=A;
        int value=A[first];
        int i=first+1;
        int j=last;
        while (j>=i) {
            if(A[i]> value && A[j]<value){
                swap(&p[i],&p[j]);
            }
            if(A[i]<=value ) {
                i++;
            } 
            if(A[j]>=value) {
                j--;
            } 
        }
        swap(&p[first],&p[j]);
        prin_array(A,n);
        quick_sort(A,first,j-1,n);
        quick_sort(A,j+1,last,n);
    }
}

int main () {
    int A[] = {101,23,57,13,25,121,87,36,13,204,111,89,59 };
    int n= sizeof(A)/sizeof(A[0]);
    quick_sort(A,0,n-1,n);
}
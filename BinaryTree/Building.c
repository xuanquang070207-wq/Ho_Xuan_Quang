#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* lp;
    struct node* rp;
} node;

node* createNode(int value) {
    node* newnode= (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->lp= NULL;
    newnode->rp=NULL;
    return newnode;
}
node* insert(int A[],int n, int index){
    while(index<n){
    node* newnode= (node*)malloc(sizeof(node));
    newnode->data = A[index];
    newnode->lp= insert(A,n,2*index+1);
    newnode->rp= insert(A,n,2*index+2);
    return newnode;
    }
    return NULL;
}
//duyen cac phan tu trong cay
// truoc
void hienthi1(node* bt) {
    if(bt == NULL) return;
    printf("%d ",bt->data);
    hienthi1(bt->lp);
    hienthi1(bt->rp);
}
//giua
void hienthi2(node* bt) {
    if(bt == NULL) return;
    hienthi2(bt->lp);
    printf("%d ",bt->data);
    hienthi2(bt->rp);
}
// sau
void hienthi3(node* bt) {
    if(bt == NULL) return;
    hienthi3(bt->lp);
    hienthi3(bt->rp);
    printf("%d ",bt->data);
}
int main() {
    int A[] = {0,1,2,3,4,5,6};
    int n= sizeof(A)/sizeof(A[0]);
    node* bt= insert(A,n,0);
    hienthi1(bt);
    printf("\n");
    hienthi2(bt);
    printf("\n");
    hienthi3(bt);
}
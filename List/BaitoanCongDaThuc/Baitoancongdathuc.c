//Cong 2 da thuc A(x) va B(x) va in ra ket qua
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    float hs;
    int somu;
    struct node* next;
} node;

typedef struct list {
    node* firstnode;
} list;

void InitList(list* list) {
    list->firstnode= NULL;
}
//Them vao cuoi list
void insertEnd(node** head, float val1, int val2) {
    node* newnode=(node*)malloc(sizeof(node));
    newnode->hs = val1;
    newnode->somu=val2;
    newnode->next= NULL;
    if(*head==NULL) *head= newnode;
    else {
        node* ptr= *head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next= newnode;
    }

}

void insertDT(node** head,int n) {
    for(int i=0;i<n+1;i++) {
        float val_hs;
        printf("Nhap he so cho x^%d: ",i);
        scanf("%f",&val_hs);
        insertEnd(head,val_hs,i);
    }
}
void hienthiDT(node* head) {
    if(head == NULL) return;
    while(head->next != NULL){
        printf("%f.x^%d +",head->hs,head->somu);
        head=head->next;
    }
     printf("%f.x^%d\n",head->hs,head->somu);
}
node* cong2DT(node** head1,int bacDt1, node** head2, int bacDt2) {
    if(head1==NULL && head2 == NULL) return NULL;
    if(head1==NULL && head2!=NULL) return *head2;
    if(head1!=NULL && head2==NULL) return *head1;
    node** head3 = (node**)malloc(sizeof(node*));
    *head3=NULL;
    if(bacDt1 > bacDt2) {
        int i=0;
        node* ptr1 = *head1;
        node* ptr2 = *head2;
        while(i<=bacDt2) {
            insertEnd(head3,ptr1->hs + ptr2->hs,i);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            i++;
        }
        while(i<=bacDt1){
            insertEnd(head3,ptr1->hs,i);
            i++;
            ptr1=ptr1->next;
        }
        return *head3;
    }
    if(bacDt1 < bacDt2) {
        int i=0;
        node* ptr1 = *head1;
        node* ptr2 = *head2;
        while(i<=bacDt1) {
            insertEnd(head3,ptr1->hs + ptr2->hs,i);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            i++;
        }
        while(i<=bacDt2){
            insertEnd(head3,ptr2->hs,i);
            i++;
            ptr2=ptr2->next;
        }
        return *head3;
    }
    if(bacDt1 == bacDt2){
        int i=0;
        node* ptr1 = *head1;
        node* ptr2 = *head2;
        while(i<=bacDt1) {
            insertEnd(head3,ptr1->hs + ptr2->hs,i);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            i++;
        }
        return *head3;
    }
}
int main () {
    int bacDt1,bacDt2;
    list* DtA=(list*)malloc(sizeof(list));
    list* DtB=(list*)malloc(sizeof(list));
    list* DtC=(list*)malloc(sizeof(list));
    InitList(DtA);
    InitList(DtB);
    InitList(DtC);
    node* head1= DtA->firstnode;
    node* head2= DtB->firstnode;
    node* head3= DtC->firstnode;
    printf("Nhap bac cua 2 da thuc A va B(cach nhau bang dau cach): \n");
    scanf("%d %d", &bacDt1,&bacDt2);
    printf("Da thuc A\n");
    insertDT(&head1,bacDt1);
    printf("Da thuc B\n");
    insertDT(&head2,bacDt2);
    head3= cong2DT(&head1,bacDt1,&head2,bacDt2);
    hienthiDT(head3);
}
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
//
typedef struct {
    Node* firstNode;
} list;
void Init_list1 (list* list){
    list->firstNode=NULL;
}
//Tao 1 node moi

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
//Duyet cac phan tu trong list 
void hienthi(Node** head){
    Node* ptr= *head;
    if(ptr == NULL ) return;
    while(ptr->next != NULL) {
        printf("%d ",ptr->data);
        ptr= ptr->next;
    }
    printf("%d\n",ptr->data);
}
//Tim kiem phan tu
Node* search(Node* head, int value){
    if(head==NULL)return NULL;
    while(head != NULL) {
        if(head->data==value) return head;
        head=head->next;
    }
    return NULL;
}
// Bo sung 1 node moi vao dau danh sach
void insertBegin1(Node** head, int value) {
    Node* newnode = createNode(value);
    newnode->next=*head;
    *head= newnode;
}

//Bo sung 1 node moi vao duoi danh sach
void insertEnd(Node** head, int value) {
    Node* newnode= createNode(value);
    if(head == NULL) {
        *head=newnode;
    } else {
        Node* ptr = *head;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}
// Bo sung 1 phan tu vao sau 1 ptu dc tro boi p
void insertAfter(Node** p, int value){
    if(*p == NULL){
        return;
    } else {
    Node* newnode= createNode(value);
    newnode->next=(*p)->next;
    (*p)->next=newnode;
    }
}
//Bo sung 1 phan tu vao truoc 1 ptu dc tro boi p c1
void insertBefore1(Node** head,Node* p,int value) {
    if(p==NULL) return;
    Node* newnode= createNode(value);
    Node* ptr= *head;
    if(p== *head) {
        newnode-> next= p ;
        *head = newnode;
        return;
    } 
    while (ptr->next != p){
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
}
//Bo sung 1 phan tu vao truoc 1 ptu dc tro boi p c2 
void insertBefore2(Node** head,Node* p,int value) {
    if(p==NULL) return;
   Node* newnode= (Node*)malloc(sizeof(Node));
   newnode->data= p->data;
   newnode->next= p->next;
   p->data=value;
   p->next= newnode;
}

// Xoa phan tu dau tien
void deleteBegin (Node** head) {
    if(*head== NULL) return;
    Node* ptr= *head;
    *head= (*head)->next;
    free(ptr);
}

void deleteEnd(Node** head) {
    if(*head == NULL) return;
    Node* ptr= *head;
    if(ptr->next==NULL) {
        free(ptr);
        *head = NULL;
        return;
    }
    while(ptr->next->next !=NULL){
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
}
//Ghep noi 2 danh sach
void ghepnoi(Node** head1, Node** head2, Node*p){
    if(*head1==NULL || *head2==NULL || p ==NULL) return;
    Node* ptr1 = p->next;
    Node* ptr2 = *head2;
    p->next= *head2;
    while(ptr2->next != NULL){
        ptr2= ptr2->next;
    }
    ptr2->next = ptr1;
}

int main () {
    list* mylist1=(list*)malloc(sizeof(list));
    Init_list1(mylist1);
    Node* head1= mylist1->firstNode;
    insertBegin1(&head1,1);
    insertBegin1(&head1,2);
    insertBegin1(&head1,3);
    insertBegin1(&head1,4);
    insertBegin1(&head1,5);
    insertEnd(&head1,0);
    Node* p= search(head1,3);
    insertAfter(&p,7);
    insertBefore1(&head1,p,8);
    deleteBegin(&head1);
    deleteEnd(&head1);
    hienthi(&head1);
    list* mylist2=(list*)malloc(sizeof(list));
    Init_list1(mylist2);
    Node* head2= mylist2->firstNode;
    insertBegin1(&head2,11);
    insertBegin1(&head2,12);
    insertBegin1(&head2,13);
    insertBegin1(&head2,14);
    ghepnoi(&head1,&head2,p);
    hienthi(&head1);
}

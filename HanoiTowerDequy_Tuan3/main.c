// Bai toan thap ha noi bang phuong phap de quy
// Di chuyen n dia tu A sang B voi C la trung gian
#include<stdio.h>

void Hanoi(int n,char A,char B,char C){
    if(n==1) {
        printf("Dich chuyen dia %d tu %c sang %c\n",n,A,B);
    } else {
        Hanoi(n-1,A,C,B);
        printf("Dich chuyen dia %d tu %c sang %c\n",n,A,B);
        Hanoi(n-1,C,B,A);
    }
}
int main() {
    int n=3;
    char A='A',B='B',C='C';
    Hanoi(n,A,B,C);
}
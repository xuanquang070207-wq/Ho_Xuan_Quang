//Bai toan thap Ha Noi khi khong dung de quy
// index 0 ung voi dia thu n, index n-1 ung voi dia 1
#include<stdio.h> 
bool allowed( int i,int n, int A[]){
    for(int j=i+1;j<n;j++){
        if(A[j]==1) {
            return 0; //da ton tai 1 dia be hon dat truoc
        }
    }
    return 1;
}
bool must(int A[],int B[],int n){
    int a,b;
    for(int i=n-1;i>=0;i--){
        if(A[i]==1){
           a=n-i;
           break;
        }
    }
    for(int i=n-1;i>=0;i--) {
        if(B[i]==1){
            b=n-i;
            break;
        }
    }
    if(a>b) {return 1;} else {return 0;} // Nen di chuyen dia tu cot B
}

int so_buoc(int n) {
    int a=1;
    for(int i=0;i<n;i++){
        a*=2;
    }
    return a-1;
}

int chi_so(int A[],int n){
    for(int i=n-1;i<=0;i--) {
        if(A[i]==1) {
            return n-i;
        }
    }
}

bool sang(int B[],int A[],int C[]){

}

void hanoi(int A[],int B[],int C[], int n){ // A: cot dau, B:dich, C: trung gian
    char a='A',b='B',c='C';
    int N=so_buoc(n);
    if(n%2==0){
        A[n-1]=0;
        C[n-1]=1;
        printf("Dich chuyen dia 1 tu A sang C\n");
        int i=2;
        for(int j=2;j<=N;j++){
            if(allowed(i,n,B)&&A[0]==1) { // Neu co the chuyen sang cot B
                printf("Dich chuyen dia %d tu %c sang %c",i,a,b);
                A[i]=0;
                B[i]=1;
                i+=1;
            } 
            else {
                if(allowed(i,n,C)&&A[0]==1) { // Neu co the chuyen sang cot C
                    printf("Dich chuyen dia %d tu %c sang %c",i,a,c);
                    A[i]=0;
                    C[i]=1;
                    i+=1;
                } 
                else {
                    if(must(B,C,n)){
                        printf("Dich duyen dia %d tu %c sang %c",chi_so(C,n)) ;
                        
                    }
                }
            }
        }
    }
}
int main () {
    int n=3;
    int A[n],B[n],C[n];
    for(int i=0;i<n;i++) {
        A[i]=1;
        B[i]=0;
        C[i]=0;
    }
}
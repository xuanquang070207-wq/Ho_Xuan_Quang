# Introduction

Giải bài toán tháp Hà Nội nhưng không dùng phương pháp đệ quy

## Cấu trúc dữ liệu

* Xem các cột A,B,C là các mảng n phần tử chứa các số 0 và 1, index 0 sẽ là đĩa thứ n và index n-1 sẽ là đĩa thứ 1
* Số 0 sẽ đại diễn cho việc không có đĩa và số 1 sẽ là có đĩa

## Thuật toán 

* Vì không dùng đệ quy nên nghĩ đến việc xây dựng các hàm sau:
    * allowed: để kiểm tra liệu có thể chuyển đĩa từ cột này sang cột khác hay không bằng cách kiểm tra ngược xem đĩa mình cần chuyển có lớn hơn đĩa cao nhất ở cột kia hay không
    ```c
        bool allowed( int i,int n, int A[]){
            for(int j=i+1;j<n;j++){
                if(A[j]==1) {
                    return 0; //da ton tai 1 dia be hon dat truoc
                }
            }
            return 1;
        }
    ```
    * must: hàm được dùng khi không thể di chuyển đĩa từ cột A sang 2 cột còn lại thì sẽ kiểm tra xem ở cột B và C nên di chuyển đĩa từ cột nào.
    ```c
        bool must(int A[],int B[],int n){
            int a,b;
            for(int i=n-1;i>=0;i--){ // Kiểm tra đĩa nào ở đỉnh cột A
                if(A[i]==1){
                a=n-i; // đĩa thu i
                break;
                }
            }
            for(int i=n-1;i>=0;i--) { // Kiểm tra đĩa nào ở đỉnh cột B
                if(B[i]==1){
                b=n-i; 
                break;
            }
            }
            if(a>b) {return 1;} else {return 0;}
            // Nếu a>b thì đĩa ở cột A lớn hơn đĩa ở cột B -> nên chuyển đĩa ở cột B đi sang 2 cột còn lại
        }

    ```
    * so_buoc: Để tính số bước phải sử dụng
    * chi_so: Để tính đĩa trên cùng của 1 cột
    ```c
        int chi_so(int A[],int n){
            for(int i=n-1;i<=0;i--) {
                if(A[i]==1) {
                    return n-i;
                }
            }
        }
    ```
    * sang : Để xác định khi cần di chuyển đĩa từ cột trung gian hoặc cột đích, thì đĩa nên sang cột nào
* Với trường hợp di chuyển đĩa 1 thì có thể chuyển sang B hoặc C; nhưng nhận thấy có 2 trường hợp:
    * Nếu n chẵn: thì nên di chuyển đĩa 1 sang cột C
    * Nếu n lẻ : thì nên di chuyển đĩa 1 sang cột B
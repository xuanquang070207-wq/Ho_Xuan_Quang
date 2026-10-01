# Introduction
Giải bài toán Tháp Hà Nội bằng phương pháp đệ quy

## Các bước thực hiện

Xác định các input: Gồm có số đĩa n, các cột A,B,C tương ứng là cột đầu, cột đích và cột trung gian
Yêu cầu mỗi lần chỉ di chuyển 1 đĩa và đĩa to không thể đặt lên đĩa nhỏ hơn.

B1: Xây dựng bài toán cơ sở khi n=1
     '''if(n==1) {
        printf("Dich chuyen dia %d tu %c sang %c\n",n,A,B); }'''

B2: Xây dựng bài toán đệ quy 
    *B2.1: Để chuyển n đĩa từ cột A sang cột B, ta sẽ chuyển trước n-1 đĩa từ A sang C
        *gọi lại hàm với input: n-1,A,C,B
    *B2.2: Di chuyen dia thu n tu A sang B
        *printf("Dich chuyen dia %d tu %c sang %c\n",n,A,B);
    *B2.3: Di chuyển n-1 đĩa còn lại từ C sang B
        *gọi lại hàm với input: n-1,C,B,A

### Test case :

*Với n=3:
*Các bước di chuyển đĩa:
'''Đĩa 1 từ A sang B
Đĩa 2 từ A sang C
Đĩa 1 từ B sang C 
Đĩa 3 từ A sang B
Đĩa 1 từ C sang A
Đĩa 2 từ C sang B
Đĩa 1 từ A sang B'''

Output khi chạy giải thuật:
'''Dich chuyen dia 1 tu A sang B
Dich chuyen dia 2 tu A sang C
Dich chuyen dia 1 tu B sang C
Dich chuyen dia 3 tu A sang B
Dich chuyen dia 1 tu C sang A
Dich chuyen dia 2 tu C sang B
Dich chuyen dia 1 tu A sang B'''

 
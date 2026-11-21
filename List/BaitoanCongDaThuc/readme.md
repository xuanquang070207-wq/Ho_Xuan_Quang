## Bài toán cộng 2 đa thức A(x) và B(x)

Ta sẽ xây dựng 1 đa thức kết quả C(x) = A(x) + B(x)

Trước hết là cân xây dựng 1 kiểu dữ liệu để thể hiện đa thức, vì sẽ sử dụng danh sách liên kết nên node sẽ gồm 3 phần tử: hệ số, số mũ và liên kết đến node tiếp theo.

Cần 1 hàm để nhận các đa thức từ bàn phím (bậc của đa thức, các hệ số)

Cần 1 hàm để in các đa thức ra màn hình(theo thứ tự từ bậc cao nhất)

1 hàm để cộng 2 đa thức, vì A(x) có thể có bậc lớn hơn B(x) nên cần kiểm tra xem điều kiện bậc cái nào cao hơn:
* Nếu A(x) > B(x) sẽ thực hiện cộng từ bậc 0 đến bậc của B(x), sau đó phần còn lại sẽ lấy trực tiếp từ A(x).


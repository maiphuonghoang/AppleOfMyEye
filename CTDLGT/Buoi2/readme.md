### Mảng đánh dấu
Chỉ dùng mảng đánh dấu khi dữ liệu không âm và <= 10^7
Áp dụng cho: Đánh dấu sự xuất hiện, đếm giá trị khác nhau, đếm tần xuất xuất hiện 
### Mảng cộng dồn 
Cho mảng số nguyên A gồm N phần tử, có Q truy vấn, mỗi truy vấn là 2 số L, R 
Hãy tính tổng các số từ chỉ số L tới R của mảng \
A:      3 8 2 1 4 6 3\
pre[i]  3 11 13\
pre[0] = a[0]\
pre[i] = pre[i-1]+a[i]\
sum(l,r) =  pre[r] - pre[l-1]\

### Mảng hiệu 
Cho mảng số nguyên A gồm N phần tử, có Q truy vấn, mỗi truy vấn sẽ tăng các phần tử trong đoạn từ chỉ số L tới R của mảng A lên K đơn vị.
Hãy xác định mảng A[] sau Q thao tác \
d[0] = a[0]\
d[i] = a[i] - a[i-1]\

A : 3  8  2 4 9  5  1 \
D : 3 -5 -6 2 5 -4 -4 \
Mảng cộng dồn của mảng hiệu là mảng A ban đầu\
P : 3  8  2 4 9  5  1\

Cập nhật mảng D
d[l] += k;
d[r+1] -= k;

### Comparision function
- Trả về true nếu muốn a đứng trước b sau khi sắp xếp
- Trả về false nếu muốn a đứng sau b sau khi sắp xếp
- stable trong sắp xếp: bảo toàn thứ tự tương đối giữa các phần tử 

   
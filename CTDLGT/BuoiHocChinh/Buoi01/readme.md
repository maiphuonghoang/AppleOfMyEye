### Mảng đánh dấu
- Chỉ dùng mảng đánh dấu khi dữ liệu không âm và <= 10^7
- Áp dụng cho: Đánh dấu sự xuất hiện, đếm giá trị khác nhau, đếm tần xuất xuất hiện 
- Bản chất của mảng đánh dấu là mượn chỉ số để lưu giá trị 
    d[a[i]] = ... (chỉ số i của d lưu giá trị a[i])
- Lưu được từ 0 đến 1e7 
### Fibonaci 
- F(n) = F(n-1) + F(n-2)
- 93 là số fibonaci cuối cùng còn lưu được trong long long
    0 1 1 2 3 5 8 ... 

### Đồng dư 
- (a + b) % c = [(a % c) + (b % c)] % c
- (a - b) % c = [(a % c) - (b % c) + c] % c         <do c%c=0>
- (a x b) % c = [(a % c) x (b % c) + c] % c
### Khởi tạo cấu hình đầu tiên 
### while(Khi chưa phải cấu hình cuối cùng){ 
###    In ra cấu hình hiện tại 
###    Sinh ra cấu hình tiếp theo 
### }

- Sinh xâu nhị phân có độ dài n
    + Tìm bit đầu tiên = 0
    + Cấu hình đầu:  000
    + Cấu hình cuối: 111
- Sinh tập con k phần tử của tập n phần tử (Tổ hợp)
    + n = 5, k = 3
    + Tìm bit đầu tiên chưa bằng max n-i+k
    + Cấu hình đầu:  1 2 3
    + Cấu hình cuối: 3 4 5
- Sinh hoán vị của n phần tử
    + Tìm vị trí ptu đứng trước nhỏ hơn ptu đứng sau, rồi tìm số nhỏ nhất lớn hơn ptu đó để hoán đổi 
    + Cấu hình đầu:  1 2 3 4 5 
    + Cấu hình cuối: 5 4 3 2 1
    + next_permutation: hàm có sẵn sinh ra hoán vị kế tiếp từ cấu hình hiện tại (nếu là cấu hình cuối cùng thì trả về false )
- Sinh phân hoạch nguyên của số tự nhiên n ( Cách phân tích n dưới dạng tổng các số tự nhiên không vượt quá n)    
    + Tìm thằng đầu tiên chưa bằng 1 rồi giảm nó đi 1 đơn vị, tính phần bù để có tổng là n, thông qua số lượng còn thiếu biểu diễn theo số đã giảm  
    + Cấu hình đầu:  n
    + Cấu hình cuối: n số 1

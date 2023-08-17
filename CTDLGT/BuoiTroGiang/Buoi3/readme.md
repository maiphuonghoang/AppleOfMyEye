## Mảng 1 chiều trung bình 
1. Đổi tiền tham lam 
Tại ngân hàng có các mệnh giá 1,2,5,10,20,50,100,200,500,1000 số lượng tờ tiền mỗi mệnh giá là không hạn chế. Một người cần đổi số tiền bằng N. Hãy xác định xem số tờ tiền ít nhất sau khi đổi. 
- Chỉ có mệnh giá thật: 2 lần số bé không vượt quá số lớn 
- TH đặc biệt:
mệnh giá: 1 18 32 \
36 = 1*32 + 4*1 = 5 tờ \ 
36 = 2*18 = 2 tờ 
2. Liệt kê và đếm
Cho 1 dãy các số nguyên dương <= 9 chữ số, mỗi số cách nhau vài khoảng trống, có thể xuống dòng. Hãy tìm các số không giảm (các chữ số theo thứ tự từ trái qua phải tạo thành dãy không giảm) và đếm số lần xuất hiện của các số đó. 
- 9 chữ số thì phải dùng map, k dùng được mảng đánh dấu 
- map có key tăng dần và k sort được, mượn kết quả của map ném vào vector để sort 
3. BRT 
Thành phố X có n thị trấn trên trục đường chính. Tọa độ của các thị trấn lần lượt là a[1],a[2],...a[n], các tọa độ này là phân biệt, k có 2 tọa độ nào trùng nhau. Chính quyền thành phố muốn xây dựng 1 tuyến buýt nhanh BRT để kết nối 2 thị trấn gần nhau nhất với nhau. Tính chiều dàu của tuyến bus? Và có bao nhiêu cặp thị trấn có tiềm năng giống nhau để xây dựng tuyến BRT này 




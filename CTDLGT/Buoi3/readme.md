
### 1.Pha trà sữa 
Tèo kiếm được một công việc tại hàng trà sữa, có không quá 200,000 cốc trà sữa xếp thành 1 hàng ngang. Ban đầu mỗi cốc trà sữa có độ ngọt = 0. Tèo tiến hành liên tiếp N các thao tác, mỗi thao tác anh ta sẽ thêm 1 gam đường vào các cốc trà sữa từ vị trí L tới vị trí R. Cuối cùng, những cốc trà sữa có lượng đường >= K gam sẽ được chuyển đi để phục vụ với khách hàng. Có nhiều câu hỏi, mỗi câu hỏi yêu cầu bạn đếm trong các cốc trà sữa từ thứ L tới thứ R có bao nhiêu cốc đạt chuẩn để phục vụ cho khách hàng?
Input format 
* Dòng 1 gồm n,k,q
* n dòng tiếp theo mỗi dòng gồm 2 số L, R (thao tác)
* q dòng tiếp theo mỗi dòng là 2 số L, R (truy vấn)
- Mảng hiệu lưu lại độ ngọt 
- Mảng cộng dồn f[i] >=k, từ L tới R có f[R]-F[L-1] 
=> O(n)

i=      1   2   3   4   5 
d       0   0   0   0   0
3-5     0   0   1   0   0
1-4     1   0   1   0   -1
2-4     1   1   1   0   -2

f       1   2   3   3   1
r       0   1   2   2   2 
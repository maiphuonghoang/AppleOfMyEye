
### 1. Pha trà sữa 
Tèo kiếm được một công việc tại hàng trà sữa, có không quá 200,000 cốc trà sữa xếp thành 1 hàng ngang. Ban đầu mỗi cốc trà sữa có độ ngọt = 0. Tèo tiến hành liên tiếp N các thao tác, mỗi thao tác anh ta sẽ thêm 1 gam đường vào các cốc trà sữa từ vị trí L tới vị trí R. Cuối cùng, những cốc trà sữa có lượng đường >= K gam sẽ được chuyển đi để phục vụ với khách hàng. Có nhiều câu hỏi, mỗi câu hỏi yêu cầu bạn đếm trong các cốc trà sữa từ thứ L tới thứ R có bao nhiêu cốc đạt chuẩn để phục vụ cho khách hàng? \
Input format 
* Dòng 1 gồm n,k,q
* n dòng tiếp theo mỗi dòng gồm 2 số L, R (thao tác)
* q dòng tiếp theo mỗi dòng là 2 số L, R (truy vấn)
- Mảng hiệu lưu lại độ ngọt 
- Mảng cộng dồn f[i] >=k, từ L tới R có f[R]-F[L-1] 
=> O(n)

i=      1   2   3   4   5 \
d       0   0   0   0   0 \
3-5     0   0   1   0   0 \
1-4     1   0   1   0   -1 \
2-4     1   1   1   0   -2 \

f       1   2   3   3   1 \
r       0   1   2   2   2 
### 2. PrefixPrefix
Cho một mảng A có N phần tử và M thao tác. Mỗi thao tác yêu cầu bạn tăng các phần tử từ vị trí L đến R của mảng lên D đơn vị (1<=L<=R<=N). Các thao tác này được đánh số từ 1 đến M. Ngoài ra, Tèo muốn thực hiện K truy vấn. Mỗi truy vấn Tèo lại muốn thực hiện các thao tác từ x tới y theo số thứ tự của thao tác (1 <= x <=y <= M). Hãy giúp Tèo in ra mảng A sau K truy vấn. 
- Đếm xem thao tác thực hiện bao nhiêu lần thì lấy k*tần xuất 
    + D[l] += k*fre;
    + D[r+1] -= k*fre;
- B1: dùng mảng hiệu xác định mỗi truy vấn được thực hiện bao nhiêu lần lưu vào mảng diff 
- B2: Tính mảng hiệu query cho các thao tác, Dựa vào số lần truy vấn sẽ nhân lên 
- B3: Mảng cộng dồn: query + a[i] ban đầu  
### Two pointer 
3. Trộn 2 dãy
Cho 2 mảng a và b có n và m phần tử đã được sắp xếp theo thứ tự tăng dần. Trộn 2 mảng này thành 1 mảng và sắp xếp theo thứ tự tăng dần 
4. Smaller
Cho 2 mảng a và b có n và m phần tử đã được sắp xếp theo thứ tự tăng dần. Đối với mỗi phần tử trong mảng b, hãy đếm xem trong mảng a có bao nhiêu phần tử nhỏ hơn nó
5. Number of equal 
Cho 2 mảng a và b có n và m phần tử đã được sắp xếp theo thứ tự tăng dần. Hãy đếm xem trong 2 mảng tồn tại bao nhiêu cặp i,j sao cho a[i] = b[j]
- Tần xuất xuất hiện trong mảng a * tần xuất trong mảng b 
6. Two Sum
Cho mảng a gồm n phần tử và số nguyên k. Hãy kiểm tra xem trong mảng có a[i] + a[j] = k không?
7. Three Sum
a[i] + a[j] + a[k] = s 
8. Phát quà noel 1
Có N món quà được xếp thành hàng ngang, mỗi món quà đều có khối lượng cho trước. Tèo là một đứa trẻ cũng như nhiều đứa trẻ khác chỉ muốn có càng nhiều phần quà càng tốt, không cần biết tới khối lượng của từng món quà nặng nhẹ ra sao. Tuy nhiên, chiếc túi của Tèo chỉ có thể chứa được trọng lượng tối đa là S. Bạn hãy xác định xem số lượng phần quà mà Tèo có thể chọn tối đa là bao nhiêu để có thể không vượt quá trọng lượng tối đa mà chiếc túi có thể chịu đựng. Ngoài ra, trong lúc chọn quà, Tèo chỉ có thể chọn các phần quà xếp cạnh nhau mà thôi.
- Dòng đầu tiên là n và s
- Dòng 2 là trọng lượng của n phần quà 
- => Tìm dãy con liên tiếp dài nhất có tổng <= S 
9. Phát quà noel 2
Có N món quà được xếp thành hàng ngang, mỗi món quà đều có khối lượng cho trước. Tí là một đứa trẻ không như nhiều đứa trẻ khác, Tí chỉ muốn chỉ muốn chọn ít phần quà càng tốt, miễn là tổng các phần quà này >= S. Tí chỉ có thể chọn các phần quà xếp cạnh nhau. Hãy xác định xem Tí có thể chọn tối thiểu bao nhiêu phần quà để tổng khối lượng các phần quà >= S.
- =>  Tìm dãy con liên tiếp ngắn nhất có tổng >= S
10. Cho một xâu kí tự S chỉ gồm kí tự 2 và kí tự 8. Hãy tìm xâu con liên tiếp có độ dài lớn nhất mà trong đó chứa nhiều nhất X kí tự 2 và Y kí tự 8.




### Dãy Con Tăng Dài Nhất | Longest Increasing Subsequence
- O(n^2)
- Gọi L[i] : độ dài dãy con tăng dài nhất kết thúc ở chỉ số i 
- Trường hợp cơ sở: ban đầu tất cả **L[i] = 1** với mọi i thuộc [0, n-1]
- Xét tất cả phần tử đứng trước chỉ số i, xem có đưa được ptu thứ i vào trong 1 dãy con nào đó đã tăng dần trước nó hay không 
  - **L[i] = max(L[i], L[j] + 1)** với j thuộc [0, i-1], **a[i]>a[j]**

###  Tập Con Có Tổng Bằng S | Subset Sum
- Gọi dp[i]: xác định xem từ các phần tử trong mảng xác định có tạo được tập con có tổng = i hay k 
    - true: nếu có tập con tổng = i
    - false: 
- Kết quả bài toán là dp[S] chọn ra tập con có tổng = S
- Trường hợp cơ sở: lúc nào cũng có tập rỗng có tổng = 0 **dp[0] = true**  
- Xét từ tổng lớn về tổng bé  **dp[j] true khi dp[j - a[i]] true** => tạo ra được tập con có tổng j khi cho a[i] vào 

### Xâu Con Đối Xứng Dài Nhất | Longest Palindrome Substring
- O(n^2)
- substring: xâu con liên tiếp 
- Gọi F[i][j]: xâu con bắt đầu từ chỉ số i và kết thúc ở chỉ số i 
    - true: nếu s[i] != s[j]
    - false: nếu s[i] == s[j] và F[i+1][j-1] true 
      - => F[i][j] = (s[i] == s[j]) && F[i+1][j-1]
- Trường hợp cơ sở: tất cả xâu con độ dài 1 đều đối xứng **F[1][1], F[2][2]...true**
- Chú ý  
  - Không cần duyệt từ chỉ số bắt đầu > chỉ số kết thúc
  - Xét tất cả cá xâu con có độ dài từ 1 tới n 
  - Trong trường hợp xâu có độ dài 2 sẽ không có xâu con đứng ở giữa, chỉ cần quan tâm đến 2 kí tự ở 2 đầu 

### Xâu Con Chung Dài Nhất | Longest Common Subsequence
- Gọi F[i][j] lưu độ dài của xâu con chung dài nhất sử dụng i kí tự đầu tiên của X và j kí tự đầu tiên của xâu Y
  - F[n][m]: đáp án của bài toán 
- Trường hợp cơ sở: không chọn kí tự nào xâu này dù chọn bất kì kí tự nào xâu kia thì độ dài xâu con chung là 0
  - F[i][0] = 0
  - F[0][i] = 0
- Xét X[i] và Y[j]
  - X[i] = Y[j] => F[i][j] = F[i-1][j-1] + 1;
  - X[i] != Y[j] => F[i][j] = max(F[i][j-],F[i-1][j])


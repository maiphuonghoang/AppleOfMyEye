## Các Khái Niệm Cơ Bản Của Đồ Thị
### Đơn đồ thị vô hướng
![DON_DO_THI!](img/graph1.png)

### Đa đồ thị vô hướng
![DA_DO_THI!](img/graph1.png)
- Giữa 2 đỉnh có nhiều hơn 1 cạnh
### Giả đồ thị vô hướng
![GIA_DO_THI!](img/graph3.png)
- 2 đỉnh nối 1 cạnh không nhất thiết phải khác nhau 
- Cạnh khuyên: bắt đầu tại 1 đỉnh và kết thúc tai đỉnh đấy 
### Đơn đồ thị có hướng
![DON_DO_THI_CO_HUONG!](img/graph4.png)
- Các cạnh có thứ tự (các cung) 
### Đa đồ thị có hướng
- Giữa 2 đỉnh tồn tại nhiều cung khác nhau 
### Đỉnh kề, cạnh liên thuộc 
![DINH_KE!](img/graph5.png)
### Bậc của đỉnh trên đồ thị vô hướng 
![BAC!](img/graph6.png)
- Bậc của đỉnh trên đồ thị là số cạnh liên thuộc với đỉnh đó 
- Đỉnh cô lập là đỉnh có bậc = 0
- Đỉnh treo là đỉnh có bậc = 1
- Tổng bậc = 2 * Số cạnh 
### Bán bậc ra, bán bậc vào 
![BAC_RA_VAO!](img/graph7.png)
- Tổng bán bậc ra = Tổng bán bậc vào = Số cạnh 
### Đường đi 
![DUONG_DI!](img/graph8.png)
- Đường đi là 1 dãy các đỉnh + cạnh 
- Đường đi đơn: các đỉnh phân biệt 
- Độ dài đường đi = số cạnh 
### Chu trình 
![CHU_TRINH!](img/graph9.png)
- Là đường đi gồm các cạnh phân biệt, và đỉnh đầu trùng với đỉnh cuối 
### Liên thông trên đồ thị vô hướng 
![LIEN_THONG!](img/graph10.png)
- Giữa 2 đỉnh bất kì luôn có đường đi 
### Thành phần liên thông 
![TP_LIEN_THONG!](img/graph11.png)
### Liên thông mạnh, yếu trên đồ thị có hướng 
![LIEN_THONG_MANH!](img/graph12.png)
- Liên thông mạnh: Giữa 2 đỉnh bất kì luôn có đường đi 
- Liên thông yếu: khi đồ thị vô hướng tương ứng của nó liên thông 
## Biểu diễn đồ thị 
### 1. Ma trận kề 
- **Vô hướng**
![MA_TRAN_KE_Vo!](img/graph13.png)
  - Là ma trận đối xứng 
  - Có cạnh nối giữa 2 đỉnh i,j thì a[i][j] = 1
  - Tổng các phần tử trên hàng = Tổng các phần tử trên cột = Bậc của đỉnh 
  - Tổng phần tử = 2 * cạnh 
- **Có hướng**  
![MA_TRAN_KE_Co!](img/graph14.png)
  - Tổng phần tử = cạnh 
  - Bán bậc ra = Tổng ptu trên hàng 
  - Bán bậc vào = Tổng ptu trên cột 
- **Ma trận trọng số**
![MA_TRAN_TRONG_SO!](img/graph15.png)
### Ưu - Nhược ma trận kề 
![UU_NHUOC!](img/graph16.png)
- Ma trận n đỉnh cần n^2 ô nhớ 
- Xác định đỉnh kề cần duyệt từ 1 đến n ngay cả khi là đỉnh cô lập 
### 2. Danh sách cạnh  
![DS_CANH!](img/graph17.png)
![DS_CANH_TRONG_SO!](img/graph18.png)
![UU_NHUOC_DSC!](img/graph19.png)
### 3. Danh sách kề 
![DS_KE!](img/graph20.png)
![UU_NHUOC_DSK!](img/graph21.png)

### Tool
- csacademy.com

## Thuật toán 

### Thuật Toán Tìm Kiếm Theo Chiều Sâu | Giải Thuật DFS
- Dùng đệ quy (Stack) 
![DFS!](img/dfs1.png)
![DFS_vd!](img/dfs3.png)
![DFS_edge!](img/dfs2.png)

### Thuật Toán Tìm Kiếm Theo Chiều Rộng | Giải Thuật BFS
- Dùng (Queue)  
![BFS!](img/bfs1.png)
![BFS_vd!](img/bfs2.png)

### Áp dụng DFS, BFS
#### Số Thành Phần Liên Thông
- Là số lần gọi DFS/BFS sao cho tất cả các đỉnh của đồ thị được thăm 
- Gọi DFS/BFS để thăm các đỉnh thuộc cùng thành phần liên thông với đỉnh i đấy 
![ConnectedComponent!](img/connectedComponent.png)

#### Tìm Đường Đi Trên Đồ Thị Không Có Trọng Số.
- Cần thêm mảng parent để truy vết đường đi, parent khác 0 chứng tỏ có đường đi đến điểm đấy 
![retrivePath!](img/findPath1.png)
- 2 đỉnh thuộc cùng 1 thành phần liên thông sẽ luôn có  đường đi  
- Trên đồ thị không có trọng số (có hướng và vô hướng) thuật toán BFS cho đường đi có số cạnh là ngắn nhất 

#### Áp Dụng Thuật Toán DFS, BFS Trên Lưới Ô Vuông
![vd!](img/grid1.png)
- Tư tưởng 
  - DFS,BFS không còn là 1 đỉnh như trên đồ thị thông thường nữa mà tham số của DFS,BFS là cặp i,j (chỉ số hàng/cột của ô đang xét)
  - check ô kề vẫn phải nằm trên lưới và có đường đi (chưa được thăm)
- Di chuyển từ ô i,j sang 4 ô xung quanh chung đỉnh 
![4o!](img/grid2.png)
- Di chuyển từ ô i,j sang 8 ô xung quanh
![8o!](img/grid3.png)
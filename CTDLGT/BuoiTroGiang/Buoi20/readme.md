### Thuật toán BellmanFord
- Được sử dụng để tìm đường đi ngắn nhất từ 1 đỉnh tới mọi đỉnh còn lại trên đồ thị. 
- Khác với Dijkstra, BellmanFord có thể áp dụng cho đồ thị với cạnh có trọng số âm.
- Tuy nhiên k thể áp dụng nếu đồ thị có chu trình âm (tổng trọng số trên chu trình là số âm). Thuật toán này có thể sử dụng để xác định rằng đồ thị có chu trình âm 
- Độ phức tạp: O(V*E)
- Tư tưởng thuật toán:
  - Ban đầu sử dụng mảng d[] để lưu khoảng cách từ đỉnh nguồn s tới mọi đỉnh còn lại trên đồ thị, d[s] = 0, d[u] = INF
  - Thuật toán lặp n-1 bước, mỗi bước sẽ xét tất cả các cạnh (u, v) có trọng số w. Nếu d[v]>d[u]+w thì cập nhập d[v].
- Đặc điểm 
  - K chu trình âm lặp n-1 vòng, lặp thêm nữa cũng k nhỏ hơn 
  - Có chu trình âm lặp n-1 vòng, lặp 1 lần nữa nhỏ hơn 

### Thuật toán Floyd Warshall
- Khác với Dijkstra, BellmanFord áp dụng để tìm đường đi ngắn nhất từ 1 đỉnh tới mọi đỉnh còn lại trên đồ thị (SSSP-Single source shortest path), Floyd được áp dụng để tìm đường đi ngắn nhất giữa mọi cặp đỉnh trên đồ thị (All-pair shortest path).
- Thuật toán áp dụng cho đồ thị có hướng, vô hướng k có chu trình âm (có thể có cạnh âm)
- Độ phức tạp: O(V^3)
- Thông thường Floyd chỉ áp dụng được với đồ thị nhỏ có V <= 400, dùng ma trận kề 

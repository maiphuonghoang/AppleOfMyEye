### SELECTION SORT (Sắp xếp chọn)
- Tư tưởng: Ở mỗi bước của thuật toán luôn đưa phần tử nhỏ nhất chưa được sắp xếp về đầu dãy 
- Độ phức tạp: O(n^2)
- Giải thuật: Tìm vị trí ptu nhỏ nhất tính từ i hiện tại cho tới cuối dãy (tìm min trong những phần tử chưa được sắp xếp) rồi hoán vị ptu đó với ptu ở vị trí i => swap (a[i], a[min_pos])
### BUBBLE SORT (Sắp xếp nổi bọt)
- Tư tưởng: So sánh 2 phần tử liền kề và đưa phần tử lớn nhất về cuối dãy 
- Độ phức tạp: O(n^2)
- Giải thuật: Ở mỗi bước của thuật toán sẽ có thêm 1 phần tử được sắp xếp và đưa về cuối dãy - trước < sau => swap
### INSERTION SORT (Sắp xếp chèn)  
- Tư tưởng: Ở mỗi bước của thuật toán sẽ cố gắng đưa phần tử ở vị trí hiện tại về đúng vị trí bằng cách chèn nó vào dãy các phần tử đứng trước nó sao cho đúng thứ tự 
- Độ phức tạp: O(n^2)

### COUTING SORT (Sắp xếp đếm phân phối)
- Tư tưởng: Đếm xem mỗi phần tử trong mảng xuất hiện bn lần, duyệt và in ra từ ptu nhỏ nhất cho tới ptu lớn nhất 
- Độ phức tạp: O(n + max)
- Nhược điểm: k sắp xếp nếu có các phần tử âm hoặc quá lớn (>1e7)

### HEAP SORT
- Heap là 1 cây nhị phân hoàn chỉnh 
- Max-Heap: node cha lớn hơn các node con của nó 
- Min-Heap: node cha nhỏ hơn các node con của nó 
![heap!](img/heap1.png)
- **Xây Max-Heap**
  - Xét các node k là node lá từ dưới lên 
    - Node đầu tiên k phải node lá là n/2-1 
  - Tiếp tục heapify node bị hoán vị từ trên xuống 
    - Node heapify phải có ít nhất 1 con và node ở cha không là lớn nhất thì gọi đệ quy heapify tới các cây con bên dưới
 - Swap phần tử lớn nhất ptử gốc với phần tử cuối cùng trong cây, cắt node cuối đi
 - Heapify ptu gốc tiếp  
   

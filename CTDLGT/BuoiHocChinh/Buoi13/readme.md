### STACK 
- LIFO: last in first out  
stack<data_type> stack_name  
- push, pop, top, size, empty **O(1)**
  - push(x): Thêm phần tử vào đỉnh ngăn xếp
  - pop(): Xóa phần tử khỏi ngăn xếp (chú ý nếu ngăn xếp rỗng việc pop sẽ gây ra lỗi)
  - size(): trả về số lượng phần tử 
  - top(): Lấy về phần tử ở đỉnh ngăn xếp nhưng không xóa 
### QUEUE
- FIFO: first in first out  
queue<data_type> data_type
- Thao tác enqueue, dequeue
  - enqueue: Thêm 1 phần tử vào cuối hàng đợi 
  - dequeue: Xóa 1 phần tử khỏi đầu hàng đợi 
- push, pop, top, size, empty, front, back **O(1)**
  - front: Truy cập vào phần tử ở đầu hàng đợi 
  - back: Truy cập vào phần tử ở cuối hàng đợi 
### PRIORITY QUEUE
- Hàng đợi ưu tiên   
priority_queue<data_type> priority_queue_name
- push, pop, top, size, empty
- top: 
  - thời gian cân bằng lại để lấy top là logN (nhanh hơn multiset)
  - lấy ra phần tử ở đầu, mặc định là lớn nhất khi khai báo *priority_queue<int> pq*
  - nếu muốn lấy ra nhỏ nhất thì khai báo  *priority_queue<int, vector(int), greater(int)> pq* 
### DEQUE
- Hàng đợi 2 đầu  
deque<data_type> deque_name
- Có thể thực hiện thao tác push và pop ở cả 2 đầu *double end queue*
- size, push_front, push_back, pop_front, pop_back, empty, front, back
  - push_front(): đẩy vào đầu 
  - pop_front(): xóa đầu 
  - front(): lấy ra phần tử ở đầu 


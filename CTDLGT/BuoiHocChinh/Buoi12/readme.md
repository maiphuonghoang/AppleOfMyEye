### VECTOR
- mảng động  
vector<data_type> vector_name
- size, push_back
  - push_pack(): thêm phần tử vào vector 
  - truy cập các phần tử trong vector thông qua chỉ số v[0],v[v.size()-1]
  - back(): lấy ra ptu cuối cùng 
  - duyệt bằng index, for each, interator

### SET
- lưu những phần tử khác nhau  
- các phần tử trong set có thứ tự (số tăng dần, chữ theo thứ tự từ điển)
- size, insert, find, count, erase **O(logn)**
set<data_type> set_name
  - count(x): đếm số lượng ptu có gtri x 
  - find(): trả về iterator đến phần tử đó trong set (có s.begin(), s.end())
  - erase(giá trị): xóa ptu trong set 
  - erase(iterator): 
  - begin(), rbegin(): truy cập vào it của ptu đầu tiên/ cuối cùng trong set 
  - end(): truy cập vào it của ptu sau ptu cuối cùng

### MULTISET 
- Các phần tử có thể giống nhau 

### UNOREDERED SET
- Lưu các phần tử riêng biệt nhưng không còn theo thứ tự nữa  
- tìm kiếm O(1)/O(n)

### MAP
- Bản thân map lưu các cặp key-value chính là lưu các pair  
map<data_type1, data_type2> map_name
  - map[key] = value
  - map.insert(key, value) 
- insert, count, find, erase 
- Các ptu trong map sắp xếp tăng dần theo key 

### MULTIMAP
- Cho phép nhiều key có cùng giá trị 
- Chỉ có multimap.insert(key, value) 
- Có thứ tự 

### UNORDERED MAP
- Không có thứ tự 

### PAIR
- Lưu các cặp số đi kèm nhau  
pair<data_type1, data_type2> pair_name
- VD: Thời gian bắt đầu + kết thúc, điểm đầu + cuối của đoạn thẳng 
- Thành phần thứ 1,2 của pair: pair.first; pair.second

### TUPLE
- Nhóm >2 phần tử đi kèm nhau 
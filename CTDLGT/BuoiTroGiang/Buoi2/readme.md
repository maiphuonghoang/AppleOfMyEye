### Set
- key tăng dần 
- key là duy nhất (unique)
- erase insert find (Ologn)

1. Cho thông tin về các trận đấu giải bóng đá Sunday League, nhiệm vụ của bạn là đối với mỗi đội bóng hãy liệt kê các đối thủ đã từng chạm trán. Danh sách các đội bóng và đối thủ của dội bóng được liệt kê tăng dần theo thứ tự từ điển.

Gợi ý: Dùng map(string, vector(string)) mp; mỗi đội bóng sẽ dùng một vector để lưu danh sách các đối thủ trong các trận bóng, sort danh sách đội bóng trước khi in ra kết quả.

- Dòng 1 là N: số trận bóng diễn ra.
- N dòng tiếp theo mỗi dòng gồm thông tin của 1 trận đấu theo cú pháp X - Y, trong đó đội X thi đấu với đội Y.
2. Die Hard
Có n người tại phòng vé đứng thành 1 hàng lớn. Mỗi người trong số họ có 1 tờ tiền mệnh giá 100, 50 hoặc 25. Một vé giá 25 rúp. Nhân viên có thể bán vé cho mỗi người và trả tiền thừa nếu ban đầu không có tiền và bán vé theo đúng thứ tự mọi người xếp hàng hay không ? 
- Kiểm soát số lượng tiền => Dùng mảng đánh dấu 
3. Gửi thư Mini Maxi 
Tất cả các thành phố trong Lineland đều nằm trên trục tọa độ Ox, liên kết với vị trí xi - tọa độ trên trục Ox. Không có hai thành phố nào nằm tại cùng một điểm. Người dân Lineland thích gửi thư cho nhau. Một người chỉ có thể gửi thư nếu người nhận sống ở một thành phố khác. Chi phí gửi thư chính xác bằng khoảng cách giữa thành phố của người gửi và thành phố của người nhận. Đối với mỗi thành phố, tính hai giá trị: chi phí tối thiểu/đa để gửi thư từ thành phố thứ i đến 1 thành phố khác.
- Dòng 2 gồm xi là tọa độ của thành phố thứ i, tất cả các xi là khác biệt và theo thứ tự tăng dần 
- Đối với mỗi thành phố in ra 2 giá trị mini và maxi trên 1 dòng 
4. Hợp và Giao của 2 mảng 
- Mảng đánh dấu 
    + vector giao: dA[val] && dB[val]
    + vector hop:  dA[val] || dB[val] //chỉ thuộc 1 trong 2        
- Two pointer (cả số âm)
    + Sử dụng khi logic và bắt buộc chỉ đưa ra 1 quyết định duy nhất trong 1 trạng thái  
    + Hợp & giao: tăng i lên, chỉ cho thằng bé hơn vào; bằng nhau thì đưa vào cả hợp và giao rồi tăng cả i và j lên 


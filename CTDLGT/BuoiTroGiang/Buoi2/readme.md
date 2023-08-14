### Set
- key tăng dần 
- key là duy nhất (unique)
- erase insert find (Ologn)

1. Cho thông tin về các trận đấu giải bóng đá Sunday League, nhiệm vụ của bạn là đối với mỗi đội bóng hãy liệt kê các đối thủ đã từng chạm trán. Danh sách các đội bóng và đối thủ của dội bóng được liệt kê tăng dần theo thứ tự từ điển.

Gợi ý: Dùng map(string, vector(string)) mp; mỗi đội bóng sẽ dùng một vector để lưu danh sách các đối thủ trong các trận bóng, sort danh sách đội bóng trước khi in ra kết quả.

- Dòng 1 là N: số trận bóng diễn ra.
- N dòng tiếp theo mỗi dòng gồm thông tin của 1 trận đấu theo cú pháp X - Y, trong đó đội X thi đấu với đội Y.


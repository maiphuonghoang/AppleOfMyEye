#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input(a) f0(i,n) cin >> a[i]
using ll = long long;
using namespace std;

/** Job scheduling with profit
 * Cho n công việc. Mỗi công việc được biểu diễn như 1 bộ 3 số nguyên dương,
 * trong đó 
 *      - JobId là mã của việc
 *      - Deadline là thời gian kết thúc của việc : dl=4 có thể làm 1 trong những ngày [1..4]
 *      - Profit là lợi nhuận đem lại nếu hoàn thành đúng thời gian 
 * Hãy cho biết lợi nhuận lớn nhất có thể thực hiện các việc với giả thiết 
 * mỗi việc được thực hiện đơn lẻ 
 * Gợi ý 
B1: Sắp xếp công việc theo lợi nhuận giảm dần
B2: Đối với mỗi cv => lựa chọn mốc thời gian bắt đầu để thực hiện cv,
Vd nếu dealine là x thì mốc thời gian hợp lệ sẽ là 0,1...x-1, và lựa chọn 
mốc thời gian lớn nhất còn trống để thực hiện cv này, sau đó đánh dấu 
mốc thời gian này đã được sử dụng 
4
1 4 20
2 1 10
3 1 40 
4 1 30  
=> 60

đi từ trên xuống, sắp xếp theo deadline giảm dần 
7 50
7 100
6 200
6 100
4 30
3 50
2 100
2 90
2 80
1 180
                                         <-------------
      1      2      3      4      5      6      7  
______|______|______|______|______|______|______|______
      180   100    50     50     100    200    100

- Nếu hôm nay là T7 được quyền làm (7 50) (7 100)
    đánh dấu (7 100) đã được làm 
- Nếu hôm nay là T6 được quyền làm (7 50) (6 200)* (6 100)
- Nếu hôm nay là T5 được quyền làm (7 50) (6 100)*
    được quyền làm việc T6 T7 mới kết thúc 
- Nếu hôm nay là T4 được quyền làm (7 50)* (4 30)
- Nếu hôm nay là T3 được quyền làm (4 30) (3 50)*
- Nếu hôm nay là T2 được quyền làm (4 30) (2 100)* (2 90) (2 80)
    thời gian deadline >= 2
- Nếu hôm nay là T1 được quyền làm (4 30) (2 90) (2 80) (1 180)*

3 50
3 20
3 100
=> cur_date = 3
    3->100 2->50 1->20
*/
struct Job{
    int id, deadline, profit;
};
bool cmp(Job a, Job b) {
    return a.deadline > b.deadline;
}
void run(){
    int n; cin >> n;
    Job a[n];
    for(int i=0; i<n; i++){
        cin >> a[i].id >> a[i].deadline >> a[i].profit;
    }
    //sắp xếp theo deadline giảm dần 
    sort(a, a+n, cmp);
    priority_queue<int> pq; //lấy lợi nhuận lớn nhất trong danh sách các cv 
    int cur_date = a[0].deadline;
    //xét tất cả cv có deadline >= current date 
    int idx = 0;
    ll res = 0;
    while(cur_date >= 1){
        while(idx < n && a[idx].deadline >= cur_date){
            //cho profit vào queue
            pq.push(a[idx].profit);
            idx++;
        }
        if(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        cur_date--; 
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}
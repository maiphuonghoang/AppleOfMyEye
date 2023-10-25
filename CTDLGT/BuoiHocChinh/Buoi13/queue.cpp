#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
void basicQueue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    cout << q.size() << " " << q.front() << " " << q.back() << " " << q.empty();
}
//----------------------------------------------------------------
/* Liệt kê các số nhị phân từ 1 tới n 
                1000
        100     1001
    10  
        101     1010
                1011

1               
        110     1100
                1101
    11  
        111     1110
                1111
Input 
2 
2 10
=> 
1 10 
1 10 11 100 101 110 111 1000 1001 1010
*/
vector<string> bin;
void initSoNhiPhan(){
    queue<string> q;
    //bắt đầu từ 1, đẩy 1 vào hàng đợi
    q.push("1");
    bin.push_back("1");
    while(bin.size() < 100000){//chừng nào sinh ra được 10000 số nhị phân 
        //lấy ra phần tử đầu 
        string top = q.front();
        q.pop();//xóa ptu đầu khỏi hàng đợi  
        //sinh ra 2 số nhị phân liên tiếp bằng cách thêm 0/1 ở cuối
        bin.push_back(top + "0");
        bin.push_back(top + "1");
        q.push(top + "0");//đẩy số mới này vào cuối hàng đợi 
        q.push(top + "1");
    }

}
void runSoNhiPhan(){
    initSoNhiPhan();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for (int i = 0; i<n; i++)
            cout << bin[i] << " ";
        cout << endl;
    }
}
//----------------------------------------------------------------
/* Bội số chỉ chứa 0 và 9
Tìm số x nhỏ nhất tạo bởi số 0 và số 9 chia hết cho n 
2
5 7 
=> 90 9009
        900
    90  909
9 
    99  990
        999
Sinh ra các số theo thứ tự tăng dần 
9 90 99 900 909 990 999 
*/
ll ans[101];//Sinh ra bội của tất cả các số từ 1 đến 100
vector<ll> boi09;
void initBoi09(){
    queue<string> q;
    q.push("9");
    boi09.push_back(9);
    while(1){
        string top = q.front();
        q.pop();
        if(top.length() == 10) 
            break;// chừng nào sinh ra số có 10 chữ số 
        boi09.push_back(stoll(top + "0"));//chuyển thành số 
        boi09.push_back(stoll(top + "9"));
        q.push(top + "0");
        q.push(top + "9");
    }
    int cnt = 0;
    for (int i = 1; i <= 100; i++){
        for (ll x: boi09){
            if(x % i == 0){
                ans[i] = x;
                cnt++;
                break; 
            }
        }
    }
    cout << cnt << endl;

}
void runBoi09(){
    initBoi09();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ans[n] << " ";
    }
}
//----------------------------------------------------------------
/*Số lộc phát
1 số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8.
Hãy liệt kê giảm dần các số lộc phát có không quá n (max=15) chữ số 
2
2 3
=>
88 86 68 66 8 6 
888 886 868 866 688 686 668 666 88 86 68 66 8 6
*/
vector<string> locphat;
void initLocPhat(){
    queue<string> q;
    q.push("6");
    locphat.push_back("6");
    q.push("8");
    locphat.push_back("8");
    while(1){
        string top = q.front();
        q.pop();
        if(top.length() == 15) 
            break;
        locphat.push_back(top + "6");
        locphat.push_back(top + "8");
        q.push(top + "6");
        q.push(top + "8");
    }
}
void runLocPhat(){
    initLocPhat();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> tmp;
        for (string x: locphat){
            if(x.length() == n + 1) break;
            tmp.push_back(x);
        }
        reverse(tmp.begin(), tmp.end());
        for (string x: tmp) cout << x << " ";
        cout << endl;
    }
}
//----------------------------------------------------------------
/**
Cho 2 số nguyên dương S và T (S, T < 10000) và 2 thao tác:
Thao tác (a): Trừ S đi 1 (S = S-1)
Thao tác (b): Nhân S với 2 (S = S*2)
Hãy dịch chuyển S thành T sao cho số lần thực hiện các thao tác a, b là ít nhất.
VD: S=2, T=5 thì mất 4 thao tác
    (a) 2*2 = 4
    (b) 4-1 = 3
    (a) 3*2 = 6
    (b) 6-1 = 5
3
2 5
3 7
7 4
=> 4 4 3 
*/
//pair lưu gtri của số hiện tại, số bước tính từ S tới số hiện tại 
//set để đánh dấu trạng thái các số đã được duyệt
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    runLocPhat();
    return 0;
}

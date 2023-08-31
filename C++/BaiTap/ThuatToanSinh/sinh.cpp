#include <bits/stdc++.h>
using namespace std;

/**Sinh xâu nhị phân có độ dài n 
 4
=>
0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111
*/
int n, a[100], ok;
void initSinhXauNhiPhan(){
    for (int i=1; i<=n; i++)
        a[i] = 0;
    
}
void sinhXauNhiPhan(){
    //Bắt đầu từ bit cuối cùng, và đi tìm bit 0 đầu tiên 
    int i = n;
    while (i >= 1 && a[i] == 1){//gặp bit 1 thì lặp tiếp 
        //chỉ truy cập từ bit 1 đến bit n 
        a[i] = 0;
        --i;
    }
    if(i == 0) //đây chính là cấu hình cuối cùng 
        ok = 0;
    //sau vòng while tìm được bit 0 đầu tiên đến từ bên phải 
    else a[i] = 1;//bật bit 0 thành 1 
}
void ppSinhXauNhiPhan(){
    cin >> n;
    ok = 1;
    initSinhXauNhiPhan();//khởi tạo cấu hình đầu tiên 
    while (ok){//chừng nào chưa phải cấu hình cuối cùng 
        //in ra cấu hình hiện tại 
        for (int i = 1; i <= n; i++)
            cout << a[i];
        cout << endl;
        //sinh ra cấu hình kế tiếp 
        sinhXauNhiPhan();
    }
}
/**Sinh xâu nhị phân có k bit 1
4 3
=> 
0111
1011
1101
1110
*/
bool checkKbit1(int k){
    int cnt = 0;
    for (int i=1; i <= n; i++)
        cnt += a[i];
    return cnt == k;
}
void ppSinhXauNhiPhanCoKbit1(){
    int k;
    cin >> n >> k;
    ok = 1;
    initSinhXauNhiPhan();
    while (ok){
        //check đk thì mới in 
        if(checkKbit1(k)){
            for (int i = 1; i <= n; i++)
                cout << a[i];
            cout << endl;
        }
        sinhXauNhiPhan();
    }
}
//----------------------------------------------------------------
/**Sinh tổ hợp chập k của n 
n = 5, k = 3;
=>
123
124
125
134
135
145
234
235
245
345
*/
void initToHop(int k){
    for (int i = 1; i <= k; i++)
        a[i] = i;
}
void sinhToHop(int k){
    int i = k;
    //1,2,...,k
    //n-k+1, n-k+2,..., n-k+k;
    //ở mỗi vị trí i thì giá trị max là n-k+i
    while ( i>=1 && a[i] == n-k+i){//gặp bit max thì lặp tiếp 
        --i;
    }
    if(i==0) ok = 0;
    else {//tìm được vị trí chưa max 
        a[i]++;//tăng bit đó lên 1
        for (int j=i+1; j<=k; j++)//các bit đằng sau bit đó tăng dần 
            a[j] = a[j-1] + 1; 
    }
}
void ppSinhToHop(){
    int k;
    cin >> n >> k;
    ok = 1;
    initToHop(k);
    while (ok){
        for (int i = 1; i <= k; i++)
            cout << a[i];
        cout << endl;
        sinhToHop(k);
    }    
}
//----------------------------------------------------------------
/** Sinh hoán vị có độ dài n 
1234
1243
1324
1342
1423
1432
2134
2143
2314
2341
2413
2431
3124
3142
3214
3241
3412
3421
4123
4132
4213
4231
4312
4321 
*/
void initHoanVi(){
    for (int i = 1; i <= n; i++){
        a[i] = i;
    }
}
void sinhHoanVi(){
    int i = n - 1;//bắt đầu từ bit sát cuối cùng 
    while (i >= 1 && a[i] > a[i+1]){
        i--;
    }
    if(i==0) ok = 0;//9 8 7 6 5 4 3 2 1 
    else {//tìm được thằng đứng trước nhỏ hơn thằng đứng sau ai<ai+1
        //1 2 4 9 8 7 6 5 3
        //    tìm số nhỏ nhất đứng sau và lớn hơn 4 để hoán vị
        // xét thằng cuối cùng dịch sang trái bao giờ gặp thằng đầu tiên> 4 thì lấy 
        // vì đây đã là dãy giảm dần 
        //1 2 5 9 8 7 6 4 3
        //tìm thằng > a[i] trong đoạn [i+1,n]
        int j = n;
        while(a[i] > a[j]) j--;//sau while tìm được a[j]>a[i]
        swap(a[j], a[i]);

        //1 2 5 3 4 6 7 8 9 
        //đảo ngược dãy giảm dần 
        int l = i + 1, r = n;
        while (l<r){
            swap(a[l], a[r]);
            l++; r--;
        }
        // reverse(a+i+1,a+n+1); đảo ngược từ [a+i+1, a+n]
    }
}
void ppSinhHoanVi(){
    cin >> n;
    ok = 1;
    initHoanVi();
    while(ok){
        for (int i=1; i<=n; i++)
            cout << a[i];
        cout << endl;
        sinhHoanVi();
    }
}
//----------------------------------------------------------------
/** Hàm có sẵn cho hoán vị */
void builtHoanVi(){
    int n; cin >> n;
    int a[n];

    //HOÁN VỊ THUẬN 
    for (int i=0; i<n; i++) 
        a[i] = i + 1;//1 2 3 4 5 
    do{
        //in ra cấu hình hiện tại
        for (int i=0; i<n; i++)
            cout << a[i];
        cout << endl;
    }
    while(next_permutation(a, a+n));//sinh ra cấu hình kế tiếp 

    //HOÁN VỊ NGƯỢC  
    for (int i=0; i<n; i++) 
        a[i] = n - i;//5 4 3 2 1 
    do{
        //in ra cấu hình hiện tại
        for (int i=0; i<n; i++)
            cout << a[i];
        cout << endl;
    }
    while(prev_permutation(a, a+n));//sinh ra cấu hình kế tiếp 
     
    //áp dụng cho xâu
    string s = "abcdef";
    next_permutation(s.begin(), s.end());
    cout << s << endl; //abcdfe
}
//----------------------------------------------------------------
/**Sinh phân hoạch nguyên của số tự nhiên n 
n = 6
=>
6 
5 1
4 2
4 1 1
3 3
3 2 1
3 1 1 1
2 2 2
2 2 1 1
2 1 1 1 1
1 1 1 1 1 1
*/
int cnt;
void initPhanHoach(){
    cnt = 1;
    a[1] = n;
}
void sinhPhanHoach(){
    int i = cnt;
    while(i >= 1 && a[i] == 1)
        --i;
    if(i==0) ok = 0;
    else{
        a[i]--;
        //phần bù = số lượng số 1 bị bỏ qua + 1 đơn vị bị giảm 
        int d = cnt - i + 1;
        cnt = i;
        //phân tích d thông qua a[i]
        int q = d / a[i];
        int r = d % a[i];

        //viết q thằng a[i] vào sau chỉ số i
        if(q){
            for (int j = 1; j <= q; j++){
                cnt++;
                a[cnt] = a[i];
            }            
        }
        if(r){
            cnt++; a[cnt] = r;
        }
    }

}
void ppSinhPhanHoach(){
    cin >> n;
    ok = 1;
    initPhanHoach();
    while(ok){
        for (int i=1; i <= cnt; i++)
            cout << a[i] << " ";
        cout << endl;
        sinhPhanHoach();
    }
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    ppSinhPhanHoach();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
void minValue(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    int min_val = 1e9;
    //C1: tìm min rồi so sánh min với các ptu trong mảng 
    int cnt = 0;
    for (int x : a)
        min_val = min(min_val,x);
    for (int x : a)
        if(min_val == x) cnt ++;
    
    //C2: nếu có số nhỏ hơn mới thì cập nhật min, set lại count = 1 không thì tăng count
    min_val = 1e9;
    int count = 1;
    for (int x : a)
        if(x<min_val){
            min_val = x;
            count = 1;//lần đầu tiên được cập nhật 
        }
        else if(x == min_val) count++;   
}
//----------------------------------------------------------------
/**
 * Đếm trong mảng A tồn tại bao nhiêu cặp số A[i][j] (i#j) sao cho 
 * tổng của 2 phần tử này bằng số k cho trước 
5 3
1 2 3 1 2
=> 4
*/
void pairSumK(){
    int n, k; cin >> n>>k;
    int d[1001] = {0};//đánh dấu ngay trong lúc nhập 
    int a[n];
    for (int &x : a) {
        cin >> x;
        d[x]++;//đếm số lần xuất hiện 
    }
    int cnt = 0;
    for (int l = 0; l <= k/2; l++){
        int r = k - l;
        if(l!=r)
            cnt += d[l] * d[r];
        else
            cnt += d[l]*(d[l]-1)/2; //tổ hợp chập 2 của d[l]
    }
    cout << cnt;

}
//----------------------------------------------------------------
/**
 * Cho mảng số nguyên gồm n phần tử, tìm độ chênh lệch nhỏ nhất giữa 2 phần tử trong mảng
8 
69 96 93 27 84 32 78 56
=> 3 
*/
void pairMinSub(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    int min_val = 1e9;
    //C1: tìm độ chênh lệch rồi cập nhật min 
    for (int i =0; i < n; i++)
        for (int j = i+1; j <n; j++) {
            int cl = abs(a[i]-a[j]);
            min_val = min(min_val, cl);
        }   
    cout << min_val << endl;     

    //C2: Cố định 1 ptu, tìm ptu > và < ngay kề gtri của nó
    //=> sort, khoảng cách là a[i] - a[i-1]
    min_val = 1e9;   
    sort(a, a+n);
    for (int i =1; i < n; i++)
        min_val =  min(min_val,a[i] - a[i-1]);
    cout << min_val;     
}
//----------------------------------------------------------------
/**
 * Liệt kê các giá trị khác nhau trong mảng theo thứ tự xuất hiện, mỗi giá trị chỉ liệt kê 1 lần 
9
1 3 2 4 1 2 3 4 5
=> 1 3 2 4 5
*/
void TanXuatMot(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;

    //C1: chỉ in ra khi a[i] đầu tiên (khác a[i-1]thằng còn lại)
    for (int i = 0; i < n; i++){
        int ok=0;
        for (int j = 0; j < i; j++){
            if(a[i]==a[j])  {
                ok=1;
                break;
            }
        }
        if(!ok) cout << a[i] << " ";
    }
    //C3: Mảng đánh dấu tăng biến đếm lần xh (áp chụng chỉ số dương)
    int d[1001] = {0};
    for (int i = 0; i < n; i++){
        d[a[i]]++;
        if(d[a[i]] == 1) cout << a[i]<< " ";
    }
    //C2: chỉ in ra khi a[i] đầu tiên, khử các giá trị sau = -1;
    for (int i = 0; i < n; i++){
        if(a[i]>=0){
            cout << a[i] << " ";
            for(int j = i+1; j <n; j++)
                if(a[j] == a[i]) a[j] = -1;
        }
    }

}   
//----------------------------------------------------------------
/**
 * Liệt kê các giá trị khác nhau trong mảng theo thứ tự xuất hiện
 * kèm theo tân tần xuất tương ứng, mỗi giá trị chỉ liệt kê 1 lần 
6
1 3 3 3 3 2
*/
void TanXuatTuongUng(){
    int n; cin >> n;
    int a[n];
    int d[1001] = {0};
    for (int &x : a){
        cin >> x;
        d[x]++;
    } 
    // for (int i = 0; i < n; i++){
    //     d[a[i]]++;
    // } //nên đếm luôn lúc nhập 
    for (int i = 0; i < n; i++){
         if(d[a[i]]>0){
            cout << a[i] << " " << d[a[i]] << endl;
            d[a[i]] = 0; //khử những ptu xuất hiện lần 2 
        }       
    }
}
//----------------------------------------------------------------
/**
 * Cho mảng A gồm N phần tử. Liệt kê các chỉ số i trong mảng thỏa mãn:
 * Tổng các phần tử bên trái i và tổng các phần tử bên phải i là các số nguyên tố 
5
53 5 69 47 19
*/
int ngto(int n){
    for (int i=2; i<= sqrt(n); i++)
        if(n%2 == 0) return 0;
    return n>1;
}
void positionSumPrimeLeftRight(){
    int n; cin >> n;
    int a[n];
    int sum = 0;
    for (int &x : a) {
        cin >> x;
        sum+=x;
    }
    //C1
    for (int i=1; i<n-1; i++) {
        int sum_left = 0, sum_right = 0;
        for (int j=0; j<i; j++) sum_left += a[j];
        for (int j=i+1; j<n; j++) sum_right += a[j];
        if (ngto(sum_left) && ngto(sum_right)) 
            cout << i << " ";
    }
    //C2
    int sum_left = a[0];
    for (int i = 1; i < n; i++){
        int sum_right = sum - sum_left - a[i];
        if (ngto(sum_left) && ngto(sum_right)) 
            cout << i << " ";
        //chuẩn bị cho bước sau 
        sum_left += a[i];
    }

}
//----------------------------------------------------------------
/**
 * In ra các số Fibonaci trong dãy 
6
1597 25358 7318 5878 0 2634
=> 1597 0
*/
#define ll long long 
ll F[100];
void fibonacci(){
    F[0] = 0; F[1] = 1;
    for (int i=2; i<93; i++) 
        F[i] = F[i-1] + F[i-2];   
}
void findFibo(){
    fibonacci();
    int n; cin >> n;
    ll a[n];
    for (ll &x : a) cin >> x;
    int ok = 0;
    for (ll x: a){
        for (int i=0; i<93; i++) 
            if(F[i] == x){
                cout << " " <<x;
                ok = 1;
            }
    }
    if(!ok) cout << "None";
}
//----------------------------------------------------------------
/**
 * Tìm vị trí cuối cùng của giá trị nhỏ nhất và vị trí đầu tiên của giá trị lớn nhất 
9
936 234 471 168 834 82 280 674 881
*/
// cuối cùng: chỉ cập nhật vị trí và gtri min khi <= min 
// đầu tiên: chỉ cập nhật vị trí và gtri max khi > max 
void positionFirstLast(){
    fibonacci();
    int n; cin >> n;
    int a[n]; 
    for (int &x : a) cin >> x;

    int min_val = 1e9, idx_min_val = 0;
    int max_val = -1e9, idx_max_val = 0;
    for (int i = 0; i < n; i++){
        // if (a[i] <= min_val) {
        if (a[i] <= a[idx_min_val]) {  
            // min_val = a[i];
            idx_min_val = i;
        }
        if (a[i] > max_val) {
            max_val = a[i];
            idx_max_val = i;
        }
    }
    cout << idx_min_val <<" " << idx_max_val;
} 
//----------------------------------------------------------------
/**
 * Tính tổng và tích các phần tử trong mảng và lấy dư với 10^9+7
*/
void module(){
    int n; cin >> n;
    int a[n]; 
    for (int &x : a) cin >> x;

    ll sum = 0, tich = 1;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++){
        // sum = sum + a[i];
        // sum = ((sum % mod) + (a[i] % mod)) % mod;
        //sau mỗi bước sum đều chia du cho mod => sum < mod 
        //cả sum và a[i] đều là số bé chia dư cho số lớn thì vẫn là số bé => có thể bỏ %mod  
        sum = (sum+ a[i]) % mod;

        tich = (tich * a[i]) % mod;
    }

}
//----------------------------------------------------------------
int gcd(int a, int b) {
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void findGcd(){
    int n; cin >> n;
    int a[n]; 
    for (int &x : a) cin >> x;

    int res = a[0];
    for (int i=1; i<n; i++)
        res = gcd(res, a[i]);
    cout << res << endl;
}
//----------------------------------------------------------------
/**
 * Tìm số lớn thứ nhất và số lớn thứ 2 trong mảng (có thể giống nhau)
*/
void findMaxes(){
    //sort thì mất O(nlogn)

    //chỉ cần O(n)
    //>= max1 thì max2 = max1 cũ, max1=mới 
    //>  max2 thì cập nhật max 2
    // 1 9 3 2 9 5 10
    // max1 = 1 9 9 9 10
    //max2 = 0 1 3 9 9

    int n; cin >> n;
    int a[n], max1=0, max2=0; 
    for (int &x : a) cin >> x;

    for (int x: a)
        if(max1 <= x){
            max2 = max1;
            max1 = x;
        }else if(x > max2){
            max2 = x;
        }          
}
int main(){
    int a[] = {-123482634, 0, 0, 0};//khai báo trong main phần tử đầu tiên là rác 
    //chỉ cần khai báo ptu đầu tiên là 0;
    int d[1001] = {0}; //{0, 0, 0, 0}
    positionFirstLast();
}
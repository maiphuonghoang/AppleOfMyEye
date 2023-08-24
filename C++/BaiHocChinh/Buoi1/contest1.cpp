#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int divisorMinMax(){
    // Số lớn nhất <= a mà chia hết cho b: [a/b]*b
    // Số nhỏ nhất >= a mà chia hết cho b : a hoặc [a/b+1]*b 
    //                                      [(a+b-1)/b] * b 
    int a, b; cin >> a >> b;
    cout << a/b * b << endl;

    if(a%b==0) cout << a;
    else cout << (a/b + 1) * b << " ";

    cout << (a+b-1)/b*b ; 

}
void triangle(){
    int a,b,c; cin >> a >> b >> c;
    //check tính hợp lệ của tam giác
    if(a>0 && b>0 && c>0 && (a+b)>c && (b+c)>a && (a+c)>b){
        //phân loại tam giác  
        if(a==b & b==c) cout << "deu";
        else if(a==b || b==c || a==c) cout << "can";
        else if(a*a==b*b+c*c || b*b==a*a+c*c || c*c==b*b+a*a) cout << "vuong";
        else cout << "tam giac thuong";
    }
    else cout << "Invalid";
}
void dayOfMonth(){
    int t,n; cin >> t >> n ;
    if(n>0){
        if(t==1||t==3||t==5||t==7||t==8||t==10||t==12) 
            cout << 31;
        else if(t==4||t==6||t==9||t==11) 
            cout << 30;
        else if(t==2)
            if(n%400 || (n%4==0 && n%100 != 0))
                cout << 29;
            else cout << 28;
        else cout << "Invalid month";
    }
    else cout << "Invalid year";

    if(t<1||t>12||n<=0)
        cout << "Invalid";
}
void convertDayMonthYear(){//đổi x thành số năm, số tuần, số ngày 
    int x; cin >> x;
    int N = x/365;
    int T = x%365;
    int NG = x - 365*N - 7*T;
}
void character(){
    //in ra mã ascii
    cout << (int)('A') <<endl;
    //ASCII 256 kí tự: 0-255
    //A-Z: 65-90
    //a-z: 97-122
    //0-9: 48-57

    char c; cin >> c;
    if(c>='a' && c<='z') cout << "Lower";
    else if(c>='A' && c<='Z') cout << "Upper";
    else if(c>='0' && c<='9') cout << "Digit"; //chữ số vs số  
    else cout << "Special";

    //khi tính toán thì mã ascii được đem ra thực hiện 
    char kitu = 'A';
    int x = kitu + 2; //65+2
    cout << x ; //67

}
void domino1(){
    //thanh domino 2x1 vào bảng nxm 
    int n, m; cin >> n >> m;
    if(n%2==0) cout << 1ll * n/2*m;
    else cout << 1ll*n/2*m + m/2;
}
void domino2(){
    //thanh domino a*a vào bảng nxm 
    int n, m, a; cin >> n >> m >> a;
    int x,y;
    if(n%a==0) x = n/a;
    else x= n/a+1;
    if(m%a==0) y = m/a;
    else y= m/a+1;
    cout << 1ll*x*y;
}
void frog(){
    //vị trí của ếch là tổng bước nhảy sang phải trừ tổng bước nhảy sang trái
    // k1*a - k2*b; (k1=k2 hoặc k1=k2+1)
    long long a,b,k; cin >> a>>b>>k;
    if(k%2 == 1) cout << (k/2+1)*a - (k/2)*b;
    else cout << k/2*a - (k/2)*b;
}
void muaNuoc(){
    //chai 1l giá a, chai 2l giá b
    //tìm số tiền tối thiểu mua chính xác n lít nước 

    //mua tất cả theo đơn giá nhỏ 
    // 5000/chai 1l; 12000/chai 2l 
    // 5000/chai 1l; 8000/chail 2l; n=41=> 20chai 2l và 1 chail 1l

    int n, a, b; cin >> n,a,b;
    
    if(2*a<=b) cout << n * a;
    else cout << n/2*b + (n%2)*a;
}
void dongXu(){
    //xu có các giá trị: 1,2,3,...n 
    //Tìm số lượng xu tối thiểu để có được tổng là s
    // s/n tờ n và tờ s%n;
    int n,s; cin >> n >> s;
    if (s%n == 0) cout << s/n;
    else cout << s/n + 1;
}
void doraemon(){
    //số lượng bước tối thiểu và số lượng bước tối đa [l,r] = [n/2,n] || [n/2 + 1,n]
    //số lượng bước nhỏ nhất >=l và chia hết cho m
    int m,n; cin >> m >> n;
    int l, r = n;
    if(n%2 == 0) l = n/2;
    else l = n/2 + 1;
    int res = (l-m+1)*m/m;
    if(res<=r) cout << res << endl;
    else cout << -1;

}
void roadMin(){
    int d1,d2,d3; cin >> d1 >> d2 >> d3;//832 56 273
    int kc1 = d1+d2+d3;
    int kc2 = 2*(d1+d2);
    int kc3 = 2*(d2+d3);
    int kc4 = 2*(d1+d3);
    cout << min({kc1,kc2,kc3,kc4}) << endl; // 658
}
void moneyMin(){
    //Các tờ tiền có mệnh giá 1,5,10,20,100
    //Số tờ tiền tối thiểu cho n đô la?

    int n; cin >> n;
    int a,b,c,d,e;
    a = n/100;
    b = (n-a*100)/20;
    c = (n-a*100-b*20)/10;
    d = (n-a*100-b*20-c*10)/5;
    e = n-a*100-b*20-c*10-d*5;
    cout << a+b+c+d+e <<endl;
}
void capSoCong(){
    //Cấp số cộng có n phần tử, phần tử đầu tiên là u1 và công sai d
    //3646 662 114 => 759924842
    int n, u1, d; cin >> n >> u1 >> d;
    int un = u1 + (n-1)*d;
    int sum = (n*(u1+un))/2;
    cout << sum << endl;
}
void checkCapSoNhan(){
    //VD: 92 92 92 92 là 1 CSN với công bội = 1
    int a,b,c,d; cin >> a >> b >> c >> d;
    int q = b/a;
    if(b*q==c && c*q==d) cout << "Yes";
    else cout << "No";

}
void toHopChap2(){
    // kCn = n! / (k!*(n-k)!)
    // 2Cn = n(n-1)/2
}
void cup(){
    //Cúp: a1 giải nhất, a2 giải nhì, a3 giả ba 
    //Huy chương: b1 giải nhất, b2 giải nhì, b3 giải ba (<100)
    //Tủ n kệ 
    //kệ k chứa cả cúp và huy chương cùng lúc
    //kệ k chứa >5 cúp, k chứa >10 huy chương 

    //46 76 52 40 60 67 , n = 11 => YES
    //a1+a2+a3 cần x kệ 
    //b1+b2+b3 cần y kệ 
    //nếu x+y <=n thì thỏa mãn 
    int n,a1,a2,a3,b1,b2,b3; cin >>n>>a1>>a2>>a3>>b1>>b2>>b3;
    int tongC, tongHC, keC, keHC;
    tongC = a1+a2+a3;
    tongHC = b1+b2+b3;
    keC = (tongC%5==0)?(tongC/5):(tongC/5+1);
    keHC = (tongHC%10==0)?(tongHC/10):(tongHC/10+1);
    if(keC+keHC <= n) cout << "Yes";
    else cout << "No";
}
void taoSo(){
    /* k2 chữ số 2, k3 chữ số 3, k5 chữ số 5, k6 chữ số 6
    tạo số 32, 256
    Các chữ số tạo ra có tổng càng lớn càng tốt
    Mỗi chữ số được sử dụng chỉ 1 lần
    các số nguyên được tổng hợp nên chứa k quá k2 chữ số 2, k3 chữ số 3,...
    */

   //để có tổng max thì ưu tiên các số 2 vào 256 trước, còn lại thì đưa vào 32
    //2:2, 3:3, 5:5, 6:16 => 256 = min(2,5,16)

    //5 1 3 4 => 800
    int k2,k3,k5,k6; cin >> k2 >>k3 >>k5 >>k6;
    int soluong256 = min ({k2,k5,k6});
    int soluong32 = min ({k2 - soluong256,k3});
    cout << soluong256*256 + soluong32*32 << endl;
}
void chiaTien(){
    /**
     * A + B + C = n
     * a + A = b +B = c + C ;
     * 
     * 5 3 2 | 8 => Yes 
     * 1 1 8 | 2 => No 
    */
   // a+b+c+n phải chia hết cho 3 
   // (a+b+c+n)/3 = t >=a,b,c
}
void HPNY(){//số phút đến giao thừa 
    //h giờ m phút 
    //23 0 => 60
    int h,m; cin >> h >> m;
    int time = (24 - h) * 60 - m; 
    cout << time;

}
int main(){
    HPNY();
}

#include <bits/stdc++.h>
#include <stack>
using namespace std;

void basicStack(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl;
    st.pop();
    st.size();
    cout << st.empty() << endl;
}
void chuyenThapPhan2NhiPhan(){
    int n; cin >> n;
    stack<int> st;
    while(n!=0){
        st.push(n % 2);
        n /= 2;
    }
    while(!st.empty()){
        cout << st.top();//in ptu đầu
        st.pop();//xóa nó đi 
    }
}
/**
python java php c++   js
=> js c++ php java python 
*/
void inTuNguoc(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string token;
    stack<string> st;
    while(ss >> token){
        st.push(token);
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}
//-------------------------------------------------
/*
()()) => invalid
((()))() => valid 
*/
void validParentheses(){
    string s; cin >> s;
    stack<char> st;
    for(char x : s){
        if(x == '(') st.push(x);
        else{
            if(st.empty()){
                cout << "Invalid";
                return;
            }
            else st.pop();
        }
    }
    if(st.empty()) cout << "Valid";
    else cout << "Invalid";
}
/*
4
()
()[]{}
(]
([)]
=> 1 1 0 0 
*/
bool isValid(string s) {
    stack<char> st;
    for (char x : s){
        if(x == '(' || x == '[' || x == '{')
            st.push(x);
        else{
            if(st.empty()){
                return false;
            }
            else {
                if(x == ')' && st.top() == '('|| (x == ']' && st.top() == '['||x == '}' && st.top() == '{'))
                    st.pop();
                else return false;
            }
        }

    }
    if(st.empty())
        return true;
    return false;
}
void leetcodeValidParentheses(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << s;
        cout << isValid(s) << endl;
    } 
}

//-------------------------------------------------------
/**Phần tử lớn hơn tiếp theo 
Tìm phần tử lớn hơn nó, đứng gần nhất phía sau nó  
7
3 4 2 5 1 6 2 
=>
4 5 5 6 6 -1 -1  
*/
void nextGreaterElementArray(){
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin>>x;
    for (int i=0; i<n;i++){
        int res = -1;
        for (int j = i+1; j<n; j++){
            if(a[j]>a[i]){
                res = a[j];
                break;
            }
        }
        cout << res << " ";
    }

}

void nextGreaterElementStack(){
    int n; cin >> n;
    int a[n];
    int b[n];//thông qua chỉ số để lưu kết quả 
    stack<int> st;
    for(int &x : a) cin>>x;
    for (int i=0; i<n;i++){
        if(st.empty())
            st.push(i);
        //kiểm tra thằng đỉnh stack liệu nó có < a[i] hiện tại hay k 
        //và stack phải k rỗng thì mới truy cập được vào top
        else{
            while(!st.empty() && a[st.top()] < a[i]){
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    //còn lại tất cả thằng vẫn nằm trong stack 
    while(!st.empty()){
        b[st.top()] = -1;
        st.pop();
    }
    for (int x : b) cout << x << " " ;

}
/*
5
1 2 3  4 3
=> 
2 3 4 -1 4 
*/
void nextGreaterElementCircularlyStack(){
    int n; cin >> n;
    int a[n];
    int b[n];
    std::fill_n(b, n, -1);
    stack<int> st;
    for(int &x : a) cin>>x;

    for (int i = 0; i < 2 * n; ++i) {
        int num = a[i % n];
        while (!st.empty() && a[st.top()] < num) {
            b[st.top()] = num;
            st.pop();
        }
        if (i < n) {
            st.push(i);
        }
    }

    for (int x : b) cout << x << " " ;
}
//-----------------------------------------------------
/* Diện tích hình chữ nhật lớn nhất trên biểu đồ
7
6 2 5 4 5 1 6 
*/
void maximumRectangularAreaInHistogram(){
    int n; cin >> n;
    int a[n], b[n];
    for(int &x : a) cin>>x;
    stack<int> st;
    int res = INT_MIN;
    int i = 0;
    while(i<n){
        if(st.empty() || a[i] >= a[st.top()]){
            st.push(i);
            i++;
        }
        else{
            //tính toán các cột thấp hơn cột hiện tại trong stack 
                int index = st.top();//chỉ số của cột ở đỉnh stack 
                st.pop();//xóa thằng đấy đi 
                //tính toán hình chữ nhật tạo bởi cột hiện tại, trong đó
                //cột hiện tại được coi là cột ngắn nhất của hcn đó 
                if(st.empty())
                    res = max(res, i*a[index]);
                else
                    res = max(res, (i-st.top()-1)*a[index]);
                
        }
    }
    //các cột còn lại trong stack 
    while(!st.empty()){
        int index = st.top(); 
        st.pop();
        if(st.empty())
            res = max(res, i*a[index]);
        else
            res = max(res, (i-st.top()-1)*a[index]);
    }
    cout << res << endl;

}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    nextGreaterElementCircularlyStack();
    return 0;
} 
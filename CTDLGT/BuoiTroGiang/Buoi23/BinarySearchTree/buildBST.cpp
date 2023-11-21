#include <bits/stdc++.h>
#define el cout << "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define maxn 100006
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Cho mảng số nguyên a có n phần tử, lần lượt thêm các phần tử trong mảng
 * vào cây nhị phân sao cho cây nhị phân thu được là cây nhị phân tìm kiếm 
 * với gốc cây là a[0]. In ra thứ tự duyệt cây inorder
Inorder trong cây nhị phân tìm kiếm có thứ tự tăng dần 
7
7 3 5 8 6 2 4
=> 2 3 4 5 6 7 8 
*/
struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void insert(Node *root, int x){
    if(x < root->data){
        if(root->left)
            insert(root->left, x);
        else 
            root->left = new Node(x);
    }
    else{
        if(root->right)
            insert(root->right, x);
        else 
            root->right = new Node(x);
    }
}
void inOrder(Node *root){
    if(!root ) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void run(){
    int n; cin >> n;
    int a[n];
    for(int &x: a) cin >> x;
    Node *root = new Node(a[0]);
    for(int i=1; i<n; i++){
        insert(root, a[i]);
    }
    inOrder(root);
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
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
/** 2 cây nhị phân bằng nhau
 * duyệt cùng 1 kiểu phải ra kết quả giống nhau 
6
1 2 L 
1 3 R
2 4 L
2 5 R 
3 6 L
3 7 R 
6
1 2 L 
1 3 R
2 4 L
2 5 R 
3 7 R
3 6 L
=> Yes 
*/

int n;
int preOrder[105], inOrder[105];
struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void makeNode(Node *root, int u, int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}
void insert(Node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->data == u) makeNode(root, u, v, c);
    else{
        insert(root->left, u, v, c);
        insert(root->right, u, v, c);
    }
}
void input(Node *&root){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int x, y; char c;
        cin >> x >> y >> c;
        if(root == NULL){
            root = new Node(x);
            makeNode(root, x, y, c);
        }else
            insert(root, x, y, c);
    }
}

int check(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL) return 1;
    if(root1 == NULL || root2 == NULL) return 0;
    if(root1->data != root2->data)
        return 0;
    return check(root1->right, root2->right) && check(root1->left, root2->left);
}
void run(){
    Node *root1 = NULL;
    Node *root2 = NULL;
    input(root1); input(root2);
    check(root1, root2) ? yes : no;
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
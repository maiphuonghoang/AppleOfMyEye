#include <bits/stdc++.h>
#define el cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f0(i,n) for (int i = 0; i < n; i++)
#define f1(i,n) for (int i = 1; i <= n; i++)
#define input0(a) f0(i,n) cin >> a[i]
#define output0(a) f0(i,n) cout << a[i] << " "
#define input1(a) f1(i,n) cin >> a[i]
#define output1(a) f1(i,n) cout << a[i] << " "
using ll = long long;
using namespace std;
int mod = 1e9+7;

/** Maximum sub array
 * Tính tổng của dãy con liên tiếp có tổng lớn nhất 
Dãy con liên tiếp thuộc mảng 1
        /   |   \
       /    |    \
      /     |     \ 
dclt trái   phải  crossing     } max 

crossing     __|__      __|     |__  phải liên tiếp, đi từ giữa ra 
               |

Phân tích                
-2 10 -2 3 -1| -44 9 1 -1 -3

                                                -2
                                        10    /  
                                        [-2 10] __10
                                        /      \
                                10     /         10
                            [-2 10 -2] ____[10]
                            /          \
                11         /     3      [-2]   
    trái    [-2 10 -2 3 -1]____[3 -1]
                            \
                             \    11
                              [10 -2 3]
    phải    [-4 9 1 -1 -3]
                10

    cross   [10 -2 3 -1]
                10
Cách tính crossing 
        -5 3 -2 10 -1 | 1 2 -3 
             <-------- ------>
tìm max liên tiếp tính từ giữa ra     
        {2 10 7  9 -1} + {1 3 0}
               10     +   3 = 13

5
-3 6 1 -3 6
=> 10

*/
ll crossingSum(int a[], int l, int r, int mid){
    ll sumLeft = 0, maxSumLeft = 0;
    ll sumRight = 0, maxSumRight = 0;
    for(int i=mid; i>=l; i--){
        sumLeft += a[i];
        maxSumLeft = max(maxSumLeft, sumLeft);
    }
    for(int i=mid+1; i<=r; i++){
        sumRight += a[i];
        maxSumRight = max(maxSumRight, sumRight);
    }
    return maxSumLeft + maxSumRight;
}

ll maxSum(int a[], int l, int r){
    if(l==r) return a[l];
    int mid = (l+r)/2;
    return max({
        maxSum(a, l, mid),
        maxSum(a, mid + 1, r),
        crossingSum(a, l, r, mid) 
        //crossingSum của mảng a đi từ left tới right và đi qua mid 
    });
}
void run(){
    int n; cin >> n;
    cout << n << endl;
    int a[n]; input0(a);
    cout << maxSum(a, 0, n-1);
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
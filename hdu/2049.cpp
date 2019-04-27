//+base
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SIZE(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;

//+main
ll fac[21];
ll fn[21];

int main(){
    fac[0] = 1;
    fac[1] = 1;
    fac[2] = 2;
    fn[0] = 0;
    fn[1] = 0;
    fn[2] = 1;
    rep(i, 3, 21){
        fac[i] = fac[i-1] * i;
        fn[i] = (i-1) * (fn[i-1] + fn[i-2]);
    }
    int T;
    cin >> T;
    rep(t, 0, T){
        int n, m;
        cin >> n >> m;
        cout << fac[n]/fac[m]/fac[n-m]*fn[m] << endl;
    }
    return 0;
}


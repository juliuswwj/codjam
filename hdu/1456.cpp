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
int main(){
    fac[0] = 0;
    fac[1] = 1;
    rep(i, 2, 21) fac[i] = (i-1) * (fac[i-1] + fac[i-2]);

    int n;
    while(cin >> n){
        cout << fac[n] << endl;
    }
    return 0;
}


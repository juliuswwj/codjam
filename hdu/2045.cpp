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
ll dp[55];
int main(){
    dp[1] = 3;
    dp[2] = 6;
    dp[3] = 6;
    rep(i, 4, 51){
        dp[i] = dp[i-1] + dp[i-2]*2;
    }
    int n;
    while(cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}


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
int dp[31][5];

int main(){
    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[0][4] = 1;
    rep(i, 2, 31){
        //duplicate states 1=3 2=4
        //dp[i][0] = dp[i-1][1] + dp[i-1][2] + dp[i-2][3] + dp[i-2][4] + dp[i-2][0];
        dp[i][0] = dp[i-1][1] + dp[i-2][4] + dp[i-2][0];
        dp[i][1] = dp[i-1][4];
        dp[i][2] = dp[i-1][3];
        dp[i][3] = dp[i][0] + dp[i-1][2];
        dp[i][4] = dp[i][0] + dp[i-1][1];
    }

    int n;
    while(cin >> n){
        if(n < 0)break;
        cout << dp[n][0] << endl;
    }
    return 0;
}


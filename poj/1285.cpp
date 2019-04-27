//+base
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cctype>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <functional>
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
int m, n, maxn;
int uc[101];
ll dp[101];
void solve(){
    // initial
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    rep(i, 1, n+1) {
        per(c, 0, maxn+1) {
            rep(k, 1, uc[i]+1) if(k+c <= maxn){
                dp[k+c] += dp[c];
            }
        }
    }
    rep(i, 0, m){
        int v;
        cin >> v;
        cout << dp[v] << endl;
    }
}
int main(){
    int t = 1;
    while(cin >> maxn >> m){
        if(maxn == 0) break;

        map<int, int> ids;
        rep(i, 0, maxn){
            int v;
            cin >> v;
            if(ids.find(v) != ids.end())
                ids[v] += 1;
            else
                ids[v] = 1;
        }
        n = 0;
        for(map<int,int>::iterator i = ids.begin(); i != ids.end(); i++) uc[++n] = i->se;

        cout << "Case " << t++ << ":" << endl;
        solve();
    }
    return 0;
}


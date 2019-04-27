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
const int MAXN = 1002;

/*
dp[i][j] 已完成 i/n 和 j/s 还剩下的期望天数
dp[i][j]可以转化成以下四种状态:
    dp[i][j],发现一个bug属于已经有的i个分类和j个系统。概率为(i/n)*(j/s);
    dp[i][j+1],发现一个bug属于已有的分类，不属于已有的系统.概率为 (i/n)*(1-j/s);
    dp[i+1][j],发现一个bug属于已有的系统，不属于已有的分类,概率为 (1-i/n)*(j/s);
    dp[i+1][j+1],发现一个bug不属于已有的系统，不属于已有的分类,概率为 (1-i/n)*(1-j/s);

*/
double dp[MAXN][MAXN]; 

int main(){
    int n, s;
    cout.precision(12);
    while(cin >> n >> s){
        dp[n][s] = 0;  // 已经全部完成了
        per(i, 0, n+1) per(j, 0, s+1) if(i != n || j != s) {
            dp[i][j] = ( i*(s-j)*dp[i][j+1] + (n-i)*j*dp[i+1][j] + (n-i)*(s-j)*dp[i+1][j+1] + n*s) / (n*s - i*j);
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}


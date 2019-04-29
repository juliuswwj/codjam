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
int solve(){
    int N, K;
    cin >> N >> K;
    vector<int> C(N);
    vector<int> D(N);

    rep(i, 0, N)cin >> C[i];
    rep(i, 0, N)cin >> D[i];


    int c = 0;
    rep(i, 0, N) {
        int cm = 0;
        int dm = 0;
        rep(j, i, N){
            cm = max(cm, C[j]);
            dm = max(dm, D[j]);
            if(cm-K<=dm && cm+K>=dm) c += 1;
        }
    }
    return c;
}
int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": " << solve() << endl;
    }
    return 0;
}


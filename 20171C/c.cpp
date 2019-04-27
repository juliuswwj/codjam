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

double solve(){
    int N, K;
    double U;
    double P[51];
    cin >> N >> K >> U;
    rep(n, 0, N) cin >> P[n];
    sort(P, &P[N], [&](double a, double b){
        return a > b;
    });

    int base = 0;
    double c;
    while(base < K){
        c = 0;
        rep(i, base, K) c += P[i];
        c += U;
        c /= K-base;
        if(P[base] <= c) break;
        base += 1;
    }
    rep(i, base, K) {
        U -= c - P[i];
        P[i] = c;
    }
    if(base > 0) P[base-1] += U;
    return combprob(P, N, K);
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


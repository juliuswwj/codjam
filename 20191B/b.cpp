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
int main(){
    int T, W;
    cin >> T >> W;
    rep(z, 0, T) {
        ll t[6];
        cout << 56 << endl; cout.flush();
        cin >> t[0];
        if(t[0] < 0) break;
        cout << 224 << endl; cout.flush();
        cin >> t[1];

        int vv[6];
        vv[0] = t[0] >> 56;
        vv[1] = (t[0] >> 28) & 127;
        vv[2] = (t[0] >> 18) & 127;
        vv[3] = (t[1] >> 56) & 127;
        vv[4] = (t[1] >> 44) & 127;
        vv[5] = (t[1] >> 37) & 127;

        rep(i, 0, 6) cout << vv[i] << " ";
        cout << endl;
        cout.flush();

        cin >> t[0];
        if(t[0] < 0)break;
    }
    return 0;
}


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
const int MOD = 1000000007;
int solve(){
    int A, C;
    cin >> A >> C;

    // get common factors of A+1 A-1
    map<int, int> fs1, fs2;
    getfactor(A+1, fs1);
    getfactor(A-1, fs2);


    return 0;
}

int main(){
    int T;
    cin >> T;
    rep(t, 0, T){
        cout << "Case " << (t+1) << " " << solve() << endl;
    }
    return 0;
}


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
string code(int n) {
    std::bitset<8> v;
    while(v.count() != n) {
        v.flip(rand()%8);
    }
    return v.to_string();
}

int solve(){
    cout << code(4) << endl << flush;
    int n;
    while(true) {
        cin >> n;
        if(n == -1) exit(1);
        if(n == 0) break;
        cout << code(n) << endl << flush;
    }
    return 0;
}
int main(){
    int T;
    cin >> T;
    rep(t, 0, T) {
        //cerr << "case" << t << endl;
        solve();
    }
    return 0;
}


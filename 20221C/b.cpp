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
string l2a(ll n) {
    ostringstream os;
    os << n;
    return os.str();
}

string solve(){
    int n, k;
    cin >> n >> k;

    ll a = 0;
    ll s = 0;

    for(int i=0; i<n; i++) {
        int e;
        cin >> e;
        a += e;
        s += e*e;
    }
    if(n == 1 || a*a == s) return "0";
    if(a != 0 && (s-a*a)%(2*a) == 0) {
        return l2a((s-a*a)/(2*a));
    }
    if(k == 1 || (s-a*a)%2) return "IMPOSSIBLE";
    s = (s-a*a)/2;

    return l2a(1-a) + " " + l2a(s-a*(1-a));
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



#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define size(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// ------------------------

    
void resolve(){
    ll N, K, k, x0, x1;
    cin >> N >> K;
    
    map<ll, ll> ns;
    ns[N] = 1;
    k = 0;
    while(true){
        map<ll, ll>::reverse_iterator i = ns.rbegin();
        if(i == ns.rend())break;
        ll f = i->fi-1; 
        x0 = f / 2;
        x1 = f - x0;
        k += i->se;
        if(k >= K) break;
        if(ns.count(x0)) ns[x0] += i->se; else ns[x0] = i->se;
        if(ns.count(x1)) ns[x1] += i->se; else ns[x1] = i->se;
        ns.erase(i->fi);
    }
    
    cout << x1 << " " << x0;
}

int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": ";
        resolve();
        cout << endl;
    }
    return 0;
}
    

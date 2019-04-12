
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

bool pic(const pair<int, char>&a, const pair<int, char>&b){
    return a.fi > b.fi;
}

void resolve(){
    int N;
    vector< pair<int, char> > P;
    
    int cnt = 0;
    cin >> N;
    rep(n, 0, N) {
        int p;
        cin >> p;
        P.pb(mp(p, 'A' + n));
        cnt += p;
    }
    while(cnt > 3){
        sort(P.begin(), P.end(), pic);
        
        if(P[0].fi >= P[1].fi+2){
            P[0].fi -= 2;
            cout << P[0].se << P[0].se << " ";
        } else {
            P[0].fi -= 1;
            P[1].fi -= 1;
            cout << P[0].se << P[1].se << " ";
        }
        if(P[1].fi == 0) P.erase(P.begin()+1);
        if(P[0].fi == 0) P.erase(P.begin());
        cnt -= 2;
    }
    
    sort(P.begin(), P.end(), pic);
    if(cnt == 3){
        cout << P[0].se << " ";
        P[0].fi -= 1;
        if(P[0].fi == 0) P.erase(P.begin());
    }
    cout << P[0].se << P[1].se;
}
int main(){
    int T;
    cin >> T;
    
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": ";
        resolve();
        cout << endl;
    }
    return 0;
}
    

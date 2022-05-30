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

//+debug
template<class T>
ostream& operator<<(ostream& os, const vector<T>& vs) {
    os << "[";
    bool first = true;
    for(auto v: vs) {
        if(!first) os << ", ";
        first = false;
        os << v;
    }
    os << "]";
    return os;
}

template<class T, class V>
ostream& operator<<(ostream& os, const pair<T,V>& p) {
    os << p.first << ":" << p.second;
    return os;
}

template<class T, class V>
ostream& operator<<(ostream& os, const map<T,V>& vs) {
    os << "{";
    bool first = true;
    for(auto v: vs) {
        if(!first) os << ", ";
        first = false;
        os << v;
    }
    os << "}";
    return os;
}

//+main
struct PT {
    int x, y;
};

ll caldist(const PT& a, const PT& b) {
    return (ll)(a.x - b.x)*(a.x - b.x) + (ll)(a.y - b.y)*(a.y - b.y);
}

typedef pair<ll,int> pli;

void solve(){
    int N;
    cin >> N;
    vector<PT> children;
    vector<PT> sweet;
    for(int i=0; i<N; i++) {
        PT pt;
        cin >> pt.x >> pt.y;
        children.push_back(pt);
    }
    for(int i=0; i<N+1; i++) {
        PT pt;
        cin >> pt.x >> pt.y;
        sweet.push_back(pt);
    }

    vector<int> calls(N);
    for(int i=0; i<N; i++)calls[i] = i;

    vector<set<pli>> dists(N);
    for(int i=0; i<N; i++) {
        ll dist = caldist(children[i], sweet[0]);
        for(int j=0; j<N+1; j++) {
            ll d = caldist(children[i], sweet[j]);
            if(d <= dist) dists[i].insert({d, j});
        }
        //cout << "dist" << i << "=" << dists[i] << endl;
    }

    vector<bool> cvisit(N);
    vector<bool> svisit(N+1);



    vector<int> csweet(N);
    do {
        vector<bool> picked(N+1);

        int i = 0;
        for(; i<N; i++) {
            ll md = dists[i][0];
            int mj = 0;
            for(int j=1; j<N+1; j++) if(!picked[j] && md >= dists[i][j]) {
                md=dists[i][j];
                mj=j;
            }
            if(mj == 0) break;
            picked[mj] = true;
            csweet[i] = mj;
        }
        if(i == N) {
            cout << "POSSIBLE" << endl;
            for(i=0; i<N; i++) {
                cout << calls[i]+1 << " " << csweet[i]+1 << endl;
            }
            return;
        }
        //cout << "call" << calls << " f=" << i << endl;
    } while(next_permutation(calls.begin(), calls.end()));
    cout << "IMPOSSIBLE" << endl;
}
int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": ";
        solve();
    }
    return 0;
}


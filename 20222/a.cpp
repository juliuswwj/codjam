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
void solve(){
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> ans;
    int base = 0;
    while(N > 1) {
        if(N == 3) {
            if(K == 2) {
                ans.push_back({base+2, base+9});
                K = 0;
                break;
            }
            if(K == 4) {
                ans.push_back({base+4, base+9});
                K = 0;
                break;
            }
            if(K == 6) {
                ans.push_back({base+6, base+9});
                K = 0;
                break;
            }
            K -= 8;
            break;
        }
        if(N == 5) {
            if(K == 12) {
                ans.push_back({base+6, base+19});
                K = 0;
                break;
            }
            if(K == 14) {
                ans.push_back({base+10, base+21});
                K = 0;
                break;
            }
            if(K == 16) {
                ans.push_back({base+14, base+23});
                K = 0;
                break;
            }
        }

        int N41 = 4*(N-1);
        if(K >= 4*(N-1) + N-3){
            // 5=18 7=28 9=38
            base += N41;
            N -= 2;
            K -= N41;

        } else if(K <= 2 + (N-2)*(N-2)-1) {
            // 5=10 7=26 9=50
            ans.push_back({base+2, base+1+4*(N-1)});
            base += N41;
            N -= 2;
            K -= 2;

        } else {
            break;
        }
    }

    if(K != 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << ans.size() << endl;
    //int v = 1;
    //int c = 0;
    for(auto p=ans.begin(); p!=ans.end(); p++){
        //c += p->first-v + 1;
        //v = p->second;
        cout << p->first << " " << p->second << endl;
    }
    //c += N*N - v;
    //cout << K << "??" << c << endl;
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


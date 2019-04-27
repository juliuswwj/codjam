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
struct SEG {
    int b, e, v, s;
    bool operator<(const SEG& t){ return b < t.b; }
};

int solve(){
    vector<SEG> segs;
    int ac, aj;
    cin >> ac >> aj;
    if(ac == 0 && aj == 0)return 2;
    int cc = 0;
    int cj = 0;
    SEG seg;
    rep(i, 0, ac){
        cin >> seg.b >> seg.e;
        seg.v = 0;
        segs.pb(seg);
        cc += seg.e - seg.b;
    }
    rep(i, 0, aj){
        cin >> seg.b >> seg.e;
        seg.v = 1;
        segs.pb(seg);
        cj += seg.e - seg.b;
    }
    sort(all(segs));
    seg = segs[0];
    seg.b += 1440;
    segs.pb(seg); // create a loop

    cc = 720 - cc;
    cj = 720 - cj;

    while(cc > 0){
        vector<PII> chunk;
        rep(i, 0, segs.size()-1)if(segs[i].v == 0 && segs[i+1].v == 0 && segs[i+1].b > segs[i].e){
            chunk.pb( mp(segs[i+1].b - segs[i].e, i) );
        }
        if(chunk.size() == 0) break;
        sort(all(chunk));

        if(chunk[0].fi > cc)break;
        cc -= chunk[0].fi;
        int i = chunk[0].se;
        segs[i].e = segs[i+1].e;
        segs.erase(segs.begin() + i + 1);
    }
    while(cj > 0){
        vector<PII> chunk;
        rep(i, 0, segs.size()-1)if(segs[i].v == 1 && segs[i+1].v == 1 && segs[i+1].b > segs[i].e){
            chunk.pb( mp(segs[i+1].b - segs[i].e, i) );
        }
        if(chunk.size() == 0) break;
        sort(all(chunk));

        if(chunk[0].fi > cj)break;
        cj -= chunk[0].fi;
        int i = chunk[0].se;
        segs[i].e = segs[i+1].e;
        segs.erase(segs.begin() + i + 1);
    }
    int ans = 0;
    rep(i, 0, segs.size()-1){
        if(segs[i].v != segs[i+1].v) ans += 1;
        else if(segs[i].e != segs[i+1].b) ans += 2;
    }
    return ans;
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


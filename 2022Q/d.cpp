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
#include <bits/stdc++.h>
using namespace std;

long long run() {
    int n;
    cin >> n;
    vector<int> f(n+1);
    for(int i=1; i<=n; i++) cin >> f[i];

    // get prev & next
    vector<int> prev(n+1);
    vector<vector<int>*> next(n+1);
    for(int i=1; i<=n; i++) {
        cin >> prev[i];
        auto& np = next[prev[i]];
        if(!np)np=new vector<int>();
        np->push_back(i);
    }

    function<int(int, int&)> minChild = [&](int r, int& mi) {
        mi = r;
        if(!next[r]) return 0;
        int g = INT_MAX;
        for(auto i: *next[r]) {
            if(f[i] >= g) continue;
            //cout << "m " << r << " " << i << " " << g << " " << f[i] << endl;

            int t = 0;
            int c = max(f[i], minChild(i, t));
            if(c < g) {
                //cout << "mi->" << t << " c=" << c << endl;
                mi = t;
                g = c;
            }
        }
        return g;
    };

    long long ans = 0;
    for(int i=1; i<=n; i++) while(!next[i] && f[i]) {
        int r = i;
        while(f[prev[r]]) r = prev[r];
        int mi = r;
        ans += max(f[r], minChild(r, mi));
        //cout << "f i=" << i << " r=" << r << " mi=" << mi << " ans=" << ans << endl;
        while(f[mi]) {
            f[mi] = 0;
            mi = prev[mi];
        }
    }
    return ans;
}


int main(int argc, char* argv[]) {
    int T;
    cin >> T;

    for(int t=1; t<=T; t++) {
        long long ans = run();
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}


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
int solve(){
    string s;
    cin >> s;

    int n = s.length();
    int last = -1;
    vector<int> cnt(n+1);
    map<string, int> pos;
    for(int i=0; i<n; i++) {
        char ch = s[i];
        if(!strchr("aeiou", ch)) {
            cnt[i+1] = cnt[i];
            continue;
        }
        cnt[i+1] = cnt[i] + 1;
        if(last >= 0) {
            string w = s.substr(last, i+1-last);
            auto p = pos.find(w);
            if(p != pos.end()) {
                if(cnt[i]-cnt[p->second] > 1) return true;
            } else {
                pos[w] = i;
            }
        }
        last = i;
    }
    return false;
}
int main(){
    int T;
    cin >> T;
    cout.precision(12);
    const char* msgs[2] = {
        "Nothing.",
        "Spell!"
    };
    rep(t, 0, T) {
        cout << "Case #" << (t+1) << ": " << msgs[solve()] << endl;
    }
    return 0;
}



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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


struct TAG {
    TAG* parent;
    TAG* children[26];
    bool e;
    int  r;

    TAG(TAG* p) : parent(p), e(false), r(0) {
        memset(children, 0, sizeof(children));
    }

    ~TAG(){
        rep(i, 0, 26)if(children[i]){
            delete children[i];
        }
    }

    TAG* add(char ch){
        if(!children[ch - 'A']){
            children[ch - 'A'] = new TAG(this);
        }
        return children[ch - 'A'];
    }

    int cal(){
        rep(i, 0, 26) if(children[i]){
            r += children[i]->cal();
        }
        if(!parent) return r;
        if(e) r += 1;
        if(r > 1) r -= 2;
        return r;
    }
};

int solve(){
    int N;
    cin >> N;

    char msg[1024];
    TAG root(NULL);

    rep(n, 0, N){
        cin >> msg;

        int c = 0;
        TAG* p = &root;
        per(i, 0, strlen(msg)){
            p = p->add(msg[i]);
        }
        p->e = 1;
    }
    return N - root.cal();
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
    
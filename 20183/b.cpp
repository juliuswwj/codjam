
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
// ------------------------

int L;
int links[55][4];
int lcnt[55];
int uidx[55];
map<string, int> mytags;

void tag(int idx, string& str)
{
    vector<int> vcnt(L);
    function<void(int, int)> dfs = [&](int deep, int v){
        rep(i, 0, 4) {
            vcnt[ links[v][i] ]++;
            if(deep < 5) dfs(deep+1, links[v][i]);
        }
    };
    dfs(0, idx);
    sort(all(vcnt));

    string t;
    for(auto v : vcnt){
        char s[16];
        sprintf(s, ".%d", v);
        t += v;
    }
    str = t;
}

void generate()
{
    bool ok = false;
    int trycnt = 0;
    while(!ok){
        ok = true;
        trycnt += 1;

        vector<int> rlinks;
        rep(i, 0, L*4) rlinks.pb(i/4);
        random_shuffle(all(rlinks));
        memset(lcnt, 0, sizeof(lcnt));
        rep(i, 0, L*2){
            int a = rlinks[2*i];
            int b = rlinks[2*i+1];
            if(a == b){
                ok = false;
                break;
            }
            int c = 0;
            for(; c<lcnt[a]; c++)if(links[a][c] == b) break;
            if(c<lcnt[a]) {
                ok = false;
                break;
            }

            links[a][ lcnt[a]++ ] = b;
            links[b][ lcnt[b]++ ] = a;
        }
        if(!ok) continue;

        rep(i, 0, L){
            string str;
            tag(i, str);
            if(mytags.find(str) != mytags.end()){
                ok = false;
                break;
            }
            mytags[str] = i;
        }
    }
}

    
int main(){
    int T;
    cin >> T;
    cout.precision(12);
    rep(t, 0, T) {
        int U;
        cin >> L >> U;
        if(L < 0) break;

        generate();
        cout << L << endl;
        rep(l, 0, L) rep(n, 0, 4) if(links[l][n] > l){
            cout << l+1 << " " << links[l][n]+1 << endl;
        }
        cout.flush();

        cin >> U;
        if(U != L) break;

        memset(lcnt, 0, sizeof(lcnt));
        rep(l, 0, 2*L){
            int a, b;
            cin >> a >> b;
            a -= 1;
            b -= 1;
            links[a][ lcnt[a]++ ] = b;
            links[b][ lcnt[b]++ ] = a;
        }

        rep(i, 0, L){
            string str;
            tag(i, str);

            auto p = mytags.find(str);
            uidx[p->se] = i;
        }

        rep(i, 0, L){
            cout << uidx[i]+1 << " ";
        }
        cout << endl;
        cout.flush();
    }
    return 0;
}
    
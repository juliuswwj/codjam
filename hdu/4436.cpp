
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
    

template<char B='A', int BN=26>
struct SAM {
    struct node {
        int len;
        int next[BN];
        int rt;
        node() : len(0), rt(0){
            memset(next, 0, sizeof(next));
        }
    };
    int ss;
    vector<node> ns;  // valid [1 .. ss]
    SAM() : ss(0) {}
    const node& operator [](int idx){ return ns[idx]; }
    void add(const char* str){
        int ne;
        for(int last = 0; (ne = *str++) != 0; ){
            if(ns.size() < ss+4) ns.resize(ss + BN);
            ns[++ss].len = ns[last].len + 1;
            ne -= B;
            int x = last; last = ss;
            for (; x && !ns[x].next[ne]; x = ns[x].rt) ns[x].next[ne] = ss;
            int y = ns[x].next[ne];
            if (!y)
                ns[x].next[ne] = ss;
            else if (ns[x].len+1 == ns[y].len)
                ns[ss].rt = y;
            else {
                ns[++ss].len = ns[x].len + 1;
                memcpy(ns[ss].next, ns[y].next, sizeof(ns[y].next));
                ns[last].rt = ss, ns[ss].rt = ns[y].rt, ns[y].rt = ss;
                for (;x && ns[x].next[ne] == y; x = ns[x].rt) ns[x].next[ne] = ss;
                if (ns[x].next[ne] == y) ns[x].next[ne] = ss;
            }
        }
    }
    void count(vector<int>& cnt){
        vector<int> tail(ss+1);
        rep(i, 1, ss+1) tail[i] = i;
        int s = ss;
        vector<int> net(2*(ss+1));
        vector<int> sora(2*(ss+1));
        rep(i, 1, ss+1){
            int x = ns[i].rt;
            s++;
            net[tail[x]] = s;
            tail[x] = s;
            sora[s] = i;
        }
        cnt.resize(ss+1);
        function<void(int)> dfs = [&](int x){
            cnt[x] = (x == tail[x]) ? 1 : 0;
            for(int i=x; net[i] != 0; ){
                i = net[i];
                int ne = sora[i];
                if(ne == ns[x].rt) continue;
                dfs(ne);
                cnt[x] += cnt[ne];
            }
        };
        dfs(0);
    }
    void runs(const char* str, function<void(int s, int sum)> cb){
        int s = 0;
        int sum = 0;
        char ch;
        while( (ch = *(str++)) != 0 ){
            ch -= B;
            while(s && !ns[s].next[ch]){ s = ns[s].rt; sum = ns[s].len; }
	        if (ns[s].next[ch]) sum++, s = ns[s].next[ch];
            cb(s, sum);
        }
    }
    int run(const char* str){
        int s = 0;
        char ch;
        while( (ch = *(str++)) != 0 ){
            ch -= B;
	        s = ns[s].next[ch];
            if(s == 0) break;
        }
        return s;
    }
};


int main2(){
    const int MOD = 2012;
    int N;
    while( cin >> N ){
        string str;
        SAM<'0', 10> sam;

        rep(n, 0, N){
            cin >> str;
            sam.add(str.c_str());
        }

        vector<int> u(sam.ss+1);
        rep(i, 1, sam.ss+1) u[i] = i;
        sort(u.begin()+1, u.end(), [&](int a, int b){
            return sam[a].len < sam[b].len;
        });
        vector<int> f(sam.ss+1);
        vector<int> g(sam.ss+1);
        rep(i, 1, 10) if(sam[0].next[i]){
            f[ sam[0].next[i] ] = i;
            g[ sam[0].next[i] ] = 1;
        }
        int ans = 0;
        rep(i, 1, sam.ss+1){
            int ne = u[i];
            ans = (ans + f[ne]) % MOD;
            rep(j, 0, 10){
                int na = sam[ne].next[j];
                if(na) {
                    f[na] = (f[na] + f[ne]*10 + g[ne]*j) % MOD;
                    g[na] = (g[na] + g[ne]) % MOD;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
    

int main(){
    SAM<'0', 10> sam;

    sam.add("0912345678913579191");

    rep(i, 0, sam.ss+1){
        fprintf(stderr, "ns[%d] = {%d, %d, [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d]}\n", i, sam[i].len, sam[i].rt, 
            sam[i].next[0], sam[i].next[1], sam[i].next[2], sam[i].next[3], sam[i].next[4],
            sam[i].next[5], sam[i].next[6], sam[i].next[7], sam[i].next[8], sam[i].next[9]
            )
        ;
    }

    vector<int> cnt;
    sam.count(cnt);
    int t = sam.run("917");

    cout << t << " " << cnt[t] << endl;
    return 0;
}

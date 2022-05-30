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
string solve(){
    int n;
    cin >> n;


    vector<string> ss;
    auto merge = [&](const string& str) {
        for(auto& s : ss) {
            if(s[0] == str[str.length()-1]) {
                s = str + s;
                return;
            }
            if(s[s.length()-1] == str[0]) {
                s = s + str;
                return;
            }
        }
        ss.push_back(str);
    };

    vector<string> nss;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        if(str[0] == str[str.length()-1])
            merge(str); // merge all identical strings
        else
            nss.push_back(str);
    }
    nss.swap(ss);
    for(auto& s: nss) merge(s);

    while(true) {
        nss.clear();
        nss.swap(ss);
        for(auto& s: nss) merge(s);
        if(ss.size() == nss.size()) break;
    }

    string ans;
    for(auto& s: ss) ans += s;

    vector<int> pos(26, -1);
    for(int i=0; i<ans.size(); i++) {
        auto& p = pos[ans[i]-'A'];
        if(p >= 0 && p != i-1) return "IMPOSSIBLE";
        p = i;
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


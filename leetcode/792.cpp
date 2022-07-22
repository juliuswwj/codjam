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
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> pos[26];
        for(int i=0; i<s.size(); i++) {
            pos[s[i]-'a'].push_back(i);
        }
        for(int i=0; i<26; i++) {
            cout << i << " => " << pos[i] << endl;
        }
        
        int ans = 0;
        for(auto& w: words) {
            int z = -1;
            int f = 1;

            cout << w << endl;
            
            for(auto ch: w) {
                auto& t = pos[ch-'a'];
                auto p = upper_bound(t.begin(), t.end(), z);
                cout << z << " " << t << " => " << p - t.begin() << endl;
                if(p == t.end()) {
                    f = 0;
                    break;
                }
                z = *p;
            }
            
            if(f) ans++;
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<string> ts = {"bt"};
    s.numMatchingSubseq("btovxbkumc", ts);
    return 0;
}


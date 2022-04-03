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
    const long long M = 72057594037927931L; // the largest prime < 2^56
    long long sumScores(string s) {
        int n = s.length();
        long long prod = 1;
        long long h1 = 0;
        long long h2 = 0;
        long long ans = 0;
        for(int i=0; i<n; i++) {
            int j = n-1-i;
            h1 = (h1*26+s[i]-'a')%M;
            h2 = (h2 + prod*(s[j]-'a'))%M;
            prod = (prod*26)%M;
            //cout << i << " h=" << h1 << " " << h2 << endl;
            if(h1 == h2) {
                ans += i+1;
            } else {
                int c = 0;
                while(s[c] == s[j+c] && c<i) c++;
                ans += c;
            }
        }
        return ans;
    }
};

int main(int argc, char*argv[]) {
    Solution ss;
    string s;
    while(cin >> s) {
        long long ans = ss.sumScores(s);
        cout << s << " = " << ans << endl;
    }
    return 0;
}


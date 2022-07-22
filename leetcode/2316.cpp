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
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> d(n);
        for(int i=0; i<n; i++)d[i] = i;
        
        function<int(int)> find = [&](int i) {
            return d[i] == i ? i : (d[i] = find(d[i]));
        };
        
        for(auto& e: edges) {
            d[find(e[0])] = find(e[1]);
        }

        map<int, int> c;
        for(int i=0; i<n; i++) {
            c[find(i)]++;
        }
        cout << c << endl;
        
        
        long long ans = 0;
        for(auto p: c) {
            ans += (long long)(p.second) * (n-p.second);
        }
        return ans/2;
    }
};

int main(){
    vector<vector<int>> test = {{5,0},{1,0},{10,7},{9,8},{7,2},{1,3},{0,2},{8,5},{4,6},{4,2}};

    Solution s;
    s.countPairs(11, test);
}


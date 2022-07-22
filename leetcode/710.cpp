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

struct SEG {
    int base;
    int from;
    int to;
    
    bool operator <(const SEG& b) {
        return base < b.base;
    }
};
ostream& operator<<(ostream& os, const SEG& seg) {
    os << "{" << seg.base << "," << seg.from << "," << seg.to << "}";
    return os;
}

class Solution {
public:
    vector<SEG> segs;
    int cnt;
    Solution(int n, vector<int>& b) {
        sort(b.begin(), b.end());
        
        cnt = 0;
        
        SEG seg;
        seg.from = 0;
        for(auto v: b) {
            if(seg.from < v) {
                seg.base = cnt;
                seg.to = v-1;
                segs.push_back(seg);
                cnt += v-seg.from;
            }
            seg.from = v+1;
        }
        if(seg.from < n) {
            seg.base = cnt;
            seg.to = n-1;
            segs.push_back(seg);
            cnt += n-seg.from;
        }
    }
    
    int pick() {
        SEG seg;
        
        seg.base = rand() % cnt;
        if(cnt > RAND_MAX) {
            seg.base = (seg.base ^ ((rand()%32768)<<16)) % cnt;
        }

        cout << segs << endl;
        
        auto p = lower_bound(segs.begin(), segs.end(), seg);
        if(p == segs.end() || p->base > seg.base) p--;
        cout << seg.base << ".." << p->base << endl;
        return seg.base-p->base+p->from;
    }
};

int main() {
    vector<int> test={2,3,5};
    Solution s(7, test);
    cout << s.pick() << endl;
    return 0;
}


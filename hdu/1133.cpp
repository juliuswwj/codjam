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

//+bignum
template<int CNTN=500>
struct BigNum {
    const int MAXN = 9999;
    const int DLEN = 4;

	int a[CNTN];    //可以控制大数的位数 
	int len;       //大数长度
	BigNum(): len(0) { memset(a,0,sizeof(a)); }   //构造函数
	BigNum(int b){ //将一个int类型的变量转化为大数
        len = 0;
        memset(a, 0, sizeof(a));
        while(b > MAXN) {
            a[len++] = b % (MAXN + 1);
            b = b / (MAXN + 1);
        }
        if(b) a[len++] = b;
    }
	BigNum(const char* str){     //将一个字符串类型的变量转化为大数
        set(str);
    }
	BigNum(const BigNum & t): len(t.len) {  //拷贝构造函数
        memcpy(a, t.a, sizeof(a));
    }
	BigNum &operator=(const BigNum & t){   //重载赋值运算符，大数之间进行赋值运算
        len = t.len;
        memcpy(a, t.a, sizeof(a));
        return *this;
    }

    BigNum& set(const char* str) {
        int t,k,index,l,i;
        memset(a, 0, sizeof(a));
        l = min(CNTN*DLEN-1, (int)strlen(str));
        len = l / DLEN;
        if(l % DLEN) len++;
        index=0;
        for(i=l-1;i>=0;i-=DLEN){
            t=0;
            k=i-DLEN+1;
            if(k<0) k=0;
            for(int j=k;j<=i;j++) t=t*10+str[j]-'0';
            a[index++]=t;
        }
        return *this;
    }

	BigNum operator+(const BigNum & t) const {   //重载加法运算符，两个大数之间的相加运算 
        BigNum r(*this);
        int mlen = min(CNTN-1, max(len, t.len));
        rep(i, 0, mlen){
            r.a[i] += t.a[i];
            if(r.a[i] > MAXN){
                r.a[i] -= MAXN;
                r.a[i+1] += 1;
            }
        }
        if(r.a[mlen]) mlen += 1;
        r.len = mlen;
        return r;
    }
	BigNum operator-(const BigNum& T) const {   //重载减法运算符，两个大数之间的相减运算 
        int i,j,big;
        bool flag;
        BigNum t1,t2;
        if(*this>T) {
            t1=*this;
            t2=T;
            flag=0;
        } else {
            t1=T;
            t2=*this;
            flag=1;
        }
        big=t1.len;
        for(i = 0 ; i < big ; i++) {
            if(t1.a[i] < t2.a[i]){ 
                j = i + 1; 
                while(t1.a[j] == 0)
                    j++; 
                t1.a[j--]--; 
                while(j > i)
                    t1.a[j--] += MAXN;
                t1.a[i] += MAXN + 1 - t2.a[i]; 
            } 
            else
                t1.a[i] -= t2.a[i];
        }
        t1.len = big;
        while(t1.a[len - 1] == 0 && t1.len > 1) {
            t1.len--; 
            big--;
        }
        if(flag) t1.a[big-1]=0-t1.a[big-1];
        return t1; 
    }
	BigNum operator/(const int& b) const {    //重载除法运算符，大数对一个整数进行相除运算
        BigNum ret; 
        int i,down = 0;   
        for(i = len - 1 ; i >= 0 ; i--)
        { 
            ret.a[i] = (a[i] + down * (MAXN + 1)) / b; 
            down = a[i] + down * (MAXN + 1) - ret.a[i] * b; 
        } 
        ret.len = len; 
        while(ret.a[ret.len - 1] == 0 && ret.len > 1)
            ret.len--; 
        return ret; 
    }
 
	int    operator%(int b) const {    //大数对一个int类型的变量进行取模运算    
        int d=0;
        for (int i = len-1; i>=0; i--) {
            d = ((d * (MAXN+1))% b + a[i]) % b;
        }
        return d;
    }

	BigNum operator*(const BigNum& T) const {   //重载乘法运算符，两个大数之间的相乘运算 
        BigNum ret; 
        int i, j;
        for(i = 0 ; i < len ; i++){ 
            int up = 0;
            for(j = 0; j < T.len; j++){ 
                int temp = a[i] * T.a[j] + ret.a[i + j] + up; 
                if(temp > MAXN) { 
                    int temp1 = temp - temp / (MAXN + 1) * (MAXN + 1); 
                    up = temp / (MAXN + 1); 
                    ret.a[i + j] = temp1;
                } else { 
                    up = 0; 
                    ret.a[i + j] = temp; 
                } 
            }
            if(up != 0) ret.a[i + j] = up; 
        } 
        ret.len = i + j; 
        while(ret.len && ret.a[ret.len-1] == 0) ret.len--; 
        return ret; 
    }

	BigNum pow(int n) const {    //大数的n次方运算
        if(n <= 0)return 1;
        if(n == 1)return *this;
        BigNum t,ret(1);
        int m=n;
        while(m>1) {
            t=*this;
            int i;
            for(i=1;i<<1<=m;i<<=1)t=t*t;
            m-=i;
            ret=ret*t;
            if(m==1)ret=ret*(*this);
        }
        return ret;
    }

    int compare(const BigNum & T) const { //大数和另一个大数的大小比较
        if(len < T.len) return -1;
        if(len > T.len) return 1;
        int idx = len - 1;
        while(idx >= 0 && a[idx] == T.a[idx]) idx--;
        if(idx < 0) return 0;
        return a[idx]<T.a[idx] ? -1 : 1;
    }

	bool   operator>(const BigNum & T) const { 
        return compare(T) > 0;
    }
	bool   operator<(const BigNum & T) const { 
        return compare(T) < 0;
    }
	bool   operator>=(const BigNum & T) const { 
        return compare(T) >= 0;
    }
	bool   operator<=(const BigNum & T) const { 
        return compare(T) <= 0;
    }
	bool   operator==(const BigNum & T) const { 
        return compare(T) == 0;
    }

	friend istream& operator>>(istream& is,  BigNum& t) {   //重载输入运算符
        char str[CNTN*4+1];
        is >> str;
        t.set(str);
        return is;
    }

	friend ostream& operator<<(ostream& out,  BigNum& t){   //重载输出运算符
        if(t.len == 0) {
            out << '0';
            return out;
        }
        out << t.a[t.len-1];
        if(t.len < 2) return out;
        per(i, 0, t.len-1) out << setw(4) << setfill('0') << t.a[i];
        return out;
    }
};

//+main
int f[201][101];
int main(){
    int n=100;
    int m=100;

    f[0][0]=1;
    rep(i, 1, n+m+1) per(j, 1, min(i,n)+1) {
        int k = i - j;
        if(k > j) break;
        f[i][j] = f[i-1][j] + f[i-1][j-1];
    }

    while(cin >> n >> m){
        if(n == 0 && m == 0)break;

        BigNum<> ans(f[n+m][n]);
        rep(i, 2, n+1) ans = ans * i; // n!
        rep(i, 2, m+1) ans = ans * i; // m!
        cout << ans << endl;
    }
    return 0;
}


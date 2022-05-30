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
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

void solve(){
	int n;
	scanf("%d",&n);
	string S="0";
	int ret=0;
	for(int i=0;i<n;i++){
		int X;
		scanf("%d",&X);
		string T="";
		while(X>0){
			T+='0'+(X%10);
			X/=10;
		}
		reverse(T.begin(),T.end());
		string T2=T;
		while(S.size()>T.size()){
			T+='0';
			T2+='9';
			ret++;
		}
		if(S.size()==T.size()){
			if(T<=S&&S<T2){
				T=S;
				for(int j=(int) S.size()-1;j>=0;j--){
					if(T[j]!='9'){
						T[j]++;
						break;
					}
					T[j]='0';
				}
			} else if(T2<=S){
				ret++;
				T+='0';
			}
		}
		S=T;
        printf("%s ", S.c_str());
	}
	printf("%d\n",ret);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d: ",t);
		solve();
	}
}


//+base
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//+main

int main(){
  int T, i0;
  scanf("%d", &T);
  for(i0 = 1; i0 <= T; i0++) {
    int n, k;
    int i, j;
    double count, sum;
    count = sum = 0.;
    scanf("%d%d", &n, &k);
    scanf("%*d%*d");
    for(i = 0; i < k/2; i++) {
      int a, b;
      int da, db;
      a = rand()%n;
      printf("T %d\n", a+1);
      fflush(stdout);
      scanf("%*d%d", &da);
      printf("W\n");
      fflush(stdout);
      scanf("%*d%d", &db);
      double f = 1. / (1./da + 1./db);
      // count += f / da + f / db;
      count += 1;
      sum += f;
    }
    ll ans = round(sum / count * n);

    printf("E %lld\n", ans);
    fflush(stdout);
  }
  return 0;
}


//Bottom Up approach
#include <bits/stdc++.h>

using namespace std;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

const int INF = 100000;

int bottom_up_rod_cutting(int c[], int n) {
  int r[n+1];
  r[0] = 0;
  int i,j;

  for(j=1; j<=n; j++) {
    int maximum_revenue = -1*INF;
    for(i=1; i<=j; i++) {
      maximum_revenue = MAX(maximum_revenue, c[i] + r[j-i]);
    }
    r[j] = maximum_revenue;
  }
  return r[n];
}

int main() {

  int c[] = {0, 10, 24, 30, 40, 45};
   
  printf("%d\n", bottom_up_rod_cutting(c, 5));
  
  return 0;
}
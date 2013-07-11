#include <cstdio>

int max(int a, int b)
{
  return a > b ? a : b;
}

int LCS(int a[], int m, int b[], int n)
{
  if (m == -1 || n == -1)
    return 0;
  else
    if (a[m] == b[n]) // a != b && 0 != 'o'
      return 1 + LCS(a,m-1,b,n-1);
    else
      return max(LCS(a,m-1,b,n),LCS(a,m,b,n-1));
}

int main()
{
  int a[] = {1,2,3,22,23,4,5};
  int m = 6; // int m = sizeof(a)/sizeof(a[0]) - 1;
  int b[] = {1,3,2};
  int n = 2; // int n = sizeof(b)/sizeof(b[0]) - 1;
  printf("%d",LCS(a,m,b,n));
  return 0;
}

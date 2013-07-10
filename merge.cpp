#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <climits>
using namespace std;
int contor;
void interclas(int a[],int b[],int c[],int m,int n)
{
  int i = 1;
  int j = 1;
  int k = 1;
  while (i<=m && j<=n)
  {
    if (a[i] < b[j])
    {
      c[k++] = a[i];
      i++;
    }
    else
    {
      c[k++] = b[j];
      j++;
    }
  }
  while (i<=m)
  {
    c[k++] = a[i++];
  }
  while (j<=n)
  {
    c[k++] = b[j++];
  }
}

void merge(int v[],int p, int q, int r)
{
  int L[100];
  int R[100];
  int m = 0;
  int n = 0;
  for (int i=p;i<=q;i++)
    L[++m] = v[i];
  for (int i=q+1;i<=r;i++)
    R[++n] = v[i];
  int c[200];
  interclas(L,R,c,m,n);
  int j = 1;
  for (int i = p;i<=r;i++)
    v[i] = c[j++];
}

void merge_sort(int v[],int p, int r)
{
  if (p < r)
  {
    int q = (p + r)/2;
    merge_sort(v,p,q);
    merge_sort(v,q+1,r);
    merge(v,p,q,r);
  }
}

int main()
{
  int v[]={0,10,9,8,7,6,5,4,3,2,1};
  merge_sort(v,1,10);
  for (int i = 1;i<=10;i++)
    cout<<v[i]<<" ";
  /*int a[] = {0,1,3,5,7};
  int b[] = {0,2,4,6,8,10,12,14,16};
  int c[100];
  interclas(a,b,c,4,8);
  for(int i = 1;i<=12;i++)
*/
  return 0;
}

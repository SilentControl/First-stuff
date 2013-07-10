#include <cstdio>
using namespace std;

int partition(int v[], int st, int dr)
{
  int i = st - 1;
  int j = 0;
  int man = 0;
  for (j=st;j<dr;j++)
    if (v[j] < v[dr])
    {
      i++;
      man = v[i];
      v[i] = v[j];
      v[j] = man;
    }
  i++;
  man = v[i];
  v[i] = v[dr];
  v[dr] = man;
  return i;
}

void qsort(int v[],int st, int dr)
{
  if (st < dr)
  {
    int m = partition(v,st,dr);
    qsort(v,st,m-1);
    qsort(v,m+1,dr);
  }
}

int main()
{
  int v[] = {0,10,9,8,7,3,6,5,4,2,1};
  qsort(v,1,10);
  for (int i = 1;i<=10;i++)
    printf("%d ",v[i]);
  return 0;
}

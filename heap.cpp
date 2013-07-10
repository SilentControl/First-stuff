#include <stdio.h>
#include <stdlib.h>

struct heap
{
  int* v;
  int n;
  int cap;
};

void init_heap(heap& h)
{
  h.n = 0;
  h.cap = 50;
  h.v = (int*)malloc(h.cap*sizeof(int));
}

int peek(heap h)
{
  if (h.n == 0)
    return -1;
  else
    return h.v[1];
}

void insert(heap& h,int x)
{
  if (h.n == h.cap)
  {
    h.cap = 2*h.cap;
    h.v = (int*)realloc(h.v,h.cap*sizeof(int));
  }
  (h.n)++;
  int i = h.n;
  h.v[h.n] = x;
  while (i/2 > 0 && h.v[i] > h.v[i/2])
  {
    int aux = h.v[i];
    h.v[i] = h.v[i/2];
    h.v[i/2] = aux;
    i = i/2;
  }
}

void swap(heap &h,int i,int j)
{
  int aux = h.v[i];
  h.v[i] = h.v[j];
  h.v[j] = aux;
}

int poz_max(heap &h,int i)
{
  int m = 0;
  if (2*i <= h.n && (2*i+1) >h.n)
    if (h.v[2*i] > h.v[i])
      return 2*i;
    else
      return i;

  if ((2*i+1) <= h.n && 2*i > h.n)
    if (h.v[2*i+1] > h.v[i])
      return (2*i+1);
    else
      return i;

  if ((2*i+1) <= h.n && 2*i <= h.n)
  {
    if (h.v[2*i+1] > h.v[2*i])
      m = 2*i+1;
    else
      m = 2*i;
    if (h.v[i] > h.v[m])
      m = i;
    return m;
  }
  return i;
}

void heapify(heap &h,int i)
{
  int m = 0;
  m = poz_max(h,i);
  if (i == m)
    return;
  else
  {
    swap(h,i,m);
    heapify(h,m);
  }
}

int remove_max(heap &h)
{
  int x = h.v[1];
  h.v[1] = h.v[h.n];
  (h.n)--;
  heapify(h,1);
  return x;
}

heap max_heapify(int* v,int n)
{
  heap h;
  init_heap(h);
  h.n = n;
  for (int i = 1;i<=n;i++)
    h.v[i] = v[i];
  for (int i=n/2;i>=1;i--)
  {
    heapify(h,i);
  }
  return h;
}

int* heapsort(int* v,int n)
{
  int* rez = (int*)malloc((n+1)*sizeof(int));
  heap h = max_heapify(v,n);
  for (int i=1;i<=n;i++)
    rez[i] = remove_max(h);
  return rez;
}
int main()
{
  heap h;
  init_heap(h);
  for (int i = 1;i<=10;i++)
    insert(h,i);
  //heapify(h,2);
  for (int i = 1;i<=h.n;i++)
    printf("%d ",h.v[i]);
  printf("\n%d\n",remove_max(h));
  for (int i = 1;i<=h.n;i++)
    printf("%d ",h.v[i]);
  printf("\n");
  int vect[]={0,1,2,3,4,5,6,7,8,9};
  int* rez = heapsort(vect,9);
  for (int i=1;i<=9;i++)
    printf("%d ",rez[i]);
  return 0;
}

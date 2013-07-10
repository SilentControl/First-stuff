#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector <int> v;
  int k = 0;
  for(int i=10;i>=1;i--)
    v.push_back(i);
  int i,j,val;
  for(j=1;j<v.size();j++)
  {
    val = v[j];
    i = j - 1;
    while (i > -1 && val < v[i])
    {
      v[i+1] = v[i];
      v[i] = val;
      i--;
    }
    v[i+1] = val;
  }

  for (int i=0;i<v.size();i++)
  cout<<v[i]<<" ";
  return 0;
}

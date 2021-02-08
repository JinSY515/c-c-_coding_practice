#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
  int arr[10001];
  int i,n;
  scanf("%d",&n);
  vector<int> v(n);
  for(i=0; i<n; i++){
    scanf("%d",&v[i]);
  }
  if(next_permutation(v.begin(),v.end())){
    for(int i=0; i<n; i++){
      printf("%d ",v[i]);
    }
  }
  else printf("-1");
  return 0;
}
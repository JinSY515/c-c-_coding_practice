#include <iostream>
#include <vector>
using namespace std;

int main(){
  long long int fib[46]={1,2}; //45번째는 int형으로 안되기 때문에 long long으로 
  int t;
  scanf("%d",&t);
  int i;
  for(i=2; i<46; i++){
    fib[i]=fib[i-1]+fib[i-2];
  }

  while(t--){
    int n;
    scanf("%d",&n);
    vector <int> v;
    for(int j=45; j>=0; j--){
      if(fib[j]<=n){
        n-=fib[j];
        v.push_back(fib[j]);
      }
    }
    for(int j=v.size()-1; j>=0; j--){
      printf("%d ",v[j]);
    }
    printf("\n");
  }
  return 0;
}
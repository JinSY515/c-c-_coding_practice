#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void){
  int n;
  scanf("%d",&n);
  priority_queue<int,vector<int>,less<int>> pq;
  for(int i=0; i<n; i++){
    int a;
    scanf("%d",&a);
    if(a!=0){
      pq.push(a);
    }
    else{
      if(pq.empty()) printf("0\n");
      else{
        printf("%d\n",pq.top());
        pq.pop();
      }
    }
  }
  return 0;
}
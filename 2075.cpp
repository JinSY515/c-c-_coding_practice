#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main(void){
  int n;
  scanf("%d",&n);

  priority_queue<int,vector<int>,greater<int>> q;
  int i,j;

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      int x;
      scanf("%d",&x);

      if(q.size()<n) q.push(x); //큐에 원소가 n개 이하로 있을 때, 큐에 푸시
      else if(x> q.top()){ 
        q.push(x);
        q.pop();
      }
      
    }
  }
  printf("%d",q.top());

  return 0;
}
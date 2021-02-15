#include <iostream>
#include <queue>
using namespace std;

int main(void){
  int n,k;
  cin >> n >> k;
  queue <int> q;
  for(int i=1; i<=n; i++){
    q.push(i);
  }
  printf("<");
  while(!q.empty()){
    if(q.size()==1) break;
    for(int i=1; i<k; i++){
      q.push(q.front());
      q.pop();
    }
    printf("%d, ",q.front());
    q.pop();
  }
  printf("%d>",q.front());

  return 0;
}
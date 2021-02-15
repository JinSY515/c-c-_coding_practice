#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,less<int>> max_pq;
priority_queue<int,vector<int>,greater<int>> min_pq;
int main(void){
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++){
    int a;
    scanf("%d",&a);
    if(max_pq.empty() && min_pq.empty()){
      max_pq.push(a);
      printf("%d\n",max_pq.top());
      continue;
    }

    if(i%2==0){
      min_pq.push(a);  //짝수번째라면
    }
    else{
      max_pq.push(a); //홀수번째
    }
    int TopOfMin=min_pq.top();
    int TopOfMax=max_pq.top();

    if(TopOfMin<TopOfMax){
      max_pq.pop();  //min_pq의 탑에 있는 수가 max_pq의 탑에 있는 수보다 작다면 swap
      min_pq.pop();
      max_pq.push(TopOfMin);
      min_pq.push(TopOfMax);
    }
    printf("%d\n",max_pq.top());
  }
  return 0;
}
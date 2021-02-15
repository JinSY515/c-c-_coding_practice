#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
  int n;
  scanf("%d",&n);
  priority_queue<int, vector<int>, less<int>> pq_negative;
  priority_queue<int, vector<int>, greater<int>> pq_positive;

  for(int i=0; i<n; i++){
    int a;
    scanf("%d",&a);
    if(a<0){
      pq_negative.push(a);
    }
    else if(a>0){
      pq_positive.push(a);
    }
    else{
      if(pq_positive.empty()&&!pq_negative.empty()){
        printf("%d\n",pq_negative.top());
        pq_negative.pop();
      }
      else if(!pq_positive.empty()&& pq_negative.empty()){
        printf("%d\n",pq_positive.top());
        pq_positive.pop();
      }
      else if(pq_positive.empty() && pq_negative.empty()){
        printf("0\n");
      }
      else{
        if(pq_negative.top()*(-1)<=pq_positive.top()){
          printf("%d\n",pq_negative.top());
          pq_negative.pop();
        }
        else{
          printf("%d\n",pq_positive.top());
          pq_positive.pop();
        }
      }
      
    }
  }
  return 0;
}
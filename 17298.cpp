#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int a[1000001];
int ans[1000001];
int main(void){
  int n;
  scanf("%d",&n);
  int i;
  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }
  stack<int> s;
  
  for(i=n-1; i>=0; i--){
    while(!s.empty() && s.top()<=a[i]) s.pop(); 

    if(s.empty()) ans[i]=-1; //비어있으면 -1
    else ans[i]=s.top(); //안 비어있으면, 스택의 탑

    s.push(a[i]);
  }

  for(i=0; i<n; i++){
    printf("%d ",ans[i]);
  }

  return 0;
}
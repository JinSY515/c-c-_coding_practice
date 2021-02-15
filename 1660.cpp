#include <iostream>
#include <cstring>

#define MAX 121
int dp[MAX];
int pyramid[300001];

int min(int a, int b){
  if(a<b) return a;
  else return b;
}

int main(void){
  int n;
  scanf("%d",&n);
  dp[0]=0;
  pyramid[0]=0;
  for(int i=1; i<=n; i++){
    pyramid[i]=i;
  }
  for(int i=1; i<=MAX; i++){
    dp[i]=i*(i+1)/2;
  }
  for(int i=1; i<=MAX; i++){
    dp[i]+=dp[i-1];   //사면체를 만들기 위해 필요한 대포알 개수 
    if(dp[i]>n) break;
    pyramid[dp[i]]=1;  //dp[i]번째에 해당하는 수는 이를 만들기 위해 1개만 필요함.
  }
  
  for(int i=1; i<=n; i++){
    for(int j=MAX; j>=1; j--){
      if(dp[j]>i) continue;  //dp에 저장되어 있는 수 중에 i보다 작은 최대의 수 찾기
      pyramid[i]=min(pyramid[i-dp[j]]+pyramid[dp[j]],pyramid[i]);  
    }
  }
  printf("%d",pyramid[n]);
  return 0;
}
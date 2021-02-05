#include <iostream>

int dp[1001];
int card[1001];

int min(int a, int b){
  if(a<b) return a;
  else return b;
}

int main(void){
  int n;
  scanf("%d",&n);
  int i,j;
  
  for(i=1; i<=n; i++){
    scanf("%d",&card[i]);
    dp[i]=card[i];
    //11052번이랑 다르게, dp에 카드 값을 설정해주어야 함.
  }
  dp[0]=card[0]=0;
  for(i=2; i<=n; i++){
    for(j=1; j<=i; j++){
      dp[i]=min(dp[i],dp[i-j]+card[j]);
      //최솟값 구하는 것이므로 min함수 사용.
    }
  }
  
  printf("%d\n",dp[n]);

  return 0;
}
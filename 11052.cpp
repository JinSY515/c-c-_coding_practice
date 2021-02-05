#include <iostream>

int dp[1001]; 
int card[1001]; //카드

int max(int a, int b){
  if(a>b) return a;
  else return b;
}
int main(void){

  int n;
  scanf("%d",&n);
  int i,j;
  dp[0]=card[0]=0; 

  for(i=1; i<=n; i++){
    scanf("%d",&card[i]);
  }

  for(i=1; i<=n; i++){
    for(j=1; j<=i; j++){
      dp[i]=max(dp[i],dp[i-j]+card[j]); 
      //n번째 dp의 값과 m번째 카드의 합에서, n+m=i가 되어야 함
      //최댓값 구하는 것이기에 max함수 사용
    }
  }

  printf("%d",dp[n]);
  return 0;
}
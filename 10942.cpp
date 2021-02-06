#include <iostream>

int arr[2001];
int dp[2001][2001];
int n;
void ispalin(){
  int i,j;

  for(i=1; i<=n; i++){
    dp[i][i]=1; //i번째에서 i번째까지는 모두 palin
  }
  for(i=1; i<n; i++){
    if(arr[i]==arr[i+1]) dp[i][i+1]=1; //2자리에 대해서는 두 자리가 서로 같으면 palin
  }
  for(int len=3; len<=n; len++){ //3자리 이상~n자리까지
    for(int start=1; start<=n-len+1; start++){ //시작하는 수 
      int end=start+len-1; //끝나는 수
      if(arr[start]==arr[end]&& dp[start+1][end-1]==1){  //양끝 수가 같고 그 사이 수들이 palin이면
        dp[start][end]=1; //palin이다.
      }
    }
  }
}
int main(void){

  scanf("%d",&n);
  int i;
  for(i=1; i<=n; i++){
    scanf("%d",&arr[i]);
  }
  ispalin();
  int m;
  int a,b;

  scanf("%d",&m);
  for(i=0; i<m; i++){
    scanf("%d %d",&a,&b);
    printf("%d\n",dp[a][b]);
  }
  return 0;
}
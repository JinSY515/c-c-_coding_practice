#include <iostream>
#include <cstring>
#define MAX 1000
using namespace std;

long long dp[MAX][MAX];
int main(void){
  string s;
  cin >> s;
  int len=s.size();
  for(int i=0; i<len; i++){
    dp[i][i]=1;  //한 글자짜린 모두 팰린드롬
    if(s[i]==s[i+1]) dp[i][i+1]=3; //aa 같은 경우, 'a', 'a', 'aa' 3가지경우
    else dp[i][i+1]=2; //ab 같은 경우, 'a', 'b' 2가지 경우
  }

  for(int i=2; i<len; i++){  //인덱스 간 거리
    for(int left=0; left<len; left++){ //left를 기준으로
      int right=left+i;
      if(right>len) break;  
      dp[left][right]=dp[left][right-1]+dp[left+1][right]-dp[left+1][right-1];
      //겹치는 부분 한 번 빼주기
      if(s[left]==s[right]) dp[left][right]+=dp[left+1][right-1]+1; 
      //만약에 양 끝이 같으면 

    }
  }
  printf("%lld",dp[0][len-1]);
  return 0;

}
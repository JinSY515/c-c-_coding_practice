#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int check[9]={0};
int n;
vector<int> v;
void print(){  //프린트 함수
  for(int i=0; i<n; i++){
    printf("%d ",v[i]);  
  }
  printf("\n");
}
void permutation(){ //순열
  if(v.size()==n){
    print();
  }
  else{
    for(int i=1; i<=n; i++){ 
      if(check[i]) continue;
      check[i]=1;
      v.push_back(i);
      permutation();
      check[i]=0; //순열 후로는 제자리로
      v.pop_back();
    }
  }
}
int main(void){
  scanf("%d",&n);
  permutation(); //브루트포스
  return 0; 
}
#include <iostream>
using namespace std;
int T,M,N,K;
int arr[51][51]={0}; //배추 농장
void check(int x, int y);

//이 문제는 x 좌표 y 좌표가 반대라는 걸 명심하자.

int main(void){

  int num[50]={0};

  cin >> T;
  for (int v=0;v<T;v++){ // 테스트 케이스만큼 반복
  
  int X[2500]={0}; //K의 최대 수가 2500이기 때문에 크기를 2500으로 잡아야한다.
  int Y[2500]={0};
  
  int count=0;
  
  cin >> M >> N >> K;
  
  for (int i=0;i<K;i++){ // 배추가 있는 곳을 1로 바꿔줌. 
    cin >> X[i] >> Y[i];
    arr[Y[i]][X[i]]=1;
  }
  
  


    for(int c=0;c<N;c++){
      for(int z=0;z<M;z++){
        if(arr[c][z]==1){ //배추가 있는 곳을 찾으면 0으로 바꾸고 주위를 체크
            arr[c][z]=0;
            check(c,z);
            count++; // 이제 한 배추 모임을 찾았으니 벌레를 한 마리 더함.
        }
      }     
    }
    num[v]=count;
    count=0;
    
  }

  for (int i=0;i<T;i++){
    cout << num[i] << endl;
  }
 
 return 0;
}


void check(int x, int y){//위,아래,양 옆을 조사해서 배추가 있는 곳이 있으면 재귀를 이용해서 조사
  
  if(x!=0&&arr[x-1][y]==1){
    arr[x-1][y]=0;
    check(x-1,y);
  }
  if(x!=49&&arr[x+1][y]==1){
    arr[x+1][y]=0;
    check(x+1,y);
  }
  if(y!=0&&arr[x][y-1]==1){
    arr[x][y-1]=0;
    check(x,y-1);
  }
  if(y!=49&&arr[x][y+1]==1){
    arr[x][y+1]=0;
    check(x,y+1);
  }
}
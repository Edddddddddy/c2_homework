#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 8;
char plants[MAX_N][MAX_N];
int yy[MAX_N];
int piece,N,K,cnt;

//到了第m行，已经放了n个
void dfs(int m, int n){
    if(n == K) {
        cnt ++; //??
        return;
    }
    if(m >= N) return;

    for(int i = 0; i < N; ++i){ //遍历行m的每一列
        if(plants[m][i] == '#' && yy[i] == 0){  //能放，则放
            yy[i] = 1;
            n++;    //更新状态
            dfs(m+1,n); //看看这一行按这个状态，下一行行不行
            n--;    //没成功
            yy[i] = 0;  
        }
    }
    dfs(m+1,n);
}



int main(){
    // freopen("in/in020.txt","r",stdin);

    while(cin >> N >> K ){
        if(N == -1 || K == -1){
            break;
        }
        memset(yy,0,sizeof(yy));
        piece = 0,cnt = 0;  //初始化棋子数量，当前加入的棋子数量

        //录入棋盘位置
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                cin >> plants[i][j];   
            }
        }
        dfs(0,0);
        cout << cnt << endl;
    }
    

    return 0;
}

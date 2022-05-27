#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 25;
const int INF = 0x3f3f3f3f;
int dp[MAX][MAX][MAX] = {0};    //i*j 切k刀
// 11 11111111

void horizontalCut(int r, int c, int times){
    for(int i = 1; i <= r-1;++i){   //
        for(int n = 0; n <= times-1;++n){
            dp[r][c][times] = min(dp[r][c][times], max(dp[i][c][n],dp[r-i][c][times-1-n])); //更新dp，分成i的上下两半
        }
    }
}


void verticalCut(int r, int c, int times){
    for(int j = 1; j <= c-1;++j){   //
        for(int n = 0; n <= times-1;++n){
            dp[r][c][times] = min(dp[r][c][times], max(dp[r][j][n],dp[r][c-j][times-1-n])); //更新dp，分成i的上下两半
        }
    }
}



int main(){
    // freopen("in/in017.txt","r",stdin);
    int w,h,m;
    while(cin >> w >> h >> m){
        if (w == 0 && h == 0 && m == 0)
			break;
        memset(dp,INF,sizeof(dp)); //初始化为最大
        for(int i = 1; i <= w; ++i){
            for(int j = 1; j <= h; ++j){
                for(int k = 0; k < m; ++k){
                    if(k == 0) dp[i][j][k] = i*j;
                    else if(i*j < k + 1){
                        dp[i][j][k] = INF;
                    }
                    else{
                        horizontalCut(i,j,k);
                        verticalCut(i,j,k);
                    }
                }
            }
        }
        cout << dp[w][h][m-1] << endl;
    }
    

    return 0;
}

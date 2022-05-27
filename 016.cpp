#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N= 3500, MAX_M = 12900;
int dp[MAX_N][MAX_N] = {0}; //前i个中，选择总重量不超过j 的最大魅力值

struct Jew{
    int w;
    int d;
};
Jew * jews;


int main(){
    // freopen("in/in016.txt", "r", stdin);

    int N, M, f[MAX_M] = {0}; //f存放每个重量
    cin >> N >> M;
    Jew * jews = new Jew[N+10];

    // memset(dp,-1,sizeof(dp));
    for(int i = 1; i <= N; ++i){
        cin >> jews[i].w >> jews[i].d ;
    }
    
    // cout << fun(N,M) << endl;

    for(int i = 1; i <= N; i++){
        for(int j = M; j >= jews[i].w; j--){
            f[j] = max(f[j],f[j-jews[i].w] + jews[i].d );
        }
    }
    cout << f[M];  // 27214
    delete [] jews;
    return 0;
}

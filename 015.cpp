#include <iostream>
#include <cstring>
using namespace std;
//n个数划分成k个正整数的划分数
//n划分成若干个不同正整数的划分数
//n划分成若干个奇数正整数的划分数

const int MAX = 55;


int dp1[MAX][MAX][MAX] = {0};   //把j分成，前i个数字中 选出k个，之和=j的种数

int fun1(int i, int j, int k){
    //采用记忆性递归提高效率，根据参数多少来建立数组
    //递推关系则是dp[i][j][k]=dp[i-1][j][k]+dp[i][j-i][k-1]
    if (j == 0 && k == 0) return 1; //
    if (k == 0) return 0;
    if (j == 0) return 0;
    if (i == 0) return 0;
    if(dp1[i][j][k] != -1) return dp1[i][j][k]; 
    int result = fun1(i-1,j,k); //初始化result，至少有前i-1个数字能组成的数量
    if(j >= i) result += fun1(i,j-i,k-1);   //剪枝后（j至少>=i），加上
    dp1[i][j][k] = result;
    return result;
}

int dp2[MAX][MAX] = {0}; //前i个数中，选出某些不重复数之和能=j的种类
int fun2(int i, int j){
    //而对于第二问是不同整数，则变为二维数组，dp[i][j]=dp[i-1][j]+dp[i-1][j-i]
    if(j == 0) return 1;
    if(i == 0) return 0;
    if(dp2[i][j] != -1) return dp2[i][j];   //已经有了
    int result = fun2(i-1, j);  
    if(j >= i) result += fun2(i-1,j-i);
    dp2[i][j] = result;
    return result;
}


int dp3[MAX][MAX] = {0};
int fun3(int i , int j){
    //第三问是奇数，则只需要加一个判断条件即可，dp[i][j]=dp[i-1][j]+dp[i][j-i]
    if (j == 0)
		return 1;
	if (i == 0)
		return 0;
	if (dp3[i][j] != -1)
		return dp3[i][j];
    int result = fun3(i-1, j);
    if(j >= i && i %2) result += fun3(i,j-i);
    return result;
}


int main(){

    // freopen("in/in015.txt","r",stdin);

    int N, K;
    
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    memset(dp3,-1,sizeof(dp3));

    while(cin >> N >> K){
        cout << fun1(N, N, K) << endl;
        cout << fun2(N, N) << endl;
        cout << fun3(N, N) << endl;
    }
    return 0;
}

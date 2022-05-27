#include <iostream>
// #include <time.h>
using namespace std;
int a[60][60] = {0};
/**
 * @brief n划分成最大值不超过m的块的种类
 * 
 * @param n 
 * @param m 
 * @return int 
 */
int partition(int n ,int m){
    if(a[n][m] != 0) return a[n][m];
    if(n == 1) {
        a[n][m] = 1;
        return 1;
    }
    if(m == 1){
        a[n][m] = 1;
        return 1;
    }
    int result;
    //每种初始
    if(n == m) {
        a[n][m] = partition(n,n-1)+1;
        return a[n][m];
    }
    //分为有m的和无m的
    if(n > m){
        a[n][m] = partition(n-m,m)+partition(n,m-1);
        return a[n][m];
    }
    if(n < m) {
        a[n][m] = partition(n,n);
        return a[n][m];
    }
}

int main(){
    // clock_t start,finish;
    // double Total_time;
    // start = clock();

    int n;
    int k = 50;
    while(k--){
        cin >> n;
        cout << partition(n,n) << endl;
    }


    // finish = clock();
    // cout << "total time is " << finish - start << "ms";
    return 0;
}

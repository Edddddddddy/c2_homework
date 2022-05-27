#include <iostream>
using namespace std;


/**
 * @brief 动态规划，拦截导弹
 * 思路是
 * 
 * @return int 
 */
int main(){

    freopen("in/in012.txt","r",stdin);
    int k ;
    cin >> k;
    int * a = new  int[k];  //目标数组
    int * maxnum = new int[k];  //动态规划数组
    
    for(int i = 0; i < k; i ++){    //初始化
        cin >> a[i];
        maxnum[i] = 0;
    }
    maxnum[k-1] = 1;    //

    int max = 1;

    for(int i = k-2; i > -1; --i){  //倒数第二个出发；第i个与i后面的数组进行添加，看看max能否+1
        for(int j = i+1; j < k; ++j){   //从i+1走到最后一个，找到一个满足的j保存数据到i，然后+1
            if(a[i] >= a[j])    //与j比较，找到最大的maxnum[j]，满足条件则保存
                maxnum[i] = maxnum[j] > maxnum[i] ? maxnum[j]:maxnum[i];    //
        }
        ++maxnum[i];    //完成+1
        max =  max > maxnum[i] ? max:maxnum[i]; //更新max
    }
    cout << max;
    delete [] a;
    delete [] maxnum;

    return 0;
}

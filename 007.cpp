#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int a[100000] = {0};
int n,c;
bool isValid(int mid){
    int count = 1,k=0;  //count ：已经放了牛的个数 k：上一只牛的下标
    for(int i = 1; i < n; ++i){
        if(a[i] - a[k]>=mid){
            count++;
            k = i;
        }
    }

    if(count>=c) return 1;
    return 0;
}



int main(){
    
    //输入N和C，有N个数，要求其中C个数字之间差值最小值的所有可能中的最大值，
    cin >> n >> c;
    for ( int i = 0; i < n; i ++){
        scanf("%d",&a[i]);
    }
    
    sort(a,a+n);


    int l = 0,r = 1000000000,mid,ans;

    while(l <= r){
        mid = (l+r)/2;
        if(isValid(mid)) {
            ans = mid;  //暂存答案，下面看有没有更大的
            l = mid+1;
        }
        else {
            r = mid-1;
        }

    }
    cout << ans;

    return 0;
}

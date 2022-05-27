#include <iostream>
#include <algorithm>
// #include <time.h>
using namespace std;
int a[100010];

/**
 * 快速排序后，输出前k个数
 * 
*/


int partition(int *arr, int low , int high){
    int pivot = arr[low];   //把第一个元素当成枢纽元素

    while(low < high){  //直到交汇表示分组结束
        //从尾巴开始查找一个arr中小于pivot的元素，放置到low
        while(low < high && arr[high] >= pivot) --high;
        arr[low] = arr[high];
        //从low开始查找一个arr大于pivot的元素
        while (low < high && arr[low] <= pivot) ++low;
        arr[high] = arr[low];
    }
    //low这时候已经被移动走了，这里是pivot的位置
    arr[low] = pivot;
    return low;
}

void quickSort(int *arr, int low, int high){
    if(low < high){
        int privotPos = partition(arr, low, high);  //获取存亡枢纽的位置，划分子表
        quickSort(arr, low, privotPos-1);    //左子表
        quickSort(arr, privotPos + 1, high);     //左子表
    }
}



int main(){
    
    // freopen("./in/in010.txt","r",stdin);

    int n,k;
    cin >> n;
    for(int i = 0;  i < n; ++i){
        scanf("%d",&a[i]);
        // cin >> a[i];
    }   
    cin >> k;
    quickSort(a,0,n-1);
    for(int i = n-1 ; i >= n-k; --i){
        printf("%d\n",a[i]);
    }


    return 0;
}

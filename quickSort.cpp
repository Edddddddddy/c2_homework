#include <iostream>
#include <vector>
using namespace std;


void quickSort(vector<int> & array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

// int partition(int *arr, int low , int high){
//     int pivot = arr[low];   //把第一个元素当成枢纽元素

//     while(low < high){  //直到交汇表示分组结束
//         //从尾巴开始查找一个arr中小于pivot的元素，放置到low
//         while(low < high && arr[high] >= pivot) --high;
//         arr[low] = arr[high];
//         //从low开始查找一个arr大于pivot的元素
//         while (low < high && arr[low] <= pivot) ++low;
//         arr[high] = arr[low];
//     }
//     //low这时候已经被移动走了，这里是pivot的位置
//     arr[low] = pivot;
//     return low;
// }

// void quickSort(int *arr, int low, int high){
//     if(low < high){
//         int privotPos = partition(arr, low, high);  //获取存亡枢纽的位置，划分子表
//         quickSort(arr, low, privotPos-1);    //左子表
//         quickSort(arr, privotPos + 1, high);     //左子表
//     }
// }



int main(){
    freopen("in/inQuickSort.txt","r",stdin);
    int x;
    vector<int> v;
    while(scanf("%d",&x) != -1){
        v.push_back(x);
    }
    int n = v.size()/sizeof(int);
    vector<int>::iterator it;
    
    quickSort(v,0,4);
    for(it = v.begin();it != v.end();++it) printf("%d ", *it);
    
    // int a[10];
    // int x;
    // for(int i = 0;scanf("%d",&x) != -1 ; i++){
    //     a[i] = x;
    // }

    // quickSort(a,0,4);

    // for(int i = 0; i < 5; ++i) cout << a[i] << " ";


    return 0;
}

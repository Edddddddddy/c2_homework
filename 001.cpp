#include <iostream>
#include <cstring>
using namespace std;



void setBit(int &c, int i, int v){
    
    if(v) c |= (1<<i);
    else c &= ~(1<<i);
    // cout << c;
}

int getBit(int c, int i){
    return (c>>i) & 1;
}

void flipBit(int &c, int i){
    c ^= (1<<i);
}

int main(){
    string as;
    int ori;
    int cur;
    int tar;
    int c ;
    int count = 0;
    int minCount =999999;

    cin >> as;
    int len = as.length();
    
    for(int i = 0; i < len ;i++){
        setBit(ori,i,as[i]-'0');
    }    
    cur = ori;
    cin >> as;
    for(int i = 0; i < len ;i++){
        setBit(tar,i,as[i]-'0');
    } 

    //第一个数变不变，决定后面的 0 不变，1 变
    for(int i = 0; i < 2; i ++){
        if(i == 1) {
            flipBit(cur, 0);
            flipBit(cur, 1);
            count++;
        }  
        for(int j = 1; j < len-1;j++){
            if(getBit(cur,j-1)!=getBit(tar,j-1)){
                flipBit(cur,j-1);
                flipBit(cur,j);
                flipBit(cur,j+1);
                count++;
            }
        }
        if(getBit(cur,len-2) != getBit(tar,len-2)){
            flipBit(cur,len-2);
            flipBit(cur,len-1);
            count++;
            if(getBit(cur,len-1) == getBit(tar,len-1)){
                if(minCount > count) minCount = count; 
            }
        }else{
            if(getBit(cur,len-1) == getBit(tar,len-1)){
                if(minCount > count) minCount = count;
            }
        }
        count = 0;
        cur = ori;
    }
    if(minCount == 999999) cout << "impossible"; 
    else cout << minCount;

    return 0;
}

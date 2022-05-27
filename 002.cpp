#include <iostream>
using namespace std;

/*
    拨钟问题
    分析：
        每种action最多用三次，所以
*/

void change(int * a, char * action,int n){
    for(int i = 0; action[i] != '\0';i++){
        a[action[i]-'A'] = (a[action[i]-'A'] +n)%4;
        // cout << a[action[i]-'A'] << " " ;
    }
    
}

int main(){
    
    char action[9][6] = {"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
    int ori[9],a[9];
    bool flag = 1;
    for(int i = 0; i < 9; i ++){
        cin >> ori[i];
        if(i%3==0 && i != 0) getchar();
    }
    for(int i = 0; i < 9 ;++ i){
        a[i] = ori[i];
    }

    int shortest[9];
    int shortest_count= 9999;
    int tmp_count;

    // change(a,action[1],2);
    // for(int i = 0; i < 9 ;++ i){
    //     cout << a[i] << " ";
    // }
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            for(int k = 0; k < 4; ++k){
                for(int l = 0; l < 4; ++l){
                    for(int m = 0; m < 4; ++m){
                        for(int n = 0; n < 4; ++n){
                            for(int o = 0; o < 4; ++o){
                                for(int p = 0; p < 4; ++p){
                                    for(int q = 0; q < 4; ++q){
                                        change(a,action[0],i);
                                        change(a,action[1],j);
                                        change(a,action[2],k);
                                        change(a,action[3],l);
                                        change(a,action[4],m);
                                        change(a,action[5],n);
                                        change(a,action[6],o);
                                        change(a,action[7],p);
                                        change(a,action[8],q);
                                        for(int r = 0; r < 9; ++r){
                                            if(a[r] != 0){
                                                flag = 0;
                                                break;
                                            }
                                        }
                                        
                                        if(flag){
                                            tmp_count = i+j+k+l+m+n+o+p+q;
                                            // cout << tmp_count;
                                            if(tmp_count < shortest_count){
                                                shortest_count = tmp_count;
                                                shortest[0] = i;
                                                shortest[1] = j;
                                                shortest[2]=k;
                                                shortest[3]=l;
                                                shortest[4]=m;
                                                shortest[5]=n;
                                                shortest[6]=o;
                                                shortest[7]=p;
                                                shortest[8]=q;
                                            }
                                        }
                                        flag = 1;
                                        for(int i = 0; i < 9 ;++ i){
                                            a[i] = ori[i];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if(shortest_count != 9999){
        for (int i = 0; i < 9; ++i){
            while(shortest[i]!=0){
                cout << i+1 << " ";
                --shortest[i];
            }
        }
    }
    

    return 0;
}

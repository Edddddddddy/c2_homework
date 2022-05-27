#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/**
 * @brief 
 * 
 * @param s1 
 * @param s2 
 * @param dst 
 * @return true 
 * @return false 
 */
bool zipper(string s1,string s2,string dst){
    int len1 = s1.length(),len2 = s2.length();
    vector<vector<bool> > dp(len1+1,vector<bool>(len2+1,false));
    dp[0][0] = true;
    for(int i = 0; i <= len1; ++i){
        for(int j = 0; j <= len2; ++j){ 
            if(i >= 1 && dp[i-1][j] && dst[i+j-1] == s1[i-1])   //加上s1的下一个是否可以
                dp[i][j] = true;
            if(j >= 1 && dp[i][j-1] && dst[i+j-1] == s2[j-1])   //加上s2的下一个是否可以
                dp[i][j] = true;
        }
    }
    return dp[len1][len2];
}

int main(){
    
    // freopen("in/in013.txt","r",stdin);

    int n, cnt = 1;
    cin >> n;
    while(n--){
        string s1,s2,dst;
        cin >> s1 >> s2 >> dst;
        if(zipper(s1,s2,dst)){
            cout << "Data set " << cnt++ <<": yes" << endl;
        }else{
            cout << "Data set " << cnt++ <<": no" << endl;
        }
    }

    return 0;
}

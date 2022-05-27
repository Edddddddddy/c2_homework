#include <iostream>
#include <cstring>
using namespace std;

string add(string s1,string s2) {//大数加法
	string result;
	int if_jin = 0;
	for (int i = s1.length() - 1, j = s2.length() - 1; i > -1 || j > -1; --i, --j) {
		result = ' ' + result;
		int m = i > -1 ? s1[i] - '0' : 0;
		int n = j > -1 ? s2[j] - '0' : 0;
		result[0] = m + n + if_jin;

		if (result[0] > 9) {
			result[0] = result[0] % 10 + '0';
			if_jin = 1;
		}
		else {
			result[0] = result[0] + '0';
			if_jin = 0;
		}
	}
	if (if_jin)
		result = '1' + result;
	return result;
}

string mins(string s1, string s2) {//大数比较
	if (s1.length() < s2.length())
		return s1;
	else if (s1.length() > s2.length())
		return s2;
	else
		return s1 < s2 ? s1 : s2;
}

    string str;
    int m;
    string dp[60][60]; //i：前i个数字，j：放j个+号，dp保存当前第j个+号加入时候，第前i个数所能形成的最小值

int main(){
    freopen("in/in014.txt","r",stdin);
    while(cin >> m >> str){
        int len = str.length();
        for(int i = 0; i <= len; ++i)  dp[i][0] = str.substr(0,i); //放0个+号
        for(int j = 1; j <= m; ++j){    //放j个+号,一列一列来
            for (int i = j+1; i <= len; ++i){    //至少要j+1个数字，因此行只需要遍历j+1～len
                for(int k = j; k < i ; ++k){  //最后一个+放在第k个数字后面，k～len-1,该dp三角形只有左下半个
                    if(k == j) dp[i][j] = add(dp[k][j-1],str.substr(k+1,i-k));  
                    else dp[i][j] = mins(add(dp[k][j-1],str.substr(k+1,i-k)),dp[i][j]);
                }
            }
        }
        cout << dp[len][m] << endl;
    }
    

    return 0;
}

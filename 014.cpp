#include<iostream>
#include<string>
#include<vector>
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

int m;
string s;
string dp[60][60];

int main() {
    // freopen("in/in014.txt","r",stdin);
	while (cin >> m >> s) {
		int len = s.length();
		s = ' ' + s;//使下标从1开始
		for (int i = 0; i <= len; ++i)//加号数为0，提前处理
			dp[i][0] = s.substr(1, i);

		for (int j = 1; j <= m; ++j)//加号数目，由小到大
			for (int i = j + 1; i <= len; ++i)//前i个数放j个加号
				for (int k = j; k < i; ++k)//k保证前k个数能放j-1加号，即代表最后一个加号的位置
					if (k == j)//每个字符单独成数
						dp[i][j] = add(dp[k][j - 1], s.substr(k + 1, i - k));   //dp[k][j - 1]表示前i个数字放j-1个+，最后一个放在k位置时的最小值；s.substr(k + 1, i - k)表示最后一个+后面的数
					else//
						dp[i][j] = mins(dp[i][j], add(dp[k][j - 1], s.substr(k + 1, i - k)));
						//其他情况比较取最小值，j-1是上一个j循环处理好的结果
		cout << dp[len][m] << endl;
	}


	return 0;
}

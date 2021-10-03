#include <bits/stdc++.h>

using namespace std;
class Solution{
public:
	string removeDuplicates(string str) 
	{
	    int ans[256] = {0};
	    string s = "";
	    for(int i = 0;i<str.length();i++)
	    {
	        if(ans[str[i]]==0)
	        {
	            ans[str[i]]++;
	            s = s + str[i];
	        }
	    }
	    return s;
	}
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}

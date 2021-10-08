
/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
*/

 string longestPalindrome(string s) {
      
  if(s.size()==0)
      {
          cout<<"String is Empty"<<endl;
      }
      const int n=s.size();
      // dp(i, j): indicates if string[i:j] is palindromic or not
      vector<vector<bool>>dp(n, vector<bool>(n, false));
      int max_len=0;
      int st=0;

      //for a single char they all are palindrome
      for(int i=0;i<n;i++)
      {
          dp[i][i]=true;
      }

      //for two and more char
      max_len=1;st=0;
      for(int l=1;l<n;l++)
      {
          for(int i=0;i<n-l;i++)
          {
              int j=i+l;
              // when there are only 2 chars, just check the first and last chars
              if(j-i+1==2)
              {
                  dp[i][j]=s[i]==s[j];
              }
              else
              {
                  // current s[i:j] can only be palindromic iff
                  // first and last chars are same and the substring s[i+1:j-1]
                  // is also palindromic
                  dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1])==true;
              }
              // update max length
              if(dp[i][j]&&j-i+1>max_len)
              {
                  max_len=j-i+1;
                  st=i;
              }
          }
      }
      return s.substr(st, max_len);
        
  }

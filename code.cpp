class Solution {
public:
    int minInsertions(string text1) {
        string text3=text1;
        reverse(text1.begin(),text1.end());
       string text2=text1;
        text1=text3;
        int n=text1.length();
        int m=text2.length();
        int dp[n+1][m+1];
        //return length(text1,text2,n,m);
        for(int i=0;i<n+1;i++)
        dp[i][0]=0;
        for(int i=0;i<m+1;i++)
        dp[0][i]=0;
        for(int i=1;i<n+1;i++)
        for(int j=1;j<m+1;j++)
        {
            if(text1[i-1]==text2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
       
        return dp[n][m]==n?0:n-dp[n][m];
    }
};

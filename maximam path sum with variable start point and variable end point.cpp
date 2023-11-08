#include <bits/stdc++.h> 

int fun(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp,int m,int n)
{
	if(j<0 || j>=n) return -1e8;
	if(i==m-1) return matrix[m-1][j];
	if(dp[i][j] != -1) return dp[i][j];
	int down = matrix[i][j] + fun(i+1,j,matrix,dp,m,n);
	int dl = matrix[i][j] + fun(i+1,j-1,matrix,dp,m,n);
	int dr = matrix[i][j] + fun(i+1,j+1,matrix,dp,m,n);
	return dp[i][j]=max(down, max(dr,dl));
}


int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
	int max_path=-1e8;
	int m=matrix.size();
	int n=matrix[0].size();
    vector<vector<int>> dp(m,vector<int> (n,-1));
	for(int i=0;i<n;i++)
    {
        max_path=max(max_path,fun(0,i,matrix,dp,m,n));
    }
	return max_path;
}

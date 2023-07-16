//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int mod = 1e9+7 ;
    int f( vector<vector<int>> &grid , int i , int j, vector<vector<int>> &dp){
        if(i >= 0 && j >=0 && grid[i][j] == 0 )return  0 ;
        if(i < 0 || j < 0)return  0 ;
        if(i == 0 && j == 0)return 1 ;
        if(dp[i][j] != -1 )return dp[i][j] ; 
        int up = f(grid, i - 1 , j , dp)% mod ;
        int left = f(grid , i , j - 1 , dp) % mod ;
        return dp[i][j] = (up % mod) + (left % mod) ; 
        
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
         
        vector<vector<int>> dp(n , vector<int> (m,-1)) ;
        return f(grid , n-1  , m - 1, dp)% mod  ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends
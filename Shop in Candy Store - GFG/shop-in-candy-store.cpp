//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int K)
    {
        // Write Your Code here
        vector<int> ans ; 
        sort(candies, candies + n) ;
        int minCost = 0 , maxCost = 0 ;
        int i = 0 , j = n - 1 ;
        int k = K ;
        while(i <= j){
            minCost += candies[i] ;
            while(k--){
                j-- ;
            }
            k = K ;
            i++; 
        }
        ans.push_back(minCost) ;
        reverse(candies, candies + n) ;
        i = 0 , j = n - 1;
        k = K ;
        while(i <= j){
            maxCost += candies[i] ;
            while(k--){
                j-- ;
            }
            k = K ;
            i++; 
        }
        ans.push_back(maxCost) ;
        return ans ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
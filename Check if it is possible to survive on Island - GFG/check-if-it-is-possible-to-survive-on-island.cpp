//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        int sundays = S/7 ;
        int buyingDays = S - sundays ;
        int ans = 0 ;
        int totalFood = S*M ;
        if(totalFood % N == 0){
            ans = totalFood/N ;
        }
        else{
            ans = totalFood/N + 1 ;
        }
        if(ans <= buyingDays)return ans;
        return -1; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends
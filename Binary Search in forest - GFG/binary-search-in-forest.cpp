//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int woodCollected(int arr[] , int mid , int n){
        int wc = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] > mid){
                wc += (arr[i] - mid) ;
            } 
        }
        return wc ;
    }
    int find_height(int arr[], int n, int k)
    {
        //sort(arr, arr + n);
        int low = 0 ;
        int high = 1e9 ;
        while(low <= high){
            int mid = low + (high - low)/2 ;
            int wc = woodCollected(arr, mid , n); 
            if(wc == k){
                return mid ;
            }
            else if(wc > k){
                low = mid + 1 ;
            }
            else {
                high = mid -1 ;
            }
        }
        return -1 ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> arr, long long x)
    {
        pair<long,long> p ;
        int low = 0 ;
        int high = arr.size()-1 ;
        long long first = -1 ;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == x){
                first = mid ; 
                high = mid-1;
            }
            else if(arr[mid] > x){
                high = mid-1;
            }
            else low = mid+1;
        }
        long long last = -1;
        low = 0 ;
        high = arr.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == x){
                last = mid ; 
                low = mid+1;
            }
            else if(arr[mid] > x){
                high = mid-1;
            }
            else low = mid+1;
        }
        p.first = first ; 
        p.second = last;
        return p ;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends
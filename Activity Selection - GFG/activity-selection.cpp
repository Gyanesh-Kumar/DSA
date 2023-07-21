//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class activity{
    public:
    int start ;
    int end ;
    int id; 
};
class Solution
{
    static bool comp(activity a , activity b){
        if(a.end == b.end)return a.id < b.id ;
        return a.end < b.end ;
    }
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        activity act[n] ;
        for(int i = 0 ; i < n ; i++){
            act[i].start = start[i] ;
            act[i].end = end[i] ;
            act[i].id = i+1 ;
        }
        sort(act, act+ n , comp) ;
        
        int endTime = act[0].end ; 
        int count = 1 ;
        for(int i = 1 ; i < n ; i++){
            if(act[i].start > endTime){
                count++ ;
                endTime = act[i].end  ;
            }
        }
        return count ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
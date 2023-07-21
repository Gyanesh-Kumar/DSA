//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

struct meeting{
    int start;
    int end;
    int id; 
};
class Solution{
public:
    static bool comp(meeting a , meeting b){
        if(a.end < b.end)return true ;
        else if(a.end >= b.end)return false ;
        if(a.id < b.id)return true ;
        return false ;
    }
    vector<int> maxMeetings(int n,vector<int> &start,vector<int> &end){
        vector<int> ans ; 
        meeting meet[n];
        
        for(int i = 0 ; i < n ; ++i){
            meet[i].start = start[i] ;
            meet[i].end = end[i] ;
            meet[i].id = i+1 ;
        }
        
        sort(meet, meet + n , comp) ;
        
        // for(int i = 0 ; i < n ; i++){
        //     cout<<meet[i].id<<" "<<meet[i].start<<" "<<meet[i].end<<endl;
        // }
        // cout<<endl;
        ans.push_back(meet[0].id);
        int endTime = meet[0].end ;
        for(int i = 1 ; i < n ; ++i){
            if(meet[i].start > endTime){
                ans.push_back(meet[i].id) ;
                endTime = meet[i].end ;
            }
        }
        sort(ans.begin(), ans.end());
        return ans; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
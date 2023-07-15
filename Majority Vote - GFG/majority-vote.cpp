//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& v) {
        vector<int> ans ;
	int ele1= INT_MIN ;
	int ele2= INT_MIN ;
	int count1 = 0 , count2 = 0 ;
	for(int i = 0 ; i < n ; ++i){
		if(count1 == 0 && v[i] != ele2){
			ele1 = v[i] ;
			count1 = 1;
		}
		else if(count2 == 0 && v[i] != ele1){
			ele2 = v[i] ;
			count2 = 1 ;
		}
		else if(ele1 == v[i]){
			count1++ ;
		}
		else if(ele2 == v[i]){
			count2++ ;
		}
		else{
			count1--;
			count2-- ;
		}
	}
	count1 = 0 ;
	count2 = 0 ; 
	for(int i = 0 ; i < n ; ++i){
		if(v[i] == ele1)count1++ ;
		if(v[i] == ele2)count2++ ;
	}
	if(count1 > n/3){
		ans.push_back(ele1) ;
	}
	if(count2 > n/3){
		ans.push_back(ele2) ;
	}
	if(ans.empty())ans.push_back(-1) ;
	return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int makeProductOne(int arr[], int n) {
        // code here
        int neg = 0 ;
        int zero = 0 ;
        int count = 0 ; 
        for(int i = 0 ; i < n ; i++){
            if(arr[i] > 0){
                count+= (arr[i]-1);
            }
            else if(arr[i] < 0){
                count+= abs(arr[i])- 1 ;
                neg++;
            }
            else{
                count++;
                zero++ ;
            }
        }
        if(neg % 2 != 0 ){
            if(zero > 0){
                return count ;
            }
            else return count+2 ;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.makeProductOne(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
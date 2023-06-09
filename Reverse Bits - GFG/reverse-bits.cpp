//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    string convertToBinary(unsigned int n){
        string s = "" ;
        int i = 0 ;
        while(n){
            int dig = n % 2  ;
            s += to_string(dig) ;
            n /= 2 ;
        }
        // cout<<s<<endl;
        reverse(s.begin(),s.end()) ;
        return s ;
    }
    unsigned int convertToDecimal(string s){
        unsigned int ans = 0 ;
        int  k= 0 , j = 0 ;
        while(s[k] == '0')k++;
        for(int i = 0 ; i < s.size() ; ++i){
            int ele = s[i] - '0' ;
            //cout<<ele<<" ";
            ans += (ele * (pow(2,j)));
            j++;
        }
        return ans ;
    }
    unsigned int reverseBits(unsigned int n)
    {
        string s = convertToBinary(n) ;
        unsigned int ans = convertToDecimal(s);
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
        int N;
        cin >> N;
        
        Solution ob;
        cout<< ob.reverseBits(N) <<"\n";
        
    }
    return 0;
}

// } Driver Code Ends
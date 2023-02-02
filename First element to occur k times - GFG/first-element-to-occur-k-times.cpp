//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        std::unordered_map<int, int> myCount;
        for (auto i = 0; i < n; ++i)
        {
            auto iter = myCount.find(a[i]);
            if (iter == myCount.end())
            {
                myCount.emplace(a[i], 1);
            }
            else
            {
                ++(iter->second);
            }
            iter = myCount.find(a[i]);
            if (iter->second == k)
            {
                return a[i];
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
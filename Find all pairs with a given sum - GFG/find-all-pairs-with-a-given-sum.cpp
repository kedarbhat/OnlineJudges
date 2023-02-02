//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    static constexpr int binarySearch(int B[], const int M, const int target) noexcept {
        auto left = 0;
        auto right = M;
        while (left < right) {
            auto mid = left + (right-left)/2;
            if (B[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], const int N, const int M, const int X)
    {
        sort(A, A+N);
        sort(B, B+M);
        vector<pair<int, int>> result;
        for (auto i = 0; i < N; ++i) {
            auto target = X - A[i];
            auto targetIdx = binarySearch(B, M, target);
            if (0 <= targetIdx && targetIdx < M && B[targetIdx] == target) {
                result.emplace_back(A[i], B[targetIdx]);
            }
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends
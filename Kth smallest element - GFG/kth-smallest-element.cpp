//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    mutable random_device rd;
    int partition(int arr[], const int lhs, const int rhs) const {
        uniform_int_distribution<int> dist{lhs, rhs-1};
        auto pivotIdx = dist(rd);
        auto pivot = arr[pivotIdx];
        swap(arr[pivotIdx], arr[rhs]);
        auto writeIdx = lhs;
        for (auto readIdx = lhs; readIdx < rhs; ++readIdx) {
            if (arr[readIdx] <= pivot) {
                swap(arr[writeIdx], arr[readIdx]);   
                ++writeIdx;
            }
        }
        swap(arr[writeIdx], arr[rhs]);
        return writeIdx;
    }

    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int lhs, int rhs, int k) {
        //code here
        k = k-1;
        while (lhs < rhs) {
            auto pivotIdx = partition(arr, lhs, rhs);
            if (pivotIdx == k) {
                break;
            }
            if (pivotIdx < k) {
                lhs = pivotIdx+1;
            } else {
                rhs = pivotIdx-1;
            }
        }
        return arr[k];
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
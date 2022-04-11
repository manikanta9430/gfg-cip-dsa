// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector <int>&hash, int hashSize, int arr[], int N)
    {
        //Your code here
        for(auto &x : hash)
            x = -1;
        int counts = hashSize;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < hashSize; j++){
                int index = (arr[i]%hashSize + (j*j)%hashSize)%hashSize;
                if(hash[index] == arr[i])
                    break;
                else if(hash[index] == -1){
                    hash[index] = arr[i];
                    counts--;
                    break;
                }
            }
            if(counts == 0)
                return;
        }
        return;
    }


};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    
	    
	    int  N;
	    cin>>N;
	    int arr[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>arr[i];
	    
	    vector<int> hash (hashSize,-1);
	    Solution obj;
	    obj.QuadraticProbing (hash, hashSize, arr, N);
	    
	    for(int i = 0;i < hashSize; i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}


  // } Driver Code Ends

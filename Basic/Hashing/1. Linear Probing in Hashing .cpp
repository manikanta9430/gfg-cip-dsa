// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Linear Probing to handle collisions.
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        //Your code here
        vector<int> hashTable(hashSize,-1);
        for(int i=0;i<sizeOfArray;++i){
            int index = arr[i]%hashSize;
            if(hashTable[index]==-1)hashTable[index]=arr[i];
            else{
                int count=0;
                while(hashTable[index]!=-1 and count<=hashSize){
                    if(hashTable[index]==arr[i])break;
                    index=(index+1)%hashSize;
                    count++;
                }
                if(hashTable[index]==-1)hashTable[index]=arr[i];
            }
        }
        return hashTable;
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
	    
	    int  sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    vector<int> hash;
	    Solution obj;
	    hash = obj.linearProbing( hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}

  // } Driver Code Ends

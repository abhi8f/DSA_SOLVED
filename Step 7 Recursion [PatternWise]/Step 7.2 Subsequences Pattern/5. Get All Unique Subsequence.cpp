/*
    Time complexity: O( k * (2 ^ n) )
    Space complexity: O( k * (2 ^ n) )
    
    Where 'k' is the average size of a subset and 
    'n' is the size of the array.
*/

// Helper function to generate all unique subsets
void findSubsets(int index, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans) {
    // Pushing the array 'temp' into 'ans'
    ans.push_back(temp);
    
    for(int i = index; i < (int)arr.size(); ++i) {
        // Checking if the previous element is same as current element
        if(i != index && arr[i] == arr[i - 1]) continue;
        
        // Inserting the current element in array 'temp'
        temp.push_back(arr[i]);
        
        findSubsets(i + 1, arr, temp, ans);
        
        // Removing last element from 'temp'
        temp.pop_back();
    }
}


vector<vector<int>> getUniqueSubsets(vector<int>& arr) {
    // Initializing an 2-D array 'ans'
    // to store the subsets
    vector<vector<int>> ans;

    // Initializing an array 'temp' which will 
    // store the elements to be inserted in the 'ans'
    // as an array
    vector<int> temp;
    
    findSubsets(0, arr, temp, ans);
    return ans;
}

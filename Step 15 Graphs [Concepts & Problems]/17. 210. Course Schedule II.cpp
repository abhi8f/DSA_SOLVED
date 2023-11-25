class Solution {
public:
    // vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &vec: edges) {
            adj[vec[0]].push_back(vec[1]);
        }

	    vector<int> inDegree(V, 0);
	    for(int i=0; i<V; i++) {
	        for(auto &x: adj[i]) {
	            inDegree[x]++;
	        }
	    }
	    
	    queue<int> zeroDegreeQ;
	    for(int i=0; i<V; i++) {
	        if (inDegree[i]==0) zeroDegreeQ.push(i);
	    }
	    
	    vector<int> ans;
	    while(!zeroDegreeQ.empty()) {
	        int x = zeroDegreeQ.front();
	        zeroDegreeQ.pop();
	        ans.push_back(x);
	        
	        for(auto &y: adj[x]) {
	            inDegree[y]--;
	            
	            if (inDegree[y]==0) {
	                zeroDegreeQ.push(y);
	            }
	        }
	    }
	    reverse(ans.begin(), ans.end());
	    return ans.size()==V ? ans : vector<int>();
    }
};

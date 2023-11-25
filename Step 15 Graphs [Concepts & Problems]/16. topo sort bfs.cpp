class Solution {
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
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
	    
	    return ans;
	}
};

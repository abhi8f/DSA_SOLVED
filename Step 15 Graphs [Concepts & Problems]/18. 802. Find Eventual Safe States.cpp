class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adjGiven) {
        int V = adjGiven.size();

        vector<vector<int>> adj(V);
	    vector<int> inDegree(V, 0);

        for(int i=0; i<V; i++) {
            for(auto &x: adjGiven[i]) {
                adj[x].push_back(i);
                inDegree[i]++;
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
	    sort(ans.begin(), ans.end());
	    return ans;
    }
};

class Solution
{
    private:
    void dfs(int x, vector<bool> &vis, stack<int> &visStack, vector<int> adj[]) {
        vis[x] = true;
        
        for(int y: adj[x]) {
            if (!vis[y]) dfs(y, vis, visStack, adj);
        }
        
        visStack.push(x);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> vis(V, false);
	    stack<int> visStack;
	    
	    for(int x=0; x<V; x++) {
	        if (!vis[x]) dfs(x, vis, visStack, adj);
	    }
	    
	    vector<int> ans;
	    while(!visStack.empty()) {
	        ans.push_back(visStack.top());
	        visStack.pop();
	    }
	    return ans;
	}
};

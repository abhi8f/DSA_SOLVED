class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        vector<int> inDegree(K, 0);

        for(int i=1; i<N; i++) {
            int s = min(dict[i-1].size(), dict[i].size()), j=0;

            while(j<s && dict[i-1][j]==dict[i][j]) j++;

            if (j==s) continue;

            inDegree[dict[i][j]-'a']++;
            adj[dict[i-1][j]-'a'].push_back(dict[i][j]-'a');
        }

        queue<int> zeroDegreeQ;
        for(int i=0; i<K; i++) {
            if (inDegree[i]==0) zeroDegreeQ.push(i);
        }

        string ans="";

        while(!zeroDegreeQ.empty()) {
            int node = zeroDegreeQ.front();
            zeroDegreeQ.pop();
            ans+=(char)(node+(int)'a');

            for(int x: adj[node]){
                inDegree[x]--;
                if(inDegree[x]==0) zeroDegreeQ.push(x);
            }
        }
        return ans;
    }
};

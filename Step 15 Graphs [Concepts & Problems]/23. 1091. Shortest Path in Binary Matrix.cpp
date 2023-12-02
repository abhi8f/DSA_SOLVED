class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int16_t n = grid.size() ;
        int16_t m = grid[0].size();

         if(grid[0][0]!=0 || grid[n-1][m-1]!=0){
            return -1;
        }
         if(grid[0][0]==0 && n==1 && m==1){
            return 1;
        }

        // src  --- (0,0)
        // dest --- (n-1,n-1)
        // create a queue (weight , (row , col))
        queue<pair<int16_t, pair<int16_t, int16_t>>> q;
        vector<vector<int16_t>> dist(n ,vector<int16_t> (n, INT16_MAX)) ;
        if(n==1){
            return  0 ;
        }

        // insert the src to q ;
        q.push({1,{0,0}}) ;
        dist[0][0] = 0 ;


        // int delr[] = {-1,0,1,0};
        // int delc[] = { 0,1,0,-1} ;

        while(!q.empty()){

            auto tp =  q.front() ;
            int16_t edgw = tp.first ;
            int16_t r =  tp.second.first ;
            int16_t c =  tp.second.second ;

            q.pop() ;
            if(r == n-1 && c == n-1){
                return dist[r][c] ;
            }

            // check its neighbour
            for(int16_t  i = -1 ;i<=1 ;i++){
                for(int16_t  j = -1 ;j<=1 ;j++){


                int16_t newr = r + i ;
                int16_t newc = c + j ;

                // valid index
                if(newr >= 0 && newr <n  && newc >=0 && newc<n && grid[newr][newc] ==0
                 &&  dist[newr][newc] > 1 + edgw  ){

                    dist[newr][newc] = 1 + edgw ;
                    if(newr == n-1 && newc == n-1){
                        return dist[newr][newc] ;
                    }

                    q.push({dist[newr][newc],{newr,newc}}) ;
                    // grid[newr][newc] =1;

                }
            }
        }

        }
        return -1;

    }
};

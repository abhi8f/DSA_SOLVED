long long int n;
long long int a[110];
long long int dp[110][110];

long long int rec(long long int l,long long int r,long long int lend,long long int rend){
    if(l>r){
        return 0;
    }
    if(l==r){
        return dp[l][r]=rend-lend;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    long long int ans=1e15;
    for(int i=l;i<=r;i++){
        ans=min(ans,rec(l,i-1,lend,a[i])+rec(i+1,r,a[i],rend)+rend-lend);
    }
    dp[l][r]=ans;
    return dp[l][r];
}

vector<int> func(long long int l,long long int r,long long int lend,long long int rend,long long int req){
    if(l>r){
        vector<int>tt;
        return tt;
    }
    if(l==r){
        vector<int>tt;
        tt.push_back(a[l]);
        return tt;
    }
    vector<int>cos;
    for(int i=l;i<=r;i++){
        long long int v1=0;
        if(i!=l){
            v1=dp[l][i-1];
        }
        long long int v2=0;
        if(i!=r){
            v2=dp[i+1][r];
        }
        if(v1+v2==req-(rend-lend)){
            vector<int>t1=func(l,i-1,lend,a[i],v1);
            vector<int>t2=func(i+1,r,a[i],rend,v2);
            cos.push_back(a[i]);
            for(auto x : t1){
                cos.push_back(x);
            }
            for(auto x : t2){
                cos.push_back(x);
            }
            break;
        }
    }
    return cos;
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    n=B.size();
    sort(B.begin(),B.end());
    for(int i=0;i<n;i++){
        a[i]=B[i];
    }
    memset(dp,-1,sizeof(dp));
    long long int val=rec(1ll*0,1ll*(n-1),1ll*0,1ll*A);
    vector<int>temp;
    temp=func(1ll*0,1ll*(n-1),1ll*0,1ll*A,1ll*val);
    return temp;
}

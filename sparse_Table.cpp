
// problem statement : finding max/min/gcd... Of Ranges , without anyupdates.
//Benifit --> answer queries in O(1) Time.
// Caveat: building a sparse table take O(NlogN) time
//-->Range minimum queries:
//-->We need to precompute the minimum values of only those subarrays whole length is a power of 2.
//Sparse Table: It is a 2d array which stores the value of mn[i][j] = min of array which starts at indec i and has a length 2^j, for all 1<=i<=N and for all 0<=j<=ceil(logN)
// mn[i][j]=min(mn[i][j-1],mn[i+2^(j-1)][j-1])
int N=1e5+5;
vector<vector<int>> mn(N+1,vector<int>(log2(N)+1,0));
void sprase(vector<int> a){
    int n=a.size();
    for(int i=1;i<=n;i++){
        mn[i][0]=a[i];
    }
    for(int i=n;i>=0;i--){
        for(int j=1;j<=log2(n)+1;j++){
            if(i+(1<<(j-1))<=n) mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        int len=r-l+1;
        int pw=31-__builtin_clz(len);
        // __builtin_clz(len)=count of leading zeros
        cout<<min(mn[l][pw],mn[r-(1<<pw)+1][pw])<<endl;
    }

}
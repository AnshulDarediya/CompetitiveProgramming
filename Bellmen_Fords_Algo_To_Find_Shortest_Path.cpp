vector<int> bellman_ford(int V,int src,vector<vector<int> > edges){

    //create a vector 
    vector<int> dist(V+1,1e16);
    dist[src] = 0;

    //relax all edges v-1 times
    for(int i=0;i<V-1;i++){

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u]!=1e16 and dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    // negative wt cycle 
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if(dist[u]!=1e16 and dist[u] + wt < dist[v]){
            cout<<"negative Wt cycle found";
            exit(0);
        }

    }
    return dist;
}
vector<vector<int> > floyd_warshall(vector<vector<int> > graph){

    vector<vector<int> > dist(graph);

    int V = graph.size();

    //Phases, in kth phase we included vertices (1,2,...k) as intermediate vertices
    for(int k=0;k<V;k++){
        //Iterate over entire 2D Matrix
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){

                //if vertex k is included, and can we minimise the dist ?
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }

        }
    }
    return dist;
}
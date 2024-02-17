int dijkstra(int src, int dest,vector<vector<pair<int,int>>> &adj)
{
    int n=adj.size()-1;
    // Data Structures
    vector<int> dist(n+1, 1e18);
    set<pair<int, int>> s;

    // 1. Init
    dist[src] = 0;
    s.insert({0, src});

    while (!s.empty())
    {

        auto it = s.begin();
        int node = it->second;
        int distTillNow = it->first;
        s.erase(it); // Pop

        // Iterate over the nbrs of node
        for (auto nbrPair : adj[node])
        {
            //......

            int nbr = nbrPair.second;
            int currentEdge = nbrPair.first;

            if (distTillNow + currentEdge < dist[nbr])
            {
                // remove if nbr already exist in the set

                auto f = s.find({dist[nbr], nbr});
                if (f != s.end())
                {
                    s.erase(f);
                }
                // insert the updated value with the new dist
                dist[nbr] = distTillNow + currentEdge;
                s.insert({dist[nbr], nbr});
            }
        }
    }
    // Single Source Shortest Dist to all other nodes
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Node i " << i << " Dist " << dist[i] << endl;
    // }
    return dist[dest];
}
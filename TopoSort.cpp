void dfs(int start, vector<vector<int>> &adj, bool *visited, vector<int>& ans)
{
    visited[start] = true;
    for (auto i : adj[start])
    {
        if (visited[i])
            continue;
        dfs(i, adj, visited, ans);
    }
    ans.pb(start+1);
}
vector<int> topo_sort(int n, vector<vector<int>> &adj)
{
    vector<int> v1;
    bool *visited = new bool[n]();
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        dfs(i, adj, visited, v1);
    }
    reverse(v1.begin(), v1.end());
    return v1;
}
bool dfs1(int start, vector<vector<int> >&adj, bool *w, bool *g, bool *b)
{
    w[start] = false;
    g[start] = true;
    for (auto i : adj[start])
    {
        if (g[i])
            return false;
        if (w[i])
        {
            bool ans = dfs1(i, adj, w, g, b);
            if (!ans)
                return false;
        }
    }
    g[start] = false;
    b[start] = true;
    return true;
}
bool check_cycle(int n, vector<vector<int>> &adj)
{
    bool *white = new bool[n]();
    bool *grey = new bool[n]();
    bool *black = new bool[n]();
    for (int i = 0; i < n; i++)
        white[i] = true;
    for (int i = 0; i < n; i++)
    {
        if (white[i])
        {
            bool ans = dfs1(i, adj, white, grey, black);
            if (!ans)
                return true;
        }
    }
    return false;
}
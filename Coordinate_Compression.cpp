vector<int> coordinate_compression(vector<int> nums)
{
    int n = nums.size();
    vector<pair<int, int>> v(n), temp(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {nums[i], i};
    }
    sort(v.begin(), v.end());
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (i - 1 >= 0 && v[i].first == v[i - 1].first)
            ct--;
        temp[i] = {v[i].second, ct};
        ct++;
    }
    sort(temp.begin(), temp.end());
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i].second;
    }

    return a;
}
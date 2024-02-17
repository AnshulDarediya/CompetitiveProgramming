vector<bool> prime(N,1);
vector<ll> pr, lpf(N);
void pre() {
    prime[0] = prime[1] = false;
    for (ll i = 2; i < N; i++)
    {
        if (prime[i])
        {
            pr.pb(i);
            lpf[i] = i;
            for (ll j = i * i; j < N; j += i)
            {
                prime[j] = false;
                lpf[j] = i;
            }
        }
    }
}
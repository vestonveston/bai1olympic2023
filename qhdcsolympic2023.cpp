#include <bits/stdc++.h>
using namespace std;
void home()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
}
long long n, k;
string doi(long long a){
    string kq = "";
    while (a > 0){
        kq = char(a%10 + 48) + kq;
        a /= 10;
    }
    return kq;
}
long long tcs(long long a){
    long long kq = 0;
    while(a > 0){
        kq += a%10;
        a /= 10;
    }
    return kq;
}
long long dp[14][2][10000][110];
long long dpr(int i, int lower, int du, string x, int sum, int k){
    if(dp[i][lower][du][sum] != -1)return dp[i][lower][du][sum];
    if(i == x.size()){
        if(du == 0)return sum;
        return 0;
    }
    int mx = 9; long long ans = 0;
    if(lower == 1){
        mx = x[i] - '0';
    }
    for(int j = 0; j <= mx; j++){
        int _lower = 0;
        if(lower == 1){
            if(j == mx)_lower = 1;
        }
        ans += dpr(i + 1, _lower, (du*10 + j)%k, x, sum + j, k);
    }
    dp[i][lower][du][sum] = ans;
    return ans;
}
signed main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0); cout.tie(0); //home();
     for(int o = 1; o <= 2; o++){
        cin >> n >> k;
        long long kq = 0;
        if(k >=1e4){
            for(long long i = 1; i * k <= n; i++){
                kq += tcs(i*k);
            }
        }
        else{
            for(int i = 0; i <= 13; i++){
                for(int j = 0; j <= 1; j++){
                    for(int x = 0; x <= 9999; x++){
                        for(int y = 0; y <= 108; y++)dp[i][j][x][y] = -1;
                    }
                }
            }
            kq = dpr(0, 1, 0, doi(n), 0, k);
        } 
        cout << kq << '\n';
     }
     return 0;     
}

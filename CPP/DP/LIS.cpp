#include<bits/stdc++.h>
using namespace std;

int n;
int arr[] = {7, 9, 5, 3, 6, 2, 8, 9};

int LIS(){
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int mx = 1;
    for(int i = 0; i < n; i++) mx = max(mx, dp[i]);
    return mx;
}

int LIS_NlogN(){
    vector<int> tails;

    for(int i = 0; i < n; i++){
        auto it = lower_bound(tails.begin(), tails.end(), arr[i]);
        if(it == tails.end()) tails.push_back(arr[i]);
        else *it = arr[i];
    }

    return tails.size();
}

void LIS_Path(){
    vector<int> tails_idx;
    vector<int> par(n, -1);

    for(int i = 0; i < n; i++){
        auto it = lower_bound(tails_idx.begin(), tails_idx.end(), arr[i],
        [](int idx, int val){
            return arr[idx] < val;
        });

        int pos = it - tails_idx.begin();
        if(pos > 0) par[i] = tails_idx[pos - 1];

        if(it == tails_idx.end()) tails_idx.push_back(i);
        else *it = i;
    }

    vector<int> path;
    for(int curr = tails_idx.back(); curr != -1; curr = par[curr])
        path.push_back(curr);
    reverse(path.begin(), path.end());

    for(int idx: path) cout << arr[idx] << ' ';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    n = sizeof(arr) / sizeof(arr[0]);

    cout << LIS() << '\n';
    cout << LIS_NlogN() << '\n';

    LIS_Path();

    return 0;
}
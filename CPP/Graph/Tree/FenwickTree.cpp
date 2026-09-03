#include<bits/stdc++.h>
using namespace std;

int sz;

struct BIT{
    vector<int> tree;

    public:
        BIT(int size){
            tree.resize(size + 1, 0);
        }

        void add(int n, int i){
            for(; i <= sz; i += i&-i) tree[i] += n;
        }

        int sum(int i){
            int sum = 0;
            for(; i >= 1; i -= i&-i) sum += tree[i];
            return sum;
        }

        int query(int l, int r){
            if(l > r) swap(l, r);
            return sum(r) - sum(l - 1); 
        }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {2, 5, 7, 8, 1, 4, 3};
    sz = sizeof(arr) / sizeof(arr[0]);

    BIT fw(sz);
    
    for(int i = 1; i <= sz; i++) fw.add(arr[i - 1], i);
    
    cout << fw.query(4, sz) << '\n';

    fw.add(100, sz - 1);

    cout << fw.query(4, sz) << '\n';
    
    return 0;
}
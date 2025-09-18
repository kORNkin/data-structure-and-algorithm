/*
Topic: Lambda Function
Sub-Topic: Sort Struct with Lambda Function
Author: kornkin
*/

#include<bits/stdc++.h>
using namespace std;

struct Tuple {
    int a, b, c;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<Tuple> vec = {
        {1, 2, 3}, {2, 5, 6}, {3, 4, 7}, {1, 4, 4}, {4, 7, 1}
    };

    //----------------
    sort(vec.begin(), vec.end(), [](const Tuple &l, const Tuple &r){
        return l.c < r.c;
    });
    //----------------

    for(auto t : vec){
        cout << t.a << ' ' << t.b << ' ' << t.c << '\n';
    }
}
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public: 
    int n;
    vector<int> par;
    vector<int> rank;

    DisjointSet(int n){
        this->n = n;
        for(int i=0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int getPar(int x){
        if(par[x] == x) return x;

        return par[x] = getPar(par[x]);
    }

    void unionByRank(int a , int b){
        int parA = getPar(a);
        int parB = getPar(b);

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++; 
        }
        else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }
        else{
            par[parA] = parB;
        }
    }
};


int main(){
    DisjointSet dj(6);
    dj.unionByRank(0,2);
    cout<<dj.getPar(2)<<endl;
    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    dj.unionByRank(0,3);
    cout<<dj.getPar(2)<<endl;
    dj.unionByRank(0,4);


    return 0;
}
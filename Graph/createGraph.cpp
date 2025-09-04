#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> * l;

public:

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u =0; u<V; u++){
            list<int> neighbours  = l[u];
            cout<<u<<" : ";
            for(int e:neighbours){
                cout<<e<<" ";
            }
            cout<<endl;
        }
    }

    // void dfs(int u , visited ){
    //     visited[u] = true;
    //     cout<<u<<" ";

    //     list<int> neighbours = l[u];
    //     for(int e: neighbours){
    //         if(!visited)
    //     }
    // }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.print();

    return 0;
}
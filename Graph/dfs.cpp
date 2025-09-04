#include<bits/stdc++.h>
using namespace std;


class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int v , int u){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<" : ";
            list<int> neighbours = l[i];
            for(int e:neighbours){
                cout<<e<<" ";
            }
            cout<<endl;
        }
    }

    void dfs(int u , vector<bool> &visited){
        visited[u] = true;
        cout<<u<<" ";

        for(int e: l[u]){
            if(!visited[e]){
                dfs(e , visited);
            }
        }
    }
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

    vector<bool> visited(5 , false);
    g.dfs(0 , visited);

    return 0;
}
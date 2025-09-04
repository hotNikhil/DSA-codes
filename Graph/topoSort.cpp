#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> * l;
    bool isUndirec;

public:

    Graph(int V , bool isUndirec = true){
        this->V = V;
        l = new list<int> [V];
        this->isUndirec = isUndirec;
    }

    void addEdge(int u , int v){
        l[u].push_back(v);
        if(isUndirec) l[v].push_back(u);
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

    void topoHelper(int src , vector<bool> &vis, stack<int> &s){
        vis[src] = true;

        for(int e: l[src]){
            if(!vis[e]) topoHelper(e , vis , s);
        }

        s.push(src);
    }

    void topoSort(){
        vector<bool> vis(V ,false);
        stack<int> s;

        for(int i = 0; i<V;i++){
            if(!vis[i]){
                topoHelper(i , vis , s);
            }
        }

        while(s.size()>0){
            cout<<s.top()<<" ";
            s.pop();
        }
    }



};


int main(){
    Graph g(6 , false);

    g.addEdge(5,2);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);

    g.topoSort();

    return 0;

}

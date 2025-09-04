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

    //KANHS ALGO
    

    void clacIndegree(vector<int> &inDeg){
        for(int u =0; u<V; u++){
            for(int v: l[u] ) inDeg[v]++;
        }
    }

    void kahnAlgo(){
        vector<int> inDeg(V , 0);
        clacIndegree(inDeg);
        
        queue<int> q;
        //push nodes with 0 indegree as starting point

        for(int i=0; i<V; i++){
            if(inDeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int curr  = q.front();
            q.pop();

            cout<<curr<<" ";

            for(int e:l[curr]){
                inDeg[e]--;
                if(inDeg[e] == 0) q.push(e);
            }
        }

        cout<<endl;
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

    g.kahnAlgo();

    return 0;

}

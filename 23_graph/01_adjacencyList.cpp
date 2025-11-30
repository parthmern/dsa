#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class graph{

    public:
    
    unordered_map<int, list<int> > adj;
    
    void addEdge(int u, int v, bool direction){
        // direction = 0 then undirected
        // direction = 1 then directed

        adj[u].push_back(v);    // u -- v
        if(direction == 0){
            adj[v].push_back(u);    // v -- u
        }

    }

    void printAdjList(){

        for(auto i : adj){
            cout << i.first << "-->";
            for(auto j: i.second){
                cout << j << ", ";
            }
            cout << endl;
        }

    }
};

int main(){
    graph g;

    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 1);

    g.printAdjList();

    return 0;

}
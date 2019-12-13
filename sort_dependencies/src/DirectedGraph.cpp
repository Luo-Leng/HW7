#include "DirectedGraph.h"


DirectedGraph::DirectedGraph(Edge *edges, int size) {
    for (int i = 0; i < size; i++) {
        int src = edges[i].src, dest = edges[i].dest;
        if (nodes.count(src) == 0) {
            nodes[src] = new SingleLinkedList<int>();
        }
        nodes[src]->add(dest);
        if (nodes.count(dest) == 0) {
            nodes[dest] = new SingleLinkedList<int>();
        }
    }
}

DirectedGraph::~DirectedGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        delete (*it).second;
    }
}

void DirectedGraph::printGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        printf("node(%d) has edges: ", (*it).first);
        for (auto itl = (*it).second->begin(); itl != (*it).second->end(); itl++) {
            printf("%d ", (*itl));
        }
        printf("\n");
    }
}

//https://www.includehelp.com/cpp-programs/topological-sort-implementation.aspx
void DirectedGraph::topologySort(int val, LinkedStack<int> &Stack, set<int>& visited)
{

    visited.insert(val);
    for (auto it = nodes[val]->begin(); it != nodes[val]->end(); it++) {

            if((visited.find((*it))==visited.end()))
            {
                topologySort(*it, Stack, visited);
            }

    }

    Stack.push(val);
}

vector<int> *DirectedGraph::topologySort() {
    vector<int>* ret=new vector<int>();

    LinkedStack<int> Stack;
    int V = nodes.size();

    set<int> visited;
    for(auto it = nodes.begin();it!=nodes.end();it++){
        //https://www.cs.helsinki.fi/u/tpkarkka/alglib/k06/lectures/iterators.html
        //Algorithm find -----subrange of a sequence
        if((visited.find((*it).first)==visited.end()))
        {
            topologySort((*it).first, Stack, visited);
        }
    }


    while (Stack.isEmpty() == false)
    {
        ret->push_back(Stack.peek());
        Stack.pop();

    }
    return ret;
}




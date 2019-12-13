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


void DirectedGraph::topologySort(int val, LinkedStack<int> &Stack, bool visited[])

{

    visited[val] = true;
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        for (auto itl = (*it).second->begin(); itl != (*it).second->end(); itl++) {
            if(!visited[*itl])
            {
                topologySort(*itl,  Stack, visited);
            }
        }
    }

    Stack.push(val);
}

vector<int> *DirectedGraph::topologySort() {
    vector<int>* ret=new vector<int>();

    LinkedStack<int> Stack;
    int V = nodes.size();

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;


    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologySort(i,  Stack, visited);
    while (Stack.isEmpty() == false)
    {
        ret->push_back(Stack.peek());
        Stack.pop();

    }
    return ret;
}




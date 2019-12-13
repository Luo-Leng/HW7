#include "DirectedGraph.h"
#include "gtest/gtest.h"

TEST(topology_sort, print_test) {
    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    { 0, 1 }, { 0, 3 }, { 1, 2 },
                    { 1, 3 }, { 2, 4 }, {3, 4}
            };

    DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));
    graph.printGraph();
}


TEST(topology_sort, test_8_nodes) {

Edge edges[] =
        {
                // pair (x, y) represents edge from x to y
                { 7,5}, { 7, 6 }, { 5,4 },
                { 5, 2 }, { 6, 4 }, {6, 3},{2,1}, {3,1},{1,0}
        };
    DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));
    auto v = graph.topologySort();
    graph.printGraph();

vector<int> ans1{7  ,5  ,2  ,6  ,3  ,1  ,0  ,4  ,};
vector<int> ans2{7  ,5  ,2  ,6  ,3  ,1  ,4  ,0  ,};
vector<int> ans3{7  ,5  ,2  ,6  ,3  ,4  ,1  ,0  ,};
vector<int> ans4{7  ,5  ,2  ,6  ,4  ,3  ,1  ,0  ,};
vector<int> ans5{7  ,5  ,6  ,2  ,3  ,1  ,0  ,4  ,};
vector<int> ans6{7  ,5  ,6  ,2  ,3  ,1  ,4  ,0  ,};
vector<int> ans7{7  ,5  ,6  ,2  ,3  ,4  ,1  ,0  ,};
vector<int> ans8{7  ,5  ,6  ,2  ,4  ,3  ,1  ,0  ,};
vector<int> ans9{7  ,5  ,6  ,3  ,2  ,1  ,0  ,4  ,};
vector<int> ans10{7  ,5  ,6  ,3  ,2  ,1  ,4  ,0  ,};
vector<int> ans11{7  ,5  ,6  ,3  ,2  ,4  ,1  ,0  ,};
vector<int> ans12{7  ,5  ,6  ,3  ,4  ,2  ,1  ,0  ,};
vector<int> ans13{7  ,5  ,6  ,4  ,2  ,3  ,1  ,0  ,};
vector<int> ans14{7  ,5  ,6  ,4  ,3  ,2  ,1  ,0  ,};
vector<int> ans15{7  ,6  ,3  ,5  ,2  ,1  ,0  ,4  ,};
vector<int> ans16{7  ,6  ,3  ,5  ,2  ,1  ,4  ,0  ,};
vector<int> ans17{7  ,6  ,3  ,5  ,2  ,4  ,1  ,0  ,};
vector<int> ans18{7  ,6  ,3  ,5  ,4  ,2  ,1  ,0  ,};
vector<int> ans19{7  ,6  ,5  ,2  ,3  ,1  ,0  ,4  ,};
vector<int> ans20{7  ,6  ,5  ,2  ,3  ,1  ,4  ,0  ,};
vector<int> ans21{7  ,6  ,5  ,2  ,3  ,4  ,1  ,0  ,};
vector<int> ans22{7  ,6  ,5  ,2  ,4  ,3  ,1  ,0  ,};
vector<int> ans23{7  ,6  ,5  ,3  ,2  ,1  ,0  ,4  ,};
vector<int> ans24{7  ,6  ,5  ,3  ,2  ,1  ,4  ,0  ,};
vector<int> ans25{7  ,6  ,5  ,3  ,2  ,4  ,1  ,0  ,};
vector<int> ans26{7  ,6  ,5  ,3  ,4  ,2  ,1  ,0  ,};
vector<int> ans27{7  ,6  ,5  ,4  ,2  ,3  ,1  ,0  ,};
vector<int> ans28{7  ,6  ,5  ,4  ,3  ,2  ,1  ,0  ,};


ASSERT_TRUE((*v)==ans1 || (*v)==ans2 ||(*v)==ans3 || (*v)==ans4 ||
(*v)==ans5 || (*v)==ans6 ||(*v)==ans7 || (*v)==ans8 ||
(*v)==ans9 || (*v)==ans10 ||(*v)==ans11 || (*v)==ans12 ||
(*v)==ans13 || (*v)==ans14 ||(*v)==ans15 || (*v)==ans16 ||
(*v)==ans17 || (*v)==ans18 ||(*v)==ans19 || (*v)==ans20 ||
(*v)==ans21 || (*v)==ans22 ||(*v)==ans23 || (*v)==ans24 ||
(*v)==ans26 || (*v)==ans25 ||(*v)==ans27 || (*v)==ans28 );

    delete v;

}

TEST(topology_sort, test_5_nodes) {

    Edge edges[] =
            {
                    // pair (x, y) represents edge from x to y
                    { 0, 1 }, { 0, 3 }, { 1, 2 },
                    { 1, 3 }, { 2, 4 }, {3, 4}
            };
DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));
auto v = graph.topologySort();
vector<int> ans1{0, 1, 3, 2, 4,};
vector<int> ans2{0, 1, 2, 3, 4,};

ASSERT_TRUE((*v)==ans1 || (*v)==ans2);

delete v;

}


TEST(topology_sort, test_1_nodes) {
    Edge edges[] = {};

    DirectedGraph graph(edges, sizeof(edges)/sizeof(edges[0]));
    auto v = graph.topologySort();

    ASSERT_TRUE((*v).empty());

    delete v;
}


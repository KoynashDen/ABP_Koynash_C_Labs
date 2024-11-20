//
// Created by Denys on 20.11.1899.
//

#include "Lab_13.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class GraphNode {
private:
    string name;

public:

    GraphNode() : name("Unnamed") {}


    explicit GraphNode(const string &name) : name(name) {}


    GraphNode(const GraphNode &other) : name(other.name) {}


    ~GraphNode() = default;


    string get_name() const {
        return name;
    }


    void set_name(const string &new_name) {
        name = new_name;
    }
};


class Graph {
private:
    vector<GraphNode *> nodes; // вузли
    vector<pair<GraphNode *, GraphNode *>> connections; // звязки

public:

    Graph() = default;


    ~Graph() {
        clear_graph();
    }


    GraphNode *add_node(const string &name) {
        auto *node = new GraphNode(name);
        nodes.push_back(node);
        return node;
    }


    void remove_node(GraphNode *node) {
        if (!node) return;


        vector<GraphNode *> connected_nodes;
        for (const auto &connection : connections) {
            if (connection.first == node) {
                connected_nodes.push_back(connection.second);
            } else if (connection.second == node) {
                connected_nodes.push_back(connection.first);
            }
        }


        for (size_t i = 0; i < connected_nodes.size(); ++i) {
            for (size_t j = i + 1; j < connected_nodes.size(); ++j) {
                add_connection(connected_nodes[i], connected_nodes[j]);
            }
        }


        connections.erase(remove_if(connections.begin(), connections.end(),
                                    [node](const pair<GraphNode *, GraphNode *> &connection) {
                                        return connection.first == node || connection.second == node;
                                    }),
                          connections.end());


        nodes.erase(remove(nodes.begin(), nodes.end(), node), nodes.end());
        delete node;
    }



    void add_connection(GraphNode *node1, GraphNode *node2) {
        if (node1 && node2) {
            connections.emplace_back(node1, node2);
        }
    }


    void clear_graph() {
        for (auto *node : nodes) {
            delete node;
        }
        nodes.clear();
        connections.clear();
    }

    //обход
    void traverse_graph() const {
        cout << "Граф містить:" << endl;


        for (const auto &node : nodes) {
            cout << "Вузол: " << node->get_name() << endl;
        }

        cout << "Звязки:" << endl;
        for (const auto &connection : connections) {
            cout << connection.first->get_name() << " -> " << connection.second->get_name() << endl;
        }
    }
};


int lab_13() {
    Graph graph;


    auto *nodeA = graph.add_node("Вузол A");
    auto *nodeB = graph.add_node("Вузол B");
    auto *nodeC = graph.add_node("Вузол C");

    graph.add_connection(nodeA, nodeB);
    graph.add_connection(nodeB, nodeC);

    cout << "Початковий граф:" << endl;
    graph.traverse_graph();


    cout << "Видалення вузла B зі звязками..." << endl;
    graph.remove_node(nodeB);


    graph.traverse_graph();


    cout << "Видалення графу..." << endl;
    graph.clear_graph();
    graph.traverse_graph();

    return 0;
}

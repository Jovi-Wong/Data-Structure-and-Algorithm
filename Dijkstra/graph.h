#ifndef __JOVI__
#define __JOVI__
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Aim
{
public:    
    int id;
    double weight;
    Aim(int i, double w);
};


class Side
{
public:
    int _start;
    int _end;
    double _weight;
    Side();
};


class Edge
{
public:
    int _size;
    std::vector<Side> base;
    Edge(int s);
    Edge(){};
};

class Node
{
public:
    double key = std::numeric_limits<double>::max();
    std::vector<Aim> adj;
    bool ex = 0;
    int parent =0;
    Node(){};
};

class Vertex
{
public:
    int _size;
    std::vector<Node> set;
    Vertex(int s);
    Vertex(){};
};


class Graph
{
public:
    Vertex _v;
    Edge _e;
    Graph(Vertex V, Edge E);
    double Dijkstra(int s=0); 
    int display(int num);
private:
    int Extract_Min_index(std::vector<Node>& Q);
    int Extract_Max_index(std::vector<Node> a);
};
#endif

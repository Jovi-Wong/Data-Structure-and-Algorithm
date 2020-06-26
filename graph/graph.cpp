#include "graph.h"
Aim::Aim(int i, double w)
{
    id = i;
    weight = w;
};

int Graph::display(int num)
{
    int p =_v.set[num].parent;
    std::cout << num <<" ";
    while (p!= -1)
    {
        std::cout << p << " ";
        p = _v.set[p].parent;
    }    
    return 0;

};

Side::Side()
{
    int s, e;
    double w;
    std::cout << "input start, end and weight" << std::endl;
    std::cin >> s >> e >> w;
    std::cout << std::endl;
    _start = s;
    _end = e;
    _weight = w;
};


Edge::Edge(int s)
{
    _size = s;
    for (int i=0; i < s; i++)
    {
        Side a;
        base.push_back(a);
    } 
};


Vertex::Vertex(int s)
{
    _size = s;
    for(int i=0; i<s; i++)
    {
        Node a;
        set.push_back(a);    
    }
};

Graph::Graph(Vertex V, Edge E)
{
    _v = V;
    _e = E;
    for (int i=0; i<_e._size; i++)
    {
        int tgt = _e.base[i]._end;
        double w = _e.base[i]._weight;
        int org = _e.base[i]._start;        
        Aim a(tgt, w);
        _v.set[org].adj.push_back(a);        
    }
};

int Graph::Extract_Min_index(std::vector<Node>& Q)
{
    int idx = -1;
    for(int i=0; i<Q.size(); i++)
    {
        if (Q[i].ex == false)
        {
            idx = i;
            break;            
        }
    }    

    if (idx == -1)
    {
        return -1;    
    }

    for(int i=idx; i<Q.size(); i++)
    {        
        if ((Q[i].key < Q[idx].key) and (Q[i].ex == false))
        {
            idx = i;
        }
    }
    
    Q[idx].ex = true; 
    return idx;
};

double Graph::Dijkstra(int s)
{
    std::vector<Node>& Q = _v.set;    
    Q[s].key = 0;
    Q[s].parent = -1;
    for(int c=0; c<Q.size(); c++)
    {
        int u = Extract_Min_index(Q);
        for(int j=0; j<Q[u].adj.size(); j++)
        {
            int tgt = Q[u].adj[j].id;       
            double d = Q[u].adj[j].weight;             
            if (Q[tgt].key > Q[u].key + d)        
            {        
                 Q[tgt].key = Q[u].key + d;
                 Q[tgt].parent = u;
            }
        }
    }
    double w;
    for (int k=0; k<Q.size(); k++)
    {
        if (Q[k].parent != -1)            
        {
            w = w + (Q[k].key - Q[Q[k].parent].key);
        }
    }
    return w;
};

int Graph::Extract_Max_index(std::vector<Node> a)
{
    int rst=0;
    for (int i=0; i<a.size(); i++)
    {
        if(a[i].key>a[rst].key)
        {
            rst = i;            
        }
    }
    return rst; 
};

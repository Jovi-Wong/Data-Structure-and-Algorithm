#include "graph.h"

int main()
{
    Vertex a(5);
    Edge b(10);
    Graph c(a,b);    
    std::cout <<"length of the shortest path to connect all node is " <<c.Dijkstra() << std::endl;
    std::cout << "which Node do you want to show path?"<< std::endl;
    int i;
    std::cin >> i;
    std::cout << std::endl;
    std::cout << "display Node number " << i << "'s path "<< std::endl;
    c.display(i); 
    std::cout<< std::endl;
    return 0;
};

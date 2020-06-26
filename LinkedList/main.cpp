#include "simple_list.cpp"
int main (int argc, char *argv[])
{
    LinkedList A;
    LinkedList B(1);
    for (int i = 0; i < 3; i++)
    	A.append(i);
    A.push(100);
    A.step();
    A.step();
    A.get_value();
    A.insert(13);
    A.push(101);
    B.del();
    A.print();
    B.print();
    A.begin();
    A.print();
    A.clean();
    A.print();
    return 0;
};

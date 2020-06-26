#include <iostream>
#include <limits>

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *__head;
    int __length;
    Node *__tail;
    Node *__current;
public:   
    LinkedList()
    {
	__head = __tail = __current = NULL;
	__length = 0;
    };
    LinkedList(int _v);
    int append(int _v);
    int push(int _v);
    int print() const;
    int insert(int _v);
    int del();
    int clean();
    int step();
    int begin();
    int get_value();
};

LinkedList::LinkedList(int _v)
{
    __head = new Node;
    __head->next = NULL;
    __head->data = _v;
    __current = __head;
    __tail = __head;
    __length = 1;
};


int LinkedList::clean()
{
    if (__head != NULL)
    {
	while (__head->next != NULL)
	{
	    Node *t = __head;
	    __head = __head->next;
	    delete t;
	}
	delete __head;
	__head = NULL;
	/*BUG������ֻ�ǰѽڵ�ɾ���ˣ�LinkedList���__lengthû�����㣬__current��__tailû�иĳ�NULL*/ 
    }
    return 0;
};

int LinkedList::del()
{
    if (__head != NULL)
    {
	if (__length == 1)
	{
	    if (__current != __tail)
	    {
		std::cerr << "Error!" << std::endl;
		exit(-1);
	    }
	    delete __head;
	    __head = __tail = __current = NULL;
	    __length = 0;
	}
	else
	{
	    if (__current == __tail)
	    { 
		std::cerr << "Error!" << std::endl;
		exit(-1);
	    }
	    else
	    {
		Node *t = __current->next;
		__current->next = __current->next->next;
		delete t;
		__length -= 1;
	/*BUG: ����û�п��ǵ����__currentָ����ǵ����ڶ����ڵ㣬��ôβ�ڵ�ᱻɾ������ʱҪ�޸�__tail��ָ��λ��*/ 
	    }
	}
    }
    return 0;
};

int LinkedList::insert(int _v)
{
    Node *t = new Node;
    t->data = _v;
    if (__head == NULL)
    {
	__head = t;
	__current = t;
	__tail = t;
	__length = 1;
    }
    else
    {
	t->next = __current->next;
	__current->next = t;
	__length += 1;
    }
    /*BUG��������������һ�������ƣ����__current->nextָ��__tail�Ļ�������Ҫ�޸�__tail��ֵ*/
    return 0;
};

int LinkedList::print() const
{
    if (__head != NULL)
    {
	Node *p = __head;
	while (p->next != NULL)
	{
	    std::cout << p->data << "\t";
	    p = p->next;
	}
	std::cout << p->data << std::endl;
    }
    return 0;
};

int LinkedList::append(int _v)
{
    if (__head == NULL)
    {
	__head = new Node;
	__head->data = _v;
	__head->next = NULL;
	__length = 1;
	__current = __head;
	__tail = __head;
    }
    else
    {
	__tail->next = new Node;
	__tail->next->data = _v;
	__tail->next->next = NULL;
	__length += 1;
	__tail = __tail->next;
    }
    return 0;
};

int LinkedList::push(int _v)
{
    Node *t = new Node;
    t->next = __head;
    t->data = _v;
    __head = t;
    __current = __head;
    __length += 1;
    /*BUG:���ԭ���������ǿյģ���ôԭ����__tailָ�����NULL���Կ�����push��Ҫ�޸�__tail��ֵ*/ 
    return 0;
};

int LinkedList::step()
{
  if (__tail !=  __current)
  {
         __current = __current->next;
  }
  else
  {
    std::cerr << "FBI Warning:current has already reach the tail"; 
    exit(-1);
  }
    return 0;
}

int LinkedList::begin()
{
  __current = __head;
  return 0;
}

int LinkedList::get_value()
{
  if (__current == NULL)
  {
    std::cerr << std::numeric_limits<int>::min();
    exit(-1);
  }
  else
  {
    std::cout << __current->data<< "\t";
  }
  return 0;
}


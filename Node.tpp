#ifndef NODE_CPP
#define NODE_CPP
#include "Node.h"

template <typename T>
Node<T> :: Node(const T& v): data(v), next(nullptr){}

#endif
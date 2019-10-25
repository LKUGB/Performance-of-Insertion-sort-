#include "Node.h"

Node::Node(int v, Node *n) {
    value = v;
    next = n;
}

int Node::getValue() const {
    return value;
}

Node* Node::getNext() const {
    return next;
}

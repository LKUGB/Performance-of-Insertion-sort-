#ifndef NODE_H
#define NODE_H

class Node {
public:
    int value;
    Node* next;

    // Node constructor
    Node(int v = 0, Node* n = nullptr);
    // Node value accessor
    int getValue() const;
    // Node next pointer accessor
    Node* getNext() const;
};

#endif //NODE_H

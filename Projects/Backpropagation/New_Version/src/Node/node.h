#ifndef NODE_H
#define NODE_H

#include "../headers.h"

// Singular node in neural net.
class Node {
public:
    DATATYPE impact_on_error;
    DATATYPE value;

public:

    // Default constructor for node.
    Node() : impact_on_error(0), value(0) {}

    // Prepare node for iteration.
    void Prepare();

    // Activation function
    void Activation();
};

#endif /* NODE_H */
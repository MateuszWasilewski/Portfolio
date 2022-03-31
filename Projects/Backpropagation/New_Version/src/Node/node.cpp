#ifndef NODE_CPP
#define NODE_CPP

#include "../headers.h"

void Node::Prepare() {
    value = 0;
    impact_on_error = 0;
}

void Node::Activation() {
    value = 1 / (1 + exp(-value));
}

#endif /* NODE_CPP */
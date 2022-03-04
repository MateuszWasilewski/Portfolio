#ifndef LAYER_CPP
#define LAYER_CPP

#include "layer.h"

Layer::Layer(const size_t& size) {
    nodes.reserve(size);
    for (size_t iter = 0; iter < size; iter++)
        nodes.emplace_back();
}

void Layer::Prepare() {
    for (Node& node : nodes) {
        node.Prepare();
    }
}

Node& Layer::operator[](const size_t& iter) {
    return nodes[iter];
}

#endif


#ifndef LAYER_H
#define LAYER_H

#include "../headers.h"

// Class for individual layer consising of array of nodes.
class Layer {
public:
    std::vector <Node> nodes;

    // Layer constructor, creates given number of nodes.
    Layer(const size_t& size);

    // Returns number of nodes in this layer.
    size_t size() const {
        return nodes.size();
    }

    // Prepare layer for iteration.
    void Prepare();

    // Simlifies accesing nodes in layer.
    Node& operator[](const size_t& iter);
};

#endif
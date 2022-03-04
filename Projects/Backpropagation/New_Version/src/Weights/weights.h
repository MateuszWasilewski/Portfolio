#ifndef WEIGHTS_H
#define WEIGHTS_H

#include "../headers.h"

// Class used for correct model operations, holds model weights and adjustments to be done to them.
class Weights {
private:
    std::vector <DATATYPE> values;
    std::vector <DATATYPE> adjustments;
    size_t prev_size;
    size_t next_size;

public:
    // Contructor accepting 2 sizes (prev and next layers).
    Weights(const size_t& prev_size, const size_t& next_size);

    // Returns reference to weights connecting 
    // node with id = prev in previous layer and
    // node with id = next in next layer.
    DATATYPE& Value(const size_t& prev, const size_t& next);
    
    // Returns reference to adjustment to weight connecting 
    // node with id = prev in previous layer and
    // node with id = next in next layer.
    DATATYPE& Adjustment(const size_t& prev, const size_t& next);

    // Read weights from given input.
    void ReadWeights(std::fstream& file);

    // Write weights to given output.
    void WriteWeights(std::fstream& file);

    // Adjusts weights in model according to previosly calculated values.
    void AdjustWeights();
};


#endif
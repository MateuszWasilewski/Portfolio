#ifndef MODEL_H
#define MODEL_H

#include "../headers.h"

// Class creating and managing AI model using backpropagation algortithm implemented form scratch with minimal changes. 
class Model {
private:

    std::vector <Layer> layers;
    std::vector <Weights> weights;

    // Prepare model for iteration.
    void Prepare();

    // Function propagating model forward.
    void GoForward();

    // Calculates error in last layer.
    DATATYPE Calculate_Error(size_t correct_answer);

    // Performs backpropagation on model.
    void BackPropagation();

    // Adjusts weights in model according to previosly calculated values.
    void AdjustWeights();

    // Returns label which according to the model is the correct label.
    size_t MakePrediction();

public:
    // Constructor for class model, takes in path to file storing all model weights in binary
    // as well as a list of nodes in each layer.
    Model(const std::vector <size_t>& layers_sizes);

    // Read all model weights from file given, if reading fails then values are randomly generated.
    void ReadWeights(const std::string& file);

    // Write all model weight to file given.
    void WriteWeights(const std::string& file);

    // Train model for given number of epochs.
    void Train(const size_t& number_of_epochs);

    // Checks model accuracy on test data.
    void CheckAccuracy();
};




#endif
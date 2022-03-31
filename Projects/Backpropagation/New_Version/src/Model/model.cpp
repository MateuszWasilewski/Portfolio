#ifndef MODEL_CPP
#define MODEL_CPP

#include "model.h"

Model::Model(const std::vector <size_t> &layers_sizes) {
    if (layers_sizes.size() < 1) {
        std::cout << "Invalid Model\n";
        return;
    }

    layers.reserve(layers_sizes.size());
    for (size_t layer_size : layers_sizes) {
        layers.emplace_back(layer_size);
    }

    weights.reserve(layers_sizes.size() - 1);
    for (size_t iter = 0; iter + 1 < layers.size(); iter++) {
        weights.emplace_back(layers_sizes[iter], layers_sizes[iter + 1]);
    }
}

void Model::ReadWeights(const std::string& File) {
    srand(time(NULL));  // Set seed for possible random weights to be generated.
    std::fstream file(File, std::ios::in | std::ios::binary);
    for (auto& weights_between_layers : weights) 
        weights_between_layers.ReadWeights(file);
    // File closes automatically.
}

void Model::WriteWeights(const std::string& File) {
    std::fstream file(File, std::ios::out | std::ios::binary);
    for (auto& weights_between_layers : weights) {
        weights_between_layers.WriteWeights(file);
    }
    // File closes automatically.
}

void Model::Prepare() {
    for (Layer& layer : layers) {
        layer.Prepare();
    }
}

static void ForwardOnLayers(Layer& prev, Weights& weights, Layer& next) {
    for (size_t iter_prev = 0; iter_prev < prev.nodes.size(); iter_prev++) {
        for (size_t iter_next = 0; iter_next < next.nodes.size(); iter_next++) {
            next[iter_next].value += prev[iter_prev].value * weights.Value(iter_prev, iter_next);
        }
    }
}

static void BackwardOnLayers(Layer& prev, Weights& weights, Layer& next) {
    for (size_t iter_prev = 0; iter_prev < prev.nodes.size(); iter_prev++) {
        for (size_t iter_next = 0; iter_next < next.nodes.size(); iter_next++) {
            prev[iter_prev].impact_on_error += weights.Value(iter_prev, iter_next) * next[iter_next].impact_on_error;
            weights.Adjustment(iter_prev, iter_next) += next[iter_next].impact_on_error * prev[iter_prev].value;
        }
    }
}

void Model::GoForward() {
    for (size_t iter = 0; iter < layers.size(); iter++) {
        for (Node& node : layers[iter].nodes) 
            node.Activation();
        if (iter + 1 < layers.size())
            ForwardOnLayers(layers[iter], weights[iter], layers[iter + 1]);
    }
}

void Model::Train(const size_t& number_of_epochs) {
    for (size_t epoch = 1; epoch <= number_of_epochs; epoch++) {
        Clock timer("epoch");
        Files learn_data(PATH + "t10k-images.idx3-ubyte", PATH + "t10k-labels.idx1-ubyte");
        std::cout << "-----------------------------------\n";
        std::cout << "Starting epoch: " << epoch << " / " << number_of_epochs << std::endl;

        DATATYPE error = 0;
        size_t correct_answer;
        size_t good_guess_counter = 0;
        const size_t batch_size = 100;
        for (size_t iter = 1; iter <= learn_data.number_of_tests; iter++) {
            Prepare();
            learn_data.WriteInputsToLayer(layers[0]);
            correct_answer = learn_data.GetCorrectAnswer();
            GoForward();
            error += Calculate_Error(correct_answer);
            BackPropagation();
            good_guess_counter += (correct_answer == MakePrediction());

            // Batch multiple adjustments together.
            if (iter % batch_size == 0) {
                AdjustWeights();
            }
        }
        std::cout << "Average error per image: " << error / (DATATYPE) learn_data.number_of_tests << std::endl;
        std::cout << "Accuracy achievied: " << (DATATYPE) good_guess_counter / (DATATYPE) learn_data.number_of_tests << std::endl;
    }
}

DATATYPE Model::Calculate_Error(size_t correct_answer) {
    size_t node_id = 0;
    DATATYPE error = 0;
    for (Node& node : layers[layers.size() - 1].nodes) {
        node.impact_on_error = node.value - (node_id == correct_answer ? 1 : 0);
        error += node.impact_on_error * node.impact_on_error / 2;
        node_id++;
    }
    return error;
}

void Model::BackPropagation() {
    for (int iter = layers.size() - 2; iter >= 0; iter--) {
        BackwardOnLayers(layers[iter], weights[iter], layers[iter + 1]);
    }
}

void Model::AdjustWeights() {
    for(Weights& wg : weights)
        wg.AdjustWeights();
}

size_t Model::MakePrediction() {
    DATATYPE highest_score = -10;
    size_t answer = -1;
    size_t node_id = 0;
    for (Node& node : layers[layers.size() - 1].nodes) {
        if (node.value > highest_score) {
            highest_score = node.value;
            answer = node_id;
        }
        node_id++;
    }
    return answer;
}

void Model::CheckAccuracy() {
    Files test_data(PATH + "train-images.idx3-ubyte", PATH + "train-labels.idx1-ubyte");
    std::cout << "-----------------------------------\n";
    std::cout << "Starting testing" << std::endl;

    size_t good_guess_counter = 0;
    DATATYPE error = 0;
    for (size_t iter = 1; iter <= test_data.number_of_tests; iter++) {
        test_data.WriteInputsToLayer(layers[0]);
        size_t correct_answer = test_data.GetCorrectAnswer();
        GoForward();
        error += Calculate_Error(correct_answer);
        BackPropagation();
        good_guess_counter += (correct_answer == MakePrediction());
    }
    std::cout << "Average error per image: " << error / (DATATYPE) test_data.number_of_tests << std::endl;
    std::cout << "Accuracy achievied: " << (DATATYPE) good_guess_counter / (DATATYPE) test_data.number_of_tests << std::endl;
}

#endif /* MODEL_CPP */
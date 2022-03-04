#ifndef WEIGHTS_CPP
#define WEIGHTS_CPP


#include "../headers.h"

Weights::Weights(const size_t& prev_size, const size_t& next_size) 
    : prev_size(prev_size), next_size(next_size) {
    const size_t total_size = prev_size * next_size;
    values.reserve(total_size);
    adjustments.reserve(total_size);
    for (size_t iter = 0; iter < total_size; iter++) {
        values.push_back(0);
    }
}


DATATYPE& Weights::Value(const size_t& prev, const size_t& next) {
    return values[next_size * prev + next];
}

DATATYPE& Weights::Adjustment(const size_t& prev, const size_t& next) {
    return adjustments[next_size * prev + next];
}

void Weights::ReadWeights(std::fstream& file) {
    for (DATATYPE& weight : values) {
        weight = GetValue(file);
    }
}

void Weights::WriteWeights(std::fstream& file) {
    for (DATATYPE& weight : values) {
        WriteToFile(file, weight);
    }
}

void Weights::AdjustWeights() {
    for (size_t iter = 0; iter < values.size(); iter++) {
        values[iter] -= adjustments[iter] * RATE;
        //LOG("adjustment " << std::fixed << std::setprecision(5) << adjustments[iter]);
        adjustments[iter] = 0;
    }
}


#endif
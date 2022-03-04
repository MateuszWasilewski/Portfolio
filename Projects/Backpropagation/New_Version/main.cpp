#include "src/headers.h"
#include "src/cpps.cpp"

// Example cpp program using model.
// It loads previously calculated weights and checks model accuracy

int main() {
    Model model({784, 50, 10});
    model.ReadWeights("wg_83%.bin");
    //model.Train(20);
    model.CheckAccuracy();
    //model.WriteWeights("wg.bin");
    return 0;
}
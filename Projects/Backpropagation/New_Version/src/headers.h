#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <assert.h>
#include <chrono>
#include <iomanip>


#ifndef DATATYPE 
#define DATATYPE double
#endif

#define RATE 0.05                   // Learning rate.
#define MIN_VALUE 0.1               // abs(min possible random weight value)
#define MAX_VALUE 0.5               // abs(max possible random weight value)
#define PATH std::string("Files/")  // Path to folder storing files from MNIST database.

// Managing headers
#include "Clock/clock.h"
#include "Node/node.h"
#include "Layer/layer.h"
#include "File_Operations/file.h"
#include "Weights/weights.h"
#include "Model/model.h"

#endif

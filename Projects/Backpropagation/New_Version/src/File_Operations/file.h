#ifndef FILE_H
#define FILE_H

#include "../headers.h"

// This file containg headers of functions used for manipulating binary files for storing data.

// Read DATATYPE value in binary from file input.
DATATYPE ReadFromFile(std::fstream& file);

// Write DATATYPE number in binary to given open file.
void WriteToFile(std::fstream& file, const DATATYPE& number);

// Reads value from file if possible, if not, then returns random weight.
DATATYPE GetValue(std::fstream& file);

// Class used to read files used for model training and testing.
class Files {
private:
    size_t size_of_test;
    std::fstream images;
    std::fstream labels;
public:
    size_t number_of_tests;

private:
    // Function used in contructor to open files.
    void OpenFiles(const std::string& images_path, const std::string& labels_path);
    // Function used in destructor to close files.
    void CloseFiles();

    // Reads constant beggining from Images file.
    void ReadBeginningImages();
    // Reads constant beggining from Labels file.
    void ReadBeginningLabels();

    // Contructor required by compiler - not to be used.
    explicit Files() {}

public:
    // Contructor to use while connecting to files, 
    Files(const std::string& images_path, const std::string& labels_path);

    // Default destructor which closes previosly opened files.
    ~Files();

    // Read whole image from file and write it to given layer;
    void WriteInputsToLayer(Layer& layer);

    // Returns correct label to image.
    size_t GetCorrectAnswer();
};

#endif /* FILE_H */
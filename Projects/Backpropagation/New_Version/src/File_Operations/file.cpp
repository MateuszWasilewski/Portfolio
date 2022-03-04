#ifndef FILE_CPP
#define FILE_CPP

#include "../headers.h"

// Function reading given number of bytes from given stream, works up to 4 bytes.
static size_t ReadBytes(std::fstream& file, size_t size) {
    //LOG("maybe");
    size_t result = 0;
    while (size--) {
		unsigned char x;
		file.read((char*)&x, 1);
		result <<= 8;
		result += (int) x;
	}
    //LOG(result);
	return result;
}

// Read DATATYPE value in binary from file images.
DATATYPE ReadFromFile(std::fstream& file) {
    DATATYPE data;
    file.read(reinterpret_cast<char*> (&data), sizeof(DATATYPE));
    return data;
}

// Write DATATYPE number in binary to given open file.
void WriteToFile(std::fstream& file, const DATATYPE& number) {
    file.write(reinterpret_cast<const char*> (&number), sizeof(DATATYPE));
    LOG_WRITE(number); 
}

// Returns random value that can be used as base weight.
static DATATYPE RandomWeight(void) {
    DATATYPE number = rand();
    number -= RAND_MAX / 2;
    number /= (DATATYPE) RAND_MAX;
    while (abs(number) < MIN_VALUE)
        number *= 2;
    while (abs(number) > MAX_VALUE)
        number /= 2;
    return number;
}

// Reads value from file if possible, if not, then returns random weight.
DATATYPE GetValue(std::fstream& file) {
    DATATYPE result = file.good() ? ReadFromFile(file) : RandomWeight();

    LOG_READ(result);
    return result;
}


Files::Files(const std::string& images_path, const std::string& labels_path) {
    OpenFiles(images_path, labels_path);
    ReadBeginningImages();
    ReadBeginningLabels();
}

Files::~Files() {
    CloseFiles();
}

void Files::OpenFiles(const std::string& images_path, const std::string& labels_path) {
    images.open(images_path, std::ios::in | std::ios::binary);
    labels.open(labels_path, std::ios::in | std::ios::binary);
}

void Files::CloseFiles() {
    images.close();
    labels.close();
}

void Files::ReadBeginningImages() {
    ReadBytes(images, 4);       // Read magic number.
    number_of_tests = ReadBytes(images, 4);
    size_of_test = ReadBytes(images, 4) * ReadBytes(images, 4);
}

void Files::ReadBeginningLabels() {
    ReadBytes(labels, 4);     // Read magic number.
    number_of_tests = ReadBytes(labels, 4);
}

void Files::WriteInputsToLayer(Layer& layer) {
    size_t value;
    for (size_t iter = 0; iter < size_of_test; iter++) {
        //LOG(iter);
        value = ReadBytes(images, 1);
        if (iter < layer.size()) {
            layer[iter].value = value;
            layer[iter].value /= 256;
        }
    }
}

size_t Files::GetCorrectAnswer() {
    return ReadBytes(labels, 1);
}

#endif

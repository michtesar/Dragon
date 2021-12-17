#include <iostream>
#include "bundle.h"

Bundle::Bundle(char* basePath) {
    this->root = std::filesystem::absolute(std::filesystem::path(basePath).parent_path());
};

std::string Bundle::getBundleAsset(std::string fileName) {
    return root / std::filesystem::path(fileName);
};

std::string Bundle::getBundleRoot() {
    return root.c_str();
};
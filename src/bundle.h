#ifndef BUNDLE_H
#define BUNDLE_H

#include <filesystem>
#include <iostream>

class Bundle {
    private:
        std::filesystem::path root;
    public:
        Bundle(char* basePath);
        std::string getBundleRoot();
        std::string getBundleAsset(std::string fileName);
};

#endif
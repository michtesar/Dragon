#include "bundle.h"

/**
 * @brief Construct a new Bundle:: Bundle object
 * 
 * @param basePath path of current executable 
 * (obtained from **argv)
 */
Bundle::Bundle(char* basePath) {
    this->root = std::filesystem::absolute(std::filesystem::path(basePath).parent_path());
};

/**
 * @brief Get bundle absolute path.
 * 
 * @param fileName name of the file in the same directory.
 * as the executable is. Also, see `Bundle::getBundleRoot()`.
 * @return std::string absolute path to the asset.
 */
std::string Bundle::getBundleAsset(std::string fileName) {
    return root / std::filesystem::path(fileName);
};

/**
 * @brief Get relative bundle root path.
 * 
 * @return std::string relative path to the bundle.
 */
std::string Bundle::getBundleRoot() {
    return root.c_str();
};
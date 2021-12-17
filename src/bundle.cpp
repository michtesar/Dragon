/* 
 * This file is part of the Dragon Curve distribution.
 * Copyright (c) 2021-2022 Michael Tesar.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
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
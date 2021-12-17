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
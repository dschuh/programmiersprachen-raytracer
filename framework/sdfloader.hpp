#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "material.hpp"
 
struct SDFloader
{
std::vector<Material> holdMaterial;
public:
SDFloader();

void loadMaterial (std::string const& path);

};

#endif 
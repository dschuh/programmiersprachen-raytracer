#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include "material.hpp"
#include "scene.hpp"
 
struct SDFloader
{
std::map<std::string,Material> holdMaterial;
public:
SDFloader();

Scene loadMaterial (std::string const& path);

};

#endif 

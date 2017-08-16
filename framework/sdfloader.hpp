#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include "scene.hpp"
 
struct SDFloader
{

Scene loadScene (std::string const& path);

};

#endif 

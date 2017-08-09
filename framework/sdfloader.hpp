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
std::map<std::string,Material> holdMaterial;
std::vector<Light> holdLights;
Intensity amb;
Camera cam;
std::vector<Sphere> holdSpheres;
std::vector<Box> holdBoxes;

SDFloader();

Scene loadScene (std::string const& path);

};

#endif 

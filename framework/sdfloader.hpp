#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include "scene.hpp"
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "color.hpp"
#include "material.hpp"
#include "composite.hpp"
#include "camera.hpp"

struct SDFloader
{

Scene loadScene (std::string const& path);

};

#endif 

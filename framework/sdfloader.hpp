#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP

#include "scene.hpp"

struct SdfLoader{

Scene loadFile(std::string const& path);

};

#endif

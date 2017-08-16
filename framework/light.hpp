#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/vec3.hpp>
#include "color.hpp"
#include "intensity.hpp"
#include <memory>

struct Light{
    std::string name_;
    glm::vec3 position_;
    Color color_;
    float brightness_;
    Intensity intensity_;

    void setIntensity();

    Light();
    Light(std::string const& nm, glm::vec3 const& pos, Color const& clr, float bgts);

    friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<Light> const& l);

};



#endif

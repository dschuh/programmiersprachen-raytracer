#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/vec3.hpp>
#include "color.hpp"

struct Light{
    std::string name;
    glm::vec3 position;
    Color color;
    float brightness;
    float intensity;

    void setIntensity();

    Light();
    Light(std::string const& nm, glm::vec3 const& pos, Color const& clr, float bgts);

    float const& getIntensity();

    friend std::ostream& operator<<(std::ostream& os, Light const& l);

};



#endif

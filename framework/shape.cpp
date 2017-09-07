#include "shape.hpp"

Shape::Shape():
    name_{"Shape"}, material_{}{}
    

Shape::Shape(std::string const& name):
	name_{name}, material_{}{}

Shape::Shape(std::string const& name, std::shared_ptr<Material> const& material):
	name_{name},material_{material}{}

Shape::~Shape()
    {}

/*Color compute_light(Color const& ambient, Light const& light, Ray const& r){
    Color result();
    Ray l{intersect(r, 50.0f).hitpos, glm::normalize(light.position_)};
    Ray n{}; // n muss in Objekten einzeln berechnet werden override
    float x = (2 * pow(n.direction_.x - n.origin_.x, 2.0f) -1) * light.position_.x +  
        (2 * (n.direction_.x - n.origin_.x) * (n.direction_.y - n.origin_.y)) * light.position_.y + 
        (2 * (n.direction_.x - n.origin_.x) * (n.direction_.z - n.origin_.z)) * light.position_.z;
    float y = (2 * (n.direction_.x - n.origin_.x) * (n.direction_.y - n.origin_.y)) * light.position_.x + 
        (2 * pow(n.direction_.y - n.origin_.y, 2.0f) -1) * light.position_.y +
        (2 * (n.direction_.y - n.origin_.y) * (n.direction_.z - n.origin_.z) * light.position_.z;
    float z = (2 * (n.direction_.x - n.origin_.x) * (n.direction_.z - n.origin_.z)) * light.position_.x +
        (2 * (n.direction_.z - n.origin_.z) * (n.direction_.y - n.origin_.y)) * light.position_.y +
        (2 * pow(n.direction_.z - n.origin_.z, 2.0f) -1) * light.position_.z;
    
    light.setIntensity()
    result.r = ambient.r * material_.ka.r + light.intensity_.r * (material_.kd.r * (l * n) + material_.ks.r * 
        pow(intersect(r, 50.0f).hitray * glm::vec3{x, y, z}, material_.m);
}*/

std::shared_ptr<Material> const& Shape::get_material() const{
    return material_;
}

std::string const& Shape::get_name() const{
    return name_;
}

std::ostream& Shape::print(std::ostream& ostream) const
{
	ostream << "Name: "<< name_ << "\n"
			<< "Material: " << *material_;
	return ostream;
}

std::ostream& operator <<(std::ostream& ostream, Shape const& s)
{
	return s.print(ostream);
}



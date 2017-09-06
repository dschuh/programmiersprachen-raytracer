#include "box.hpp"

Box::Box():
    Shape{"Box"},
    min_{glm::vec3{0.0f}},
    max_{glm::vec3{1.0f}}
    {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::shared_ptr<Material> const& material, std::string const& name):
    Shape{name, material},
    min_{glm::vec3{min}},
    max_{glm::vec3{max}}
    {}

glm::vec3 const& Box::get_min() const
{
	return min_;
}

glm::vec3 const& Box::get_max() const
{
	return max_;
}

float Box::area() const {
	return  fabs((2 * (max_.x - min_.x) * (max_.y - min_.y)) +
			(2 * (max_.x - min_.x) * (max_.z - min_.z)) +
			(2 * (max_.y - min_.y) * (max_.z - min_.z)));
}

float Box::volume() const{
	return  fabs((max_.x - min_.x) * (max_.y - min_.y) *	(max_.z - min_.z));
}

std::ostream& Box::print(std::ostream& ostream) const{
	Shape::print(ostream);
	ostream << "Min: " << "["<< min_.x << ","<< min_.y << ","<< min_.z << "]" << "\n"
		    << "Max: " << "["<< max_.x << ","<< max_.y << ","<< max_.z << "]" << "\n";
}

Hit Box::intersect(Ray const& ray ,float& distance){ //funktioniert nicht?! Zumindest geht der Test nicht
	Hit hit = Hit();
    float tx1 = (min_.x-ray.origin_.x)/ray.direction_.x;
    float tx2 = (max_.x-ray.origin_.x)/ray.direction_.x;
 
    float tfarx=std::max(tx1, tx2);
    float tnearx=std::min(tx1, tx2);

    float ty1 = (min_.y-ray.origin_.y)/ray.direction_.y;
    float ty2 = (max_.y-ray.origin_.y)/ray.direction_.y;
  
    float tfary=std::max(ty1, ty2);
    float tneary=std::min(ty1, ty2);

    float tz1 = (min_.z-ray.origin_.z)/ray.direction_.z;
    float tz2 = (max_.z-ray.origin_.z)/ray.direction_.z;

    float tfarz=std::max(tz1, tz2);
    float tnearz=std::min(tz1, tz2);

    float tfar=std::max(tfarx, tfary);
    float tnear=std::min(tnearx, tneary);

    if(tfar>tnear){
        hit.hit = true;
        hit.hitray = ray;
        hit.hitpos = glm::vec3{tnear*ray.direction_.x, tnear*ray.direction_.y, tnear*ray.direction_.z}+ray.origin_;
        hit.shape = std::shared_ptr<Box>(this);
    }
 
    tfar=std::min(tfar, tfarz);
    tnear=std::max(tnear, tnearz);

    if((tfar>0) || (tfar>tnear)){
        hit.hit = true;
        hit.hitray = ray;
        hit.hitpos =  glm::vec3{tnear*ray.direction_.x, tnear*ray.direction_.y, tnear*ray.direction_.z}+ray.origin_;
        hit.shape = std::shared_ptr<Box>(this);
    }

    return hit;
}

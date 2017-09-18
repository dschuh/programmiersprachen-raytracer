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

Hit Box::intersect(Ray const& ray) const{
    Hit hit = Hit();
    
    Ray newRay{ray.origin_,glm::normalize(ray.direction_)};

    glm::vec3 inverse{1.0f/newRay.direction_.x, 1.0f/newRay.direction_.y, 1.0f/newRay.direction_.z};

    float tx1 = (min_.x-newRay.origin_.x)*inverse.x;
    float tx2 = (max_.x-newRay.origin_.x)*inverse.x;
 
    float tfarx=std::max(tx1, tx2);
    float tnearx=std::min(tx1, tx2);

    float ty1 = (min_.y-newRay.origin_.y)*inverse.y;
    float ty2 = (max_.y-newRay.origin_.y)*inverse.y;
  
    float tfary=std::max(ty1, ty2);
    float tneary=std::min(ty1, ty2);

    float tz1 = (min_.z-newRay.origin_.z)*inverse.z;
    float tz2 = (max_.z-newRay.origin_.z)*inverse.z;

    float tfarz=std::max(tz1, tz2);
    float tnearz=std::min(tz1, tz2);

    float tfar=std::max(tfarx, tfary);
    float tnear=std::min(tnearx, tneary);

    if(tfar>tnear){
        hit.hit_ = true;
        hit.distance_ = sqrt(tnear*tnear*(newRay.direction_.x*newRay.direction_.x +
                                          newRay.direction_.y*newRay.direction_.y +
                                          newRay.direction_.z*newRay.direction_.z));
        hit.hitpos_ = glm::vec3{hit.distance_*newRay.direction_.x, hit.distance_*newRay.direction_.y, hit.distance_*newRay.direction_.z}+ray.origin_;
        hit.shape = std::make_shared<Box>(min_, max_, get_material(), get_name());
    }
 
    tfar=std::min(tfar, tfarz);
    tnear=std::max(tnear, tnearz);

    if((tfar>0) || (tfar>tnear)){
        hit.hit_ = true;
        hit.distance_ = sqrt(tnear*tnear*(newRay.direction_.x*newRay.direction_.x +
                                          newRay.direction_.y*newRay.direction_.y +
                                          newRay.direction_.z*newRay.direction_.z));
        hit.hitpos_ =  glm::vec3{hit.distance_*newRay.direction_.x, hit.distance_*newRay.direction_.y, hit.distance_*newRay.direction_.z}+ray.origin_;
        hit.shape = std::make_shared<Box>(min_, max_, get_material(), get_name());
    }
    if(hit.hitpos_.x == Approx(min_.x)){
        hit.normal_ = glm::vec3{-1.0f, 0.0f, 0.0f};
    }
    else if(hit.hitpos_.x == Approx(max_.x)){
        hit.normal_ = glm::vec3{1.0f, 0.0f, 0.0f};
    }
    else if(hit.hitpos_.y == Approx(min_.y)){
        hit.normal_ = glm::vec3{0.0f, -1.0f, 0.0f};
    }
    else if(hit.hitpos_.y == Approx(max_.y)){
        hit.normal_ = glm::vec3{0.0f, 1.0f, 0.0f};
    }
    else if(hit.hitpos_.z == Approx(min_.z)){
        hit.normal_ = glm::vec3{0.0f, 0.0f, -1.0f};
    }
    else if(hit.hitpos_.z == Approx(max_.z)){
        hit.normal_ = glm::vec3{0.0f, 0.0f, 1.0f};
    }

    return hit;
}





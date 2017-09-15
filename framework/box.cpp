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
    
    //ray.direction_ = glm::normalize(ray.direction_)

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
        hit.hit_ = true;
        /*hit.distance_ = sqrt(tnear*tnear*(ray.direction_.x*ray.direction_.x +
                                          ray.direction_.y*ray.direction_.y +
                                          ray.direction_.z*ray.direction_.z));*/
        hit.hitpos_ = glm::vec3{tnear*ray.direction_.x, tnear*ray.direction_.y, tnear*ray.direction_.z}+ray.origin_;//das scheint nicht zu funktionieren
        hit.shape = std::make_shared<Box>(min_, max_, get_material(), get_name());
    }
 
    tfar=std::min(tfar, tfarz);
    tnear=std::max(tnear, tnearz);

    if((tfar>0) || (tfar>tnear)){
        hit.hit_ = true;
        hit.distance_ = sqrt(tnear*tnear*(ray.direction_.x*ray.direction_.x +
                                          ray.direction_.y*ray.direction_.y +
                                          ray.direction_.z*ray.direction_.z));
        hit.hitpos_ =  glm::vec3{tnear*ray.direction_.x, tnear*ray.direction_.y, tnear*ray.direction_.z}+ray.origin_;
        hit.shape = std::make_shared<Box>(min_, max_, get_material(), get_name());
        hit.distance_ = (min_.x - ray.origin_.x)/ray.direction_.x;
    }

    return hit;
}


Color Box::compute_light(Color const& ambient, Light const& light, Ray const& r) const{
    Color result{};
    Ray l{intersect(r).hitpos_, light.position_};
    Ray n; 
    Material mat = *get_material();
    int delta;

    if(intersect(r).hitpos_.x == get_min().x && get_min().y <= intersect(r).hitpos_.y <= get_max().y && get_min().z <= intersect(r).hitpos_.z <= get_max().z){
        n = Ray{intersect(r).hitpos_, glm::vec3{get_min().x - 3, intersect(r).hitpos_.y, intersect(r).hitpos_.z}};
    }
    else if(intersect(r).hitpos_.y == get_min().y && get_min().x <= intersect(r).hitpos_.x <= get_max().x && get_min().z <= intersect(r).hitpos_.z <= get_max().z){
        n = Ray{intersect(r).hitpos_, glm::vec3{intersect(r).hitpos_.x, get_min().y - 3, intersect(r).hitpos_.z}};
    }
    else if(intersect(r).hitpos_.z == get_min().z && get_min().y <= intersect(r).hitpos_.y <= get_max().y && get_min().x <= intersect(r).hitpos_.x <= get_max().x){
        n = Ray{intersect(r).hitpos_, glm::vec3{intersect(r).hitpos_.x, intersect(r).hitpos_.y, get_min().z - 3}};
    }

    float x = (2 * pow(n.direction_.x - n.origin_.x, 2.0f) -1) * light.position_.x +  
        (2 * (n.direction_.x - n.origin_.x) * (n.direction_.y - n.origin_.y)) * light.position_.y + 
        (2 * (n.direction_.x - n.origin_.x) * (n.direction_.z - n.origin_.z)) * light.position_.z;
    float y = (2 * (n.direction_.x - n.origin_.x) * (n.direction_.y - n.origin_.y)) * light.position_.x + 
        (2 * pow(n.direction_.y - n.origin_.y, 2.0f) -1) * light.position_.y +
        (2 * (n.direction_.y - n.origin_.y) * (n.direction_.z - n.origin_.z)) * light.position_.z;
    float z = (2 * (n.direction_.x - n.origin_.x) * (n.direction_.z - n.origin_.z)) * light.position_.x +
        (2 * (n.direction_.z - n.origin_.z) * (n.direction_.y - n.origin_.y)) * light.position_.y +
        (2 * pow(n.direction_.z - n.origin_.z, 2.0f) -1) * light.position_.z;
    
    Color inten = light.setIntensity();

    auto vector_n = glm::normalize(n.direction_ - n.origin_);
    auto vector_l = glm::normalize(l.direction_ - l.origin_);
    
    float first_hold = vector_l.x * vector_n.x + vector_l.y * vector_n.y + vector_l.z * vector_n.z;

    auto vector_r = glm::normalize(glm::vec3{x,y,z});

    auto vector_v = glm::normalize(intersect(r).hitray_.direction_ - intersect(r).hitray_.origin_);

    if (intersect(Ray{glm::vec3{0.0f}, light.position_}).hit_ == true){

        delta = 0;
    }
    else{
        delta = 1;
    }

    float second_hold = vector_v.x * vector_r.x+ vector_v.y * vector_r.y + vector_v.z * vector_r.z;

    result.r = ambient.r * mat.ka_.r + inten.r * delta * (mat.kd_.r * first_hold + mat.ks_.r * 
        pow(second_hold, mat.m_));
    result.g = ambient.g * mat.ka_.g + inten.g * delta * (mat.kd_.g * first_hold + mat.ks_.g * 
        pow(second_hold, mat.m_));
    result.b = ambient.b * mat.ka_.b + inten.b * delta * (mat.kd_.b * first_hold + mat.ks_.b * 
        pow(second_hold, mat.m_));

    return result;

}


#include "sphere.hpp"

	Sphere::Sphere(std::string const& nm):
        Shape{nm, Color{0.0f, 0.0f, 0.0f}},
		center{},
		radius{0}{}

	Sphere::Sphere(std::string const& nm, Color const& clr, glm::vec3 const& ctr, float r):
        Shape{nm, clr},		
        center{ctr},
		radius{r}{}

    Sphere::~Sphere(){
        std::cout << "~sphere";
    }

	glm::vec3 Sphere::getCenter() const{
		return this -> center;
	}

	float Sphere::getRadius() const{
		return this -> radius;
	}

	float Sphere::area() const {
		return (4* M_PI * this -> radius * this -> radius);
	}
		
	float Sphere::volume() const {
		return ((4.0f/3.0f)* M_PI * this -> radius * this -> radius * this -> radius);
	}

    std::ostream& Sphere::print(std::ostream& os) const{
    Shape::print(os);
    os << "Center:" << "(" << center.x << "," << center.y << "," << center.z << ")" << "\n";
    os << "Radius:" << radius << "\n";
    return os;
    }

    bool Sphere::intersect(Ray const& ray, float& distance){
        auto normaldirection = glm::normalize(ray.direction);
        
        return glm::intersectRaySphere(ray.origin,
                                       normaldirection,
                                       center,
                                       radius * radius,
                                       distance);
    }

#include "sphere.hpp"

	Sphere::Sphere(std::string const& nmSphere):
        	Shape{nmSphere, Material{}},
		center{glm::vec3{}},
		radius{0.0f}{
        	std::cout << "sphere \n";
        }

	Sphere::Sphere(std::string const& nmSphere, Material const& matr, glm::vec3 const& ctr, float r):
        	Shape{nmSphere, matr},		
        	center{ctr},
		radius{r}{
        std::cout << "sphere\n";
        }

    Sphere::~Sphere(){
        std::cout << "~sphere\n";
    }

	glm::vec3 const& Sphere::getCenter() const{
		return center;
	}

	float Sphere::getRadius() const{
		return radius;
	}

	float Sphere::area() const {
		return (4* M_PI * radius * radius);
	}
		
	float Sphere::volume() const {
		return ((4.0f/3.0f)* M_PI * radius * radius * radius);
	}

    std::ostream& Sphere::print(std::ostream& os) const{
        Shape::print(os);
        os << "Center:" << "(" << center.x << "," << center.y << "," << center.z << ")" << "\n" << "Radius:" << radius << "\n";
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

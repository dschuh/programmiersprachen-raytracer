#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "ray.hpp"
#include "material.hpp"
#include "hit.hpp"
#include "window.hpp"
#include "light.hpp"
#include <math.h>
#include <memory>
#include "glm/gtc/matrix_transform.hpp"

//forward-declare inclompete type
struct Hit;

class Shape{
public:

	///////-Konstruktoren-///////
	Shape();
	Shape(std::string const& name);
	Shape(std::string const& name, std::shared_ptr<Material> const& material);
	
	///////-Dekonstruktor-///////
	~Shape();
	
	///////-Getter & Setter-///////
	std::shared_ptr<Material> const& get_material() const;
	std::string const& get_name() const; //Nutzt man const& nicht nur bei der Übergabe von zusammen gesetzten Datentypen?
	
	///////-Methoden für Unterklassen-///////
	virtual float area() const =0;
	virtual float volume() const =0;
	virtual std::ostream& print(std::ostream& os) const=0;
	virtual Hit intersect (Ray const& ray) const=0;
	virtual Color compute_light(Color const& ambient, Light const& light, Ray const& r)const =0;
	
	///////-Shape-Manipulation-///////
	void scale(glm::vec3 const& skalierungsvektor);
    void transform(glm::vec3 const& translationsvektor);
    void rotate(float winkel, glm::vec3 rotationsvektor);


private:
    std::shared_ptr<Material> material_;
	std::string name_;	

	glm::mat4 world_transformation_;
    glm::mat4 world_transformation_inv_;
    
    glm::mat4 translate_;
    glm::mat4 scale_;
    glm::mat4 rotate_;


};

std::ostream& operator <<(std::ostream& ostream, Shape const& shape);

#endif

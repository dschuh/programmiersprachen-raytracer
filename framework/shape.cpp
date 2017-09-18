#include "shape.hpp"

Shape::Shape():
	name_{"Default Shape"}, 
	material_{},
	world_transformation_{glm::mat4(1.0)},
	world_transformation_inv_{glm::mat4(1.0)},
	translate_{glm::mat4(1.0)},
	rotate_{glm::mat4(1.0)},
  	scale_{glm::mat4(1.0)}
	{}
    
Shape::Shape(std::string const& name):
	name_{name}, 
	material_{},
	world_transformation_{glm::mat4(1.0)},
	world_transformation_inv_{glm::mat4(1.0)},
	translate_{glm::mat4(1.0)},
	rotate_{glm::mat4(1.0)},
  	scale_{glm::mat4(1.0)}
	{}

Shape::Shape(std::string const& name, std::shared_ptr<Material> const& material):
	name_{name},
	material_{material},
	world_transformation_{glm::mat4(1.0)},
	world_transformation_inv_{glm::mat4(1.0)},
	translate_{glm::mat4(1.0)},
	rotate_{glm::mat4(1.0)},
  	scale_{glm::mat4(1.0)}
	{}

Shape::~Shape()
    {}


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

void Shape::scale(glm::vec3 const& skalierungsvektor){
	glm::mat4 S; //Erstellt Skalierungsmatrix mit Skalierungsvektor, der dann auf die world_matrix angewandt wird
	S[0] = glm::vec4{skalierungsvektor.x, 0.0f, 			   0.0f, 				0.0f};
	S[1] = glm::vec4{0.0f, 				  skalierungsvektor.y, 0.0f, 				0.0f};
	S[2] = glm::vec4{0.0f, 				  0.0f, 			   skalierungsvektor.z, 0.0f};
	S[3] = glm::vec4{0.0f, 				  0.0f, 			   0.0f, 				1.0f};
	scale_ = S;
	world_transformation_ = translate_ * rotate_ * scale_;
 	world_transformation_inv_ = glm::inverse(world_transformation_);
}

void Shape::transform(glm::vec3 const& translationsvektor){
	glm::mat4 T;
	T[0] = glm::vec4{1.0f, 0.0f, 0.0f, 0.0f};
	T[1] = glm::vec4{0.0f, 1.0f, 0.0f, 0.0f};
	T[2] = glm::vec4{0.0f, 0.0f, 1.0f, 0.0f};
	T[3] = glm::vec4{translationsvektor.x, translationsvektor.y, translationsvektor.z, 1.0f};
	translate_ = T;
	world_transformation_ = translate_ * rotate_ * scale_;
 	world_transformation_inv_ = glm::inverse(world_transformation_);
}

void Shape::rotate(float winkel, glm::vec3 rotationsvektor){
	float winkel_in_rad = (winkel*M_PI)/180.0f;
	glm::mat4 R = glm::rotate(glm::mat4(1.0), winkel_in_rad, rotationsvektor);
	rotate_ = R;
	world_transformation_ = translate_ * rotate_ * scale_;
  	world_transformation_inv_ = glm::inverse(world_transformation_);
}

std::ostream& operator <<(std::ostream& ostream, Shape const& s)
{
	return s.print(ostream);
}



#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include "shape.hpp"

class Composite : public Shape 
{
public:
    Composite();
    Composite(std::string const& name, std::vector<std::shared_ptr<Shape>> comp);
    ~Composite();

    void add_shape(std::shared_ptr<Shape> const& shape);
    void set_name(std::string const nm);

    //Zu überschreibende Methoden - compute_light ohne Funktion
    float area() const override;
	float volume() const override;
	std::ostream& print(std::ostream& os) const override;
    Hit intersect (Ray const& ray) const override;
    
	Color compute_light(Color const& ambient, Light const& light, Ray const& r)const override;

private:
    std::string name;
    std::vector<std::shared_ptr<Shape>> composite_;
    
};
#endif

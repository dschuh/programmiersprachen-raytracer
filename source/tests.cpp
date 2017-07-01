#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
<<<<<<< HEAD
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("sphere","[sphere]"){

  
	Sphere def{"Default"};
	Sphere cust{"Custom", Material{}, glm::vec3(2.0f,4.0f, 3.0f),4.0f};
	REQUIRE(def.getName() == "Default");
    	REQUIRE(def.getCenter().x == Approx(0.0f));
	REQUIRE(def.getCenter().y == Approx(0.0f));
	REQUIRE(def.getCenter().z == Approx(0.0f));
  	//Get Material-Tests einfügen
	REQUIRE(cust.getRadius() == 4.0f);
	REQUIRE(cust.area() == 201.06194f);
	REQUIRE(cust.volume() == 268.08258f);
}

TEST_CASE("box","[box]"){
	Box def{"Default"};
	Box cust{"Custom", Material{}, glm::vec3(2.0f,4.0f, 3.0f),glm::vec3(10.0f,25.0f, 40.0f)};
    	REQUIRE(def.getName() == "Default");
    	REQUIRE(def.getMinimum().x == 0.0f);
	REQUIRE(def.getMinimum().y == 0.0f);
	REQUIRE(def.getMinimum().z == 0.0f);
    	REQUIRE(cust.getMaximum().x == 10.0f);
    	REQUIRE(cust.getMaximum().y == 25.0f);
    	REQUIRE(cust.getMaximum().z == 40.0f);
    	//Get Material Tests einfügen
	REQUIRE(cust.area() == 2482.0f);
	REQUIRE(cust.volume() == 6216.0f);
}

TEST_CASE("print","[print]"){  
    Box custBox{"Custom", Material{}, glm::vec3(2.0f,4.0f, 3.0f),glm::vec3(10.0f,25.0f, 40.0f)};
    Sphere custSphere{"Custom", Material{}, glm::vec3(2.0f,4.0f, 3.0f),4.0f};
    std::cout<<custBox << custSphere;
}

TEST_CASE("intersectRaySphere", "[intersect]"){
    glm::vec3 ray_origin{0.0, 0.0, 0.0};
    glm::vec3 ray_direction{0.0, 0.0, 1.0};

    glm::vec3 sphere_center{0.0, 0.0, 5.0};
    float sphere_radius{1.0};

    float distance{0.0};
    auto result = glm::intersectRaySphere(
        ray_origin, ray_direction,
        sphere_center,
        sphere_radius * sphere_radius,
        distance);
    REQUIRE(distance == Approx(4.0f));

    Sphere s {"some_sphere", Material{}, sphere_center, sphere_radius};

	Ray r {ray_origin,ray_direction};

	s.intersect(r,distance);

REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("destructors","[destructors]"){
    glm::vec3 position(0.0f, 0.0f, 0.0f);

    Sphere* s1 = new Sphere("sphere0", Material{}, position, 1.2f);
    Shape* s2 = new Sphere("sphere1", Material{}, position, 1.2f);

    std::cout << s1 << s2;

    delete s1;
    delete s2;
}

=======
#include <glm/vec3.hpp>
#include "shape.cpp"
#include "sphere.cpp"
#include "box.cpp"
#include "ray.cpp"

TEST_CASE("testing box", "[box]"){

Box box0{};

REQUIRE(box0.get_min().x==0.0f);
REQUIRE(box0.get_min().y==0.0f);
REQUIRE(box0.get_min().z==0.0f);
REQUIRE(box0.get_max().x==1.0f);
REQUIRE(box0.get_max().y==1.0f);
REQUIRE(box0.get_max().z==1.0f);

REQUIRE(box0.area()==6.0f);
REQUIRE(box0.volume()==1.0f);

REQUIRE(box0.get_name()=="Box");
REQUIRE(box0.get_color().r==0.0f);
REQUIRE(box0.get_color().g==0.0f);
REQUIRE(box0.get_color().b==0.0f);



Box box1{glm::vec3{3.0f}, glm::vec3{7.0f}, Color{1.0f, 2.0f, 3.0f}, "Kasten1"};

REQUIRE(box1.get_min().x==3.0f);
REQUIRE(box1.get_min().y==3.0f);
REQUIRE(box1.get_min().z==3.0f);
REQUIRE(box1.get_max().x==7.0f);
REQUIRE(box1.get_max().y==7.0f);
REQUIRE(box1.get_max().z==7.0f);

REQUIRE(box1.area()==96.0f);
REQUIRE(box1.volume()==64.0f);

REQUIRE(box1.get_name()=="Kasten1");
REQUIRE(box1.get_color().r==1.0f);
REQUIRE(box1.get_color().g==2.0f);
REQUIRE(box1.get_color().b==3.0f);
}

TEST_CASE("testing sphere", "[sphere]"){

Sphere sphere0{};

REQUIRE(sphere0.get_center().x==0.0f);
REQUIRE(sphere0.get_center().y==0.0f);
REQUIRE(sphere0.get_center().z==0.0f);
REQUIRE(sphere0.get_radius()==1.0f);

REQUIRE(Approx(sphere0.area()).epsilon(0.001) == 12.566);
REQUIRE(Approx(sphere0.volume()).epsilon(0.001) == 4.188);

REQUIRE(sphere0.get_name()=="Sphere");
REQUIRE(sphere0.get_color().r==0.0f);
REQUIRE(sphere0.get_color().g==0.0f);
REQUIRE(sphere0.get_color().b==0.0f);


Sphere sphere1{glm::vec3{5.0f}, 3.0f};

REQUIRE(sphere1.get_center().x==5.0f);
REQUIRE(sphere1.get_center().y==5.0f);
REQUIRE(sphere1.get_center().z==5.0f);
REQUIRE(sphere1.get_radius()==3.0f);

REQUIRE(Approx(sphere1.area()).epsilon(0.01)==113.097f);
REQUIRE(Approx(sphere1.volume()).epsilon(0.01)==113.097f);

REQUIRE(sphere1.get_name()=="Sphere");
REQUIRE(sphere1.get_color().r==0.0f);
REQUIRE(sphere1.get_color().g==0.0f);
REQUIRE(sphere1.get_color().b==0.0f);


Sphere sphere2{glm::vec3{3.0f}, 7.0f, Color{1.0f, 2.0f, 3.0f}, "Kasten1"};

REQUIRE(sphere2.get_center().x==3.0f);
REQUIRE(sphere2.get_center().y==3.0f);
REQUIRE(sphere2.get_center().z==3.0f);
REQUIRE(sphere2.get_radius()==7.0f);

REQUIRE(Approx(sphere2.area()).epsilon(0.01)==615.752f);
REQUIRE(Approx(sphere2.volume()).epsilon(0.01)==1436.755f);

REQUIRE(sphere2.get_name()=="Kasten1");
REQUIRE(sphere2.get_color().r==1.0f);
REQUIRE(sphere2.get_color().g==2.0f);
REQUIRE(sphere2.get_color().b==3.0f);
}

TEST_CASE("Creating Boxes and Spheres and printing their values", "[print]"){
  Box box0{};
  box0.print(std::cout << "box0 : \n");

  Sphere sphere0{};
  sphere0.print(std::cout << "sphere0 : \n");
}

TEST_CASE("Testing intestectSphere function", "[intersect]"){
  //Ray
	glm::vec3 ray_origin{0.0,0.0,0.0};
	//ray direction has to be normalized!
	//you can use:
	//	v = glm::normalize(some_vector)
	glm::vec3 ray_direction{0.0,0.0,1.0};

	//Sphere
	glm::vec3 sphere_center{0.0,0.0,5.0};
	float sphere_radius{1.0};

	float distance{0.0};
	auto result = glm::intersectRaySphere(
			ray_origin, ray_direction,
			sphere_center,
			sphere_radius * sphere_radius, //squared radius!!
			distance);
	REQUIRE(distance == Approx(4.0f));  

  //custom testing
  Ray ray{{0.0f, 0.0f, -2.0f}, {0.0f, 0.0f, 2.5f}};
  float custom_distance{0.0};
  Sphere sphere{{0.0f, 0.0f, 4.0f}, 1.0f, Color{1.0f, 2.0f, 3.0f}, "Sphere"};

  REQUIRE(sphere.intersect(ray, custom_distance) == true);
}
>>>>>>> b0a8e5889e5176a1bbd8c6e1b5a2f1f04dad6ca8

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

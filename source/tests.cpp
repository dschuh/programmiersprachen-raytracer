#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
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


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

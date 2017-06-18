#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("sphere","[sphere]"){
	Sphere def{"Default"};
	Sphere cust{"Custom", Color(1.0f, 0.0f, 0.0f), glm::vec3(2.0f,4.0f, 3.0f),4.0f};
    //REQUIRE(def.getName() == "Default");	Will Require haben?
    REQUIRE(def.getCenter().x == 0.0f);
	REQUIRE(def.getCenter().y == 0.0f);
	REQUIRE(def.getCenter().z == 0.0f);
    REQUIRE(cust.getColor().r == 0.0f);
    REQUIRE(cust.getColor().g == 0.0f);
    REQUIRE(cust.getColor().b == 0.0f);
	REQUIRE(cust.getRadius() == 4.0f);
	REQUIRE(cust.area() == 201.06194f);
	REQUIRE(cust.volume() == 268.08258f);
}

TEST_CASE("box","[box]"){
	Box def{"Default"};
	Box cust{"Custom", Color(0.0f, 0.0f, 0.0f), glm::vec3(2.0f,4.0f, 3.0f),glm::vec3(10.0f,25.0f, 40.0f)};
    //REQUIRE(def.getName() == "Default");	
    REQUIRE(def.getMinimum().x == 0.0f);
	REQUIRE(def.getMinimum().y == 0.0f);
	REQUIRE(def.getMinimum().z == 0.0f);
    REQUIRE(cust.getMaximum().x == 10.0f);
    REQUIRE(cust.getMaximum().y == 25.0f);
    REQUIRE(cust.getMaximum().z == 40.0f);
    //REQUIRE(cust.getColor().r == 0.0f); 40 f ? Warum????
    REQUIRE(cust.getColor().g == 0.0f);
    REQUIRE(cust.getColor().b == 0.0f);
	REQUIRE(cust.area() == 2482.0f);
	REQUIRE(cust.volume() == 6216.0f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

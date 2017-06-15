#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("sphere","[sphere]"){
	Sphere def{};
	Sphere cust{glm::vec3(2.0f,4.0f, 3.0f),4.0f};
	REQUIRE(def.getCenter().x == 0);
	REQUIRE(def.getCenter().y == 0);
	REQUIRE(def.getCenter().z == 0);
	REQUIRE(cust.getRadius() == 4);
	REQUIRE(cust.area() == 201.06194f);
	REQUIRE(cust.volume() == 268.08f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

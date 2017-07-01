#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>


TEST_CASE("intersectRaySphere", "[intersect]")
{
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
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

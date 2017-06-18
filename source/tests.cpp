#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include "shape.cpp"
#include "sphere.cpp"
#include "box.cpp"

TEST_CASE("testing box", "[box]"){

Box box0{};

REQUIRE(box0.get_min().x==0.0f);
REQUIRE(box0.get_min().y==0.0f);
REQUIRE(box0.get_min().z==0.0f);
REQUIRE(box0.get_max().x==1.0f);
REQUIRE(box0.get_max().y==1.0f);
REQUIRE(box0.get_max().z==1.0f);
REQUIRE(box0.get_name()=="Box");
REQUIRE(box0.get_color().r==0.0f);
REQUIRE(box0.get_color().g==0.0f);
REQUIRE(box0.get_color().b==0.0f);
REQUIRE(box0.area()==6.0f);
REQUIRE(box0.volume()==1.0f);


Box box1{glm::vec3{3.0f}, glm::vec3{7.0f}, Color{1.0f, 2.0f, 3.0f}, "Kasten1"};

REQUIRE(box1.get_min().x==3.0f);
REQUIRE(box1.get_min().y==3.0f);
REQUIRE(box1.get_min().z==3.0f);
REQUIRE(box1.get_max().x==7.0f);
REQUIRE(box1.get_max().y==7.0f);
REQUIRE(box1.get_max().z==7.0f);
REQUIRE(box1.get_name()=="Kasten1");
REQUIRE(box1.get_color().r==1.0f);
REQUIRE(box1.get_color().g==2.0f);
REQUIRE(box1.get_color().b==3.0f);
REQUIRE(box1.area()==96.0f);
REQUIRE(box1.volume()==64.0f);
}

TEST_CASE("testing sphere", "[sphere]"){

Sphere sphere0{};

REQUIRE(sphere0.get_center().x==0.0f);
REQUIRE(sphere0.get_center().y==0.0f);
REQUIRE(sphere0.get_center().z==0.0f);
REQUIRE(sphere0.get_radius()==1.0f);
REQUIRE(sphere0.get_name()=="Sphere");
REQUIRE(sphere0.get_color().r==0.0f);
REQUIRE(sphere0.get_color().g==0.0f);
REQUIRE(sphere0.get_color().b==0.0f);
REQUIRE(Approx(sphere0.area()).epsilon(0.001) == 12.566);
REQUIRE(Approx(sphere0.volume()).epsilon(0.001) == 4.188);


Sphere sphere1{glm::vec3{5.0f}, 3.0f};

REQUIRE(sphere1.get_center().x==5.0f);
REQUIRE(sphere1.get_center().y==5.0f);
REQUIRE(sphere1.get_center().z==5.0f);
REQUIRE(sphere1.get_radius()==3.0f);
REQUIRE(sphere1.get_name()=="Sphere");
REQUIRE(sphere1.get_color().r==0.0f);
REQUIRE(sphere1.get_color().g==0.0f);
REQUIRE(sphere1.get_color().b==0.0f);
REQUIRE(Approx(sphere1.area()).epsilon(0.01)==113.097f);
REQUIRE(Approx(sphere1.volume()).epsilon(0.01)==113.097f);


Sphere sphere2{glm::vec3{3.0f}, 7.0f, Color{1.0f, 2.0f, 3.0f}, "Kasten1"};

REQUIRE(sphere2.get_center().x==3.0f);
REQUIRE(sphere2.get_center().y==3.0f);
REQUIRE(sphere2.get_center().z==3.0f);
REQUIRE(sphere2.get_radius()==7.0f);
REQUIRE(sphere2.get_name()=="Kasten1");
REQUIRE(sphere2.get_color().r==1.0f);
REQUIRE(sphere2.get_color().g==2.0f);
REQUIRE(sphere2.get_color().b==3.0f);
REQUIRE(Approx(sphere2.area()).epsilon(0.01)==615.752f);
REQUIRE(Approx(sphere2.volume()).epsilon(0.01)==1436.755f);

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

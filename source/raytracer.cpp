#include <renderer.hpp>
#include <window.hpp>
#include "../framework/sdfloader.hpp"

#include <GLFW/glfw3.h>
#include <thread>
#include <utility>
#include <cmath>

int main(int argc, char* argv[])
{
  unsigned const width = 800;
  unsigned const height = 600;
  std::string file;
  std::string filename;

  std::cout << "Dateipfad eingeben \n";
  std::cin >> file;
  std::cout << "Bitte gewuenschten Bildnamen eingeben \n";
  std::cin >> filename;

  SDFloader loader;  
  Scene to_be_rendered = loader.loadScene(file);
  Renderer app(to_be_rendered, width, height, filename);

  std::thread thr([&app]() { app.render(); });

  Window win{glm::ivec2{width,height}};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    win.show(app.colorbuffer());
  }

  thr.join();

  return 0;
}

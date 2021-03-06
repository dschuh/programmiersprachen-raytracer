// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP

#include "scene.hpp"
#include "color.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
//#include "hit.hpp"
//#include "shape.hpp"
#include <string>
#include <glm/glm.hpp>

class Renderer
{
public:
  Renderer(Scene const& scene);
  Renderer(unsigned w, unsigned h, std::string const& file);
  Renderer(Scene const& scene, unsigned w, unsigned h, std::string const& file);

  void render();
  void write(Pixel const& p);

  //Methoden zur Farbberechnung (Licht)
  //Sind in box und sphere, warum auch immer :D


  inline std::vector<Color> const& colorbuffer() const
  {
    return colorbuffer_;
  }

private:
  Scene scene_;
  unsigned width_;
  unsigned height_;
  std::vector<Color> colorbuffer_;
  std::string filename_;
  PpmWriter ppm_;
};

#endif // #ifndef BUW_RENDERER_HPP

// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"

Renderer::Renderer(Scene const& scene)
  : scene_(scene)
  , width_(scene.w)
  , height_(scene.h)
  , colorbuffer_(scene.w*scene.h, Color(0.0, 0.0, 0.0))
  , filename_(scene.pic_name)
  , ppm_(width_, height_)
{}

Renderer::Renderer(unsigned w, unsigned h, std::string const& file)
  : width_(w)
  , height_(h)
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
{}

  Renderer::Renderer(Scene const& scene, unsigned w, unsigned h, std::string const& file)
  : scene_(scene)
  , width_(w)
  , height_(h)
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
{}


void Renderer::render()
{
  const std::size_t checkersize = 20;

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);
      //Create ray
      Ray shootingstar= scene_.camera->makeRay(x, y, height_, width_);

      //////////////////////////////////////////////////////////////////
      // Hier kommt theoretisch
      // transformationsgedingse
      // da fehlt aber noch ne methode
      // Ray transformRay ( glm :: mat4 const & mat , Ray const & ray );
      //////////////////////////////////////////////////////////////////

      //Find closest hit
      Hit nearest = scene_.shapes->intersect(shootingstar);
      
      if(nearest.hit_==true){
        for(auto const& i : scene_.lights){
            std::shared_ptr<Material> mat = nearest.shape -> get_material();
            int delta;
            Light light = *i;
            Color intensity = light.setIntensity();
            glm::vec3 n = glm::normalize(nearest.normal_);

            Ray toLight{nearest.hitpos_, glm::normalize(light.position_- nearest.hitpos_)};

            toLight.origin_ += n * 0.001f;

            glm::vec3 l = glm::normalize(toLight.direction_);

            float ln = std::max(glm::dot(l, n), 0.0f);

            glm::vec3 r = glm::normalize(glm::reflect(-l, n));

            glm::vec3 v = glm::normalize(glm::vec3{- shootingstar.direction_.x, -shootingstar.direction_.y, - shootingstar.direction_.z});

            float rv = std::max(glm::dot(r, v), 0.0f);

            if(scene_.shapes -> intersect(toLight).hit_){
                delta = 0;
            }
            else{
                delta = 1;
            }

            p.color += scene_.ambiente * mat -> ka_ + intensity * delta * (mat -> kd_ * ln + mat -> ks_ * pow(rv, mat -> m_));
        }
      }
      else p.color=scene_.ambiente;
      
      write(p);
    }
  }
  ppm_.save(filename_);
}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}

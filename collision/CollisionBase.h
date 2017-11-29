#pragma once
#include <SDL2/SDL.h>
class CollisionBase {
private:
  SDL_Rect *gRect = NULL;

protected:
public:
  CollisionBase(int x, int y, int w, int h);
  CollisionBase(SDL_Rect *rect);
  ~CollisionBase();
  SDL_Rect *getCollisionRect();
  virtual void visualize(SDL_Renderer *renderer, SDL_Texture *texture);
  virtual void updateRect(int x, int y, int w, int h);
  bool collidesWith(CollisionBase *other);
};
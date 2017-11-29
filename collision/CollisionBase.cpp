#include "CollisionBase.h"
#include "../color.h"
#include "../logging.h"
#include <SDL2/SDL.h>
#include <iostream>
CollisionBase::CollisionBase(int x, int y, int w, int h) {
  updateRect(x, y, w, h);
}
CollisionBase::CollisionBase(SDL_Rect *rect) {
  if (rect == NULL)
    ERROR("CollisionBase was given null rect");
  gRect = rect;
}
void CollisionBase::updateRect(int x, int y, int w, int h) {
  if (gRect == NULL)
    gRect = new SDL_Rect;
  gRect->x = x;
  gRect->y = y;
  gRect->w = w;
  gRect->h = h;
}
CollisionBase::~CollisionBase() {
  DEBUG("CollisionBase Deconstructor called");
  if (gRect != NULL)
    delete gRect;
  gRect = NULL;
}
SDL_Rect *CollisionBase::getCollisionRect() { return gRect; }
bool CollisionBase::collidesWith(CollisionBase *other) {
  SDL_Rect *otherRect = other->getCollisionRect();
  if (gRect == otherRect) {
    return false;
  }
  return SDL_HasIntersection(gRect, otherRect);
}
void CollisionBase::visualize(SDL_Renderer *mRenderer, SDL_Texture *mTexture) {
  SDL_SetRenderTarget(mRenderer, mTexture);
  SDL_SetRenderDrawColor(mRenderer, COLLISION.r, COLLISION.g, COLLISION.b,
                         COLLISION.a);
  SDL_RenderDrawRect(mRenderer, gRect);
}
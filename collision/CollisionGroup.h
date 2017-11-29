#pragma once
#include "CollisionBase.h"
#include <SDL2/SDL.h>
#include <vector>
class CollisionGroup : public CollisionBase {
protected:
  std::vector<CollisionBase *> items;

public:
  CollisionGroup();
  CollisionGroup(SDL_Rect *);
  ~CollisionGroup();
  void addItem(CollisionBase *item);
  void removeItem(CollisionBase *item);
  std::vector<CollisionBase *> getItems();
  virtual void calculateRect();
  void visualize(SDL_Renderer *renderer, SDL_Texture *texture);
  bool collidesWith(CollisionGroup *other);
};
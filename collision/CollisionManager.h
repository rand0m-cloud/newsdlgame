#pragma once
#include "CollisionGroup.h"
#include <SDL2/SDL.h>
#include <vector>
class CollisionManager {
protected:
  std::vector<CollisionGroup *> items;

public:
  CollisionManager();
  ~CollisionManager();
  void addItem(CollisionGroup *item);
  void removeItem(CollisionGroup *item);
  bool collidesWith(CollisionGroup *other);
  void checkCollisions();
};
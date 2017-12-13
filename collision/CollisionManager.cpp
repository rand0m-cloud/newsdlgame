#include "CollisionManager.h"
#include "../logging.h"
#include <algorithm>
#include <iostream>
CollisionManager::~CollisionManager() {}
CollisionManager::CollisionManager() {}
void CollisionManager::checkCollisions() {

  for (int i = 0; i < items.size(); i++) {
    if (collidesWith(items[i])) {
      // DEBUG("COLLIDE");
    }
  }
}
void CollisionManager::addItem(CollisionGroup *item) {
  if (item != NULL)
    items.push_back(item);
}
void CollisionManager::removeItem(CollisionGroup *item) {
  if (item != NULL)
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}
bool CollisionManager::collidesWith(CollisionGroup *other) {
  bool result = false;
  for (int i = 0; i < items.size(); i++) {
    if (other->collidesWith(items[i]))
      result = true;
  }
  return result;
}
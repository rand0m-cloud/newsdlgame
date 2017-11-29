#include "CollisionGroup.h"
#include "../logging.h"
#include <SDL2/SDL.h>
#include <algorithm>
#include <iostream>
#include <vector>
CollisionGroup::CollisionGroup() : CollisionBase(0, 0, 0, 0) {}
CollisionGroup::CollisionGroup(SDL_Rect *rect) : CollisionBase(rect) {}
CollisionGroup::~CollisionGroup() {}
void CollisionGroup::addItem(CollisionBase *item) {
  if (item != NULL)
    items.push_back(item);
}
void CollisionGroup::removeItem(CollisionBase *item) {
  if (item != NULL)
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}
bool CollisionGroup::collidesWith(CollisionGroup *other) {
  if (CollisionBase::collidesWith((CollisionBase *)other) == false)
    return false;

  std::vector<CollisionBase *> otherItems = other->getItems();
  for (CollisionBase *ourItem : items) {
    for (CollisionBase *otherItem : otherItems) {
      if (ourItem->collidesWith(otherItem))
        return true;
    }
  }
  return false;
}
void CollisionGroup::calculateRect() {
  int left, right, top, bottom;
  left = right = top = bottom = 0;
  for (int i = 0; i < items.size(); i++) {
    CollisionBase *item = items[i];
    SDL_Rect *itemRect = item->getCollisionRect();
    if (i == 0) {
      left = itemRect->x;
      top = itemRect->y;
      right = itemRect->x + itemRect->w;
      bottom = itemRect->y + itemRect->h;
    } else {
      if (itemRect->x < left)
        left = itemRect->x;
      if (itemRect->y < top)
        top = itemRect->y;
      if ((itemRect->x + itemRect->w) > right)
        right = itemRect->x + itemRect->w;
      if ((itemRect->y + itemRect->h) > bottom)
        bottom = itemRect->y + itemRect->h;
    }
  }

  updateRect(left, top, right - left, bottom - top);
}
std::vector<CollisionBase *> CollisionGroup::getItems() { return items; }
void CollisionGroup::visualize(SDL_Renderer *renderer, SDL_Texture *texture) {
  CollisionBase::visualize(renderer, texture);
}
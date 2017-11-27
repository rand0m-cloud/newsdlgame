#include <SDL2/SDL.h>
#include "Player.h"
#include "../logging.h"

Player::Player(SDL_Renderer* mRenderer, int startingX, int startingY) : ImageSprite(mRenderer,"images/sprite1.png"){
  *x = startingX;
  *y = startingY;
}

void Player::createTexture() {
  return;
}
SDL_Texture* Player::render() {
  
  return ImageSprite::render();
}

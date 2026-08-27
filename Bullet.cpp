#include "Bullet.h"

Bullet::Bullet(int x, int y){
    bulletx = x; //The first two numbers set its x and y
    bullety = y;
    bulletimage = LoadTexture("bullet.png");
}
    

void Bullet::setY(int y) {
    bullety = y;
}

int Bullet::getx() const {
    return bulletx; 
}

int Bullet::gety() const {
    return bullety; 
}

Texture2D Bullet::getimage() const {
    return bulletimage;
}
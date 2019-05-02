#include "blokada.h"

blokada::blokada(sf::Vector2f xy)
{
    texture.loadFromFile("platform_1.png");
    sprite.setTexture(texture);
    sprite.setPosition(xy);
}

sf::Vector2u blokada::get_size()
{
    return texture.getSize();
}

sf::Sprite blokada::get_sprite()
{
    return sprite;
}

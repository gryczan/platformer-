#include "player.h"
#include <SFML/Graphics.hpp>

player::player(int zmienna)
{
    texture.loadFromFile("player.png");
    sprite.setTexture(texture);
    sprite.setPosition(50, 600);
    isJumping = 0;
    licznik =  200;
    isFalling = false;
    sprite.setOrigin(50, 100);
}

sf::Sprite player::getSprite()
{
    return sprite;
}

void player::test(blokada*blok, sf::View*p_view)
{
 if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
        {
            p_view->move(1,0);
            sprite.move(1,0);
        }

    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
        {
            p_view->move(-1,0);
            sprite.move(-1,0);
        }

    if(isJumping == true)
        {
            sprite.move(0, player_speed);
            licznik = licznik - 1;
        }

    if(isJumping == false && sprite.getPosition().y < floor )
    {
        isFalling = true;
    }

    kolizja(blok->get_size(), blok->sprite.getPosition());


    if(isJumping == false && sprite.getPosition().y < floor && isFalling == true)
    {
        sprite.move(0, gravity_speed);
    }

    kolizja(blok->get_size(), blok->sprite.getPosition());

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isJumping == false )
        {
            isJumping = true;
        }

    if(sprite.getPosition().y == floor)
    {
        licznik = 200;
        isFalling = false;
    }
    if( licznik == 0)
    {
        isJumping = false;
    }
}

void player::kolizja(sf::Vector2u u_xy, sf::Vector2f f_xy)
{
    sf::Vector2f player_xy;
    player_xy = sprite.getPosition();

    if(f_xy.y == player_xy.y && f_xy.x < player_xy.x && f_xy.x + u_xy.x > player_xy.x )
    {
        isFalling = false;
        isJumping = false;
        licznik = 200;
    }
}

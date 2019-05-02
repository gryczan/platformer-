#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <blokada.h>


class player
{
    public:
        player(int zmienna);
        sf::Sprite getSprite();
        void test(blokada*p_blok, sf::View*p_view);
        void kolizja(sf::Vector2u u_xy, sf::Vector2f f_xy);

    protected:

    private:
       float player_speed = -2;
       float gravity_speed = 2;
       float floor = 720;
       sf::Sprite sprite;
       sf::Texture texture;
       bool isJumping;
       bool isFalling;
       int licznik;

};

#endif // PLAYER_H

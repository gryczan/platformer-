#ifndef BLOKADA_H
#define BLOKADA_H
#include <SFML/Graphics.hpp>


class blokada
{
    public:
        blokada(sf::Vector2f xy);
        sf::Sprite get_sprite();
        sf::Vector2u get_size();
        sf::Sprite sprite;
        sf::Texture texture;


    protected:

    private:

};

#endif // BLOKADA_H

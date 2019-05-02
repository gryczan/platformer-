#include <SFML/Graphics.hpp>
#include <player.h>
#include <blokada.h>

int main()
{
    //define objects
    player gracz(38);
    blokada platform(sf::Vector2f(500, 500));
    blokada*p_blok;
    p_blok = &platform;


    // Create the main window
    sf::RenderWindow app(sf::VideoMode(1280, 720), "SFML window");
    sf::View view1(sf::Vector2f(640.f, 360.f), sf::Vector2f(1280.f, 720.f));
    sf::View*p_view1;
    app.setView(view1);
    p_view1 =&view1;


	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }
        //app actions
        gracz.test(p_blok, p_view1);


        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(gracz.getSprite());
        app.draw(platform.get_sprite());


        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

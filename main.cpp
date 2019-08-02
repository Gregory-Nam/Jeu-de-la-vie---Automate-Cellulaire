#include <SFML/Graphics.hpp>
#include "Grille.h"
#include "Cellule.h"
#include <iostream>
#include <vector>


int main()
{
	unsigned dimension = 100, taille = 15;
	Grille g(taille, dimension);
	// création de la fenêtre
	sf::RenderWindow window(sf::VideoMode((dimension * taille) + 300, dimension * taille), "Jeu de la vie");
	
	g.init();
	// on fait tourner le programme tant que la fenêtre n'a pas été fermée
	while (window.isOpen())
	{
		// on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
		sf::Event event;
		while (window.pollEvent(event))
		{
			// fermeture de la fenêtre lorsque l'utilisateur le souhaite
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::Left == event.mouseButton.button) {

				unsigned x = sf::Mouse::getPosition(window).x / taille;
				unsigned y = sf::Mouse::getPosition(window).y / taille;
				g(x, y).changeEtat();
				
			}
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::Right == event.mouseButton.button) {
				while (true) {
					g.iterationSuivante();
					window.pollEvent(event);
					window.clear(sf::Color::Black);
					// c'est ici qu'on dessine tout
					// window.draw(...);
					window.draw(g);
					// fin de la frame courante, affichage de tout ce qu'on a dessiné
					window.display();
					if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::Right == event.mouseButton.button) break;

				}
			}
		}

		// effacement de la fenêtre en noir
		window.clear(sf::Color::Black);
		// c'est ici qu'on dessine tout
		// window.draw(...);
		window.draw(g);
		// fin de la frame courante, affichage de tout ce qu'on a dessiné
		window.display();
	}

	return 0;
}

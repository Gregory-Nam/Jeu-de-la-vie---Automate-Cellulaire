#include <SFML/Graphics.hpp>
#include "Grille.h"
#include "Cellule.h"
#include <iostream>
#include <vector>


//int main()
//{
//	// création de la fenêtre
//	sf::RenderWindow window(sf::VideoMode(700, 600), "My window");
//	float tailleCellule = 20;
//	float dimensionMatrice = 10;
//	Grille grille(tailleCellule, dimensionMatrice);
//	window.draw(grille)
//	//création de la grille :
//	grille.init();
//	//std::vector <std::vector <sf::RectangleShape>> celulles;
//	// on fait tourner le programme tant que la fenêtre n'a pas été fermée
//	while (window.isOpen())
//	{
//		// on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			// fermeture de la fenêtre lorsque l'utilisateur le souhaite
//			if (event.type == sf::Event::Closed)
//				window.close();
//			//if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//			//	float x = sf::Mouse::getPosition(window).x / 20;
//			//	float y = sf::Mouse::getPosition(window).y / 20;
//			//	celulles[x][y].setFillColor(sf::Color::Blue);
//			//}
//				
//		}
//
//		// effacement de la fenêtre en noir
//		window.clear(sf::Color::Black);
//
//		float tailleCellule = 20;
//		float nombreCelluleCarre = 10;
//		
//		/*bool creation = false;
//		for (unsigned i = 0; i < nombreCelluleCarre; ++i) {
//			if (celulles.size() == 0)
//				creation = true;
//
//			if(creation) {
//				celulles.resize(nombreCelluleCarre);
//				for (unsigned j = 0; j < nombreCelluleCarre; ++j) {
//					sf::RectangleShape rec(sf::Vector2f(tailleCellule, tailleCellule));
//					rec.setPosition(i * tailleCellule, j * tailleCellule);
//					rec.setOutlineColor(sf::Color(0, 0, 0));
//					rec.setOutlineThickness(1);
//					celulles[i].push_back(rec);
//					window.draw(rec);
//				}
//			}
//			else {
//				for (unsigned j = 0; j < nombreCelluleCarre; ++j) {
//					window.draw(celulles[i][j]);
//				}
//			}
//			
//		}*/
//
//
//
//		// fin de la frame courante, affichage de tout ce qu'on a dessiné
//		window.display();
//	}
//}

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
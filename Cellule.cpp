#include "Cellule.h"
#include "Grille.h"


Cellule::Cellule(const unsigned & taille) : _taille(taille)
{
	// création de la forme avec sa taille
	_rectangle = new sf::RectangleShape(sf::Vector2f(taille, taille));
	_etat = false;

}

void Cellule::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*_rectangle, states);
}

const unsigned Cellule::compteVoisin(Grille * grille) const {

	unsigned dimension = grille->getDimension();
	unsigned compteur = 0;

	for (int i = _y - 1; i <= _y + 1; ++i) {				// chaque ligne
		for (int j = _x - 1; j <= _x + 1; ++j) {			// chaque colonne
			if (j == -1) ++j;								// on sort a gauche de la grille
			if (i == -1) ++i;								// on sort en haut de la grille
			if (i == dimension) break;						// on sort sur le bas de la grille
			if (j == dimension) continue;					// on sort sur la droite de la grille
			if (_x == j && _y == i) continue;				// cellule courante (this), pas voisin

			if (grille->operator()(j, i)._etat)
			{
				++compteur;
			}
			
		}
	}
	return compteur;

}

void Cellule::changeEtat()
{
	if (_etat) 
		_rectangle->setFillColor(MORTE);
	else 
		_rectangle->setFillColor(VIVANTE);

	_etat = (!_etat);
	return;
}

void Cellule::setEtat(const bool & etat)
{
	if (!etat)
		_rectangle->setFillColor(MORTE);
	else
		_rectangle->setFillColor(VIVANTE);

	_etat = etat;
}

const bool & Cellule::getEtat() const
{
	return _etat;
}

sf::RectangleShape & Cellule::getRectangle()
{
	return *_rectangle;
}

void Cellule::setPosition(const float & x, const float & y)
{
	_rectangle->setPosition(x, y);
	//coordonnées en données membre
	_x = x / _taille;
	_y = y / _taille;
	return;
}



Cellule::~Cellule()
{
}

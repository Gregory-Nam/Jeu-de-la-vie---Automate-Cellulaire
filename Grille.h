#pragma 
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cellule.h"
#include <iostream>

template <typename T>
using Matrice = typename std::vector<std::vector <T>>;

class Grille : public sf::Drawable
//****************************************************************************
//
// La classe grille qui va representer un ensemble de cellules
//
//****************************************************************************
{
private :
	// ensemble des cellules composant la grille
	Matrice<Cellule> _cellules;

	// taille graphique de la cellule
	unsigned _tailleCellule;

	// pour le moment la grille sera une matrice carrée
	// donc pas la notion de hauteur et longueur
	unsigned _dimension;

public:
	// constructeur
	// param :
	// - unsigned (taille des cellule)
	// - unsigned (dimension de la grille)
	Grille(const unsigned & tailleCellule, const unsigned & dimension);

	// constructeur par recopie
	// param :
	// - Grille
	Grille(Grille & grille);

	// réecriture de l'opérateur () accès au contenu de la cellule de coordonnées (x,y)
	// param :
	// - unsigned (x)
	// - unsigned (y)
	Cellule & operator() (const unsigned & x, const unsigned & y) throw();

	// renvoie la dimension de la grille
	const unsigned getDimension() const;

	// renvoie la matrice contenant l'ensemble des cellules de la grille
	const Matrice<Cellule> getCellules() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// Retourne une matrice avec le nombre de voisin par cellules
	Matrice<unsigned> nombresVoisinCellule();

	// calcule la grille à l'iteration suivante
	void iterationSuivante();

	// initialise la grille
	void init();

	// destructeur
	~Grille();
};


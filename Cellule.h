#pragma once
#include <SFML/Graphics.hpp>

#define MORTE sf::Color::White
#define VIVANTE sf::Color::Blue

class Grille;
//****************************************************************************
//
// La classe cellule correspond � un rectangle (RectangleShape de sfml)
// Pourquoi cette classe ? 
// - fonction specifique � la cellule
// - etat de la cellule
//
//****************************************************************************
class Cellule : public sf::Drawable
{
private:

	// Une cellule est repr�sent�e graphiquement par un rectangle
	sf::RectangleShape  * _rectangle;

	// donn�es du rectangle
	unsigned _taille;
	int _x, _y;

	// etat de la cellule, morte ou vivante
	// true : vivante
	// false : morte
	bool _etat;
	
public:
	// constructeur de la classe
	// param : 
	// - unsigned (taille)
	Cellule(const unsigned & taille);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// retourne le nombre de voisin de la cellule
	// Param : 
	// - Grille
	const unsigned compteVoisin(Grille * grille) const;

	// changement d'etat sans avoir � donner un etat
	void changeEtat();

	// choix d'un etat particulier pour la cellule
	// Param :
	// - bool (etat)
	void setEtat(const bool & etat);

	// retourne l'�tat de la cellule (true ou false)
	const bool & getEtat() const;

	// retourne la forme repr�sentant la cellule
	sf::RectangleShape & getRectangle();

	// appliquer la position � la cellule graphiquement
	// param :
	// - float (x)
	// - float (y)
	void setPosition(const float & x, const float & y);

	~Cellule();
};


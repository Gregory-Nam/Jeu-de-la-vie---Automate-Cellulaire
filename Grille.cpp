#include "Grille.h"

// Grille()
// Constructeur de la classe
Grille::Grille(const unsigned & tailleCellule, const unsigned & dimension) : _tailleCellule(tailleCellule),
																			 _dimension(dimension)
{
	_cellules.resize(dimension);
}

Grille::Grille(Grille & grille)
{
	_dimension = grille._dimension;
	_tailleCellule = grille._tailleCellule;
}

Cellule & Grille::operator()(const unsigned & x, const unsigned & y) throw()
{
	// retourne out_of_range exception si on est hors de la grille
	return _cellules.at(y).at(x);
}
const unsigned Grille::getDimension() const
{
	return _dimension;
}
const std::vector<std::vector<Cellule>> Grille::getCellules() const
{
	return _cellules;
}
void Grille::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (unsigned i = 0; i < _dimension; ++i) {
		for (unsigned j = 0; j < _dimension; ++j) {
			target.draw(_cellules[i][j], states);
		}
	}
}

Matrice<unsigned> Grille::nombresVoisinCellule()
{
	std::vector<std::vector <unsigned>> matriceVoisins(_dimension);
	unsigned compteur = 0;
	unsigned nbVoisin = 0;

	for (std::vector<Cellule> vecCellule : _cellules) {
		for (Cellule c : vecCellule) {
			nbVoisin = c.compteVoisin(this);
			matriceVoisins[compteur].push_back(nbVoisin);
		}
		++compteur;
	}
	return matriceVoisins;
}

void Grille::iterationSuivante()
{
	Matrice<unsigned> matriceVoisins = this->nombresVoisinCellule();
	// 3 cellules voisines vivante = cellule passe vivante
	// 2 cellules voisines vivante = cellule change pas d'etat
	// 3 < cellules vivantes < 2 = cellule meurt

	for (unsigned i = 0; i < _dimension; ++i) {
		for (unsigned j = 0; j < _dimension; ++j) {
			unsigned voisinCellule = matriceVoisins[i][j];			// nombre de voisin de la cellule (i,j)
			if (voisinCellule == 3) {								// traitement selon le nombre de voisin
				this->operator()(j,i).setEtat(true);
			}
			else if (voisinCellule > 3 || voisinCellule < 2) {
				this->operator()(j,i).setEtat(false);
			}
			//sinon la case ne change pas d'état
		}
	}
}



void Grille::init()
{
	for (unsigned i = 0; i < _dimension; ++i) {
		for (unsigned j = 0; j < _dimension; ++j) {
			Cellule cell(_tailleCellule);
			cell.setPosition(j * _tailleCellule, i * _tailleCellule);
			cell.getRectangle().setOutlineColor(sf::Color(0, 0, 0));
			cell.getRectangle().setOutlineThickness(1);
			_cellules[i].push_back(cell);								// on remplit la matrice de cellule

		}
	}

}

Grille::~Grille()
{
	std::cout << "Grille détruite" << std::endl;
}

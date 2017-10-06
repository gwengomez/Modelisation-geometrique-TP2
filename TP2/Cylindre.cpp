#include <vector>
#include <math.h>
#include "Cylindre.h"

float Cylindre::getRayon()
{
	return rayon;
}

void Cylindre::setRayon(float rayon)
{
	this->rayon = rayon;
}

float Cylindre::getHauteur()
{
	return hauteur;
}

void Cylindre::setHauteur(float hauteur)
{
	this->hauteur = hauteur;
}

int Cylindre::getNbMeridiens()
{
	return nbMeridiens;
}

void Cylindre::setNbMeridiens(int nbMeridiens)
{
	this->nbMeridiens = nbMeridiens;
}

point3 Cylindre::getPosition()
{
	return position;
}

void Cylindre::setPosition(point3 position)
{
	this->position.x = position.x;
	this->position.y = position.y;
	this->position.z = position.z;
}

Cylindre::Cylindre(float rayon, float hauteur, int nbMeridiens, point3 position)
{
	setRayon(rayon);
	setHauteur(hauteur);
	setNbMeridiens(nbMeridiens);
	setPosition(position);
}

std::pair<std::vector<point3>, std::vector<Facette>> Cylindre::generer()
{
	std::vector<point3> vecPoints;
	std::vector<Facette> vecFace;
	point3 centreHaut = point3(0, hauteur / 2, 0);
	point3 centreBas = point3(0, - hauteur / 2, 0);

	for (int i = 0; i < nbMeridiens; i++)
	{

		float xAvant = rayon * cos(2 * M_PI*((i - 1) / nbMeridiens));
std::cout << (2 * 3.14*((i - 1) / nbMeridiens)) << std::endl;
		float x = rayon * cos(2 * M_PI*(i / nbMeridiens));
		float xApres = rayon * cos(2 * M_PI*((i + 1) / nbMeridiens));

		float zAvant = rayon * sin(2 * M_PI*((i - 1) / nbMeridiens));
		float z = rayon * sin(2 * M_PI*(i / nbMeridiens));

		float sin = std::sin(2 * M_PI*((i + 1) / nbMeridiens));
		float zApres = rayon * std::sin(2 * M_PI*((i + 1) / nbMeridiens));
		point3 hautAvant = point3(xAvant, hauteur / 2, zAvant);
		point3 haut = point3(x, hauteur / 2, z);
		point3 bas = point3(x, - hauteur / 2, z);
		point3 basApres = point3(xApres, - hauteur / 2, zApres);

		vecPoints.push_back(haut);
		vecPoints.push_back(bas);

		vecFace.push_back(Facette(bas, hautAvant, haut));
		vecFace.push_back(Facette(bas, haut, basApres));
		vecFace.push_back(Facette(haut, hautAvant, centreHaut));
		vecFace.push_back(Facette(basApres, bas, centreBas));
	}

	std::pair<std::vector<point3>, std::vector<Facette>> paire;
	paire = std::make_pair(vecPoints, vecFace);

	return paire;

}
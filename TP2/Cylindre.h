#pragma once
#ifndef CYLINDRE_H
#define CYLINDRE_H
#include "point3.h"
#include "Facette.h"

class Cylindre
{
private:

	float rayon;
	float hauteur;
	int nbMeridiens;
	point3 position;

public:

	float getRayon();
	void setRayon(float rayon);
	float getHauteur();
	void setHauteur(float hauteur);
	int getNbMeridiens();
	void setNbMeridiens(int nbMeridiens);
	point3 getPosition();
	void setPosition(point3 position);
	Cylindre(float rayon, float hauteur, int nbMeridiens, point3 position);
	std::pair<std::vector<point3>, std::vector<Facette>> generer();

};
#endif
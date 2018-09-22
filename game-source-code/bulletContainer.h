#ifndef BULLETCONTAINER_H
#define BULLETCONTAINER_H
#include "laser.h"
#include <vector>

class BulletContainer : public Player {
public:
	BulletContainer();
	~BulletContainer();
	
	void shootKey();
	void addBullet(float x, float y);
	void DrawBullets(sf::RenderWindow& window);
	void deleteBullets();
	std::vector<Laser> bulletVector();
	
protected:
	Laser bullet1;
	std::vector<Laser>bulletLoop;
	std::vector<Laser>::const_iterator iter;
	bool isFiring;
	Player player1;
};

#endif
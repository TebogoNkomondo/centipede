#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "centipede.h"
#include "player.h"
#include "laser.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"CentipedeGame");
    auto startTheGame =false;
    
    // Set up text to display on splash screen
    sf::Font font;
    if(!font.loadFromFile("resources/sansation.ttf"))
        return EXIT_FAILURE;

    // Initialize the splash message
    sf::Text splashMessage;
    splashMessage.setFont(font);
    splashMessage.setCharacterSize(40);
    splashMessage.setPosition(170.f, 150.f);
    splashMessage.setFillColor(sf::Color::Green);
    splashMessage.setString("Welcome to the Centipede Game!\n\nInstructions:\nPress Space bar to shoot\nPress Right to move Right\nPress Left to move Left\nPress Down to move Down\nPress Up to move UP\n\nPress Enter to start the Game!!");
    
//===================================================Oratile's member variables==========================================================================
    centipede theCentipede(10);
    
    
//=====================================================Tebogo's member variables================================================================
	Player player1;
	//set player initial position
	player1.setPosition(sf::Vector2f(window.getSize().x/2  , window.getSize().y-player1.GetPlayer().getScale().y*90 ));
	//bullets
	Laser bullet1;
	std::vector<Laser>bulletLoop;
	bool isFiring;
	std::vector<Laser>::const_iterator iter;
	window.setFramerateLimit(30);
	//auto counter =0;
    
    
//===============================================================================================================================================
    while(window.isOpen())
    {
        sf::Event event;
		while(window.pollEvent(event))
        {
            switch(event.type)
            {
                //check that the window is not closed
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                //Check if the enter key has been presed. If it is set 'startTheGame' to true
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                        {
                        case sf::Keyboard::Enter:
                            startTheGame= true;
                            break;
                            
                        default:
                            break;
                        }
                default:
                    break;
            }

		}
        
        //If the Enter button has been pressed
        if (startTheGame)
        {
//=============================================Oratile Goes here==================================================================
            auto sizeOfCentipede= theCentipede.getCentipedesize();
                
            for(int i=0; i< sizeOfCentipede; i++)
            {
                theCentipede.moveCentipedeRight(i);
                theCentipede.moveCentipedeDown(i);
                theCentipede.moveCentipedeLeft(i);
                theCentipede.moveCentipedeUP(i);
                
                window.draw(theCentipede.myCentipede.at(i));
            }

    //====================================== Tebogo goes here======================================================================
            //handle bullet movements
            //shoot bullets
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
                isFiring = true; 
            }
            if(isFiring == true){
                bullet1.setPosition(sf::Vector2f(player1.GetPlayer().getPosition().x+13,player1.GetPlayer().getPosition().y));
                bulletLoop.push_back(bullet1);
                isFiring = false;
            }
            
            for(int i=0,kk=bulletLoop.size();i<kk;i++){
                bulletLoop[i].Shoot();
                bulletLoop[i].DrawBullet(window);
            }
            
            //delete bullets once they are out of the screen
            int counter=0;
            for(iter=bulletLoop.begin();iter<bulletLoop.end();iter++){
                if(bulletLoop[counter].GetLaser().getPosition().y<0){
                    bulletLoop.erase(iter);
                }
                counter++;
                if(bulletLoop.size()<=2){
                    counter=0;
                    break;
                }
            }

            //draw the player and deal with movement
            player1.Draw(window);
            player1.handleKey();

            window.display();
            window.clear();
        }
        
        //If Enter button has not been pressed
        else
        {
             window.draw(splashMessage);
             window.display();
             window.clear();
        }
    }
    
    return 0;
}

	

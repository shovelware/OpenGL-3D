//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include <SFML/Graphics.hpp>
#include "SFML/OpenGL.hpp" 
#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES
#include "math.h"

const double RD = 180 / M_PI;
const double DR = M_PI / 180;

using std::cout;
using std::endl;

using std::vector;
using std::string;
////////////////////////////////////////////////////////////
///Global Variables
//////////////////////////////////////////////////////////// 
const int screenW = 400;
const int screenH = 400;
const sf::Mouse mouse;
const sf::Keyboard keyboard;

////////////////////////////////////////////////////////////
///Functions
//////////////////////////////////////////////////////////// 

void LoadImages(const vector<sf::Texture> & textures, const vector<string> filenames)
{

}

void CheckInput()
{
	if (keyboard.isKeyPressed(keyboard.Up))
	{

	}
	if (keyboard.isKeyPressed(keyboard.Down))
	{

	}
	if (keyboard.isKeyPressed(keyboard.Left))
	{

	}
	if (keyboard.isKeyPressed(keyboard.Right))
	{

	}
	if (keyboard.isKeyPressed(keyboard.W))
	{

	}
	if (keyboard.isKeyPressed(keyboard.A))
	{

	}
	if (keyboard.isKeyPressed(keyboard.S))
	{

	}
	if (keyboard.isKeyPressed(keyboard.D))
	{

	}
	if (keyboard.isKeyPressed(keyboard.Q))
	{

	}
	if (keyboard.isKeyPressed(keyboard.E))
	{

	}

	if (keyboard.isKeyPressed(keyboard.R))
	{

	}
}

////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 
int main()
{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(800, 800, 32), "SFML OpenGL 3D");
	window.setFramerateLimit(60);
	vector<sf::Texture> tex;
	vector<string> filenames;

	sf::Texture pr;
	
	string image = "Assets\\pr.png";
	if (!pr.loadFromFile(image))
	{
		std::cout << "Could not load" << image;
		char c;
		std::cin >> c;
		return false;
	}

	sf::Texture::bind(&pr);
	glEnable(GL_TEXTURE_2D);

	GLdouble aaa[] = { 1, 1, 1 };
	GLdouble aab[] = { 1, 1, -1 };
	GLdouble abb[] = { 1, -1, -1 };
	GLdouble aba[] = { 1, -1, 1 };
	GLdouble baa[] = { -1, 1, 1 };
	GLdouble bab[] = { -1, 1, -1 };
	GLdouble bba[] = { -1, -1, 1 };
	GLdouble bbb[] = { -1, -1, -1 };


	double r = 0;
	// Start game loop 
	while (window.isOpen())
	{
		// Process events 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Close window : exit 
			if (Event.type == sf::Event::Closed)
				window.close();

			// Escape key : exit 
			if ((Event.type == sf::Event::KeyPressed) &&
				(Event.key.code == sf::Keyboard::Escape))
				window.close();
		}

		//Input
		CheckInput();

		r += 0.5;

		//prepare frame
		window.clear();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glRotated(r, 1, 0, 0);
		glRotated(r, 0, 1, 0);
		glScaled(0.5, 0.5, 0.5);

		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3dv(aaa);

		glTexCoord2d(1, 0);
		glVertex3dv(baa);

		glTexCoord2d(1, 1);
		glVertex3dv(bba);

		glTexCoord2d(0, 1);
		glVertex3dv(aba);

		glEnd();

		glBegin(GL_LINES);
		//top
		glVertex3dv(aaa);
		glVertex3dv(aab);

		glVertex3dv(aab);
		glVertex3dv(abb);

		glVertex3dv(abb);
		glVertex3dv(aba);

		glVertex3dv(aba);
		glVertex3dv(aaa);

		//bottom
		glVertex3dv(baa);
		glVertex3dv(bab);

		glVertex3dv(bab);
		glVertex3dv(bbb);

		glVertex3dv(bbb);
		glVertex3dv(bba);

		glVertex3dv(bba);
		glVertex3dv(baa);

		//sides
		glVertex3dv(aaa);
		glVertex3dv(baa);

		glVertex3dv(aba);
		glVertex3dv(bba);

		glVertex3dv(abb);
		glVertex3dv(bbb);

		glVertex3dv(aab);
		glVertex3dv(bab);

		glEnd();

		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;
}
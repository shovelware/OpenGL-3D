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

vector<sf::Texture> LoadImages(const vector<string> & filenames)
{
	vector<sf::Texture> textures;
	textures.reserve(filenames.size());
	sf::Texture temp;

	for (vector<string>::const_iterator vIter = filenames.begin(), vEnd = filenames.end(); vIter < vEnd; ++vIter)
	{
		if (!temp.loadFromFile(*vIter))
		{
			std::cout << "Could not load" << *vIter;
			textures.push_back(temp);
			continue;
		}

		textures.push_back(temp);
		
	}

	return textures;
}

vector<string> LoadFilenames()
{
	vector<string> filenames;
	filenames.reserve(9);

	filenames.push_back("Assets/p0.png");
	filenames.push_back("Assets/pr.png");
	filenames.push_back("Assets/pg.png");
	filenames.push_back("Assets/pb.png");
	filenames.push_back("Assets/pc.png");
	filenames.push_back("Assets/pm.png");
	filenames.push_back("Assets/py.png");
	filenames.push_back("Assets/p0.png");
	filenames.push_back("Assets/car.jpg");

	return filenames;
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

	glEnable(GL_TEXTURE_2D);
	vector<sf::Texture> tex = LoadImages(LoadFilenames());

	GLdouble aaa[] = { 1, 1, 1 };
	GLdouble aab[] = { 1, 1, -1 };
	GLdouble abb[] = { 1, -1, -1 };
	GLdouble aba[] = { 1, -1, 1 };
	GLdouble baa[] = { -1, 1, 1 };
	GLdouble bab[] = { -1, 1, -1 };
	GLdouble bba[] = { -1, -1, 1 };
	GLdouble bbb[] = { -1, -1, -1 };


	//Enable Back Face Culling
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glClearDepth(1.0f);

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

		//Draw Begin
		window.clear();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Matrices
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		r += 0.5;
		glRotated(r / 2, 1, 0, 0);
		glRotated(r, 0, 1, 0);
		glScaled(0.5, 0.5, 0.5);

		//Texture
		//Front aaa baa bba aba
		sf::Texture::bind(&tex.at(1));
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

		
		//Top aaa baa bab aab
		sf::Texture::bind(&tex.at(2));
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3dv(aaa);

		glTexCoord2d(1, 0);
		glVertex3dv(baa);

		glTexCoord2d(1, 1);
		glVertex3dv(bab);

		glTexCoord2d(0, 1);
		glVertex3dv(aab);
		glEnd();
		
		//Right aaa aba abb aab
		sf::Texture::bind(&tex.at(3));
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3dv(aaa);

		glTexCoord2d(1, 0);
		glVertex3dv(aba);

		glTexCoord2d(1, 1);
		glVertex3dv(abb);

		glTexCoord2d(0, 1);
		glVertex3dv(aab);
		glEnd();

		//Left bbb bba baa bab
		sf::Texture::bind(&tex.at(4));
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3dv(bbb);

		glTexCoord2d(1, 0);
		glVertex3dv(bba);

		glTexCoord2d(1, 1);
		glVertex3dv(baa);

		glTexCoord2d(0, 1);
		glVertex3dv(bab);
		glEnd();
		
		//Bottom bbb abb aba bba
		sf::Texture::bind(&tex.at(5));
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3dv(bbb);

		glTexCoord2d(1, 0);
		glVertex3dv(abb);

		glTexCoord2d(1, 1);
		glVertex3dv(aba);

		glTexCoord2d(0, 1);
		glVertex3dv(bba);
		glEnd();
		
		//Back bbb abb aab bab
		sf::Texture::bind(&tex.at(6));
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3dv(bbb);

		glTexCoord2d(1, 0);
		glVertex3dv(abb);

		glTexCoord2d(1, 1);
		glVertex3dv(aab);

		glTexCoord2d(0, 1);
		glVertex3dv(bab);
		glEnd();
		
		//Lines
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

		//Lines bottom
		glVertex3dv(baa);
		glVertex3dv(bab);

		glVertex3dv(bab);
		glVertex3dv(bbb);

		glVertex3dv(bbb);
		glVertex3dv(bba);

		glVertex3dv(bba);
		glVertex3dv(baa);

		//Lines sides
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
	}

	return EXIT_SUCCESS;
}
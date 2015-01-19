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
	filenames.reserve(10);

	filenames.push_back("Assets/p0.png");
	filenames.push_back("Assets/pr.png");
	filenames.push_back("Assets/pg.png");
	filenames.push_back("Assets/pb.png");
	filenames.push_back("Assets/pc.png");
	filenames.push_back("Assets/pm.png");
	filenames.push_back("Assets/py.png");
	filenames.push_back("Assets/p1.png");

	filenames.push_back("Assets/car.jpg");

	filenames.push_back("Assets/die.png");

	filenames.push_back("Assets/cant.png");
	filenames.push_back("Assets/cans.png");
	filenames.push_back("Assets/canb.png");

	return filenames;
}

vector<sf::Vector3f> GetCylinder(float radius, float vertices, float height)
{
	vector<sf::Vector3f> cyl;
	GLdouble* temp[3];

	float half = height / 2.0;

	//First point, center of top
	cyl.push_back({0, half, 0});

	//Top rim, bottom rim
	for (int i = 1; i >= -1; i -= 2)
	{
		for (int j = 0; j <= vertices - 1; ++j)
		{
			float posX = radius * (cos(DR * 360 / vertices * j));
			float posZ = radius * (sin(DR * 360 / vertices * j));
			cyl.push_back({ posX, half * i, posZ });
		}
	}

	//Last point, center of last
	cyl.push_back({ 0, -half, 0 });

	return cyl;
}

void GL(sf::Vector3f in)
{
	glVertex3d(in.x, in.y, in.z);
}

void GLT(int x)
{
	static int count = 0;
	
	if (count % 3 == 0)
	{
		cout << endl;
	}

	cout << x << " ";

	count++;
}

void GLQ(int x)
{
	static int counq = 0;

	if (counq % 4 == 0)
	{
		cout << endl;
	}

	cout << x << " ";

	counq++;
}


void Test()
{
	vector<int> vint;
	for (int i = 0; i < 10; i++)
	{
		vint.push_back(i);
	}


	int magic = (vint.size() - 2) / 2;

	cout << "Top:" << endl;
	for (vector<int>::iterator vStart = vint.begin(), vIter = vStart + 1, vLast = vStart + magic, vEnd = vLast + 1;	vIter != vEnd; ++vIter)
	{
		if (vIter != vLast)
		{
			GLT(*vStart);
			GLT(*vIter);
			GLT(*++vIter);
			--vIter;
		}

		else
		{
			GLT(*vStart);
			GLT(*vIter);
			GLT(*++vStart);
		}
	}

	cout << endl << "---" << endl << "Rim";
	for (vector<int>::iterator vStart = vint.begin(), vIter = vStart + 1, vLast = vStart + magic, vEnd = vLast + 1; vIter != vEnd; ++vIter)
	{
		if (vIter != vLast)
		{
			GLQ(*vIter);
			GLQ(*vIter + magic);
			GLQ(*vIter + magic + 1);
			GLQ(*vIter + 1);
		}

		else
		{
			GLQ(*vIter);
			GLQ(*vIter + magic);
			GLQ(*vIter + 1);
			GLQ(*vStart + 1);
		}

	}

	cout << endl << "---" << endl << "Bottom";
	for (vector<int>::iterator vStart = vint.begin() + magic, vIter = vStart + 1, vLast = vStart + magic, vEnd = vLast + 1; vIter != vEnd; ++vIter)
	{
		if (vIter != vLast)
		{
			GLT(*vEnd);
			GLT(*++vIter);
			GLT(*--vIter);
		}

		else
		{
			GLT(*vEnd);
			GLT(*vIter);
			GLT(*++vStart);
		}
	}
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

	enum prim{ cube, dice, cyl, can };
	prim mode = cyl;

	glEnable(GL_TEXTURE_2D);
	vector<sf::Texture> tex = LoadImages(LoadFilenames());

	//Cube coords
	GLdouble aaa[] = { 1, 1, 1 };
	GLdouble aab[] = { 1, 1, -1 };
	GLdouble abb[] = { 1, -1, -1 };
	GLdouble aba[] = { 1, -1, 1 };
	GLdouble baa[] = { -1, 1, 1 };
	GLdouble bab[] = { -1, 1, -1 };
	GLdouble bba[] = { -1, -1, 1 };
	GLdouble bbb[] = { -1, -1, -1 };
	
	//Cylinder vars
	float cylrad = 0.5f,
		cylhei = 1.0,
		cylver = 16,
		magic = 0;
	vector<sf::Vector3f> cylPoi = GetCylinder(cylrad, cylver, cylhei);

	//Enable Back Face Culling
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glClearDepth(1.0f);

	double r = 0;

	Test();

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

		float x, y;

		switch (mode)
		{
		case cube:
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			//Matrices
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			r += 0.5;
			glRotated(r / 2, 1, 0, 0);
			glRotated(r, 0, 1, 0);
			glScaled(0.5, 0.5, 0.5);

			//Texture
			//Front aaa baa bba aba r
			glColor3f(1, 0, 0);
			glBegin(GL_QUADS);
			glVertex3dv(aaa);
			glVertex3dv(baa);
			glVertex3dv(bba);
			glVertex3dv(aba);
			glEnd();


			//Top aaa baa bab aab g
			glColor3f(0, 1, 0);
			glBegin(GL_QUADS);
			glVertex3dv(aaa);
			glVertex3dv(baa);
			glVertex3dv(bab);
			glVertex3dv(aab);
			glEnd();

			//Right aaa aba abb aab b
			glColor3f(0, 0, 1);
			glBegin(GL_QUADS);
			glVertex3dv(aaa);
			glVertex3dv(aba);
			glVertex3dv(abb);
			glVertex3dv(aab);
			glEnd();

			//Left bbb bba baa bab c
			glColor3f(0, 1, 1);
			glBegin(GL_QUADS);
			glVertex3dv(bbb);
			glVertex3dv(bba);
			glVertex3dv(baa);
			glVertex3dv(bab);
			glEnd();

			//Bottom bbb abb aba bba m
			glColor3f(1, 0, 1);
			glBegin(GL_QUADS);
			glVertex3dv(bbb);
			glVertex3dv(abb);
			glVertex3dv(aba);
			glVertex3dv(bba);
			glEnd();

			//Back bbb abb aab bab y
			glColor3f(0, 1, 1);
			glBegin(GL_QUADS);
			glVertex3dv(bbb);
			glVertex3dv(abb);
			glVertex3dv(aab);
			glVertex3dv(bab);
			glEnd();

			//Lines
			glColor3f(1, 1, 1);	
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
			break;
		case dice:
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			//Matrices
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			r += 0.5;
			glRotated(r / 2, 1, 0, 0);
			glRotated(r, 0, 1, 0);
			glScaled(0.5, 0.5, 0.5);

			sf::Texture::bind(&tex.at(9));
			x = 1.0 / 3.0;
			y = 1.0 / 2.0;

			//Texture
			//Front aaa baa bba aba 1
			glBegin(GL_QUADS);
			glTexCoord2d(1 * x, 0 * y);
			glVertex3dv(aaa);

			glTexCoord2d(0 * x, 0 * y);
			glVertex3dv(baa);

			glTexCoord2d(0 * x, 1 * y);
			glVertex3dv(bba);

			glTexCoord2d(1 * x, 1 * y);
			glVertex3dv(aba);
			glEnd();
			
			//Top aaa baa bab aab 3
			glBegin(GL_QUADS);
			glTexCoord2d(2 * x, 1 * y);
			glVertex3dv(aaa);

			glTexCoord2d(2 * x, 0 * y);
			glVertex3dv(baa);

			glTexCoord2d(3 * x, 0 * y);
			glVertex3dv(bab);

			glTexCoord2d(3 * x, 1 * y);
			glVertex3dv(aab);
			glEnd();

			//Right aaa aba abb aab 2
			glBegin(GL_QUADS);
			glTexCoord2d(x * 1, y * 0);
			glVertex3dv(aaa);

			glTexCoord2d(x * 1, y * 1);
			glVertex3dv(aba);

			glTexCoord2d(x * 2, y * 1);
			glVertex3dv(abb);

			glTexCoord2d(x * 2, y * 0);
			glVertex3dv(aab);
			glEnd();

			//Left bbb bba baa bab 5
			glBegin(GL_QUADS);
			glTexCoord2d(x * 1, y * 2);
			glVertex3dv(bbb);

			glTexCoord2d(x * 2, y * 2);
			glVertex3dv(bba);

			glTexCoord2d(x * 2, y * 1);
			glVertex3dv(baa);

			glTexCoord2d(x * 1, y * 1);
			glVertex3dv(bab);
			glEnd();

			//Bottom bbb abb aba bba 4
			glBegin(GL_QUADS);
			glTexCoord2d(x * 1, y * 2);
			glVertex3dv(bbb);

			glTexCoord2d(x * 1, y * 1);
			glVertex3dv(abb);

			glTexCoord2d(x * 0, y * 1);
			glVertex3dv(aba);

			glTexCoord2d(x * 0, y * 2);
			glVertex3dv(bba);
			glEnd();

			//Back bbb abb aab bab 6
			glBegin(GL_QUADS);
			glTexCoord2d(x * 3, y * 2);
			glVertex3dv(bbb);

			glTexCoord2d(x * 2, y * 2);
			glVertex3dv(abb);

			glTexCoord2d(x * 2, y * 1);
			glVertex3dv(aab);

			glTexCoord2d(x * 3, y * 1);
			glVertex3dv(bab);
			glEnd();

			//Lines
			glBegin(GL_LINES);
			glColor3f(1, 1, 1);
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
			break;
			case cyl:
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				//Matrices
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();

				glDisable(GL_CULL_FACE);

				glPolygonMode(GL_BACK, GL_LINE);
				glPolygonMode(GL_FRONT, GL_FILL);
				r += 2;
				glRotated(r / 2, 1, 0, 0);
				glRotated(r, 0, 1, 0);
				glScaled(0.5, 0.5, 0.5);

				magic = (cylPoi.size() - 2) / 2;

				//Top
				glColor3f(0, 1, 0);
				glBegin(GL_TRIANGLES);
				for (vector<sf::Vector3f>::iterator vStart = cylPoi.begin(), vIter = vStart + 1, vLast = vStart + magic, vEnd = vLast + 1; vIter != vEnd; ++vIter)
				{
					if (vIter != vLast)
					{
						GL(*vStart);
						GL(*vIter);
						GL(*(vIter + 1));
					}

					else
					{
						GL(*vStart);
						GL(*vIter);
						GL(*++vStart);
					}
				}

				glEnd();

				//Rim
				
				glColor3f(0, 0, 1);
				glBegin(GL_QUADS);
				for (vector<sf::Vector3f>::iterator vStart = cylPoi.begin(), vIter = vStart + 1, vLast = vStart + magic, vEnd = vLast + 1; vIter != vEnd; ++vIter)
				{
					if (vIter != vLast)
					{
						GL(*vIter);
						GL(*(vIter + magic));
						GL(*(vIter + magic + 1));
						GL(*(vIter + 1));
					}

					else
					{
						GL(*vIter);
						GL(*(vIter + magic));
						GL(*(vIter + 1));
						GL(*(vStart + 1));
					}

				}
				glEnd();
				

				//Bottom
				glColor3f(1, 0, 0);
				glBegin(GL_TRIANGLES);
				for (vector<sf::Vector3f>::iterator vStart = cylPoi.begin() + magic, vIter = vStart + 1, vLast = vStart + magic, vEnd = vLast + 1; vIter != vEnd; ++vIter)
				{
					if (vIter != vLast)
					{
						GL(*vEnd);
						GL(*++vIter);
						GL(*--vIter);
					}
					
					else
					{
						GL(*vEnd);
						GL(*++vStart);
						GL(*vIter);
					}
				}
				glEnd();

				break;
			case can:
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

				//Matrices
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();

				glDisable(GL_CULL_FACE);

				glPolygonMode(GL_BACK, GL_LINE);
				glPolygonMode(GL_FRONT, GL_FILL);
				r += 2;
				glRotated(r / 2, 1, 0, 0);
				glRotated(r, 0, 1, 0);
				glScaled(0.5, 0.5, 0.5);

				magic = (cylPoi.size() - 2) / 2;

				//Top
				glColor3f(0, 1, 0);
				glBegin(GL_TRIANGLES);
				for (vector<sf::Vector3f>::iterator vStart = cylPoi.begin(), vIter = vStart + 1, vLast = vStart + magic, vEnd = vLast + 1; vIter != vEnd; ++vIter)
				{
					if (vIter != vLast)
					{
						GL(*vStart);
						GL(*vIter);
						GL(*(vIter + 1));
					}

					else
					{
						GL(*vStart);
						GL(*vIter);
						GL(*++vStart);
					}
				}

				glEnd();

				//Rim

				glColor3f(0, 0, 1);
				glBegin(GL_QUADS);
				for (vector<sf::Vector3f>::iterator vStart = cylPoi.begin(), vIter = vStart + 1, vLast = vStart + magic, vEnd = vLast + 1; vIter != vEnd; ++vIter)
				{
					if (vIter != vLast)
					{
						GL(*vIter);
						GL(*(vIter + magic));
						GL(*(vIter + magic + 1));
						GL(*(vIter + 1));
					}

					else
					{
						GL(*vIter);
						GL(*(vIter + magic));
						GL(*(vIter + 1));
						GL(*(vStart + 1));
					}

				}
				glEnd();


				//Bottom
				glColor3f(1, 0, 0);
				glBegin(GL_TRIANGLES);
				for (vector<sf::Vector3f>::iterator vStart = cylPoi.begin() + magic, vIter = vStart + 1, vLast = vStart + magic, vEnd = vLast + 1; vIter != vEnd; ++vIter)
				{
					if (vIter != vLast)
					{
						GL(*vEnd);
						GL(*++vIter);
						GL(*--vIter);
					}

					else
					{
						GL(*vEnd);
						GL(*++vStart);
						GL(*vIter);
					}
				}
				glEnd();

				break;
		}

		// Finally, display rendered frame on screen 
		window.display();
	}

	return EXIT_SUCCESS;
}
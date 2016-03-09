#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Utility.h"
#include "MenuInicio.h"
#include "iostream"

//Window.
sf::RenderWindow window (sf::VideoMode(750, 376), "Star Wars Rogue Republic");

using namespace std;
using namespace sf;

MenuInicio::MenuInicio(){

	//Fonts.
	Font Aurebesh;
	Aurebesh.loadFromFile("Assets/Fonts/Aurebesh.ttf");
	Font Standard;
	Standard.loadFromFile("Assets/Fonts/Standard.ttf");

	//Color.
	Color Mi_Azul(0,43,75,255);

	//Text.
	Text Instruction;
	Instruction.setString("Press Space to continue..");
	Instruction.setColor(Mi_Azul);

	Text text1;
	text1.setColor(Mi_Azul);

	Text text2;
	text2.setColor(Mi_Azul);

	//Music.
	Music BackgroundAudio;
	BackgroundAudio.openFromFile("Assets/Audio/Music/Star Wars Episode III   Order 66 Soundtrack.ogg");
	BackgroundAudio.play();

	//Sound FX.
	SoundBuffer sfxBuffer;
	sfxBuffer.loadFromFile("Assets/Audio/SFX/ButtonPressed.ogg");
	Sound ButtonPressed;
	ButtonPressed.setBuffer(sfxBuffer);

	//Textures & Sprites.
	Texture MenuTemplate;
	MenuTemplate.loadFromFile("Assets/Visual_Templates/MenuInicioTemplate.png");
	Sprite MT;
	MT.setTexture(MenuTemplate);

	Texture Tittle;
	Tittle.loadFromFile("Assets/Visual_Templates/Logo(MainMenu).png");
	Sprite TMM;
	TMM.setTexture(Tittle);

	Texture SignInButton;
	SignInButton.loadFromFile("Assets/Visual_Templates/SignIn.png");
	Sprite SignInB;
	SignInB.setTexture(SignInButton);
	Texture SignUpButton;
	SignUpButton.loadFromFile("Assets/Visual_Templates/SignUp.png");
	Sprite SignUpB;
	SignUpB.setTexture(SignUpButton);
	
	//Clock and Time.
	Clock clock;
	Time time;
	
	//Set Window Panel.
	bool Inicio = true;
	bool SignMenu = false;
	bool SignIn = false;
	bool SignUp = false;

	//Runtime loop.
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		Vector2i localPosition = Mouse::getPosition(window);

		//Panel Switch.
		if (Inicio) {
			//Sprites Location.
			TMM.setPosition(50, 50);

			//Inicio Panel Font Switch.
			time = clock.getElapsedTime();
			float seconds = time.asSeconds();

			if (seconds <= 4) {
				Instruction.setFont(Aurebesh);
				Instruction.setPosition(70, 250);
			}
			else if (seconds <= 8) {
				Instruction.setFont(Standard);
				Instruction.setPosition(220, 250);
			}
			else {
				clock.restart();
			}

			//Ir a SignMenu.
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				ButtonPressed.play();
				Inicio = false;
				SignMenu = true;
			}

			//Limpiar la ventana.
			window.clear();

			//Dibujar en la ventana.
			window.draw(MT);
			window.draw(TMM);
			window.draw(Instruction);
			window.display();
		}
		else if (SignMenu) {
			//Cambiar Textura del Fondo.
			MenuTemplate.loadFromFile("Assets/Visual_Templates/MenuTemplate.png");

			//Cargar Botones.
			SignInB.setPosition(180, 120);
			text1.setString("Sign In");
			SignUpB.setPosition(430, 120);
			text2.setString("Sign Up");

			//Texto.
			float seconds = time.asSeconds();
			if (seconds <= 4) {
				text1.setFont(Aurebesh);
				text1.setPosition(180, 270);
				text2.setFont(Aurebesh);
				text2.setPosition(430, 270);
			}
			else if (seconds <= 8) {
				text1.setFont(Standard);
				text1.setPosition(180, 270);
				text2.setFont(Standard);
				text2.setPosition(430, 270);
			}
			else {
				clock.restart();
			}

			//Limpiar la ventana.
			window.clear();

			//Dibujar en la ventana.
			window.draw(MT);
			window.draw(SignInB);
			window.draw(text1);
			window.draw(SignUpB);
			window.draw(text2);
			window.display();

		}
		else if (SignIn) {
			window.clear();
		}
		else if (SignUp) {

		}
	}
}

bool SignIn() {
	return false;
}
bool SignUp() {
	return false;
}


MenuInicio::~MenuInicio()
{
}

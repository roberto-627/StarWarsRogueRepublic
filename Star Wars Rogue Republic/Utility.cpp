#include "Utility.h"

Utility::Utility()
{
}

bool IsPressed(sf::Sprite *sprite, sf::Vector2i MousePosition) {
	if (MousePosition.x >= sprite->getPosition().x && MousePosition.x <= (sprite->getPosition().x + sprite->getTextureRect().width)) {
		if (MousePosition.y >= sprite->getPosition().y && MousePosition.y <= (sprite->getPosition().y + sprite->getTextureRect().height)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				return true;
			}
		}
	}
	return false;
}

char TextInput() {
	return 'a';
}


Utility::~Utility()
{
}

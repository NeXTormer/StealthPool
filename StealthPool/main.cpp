#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>


//#define FULLSCREEENWINDOWPETER 

sf::RectangleShape *shapes = new sf::RectangleShape[10000];



void addRects(sf::RenderWindow &window) {
	std::random_device rd;     
	std::mt19937 rng(rd());    
	std::uniform_int_distribution<int> uni(0, 255); 
	
	int p = 0;
	for (int j = 0; j < 100; j++) {
		for (int i = 0; i < 100; i++) {
			sf::RectangleShape shape(sf::Vector2f(30, 30));
			shape.setPosition(sf::Vector2f(j * 30, i * 30));
			shape.setFillColor(sf::Color(uni(rng), uni(rng), uni(rng)));
			p++;
			shapes[p] = shape;
		}
	}
	std::cout << sizeof(shapes) * 10000 << std::endl;

}

int main() {

	std::cout << "RENDL" << std::endl;

#ifdef FULLSCREEENWINDOWPETER
	sf::RenderWindow window(sf::VideoMode(2560, 1440), "Peter", sf::Style::Fullscreen);
	sf::View view(sf::Vector2f(2560 / 2, 1440 / 2), sf::Vector2f(2560, 1440));

#else
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Peter", sf::Style::Close | sf::Style::Default);
	window.setFramerateLimit(100);
	sf::View view(sf::Vector2f(500, 500), sf::Vector2f(1000, 1000));

#endif
	sf::Color clearcolor(0x3A40f5);
	sf::Clock clock;
	sf::Time time;
	sf::CircleShape shape(50);
	addRects(window);

	shape.setPosition(sf::Vector2f(100, 100));

	while (window.isOpen()) {
		window.clear(clearcolor);
		
		for (int i = 0; i < 10000; i++) {
			window.draw(shapes[i]);
		}
		window.draw(shape);

		//shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) view.move(sf::Vector2f(-10, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) view.move(sf::Vector2f(10, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) view.move(sf::Vector2f(0, 10));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) view.move(sf::Vector2f(0, -10));
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) view.zoom(1.1);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) view.zoom(0.9);
		window.setView(view);


		sf::Event ev;
		while (window.pollEvent(ev)) {
			switch (ev.type) {
			case sf::Event::Closed:
				window.close();
				return 0;
				break;
			case sf::Event::Resized:
				printf("width: %i, height %i \n", ev.size.width, ev.size.height);
				
				window.setSize(sf::Vector2u(ev.size.width, ev.size.height));
				break;
			case sf::Event::TextEntered:
				printf("%c", ev.text.unicode);
			}
		}
		window.display();

		time = clock.getElapsedTime();
		std::cout << 1.0f / time.asSeconds() << std::endl;

		clock.restart().asSeconds();
	}

	window.close();
	

}
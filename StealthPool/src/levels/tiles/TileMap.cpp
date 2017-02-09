#include "tilemap.h"
#include "../../gamestates/playstate.h"
#include <iostream>

TileMap::TileMap()
{
	tileset.loadFromFile("res/tileset.png");
	mesh = sf::VertexArray(sf::PrimitiveType::Quads, 64 * 64 * 4);

}


void TileMap::loadFromFile(sf::String path)
{
	sf::Clock c;
	c.restart();

	sf::Image tilemap;
	tilemap.loadFromFile(path);

	//TODO: Check how many tiles on the tilemap actually contain something
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			sf::Vertex *currentTile = &mesh[(i * width + j) * 4];
			int hcolor = tilemap.getPixel(j, i).toInteger();
#if 1
			if (hcolor == 0x00FFFFFF) {
				currentTile[0].position = sf::Vector2f(j * tilesize, i * tilesize);
				currentTile[1].position = sf::Vector2f((j + 1) * tilesize, i * tilesize);
				currentTile[2].position = sf::Vector2f((j + 1) * tilesize, (i + 1) * tilesize);
				currentTile[3].position = sf::Vector2f(j * tilesize, (i + 1) * tilesize);

				currentTile[0].texCoords = sf::Vector2f(3 * 32, 32);
				currentTile[1].texCoords = sf::Vector2f(4 * 32, 32);
				currentTile[2].texCoords = sf::Vector2f(4 * 32, 2 * 32);
				currentTile[3].texCoords = sf::Vector2f(3 * 32, 2 * 32);

				collisionTiles.push_back(sf::IntRect(j * 32, i * 32, 32, 32)); //add tile to  collisionTiles to make it collideable
			}
			else if (hcolor == 0x404040FF) {
				currentTile[0].position = sf::Vector2f(j * tilesize, i * tilesize);
				currentTile[1].position = sf::Vector2f((j + 1) * tilesize, i * tilesize);
				currentTile[2].position = sf::Vector2f((j + 1) * tilesize, (i + 1) * tilesize);
				currentTile[3].position = sf::Vector2f(j * tilesize, (i + 1) * tilesize);

				currentTile[0].texCoords = sf::Vector2f(0, 0);
				currentTile[1].texCoords = sf::Vector2f(32, 0);
				currentTile[2].texCoords = sf::Vector2f(32, 32);
				currentTile[3].texCoords = sf::Vector2f(0 , 32);
			}
			else if (hcolor == 0x4CFF00FF) {
				currentTile[0].position = sf::Vector2f(j * tilesize, i * tilesize);
				currentTile[1].position = sf::Vector2f((j + 1) * tilesize, i * tilesize);
				currentTile[2].position = sf::Vector2f((j + 1) * tilesize, (i + 1) * tilesize);
				currentTile[3].position = sf::Vector2f(j * tilesize, (i + 1) * tilesize);

				guards.push_back(Guard(sf::Vector2f(j * 32, i * 32), tileset));
				currentTile[0].texCoords = sf::Vector2f(0, 0);
				currentTile[1].texCoords = sf::Vector2f(32, 0);
				currentTile[2].texCoords = sf::Vector2f(32, 32);
				currentTile[3].texCoords = sf::Vector2f(0, 32);
			}
			else if (hcolor == 0xFFFFFFFF) {
				//currentTile[0].position = sf::Vector2f(j * tilesize, i * tilesize);
				//currentTile[1].position = sf::Vector2f((j + 1) * tilesize, i * tilesize);
				//currentTile[2].position = sf::Vector2f((j + 1) * tilesize, (i + 1) * tilesize);
				//currentTile[3].position = sf::Vector2f(j * tilesize, (i + 1) * tilesize);

				//currentTile[0].texCoords = sf::Vector2f(2 * 32, 0);
				//currentTile[1].texCoords = sf::Vector2f(3 * 32, 0);
				//currentTile[2].texCoords = sf::Vector2f(3 * 32, 32);
				//currentTile[3].texCoords = sf::Vector2f(2 * 32, 32);
			}
			else if (hcolor == 0xFF00FFFF) {
				currentTile[0].position = sf::Vector2f(j * tilesize, i * tilesize);
				currentTile[1].position = sf::Vector2f((j + 1) * tilesize, i * tilesize);
				currentTile[2].position = sf::Vector2f((j + 1) * tilesize, (i + 1) * tilesize);
				currentTile[3].position = sf::Vector2f(j * tilesize, (i + 1) * tilesize);

				currentTile[0].texCoords = sf::Vector2f(32, 0);
				currentTile[1].texCoords = sf::Vector2f(2 * 32, 0);
				currentTile[2].texCoords = sf::Vector2f(2 * 32, 32);
				currentTile[3].texCoords = sf::Vector2f(32, 32);
				endTiles.push_back(sf::IntRect(j * 32, i * 32, 32, 32));
			}
			else if (hcolor == 0xFFFF00FF) {
				currentTile[0].position = sf::Vector2f(j * tilesize, i * tilesize);
				currentTile[1].position = sf::Vector2f((j + 1) * tilesize, i * tilesize);
				currentTile[2].position = sf::Vector2f((j + 1) * tilesize, (i + 1) * tilesize);
				currentTile[3].position = sf::Vector2f(j * tilesize, (i + 1) * tilesize);

				currentTile[0].texCoords = sf::Vector2f(2 * 32, 32);
				currentTile[1].texCoords = sf::Vector2f(3 * 32, 32);
				currentTile[2].texCoords = sf::Vector2f(3 * 32, 2 * 32);
				currentTile[3].texCoords = sf::Vector2f(2 * 32, 2 * 32);

			}
			else {
				//currentTile[0].texCoords = sf::Vector2f(3 * 32, 0);
				//currentTile[1].texCoords = sf::Vector2f(4 * 32, 0);
				//currentTile[2].texCoords = sf::Vector2f(4 * 32, 32);
				//currentTile[3].texCoords = sf::Vector2f(3 * 32, 32);

			}
#else

			currentTile[0].texCoords = sf::Vector2f(32, 0);
			currentTile[1].texCoords = sf::Vector2f(2 * 32, 0);
			currentTile[2].texCoords = sf::Vector2f(2 * 32, 32);
			currentTile[3].texCoords = sf::Vector2f(32, 32);

#endif

		}
	}
	std::cout << "VertexCount: " << mesh.getVertexCount() << std::endl;
	std::cout << "Time: " << c.getElapsedTime().asMilliseconds() << std::endl;
	c.restart();
}


void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform = getTransform();
	states.shader = PlayState::shader;
	states.texture = &tileset;


	target.draw(mesh, states);

	for (Guard g : guards)
	{
		target.draw(g);
	}
}

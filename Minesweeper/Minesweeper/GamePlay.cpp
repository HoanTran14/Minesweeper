#include "GamePlay.h"


GamePlay::GamePlay(sf::RenderWindow* window)
{
	
	this->mWindow = window;
	this->mWindow->setSize(Vector2u(m * 32, n * 32));

	FloatRect visible(0, 0, m * 32, n * 32);
	this->mWindow->setView(View(visible));
	this->setup();
	this->play();
	}

	


void GamePlay::stop() {
	while (this->mWindow->isOpen())
	{
		Event event;
		while (this->mWindow->pollEvent(event))
		{
			if (event.type == Event::Closed)this->mWindow->close();
		}
		this->mWindow->clear();


		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				this->mWindow->draw(node[i][j].LastLayer);
			}
		this->mWindow->display();
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { 
			
			this->mWindow->setSize(Vector2u(MAIN_W, MAIN_H));

			FloatRect visible(0, 0, MAIN_W, MAIN_H);
			this->mWindow->setView(View(visible));
			break; }
	}
}
void GamePlay::win() {
	this->mWindow->setSize(Vector2u(MAIN_W, MAIN_H));

	FloatRect visible(0, 0, MAIN_W, MAIN_H);
	this->mWindow->setView(View(visible));
	Texture textureWin;
	textureWin.loadFromFile(PathImage + "Play/Win.png");

	Sprite win(textureWin);
	win.setOrigin(textureWin.getSize().x / 2, textureWin.getSize().y / 2);
	win.setPosition(MAIN_W/2,MAIN_H/2);
	while (this->mWindow->isOpen())
	{
		Event event;
		while (this->mWindow->pollEvent(event))
		{
			if (event.type == Event::Closed)this->mWindow->close();
		}
		this->mWindow->clear();

		this->mWindow->draw(win);


		this->mWindow->display();
		if (Keyboard::isKeyPressed(Keyboard::Escape)) break;
	}
	
}
void GamePlay::setup() {
	start = false;
	keyUp = false;
	this->countBoom = 0;
	this->countLat = 0;
	this->Node9.loadFromFile(PathImage + "Play/Node.png");
	this->Node0.loadFromFile(PathImage + "Play/0.png");
	this->Node1.loadFromFile(PathImage + "Play/1.png");
	this->Node2.loadFromFile(PathImage + "Play/2.png");
	this->Node3.loadFromFile(PathImage + "Play/3.png");
	this->Node4.loadFromFile(PathImage + "Play/4.png");
	this->Node5.loadFromFile(PathImage + "Play/5.png");
	this->Node6.loadFromFile(PathImage + "Play/6.png");
	this->Node7.loadFromFile(PathImage + "Play/7.png");
	this->Node8.loadFromFile(PathImage + "Play/8.png");
	this->Mine.loadFromFile(PathImage + "Play/Mine.png");
	this->Win.loadFromFile(PathImage + "Play/Win.png");
	this->Flag.loadFromFile(PathImage + "Play/Flag.png");


	


	for (int i = 0; i < (m+2); i++)
	{
		node[i][0].kinds = 0;
		node[i][n+1].kinds = 0;
	}

	for (int j = 0; j < (n+2); j++)
	{
		node[0][j].kinds = 0;
		node[m+1][j].kinds = 0;
	}

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if ((rand() % 5 - 3) == -1)
			{
				node[i][j].kinds = -1;
				countBoom++;
				node[i][j].LastLayer.setTexture(Mine);
			
			}
			else {
				node[i][j].kinds = NULL;
				node[i][j].LastLayer.setTexture(Node0);
			}

	for (int i = 1; i <= m; i++)
				for (int j = 1; j <= n; j++)
				{
					node[i][j].setData(Node9);
					node[i][j].x = i * 32-32 ;
					node[i][j].y = j * 32 -32;
					node[i][j].FirstLayer.setPosition(node[i][j].x, node[i][j].y);
					node[i][j].LastLayer.setPosition(node[i][j].x, node[i][j].y);
					

					if (node[i][j].kinds == NULL)
					{
						if ((i >= 1) && (i <= m) && (j >= 1) && (j <= n))
						{
							int count = 0;
							if (node[i - 1][j].kinds == -1)count++;
							if (node[i + 1][j].kinds == -1)count++;
							if (node[i][j - 1].kinds == -1)count++;
							if (node[i][j + 1].kinds == -1)count++;
							if (node[i - 1][j - 1].kinds == -1)count++;
							if (node[i - 1][j + 1].kinds == -1)count++;
							if (node[i + 1][j - 1].kinds == -1)count++;
							if (node[i + 1][j + 1].kinds == -1)count++;
							node[i][j].kinds = count;
							switch (node[i][j].kinds)
							{
							case 0:
								node[i][j].LastLayer.setTexture(Node0);
								break;
							case 1:
								node[i][j].LastLayer.setTexture(Node1);
								break;
							case 2:
								node[i][j].LastLayer.setTexture(Node2);
								break;
							case 3:
								node[i][j].LastLayer.setTexture(Node3);
								break;
							case 4:
								node[i][j].LastLayer.setTexture(Node4);
								break;
							case 5:
								node[i][j].LastLayer.setTexture(Node5);
								break;
							case 6:
								node[i][j].LastLayer.setTexture(Node6);
								break;
							case 7:
								node[i][j].LastLayer.setTexture(Node7);
								break;
							case 8:
								node[i][j].LastLayer.setTexture(Node8);
								break;
							}
						}
					}
				}

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			if (node[i][j].kinds == 0) {
				cout << i << "  " << j << endl;

				node[i][j].kinds = -1;
				countBoom++;
				node[i][j].LastLayer.setTexture(Mine);
				
			}
		}

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			node[i][j].setData(Node9);
			node[i][j].x = i * 32 - 32;
			node[i][j].y = j * 32 - 32;
			node[i][j].FirstLayer.setPosition(node[i][j].x, node[i][j].y);
			node[i][j].LastLayer.setPosition(node[i][j].x, node[i][j].y);


			if (node[i][j].kinds != -1)
			{
				if ((i >= 1) && (i <= m) && (j >= 1) && (j <= n))
				{
					int count = 0;
					if (node[i - 1][j].kinds == -1)count++;
					if (node[i + 1][j].kinds == -1)count++;
					if (node[i][j - 1].kinds == -1)count++;
					if (node[i][j + 1].kinds == -1)count++;
					if (node[i - 1][j - 1].kinds == -1)count++;
					if (node[i - 1][j + 1].kinds == -1)count++;
					if (node[i + 1][j - 1].kinds == -1)count++;
					if (node[i + 1][j + 1].kinds == -1)count++;
					node[i][j].kinds = count;
					switch (node[i][j].kinds)
					{
					case 0:
						node[i][j].LastLayer.setTexture(Node0);
						break;
					case 1:
						node[i][j].LastLayer.setTexture(Node1);
						break;
					case 2:
						node[i][j].LastLayer.setTexture(Node2);
						break;
					case 3:
						node[i][j].LastLayer.setTexture(Node3);
						break;
					case 4:
						node[i][j].LastLayer.setTexture(Node4);
						break;
					case 5:
						node[i][j].LastLayer.setTexture(Node5);
						break;
					case 6:
						node[i][j].LastLayer.setTexture(Node6);
						break;
					case 7:
						node[i][j].LastLayer.setTexture(Node7);
						break;
					case 8:
						node[i][j].LastLayer.setTexture(Node8);
						break;
					}
				}
			}
		}

}

void GamePlay::play() {

	this->mWindow->clear();
	this->mWindow->display();

	this->mWindow->draw(node[3][3].FirstLayer);


	this->mWindow->display();

	Texture SpacetoCtn;
	SpacetoCtn.loadFromFile(PathImage + "Play/Space.png");

	Sprite spaceCtn(SpacetoCtn);
	spaceCtn.setOrigin(SpacetoCtn.getSize().x / 2, SpacetoCtn.getSize().y / 2);
	spaceCtn.setPosition(m * 16, n * 16);
	while (!Keyboard::isKeyPressed(Keyboard::Space))
	{
		Event event;
		while (this->mWindow->pollEvent(event))
		{
			if (event.type == Event::Closed) this->mWindow->close();
		}
		this->mWindow->clear();
		this->mWindow->draw(spaceCtn);
		this->mWindow->display();
	}




	cout << "start";
	while (this->mWindow->isOpen())
	{
		Event event;
		if (!start) {

			start = true;
		}
		else {
			while (this->mWindow->pollEvent(event))
			{
				if (event.type == Event::Closed) this->mWindow->close();
			}
			this->mWindow->clear();








			if (Mouse::isButtonPressed(Mouse::Left))
			{

				sf::Vector2i mouse_position = sf::Mouse::getPosition(*this->mWindow);
				int x = mouse_position.x / 32 + 1;
				int y = mouse_position.y / 32 + 1;
				
				if (x <= m && y <= n && x >= 1 && y >= 1)
				{
					if (!node[x][y].flag)
					{
						if (node[x][y].kinds == -1)
						{
							this->stop();
							break;
						}
						if (!node[x][y].lat)
						{
							countLat++;
						}
						node[x][y].lat = true;
						
						if ((this->countBoom + this->countLat) == m*n) {

							win();
							break;
						}
					}




				}
			}

			if (Mouse::isButtonPressed(Mouse::Right))
			{
		
				keyUp = true;



			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				
				if (event.mouseButton.button == sf::Mouse::Right) {
					
					if (keyUp) {
						keyUp = false;
						sf::Vector2i mouse_position = sf::Mouse::getPosition(*this->mWindow);
						int x = mouse_position.x / 32 + 1;
						int y = mouse_position.y / 32 + 1;
						
						if (x <= m && y <= n && x >= 1 && y >= 1)
						{
							if (node[x][y].flag == false)
							{
								node[x][y].FirstLayer.setTexture(Flag);
								node[x][y].flag = true;
								//cout << "Flag";
							}
							else
							{
								node[x][y].FirstLayer.setTexture(Node9);
								node[x][y].flag = false;
							}
						}
					}
				}
			}

			for (int i = 1; i <= m; i++)
				for (int j = 1; j <= n; j++)
				{
					this->mWindow->draw(node[i][j].LastLayer);
				}
			for (int i = 1; i <= m; i++)
				for (int j = 1; j <= n; j++)
				{
					if (!node[i][j].lat)this->mWindow->draw(node[i][j].FirstLayer);
				}
			this->mWindow->display();
		}

	}

}
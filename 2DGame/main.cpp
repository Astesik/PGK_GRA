#include "Game.hpp"
#include "Menu.hpp"


int main()
{
	RenderWindow window(VideoMode(1024, 768), "Platformowka PGK2");
	
	window.setFramerateLimit(60);
	
	int numberLevel = 0;
	window.setMouseCursorVisible(false);
	std::ifstream fin("res/save.txt");
	fin >> numberLevel;
	if (menu(window) == 1)
	{
		numberLevel = 3;

		std::ofstream fout2("res/save.txt", std::ios_base::trunc);
		fout2.close();
		fout2.open("res/save.txt", std::ios_base::out);
		fout2 << 0;
		fout2.close();
	}

	Music level1, level2, level3;
	level1.openFromFile("res/sound/retro.mp3");
	level2.openFromFile("res/sound/neon.mp3");
	level3.openFromFile("res/sound/short.mp3");
	level1.setVolume(5);
	level2.setVolume(5);
	level3.setVolume(5);
	level1.setLoop(true);
	level2.setLoop(true);
	level3.setLoop(true);

	SoundBuffer start;
	start.loadFromFile("res/sound/start.mp3");
	Sound startSound(start);
	startSound.setVolume(70);

	if (numberLevel == 1)
	{
		text(window, numberLevel);
		startSound.play();

		level1.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 2)
	{
		level1.stop();

		text(window, numberLevel);
		startSound.play();

		level2.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 3)
	{
		level2.stop();

		text(window, numberLevel);
		startSound.play();

		level3.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 4)
	{
		level1.stop();
		end(window, numberLevel);
	}

	std::ofstream fout("res/save.txt", std::ios_base::trunc);
	fout.close();
	fout.open("res/save.txt", std::ios_base::out);
	fout << numberLevel;
	fout.close();
	return 0;
}

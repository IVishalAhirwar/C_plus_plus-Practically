#include"V.h"
#include<stdlib.h>
#include"Swarm.h"


int main(int argv, char* argc[])
{
	srand(time(NULL));
	V::Screen screen1;

	if (screen1.Init() == false) { return -1; };
	/*
		Program Loop
	*/
	//unsigned int max(0), red(0), green(0), blue(0);
	V::Swarm swarm;

	while (true)
	{
		int tick = SDL_GetTicks();
		
		swarm.Update(tick);
		unsigned char red = (unsigned char)((1 + sin(tick * 0.001)) * 128);

		unsigned char green = (unsigned char)((1 + sin(tick * 0.002)) * 128);

unsigned char blue = (unsigned char)((1 + sin(tick * 0.003)) * 128);

//for (int y = 0;y < V::Screen::SCREEN_HEIGHT;y++)
//{
//	for (int x = 0;x < V::Screen::SCREEN_WIDTH;x++)
//	{
//		screen1.SetPixel(x, y,0,0,blue);
//	};
//};
		const V::Particle* pParticles = swarm.GetParticles();
		for (int i = 0;i < V::Swarm::nParticles;i++)
		{
			V::Particle particle = pParticles[i];
			int x = (particle.X+1)*V::Screen::SCREEN_WIDTH/2;
			int y = (particle.Y  * V::Screen::SCREEN_WIDTH / 2)+V::Screen::SCREEN_HEIGHT/2;
			screen1.SetPixel(x,y,red,green,blue);
		};
		screen1.BoxBlur();
		screen1.Update();
						
	

		if (screen1.ProcessEvents() == false)
		{
			break;
		};	

	};
	/*
			Window Destroy Part.
	*/
	screen1.Close();
	system("pause");
	return 0;


};


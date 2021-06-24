#pragma once
#include<iostream>
#include<math.h>
#include<SDL.h>
namespace V
{
	class Screen
	{
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		Uint32* buffer;
		Uint32* buffer1;
	


	public:
		const static int SCREEN_WIDTH =1366;
		const static int SCREEN_HEIGHT =720;

		Screen();
		bool Init();
		bool ProcessEvents();
		void Close();
		void Update();
	/*	void Clear();*/
		void SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void BoxBlur();

	protected:
	};

};


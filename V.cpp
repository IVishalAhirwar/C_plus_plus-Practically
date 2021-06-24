#include"V.h"

namespace V
{
	Screen::Screen() :
		window(NULL),
		renderer(NULL),
		texture(NULL),
		buffer(NULL) ,
		buffer1(NULL)
	{};

	bool Screen::Init()
	{
		/*
		SDL------INIT---------PART
	*/
		if (SDL_INIT_VIDEO < 0)
		{
			std::cout << "Error : SDL Initilization Failed!\n";
			return false;


		};

		std::cout << "[v01-24.06.21]Message : SDL Init SuccessFully Done!\n[v01-24.06.21]Congrates Vishal!\n";


		/*
			If SDL INIT Successed Create Window
		*/
		window = SDL_CreateWindow
		("Copyright(c)2021 Vishal-Ahirwar. Programming Language : C++",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			SDL_Quit();
			std::cout << "Error : Failed To Create Window!\n";
			return false;

		};

		renderer = SDL_CreateRenderer(window,
			-1,
			SDL_RENDERER_PRESENTVSYNC
		);
		texture = SDL_CreateTexture(renderer,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC,
			SCREEN_WIDTH,
			SCREEN_HEIGHT
		);

		if (renderer == NULL)
		{
			std::cout << "Error : Failed to Create Renderer!\n";
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		};

		if (texture == NULL)
		{
			std::cout << "Error : Failed to Create Texture!\n";
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;

		};

		buffer = new Uint32[
			SCREEN_WIDTH * SCREEN_HEIGHT*sizeof(Uint32)
		];
		memset(buffer,
			0,
			SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32)
		);
		buffer1 = new Uint32[
			SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32)
		];
		memset(buffer1,
			0,
			SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32)
		);

		return true;
	};

	bool Screen::ProcessEvents()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return false;

			};

		};
		return true;
	};

	void Screen::Close()
	{
		delete[] buffer;
		delete[] buffer1;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyTexture(texture);
		SDL_DestroyWindow(window);

		SDL_Quit();
	}
	void Screen::Update()
	{

		SDL_UpdateTexture(
			texture,
			NULL,
			buffer1,
			SCREEN_WIDTH * sizeof(Uint32)
		);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);

	};

	void Screen::SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
	{
		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		{
			return;
		};

		Uint32 color = 0;
		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xFF;
		buffer1[((y * SCREEN_WIDTH) + x)] = color;
	}
	void Screen::BoxBlur()
	{
		Uint32* temp =buffer;
		buffer = buffer1;
		buffer1 = temp;

		for (int y = 0;y < SCREEN_HEIGHT;y++)
		{
			for (int x = 0;x < SCREEN_WIDTH;x++)
			{
				int redT = 0;
				int greenT = 0;
				int blueT = 0;



				for (int row = -1;row < 1;row++)
				{
					for (int col = -1;col < 1;col++)
					{
						int CurrentX = x + row;
						int CurrentY = y + col;
						if (CurrentX >= 0 && CurrentX < SCREEN_WIDTH && CurrentY >0 && CurrentY < SCREEN_HEIGHT)
						{

							Uint32  color= buffer1[CurrentY * SCREEN_WIDTH + CurrentX];
							Uint8 red = color >>24;
							Uint8 green = color >>16;
							Uint8 blue = color >> 8;

							redT += red;
							greenT += green;
							blueT += blue;

						}

					}
				}
				Uint8 red = redT / 4.1;
				Uint8 green = greenT / 4.1;
				Uint8 blue = blueT / 4.1;

				SetPixel(x, y, red, green, blue);

			}

		}


	}
	;

	//void Screen::Clear()
	//{
	//	memset(buffer,
	//		0,
	//		SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32)
	//	);
	//	memset(buffer1,
	//		0,
	//		SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32)
	//	);
	//};






}
#include"Particles.h"
#include<stdlib.h>
#include<math.h>
#ifndef PI
#define PI 3.14159265358979323846
#endif



namespace V
{
	Particle::Particle():X(0),Y(0)
	{
		Init();
		/*X = ((2.0 * rand()) / RAND_MAX) - 1;
		Y = ((2.0 * rand()) / RAND_MAX) - 1;*/
	

	/*	Xspeed = 0.01 * (((2.0 * rand()) / RAND_MAX) - 1);
		Yspeed = 0.01 * (((2.0 * rand()) / RAND_MAX) - 1);*/

	}
	void Particle::Init()
	{

		X = 0;
		Y = 0;


		Direction = (2 * PI * rand()) / RAND_MAX;
		Speed = (0.04 * rand()) / RAND_MAX;

		Speed *= Speed;
	};

	Particle::~Particle()
	{
	};
	void Particle::Update(int tick)
	{
		/*const double speed = 0.01;*/
	/*	X += Xspeed;
		Y += Yspeed;

		if (X <= -1.0 || X >= 1.0)
		{
			Xspeed = -Xspeed;
		};
		if (Y <= -1.0 || Y >= 1.0)
		{
			Yspeed = -Yspeed;
		};*/
		Direction += tick*0.0003;	 //twicking particle motion

		double XSpeed = Speed * cos(Direction);
		double YSpeed = Speed * sin(Direction);

		X += XSpeed*tick;
		Y += YSpeed*tick;
		if (X < -1 || X>1 || Y < -1 || Y>1)
		{
			Init();
		};
		if (rand() < RAND_MAX / 100)
		{
			Init();
		};





	};

};

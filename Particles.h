#pragma once
namespace V
{
	struct Particle
	{
		double X, Y,Speed,Direction;
	/*	double Xspeed, Yspeed;*/
	public:
		void Update(int tick);
	private:
		void Init();
	public:
		Particle();
		~Particle();


	};
};


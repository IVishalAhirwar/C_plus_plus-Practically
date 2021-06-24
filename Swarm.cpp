#include"Swarm.h"
namespace V
{
	Swarm::Swarm() :Ltime(0)
	{
		pParticles = new V::Particle[nParticles];

	};

	Swarm::~Swarm()
	{
		delete[]pParticles;
	};
	void Swarm::Update(int tick)
	{
		int interval = tick - Ltime;
		for (int i = 0;i < nParticles;i++)
		{
			pParticles[i].Update(interval);

		};
		Ltime = tick;


	};


};

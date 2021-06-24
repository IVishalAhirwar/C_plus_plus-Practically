#pragma once
#include"Particles.h"
namespace V
{
	class Swarm
	{
	private:
		V::Particle* pParticles;
		int Ltime;
	public:
		void Update(int tick);
		Swarm();
		~Swarm();
		const static int nParticles = 90000;
		const V::Particle*const GetParticles() { return pParticles; };

	protected:
	};
};


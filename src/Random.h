/*
 * Random.h
 *
 *  Created on: May 29, 2018
 *      Author: adolfo
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include <random>

template<typename RealType>
struct Distribution {};

template<>
struct Distribution<int>
{
	typedef std::uniform_int_distribution<int> type;
};

template<>
struct Distribution<float>
{
	typedef std::uniform_real_distribution<float> type;
};

template<>
struct Distribution<double>
{
	typedef std::uniform_real_distribution<double> type;
};

class Random
{
public:

	static void Seed()
	{
		static std::random_device r;
		static std::seed_seq seed { r(), r(), r(), r(), r(), r(), r(), r() };
		rng_engine.seed(seed);

		mSeeded = true;
	}

	// Generate random number between low and high (both included)
	template <typename RealType>
	static RealType GetRandom(RealType low, RealType high)
	{
		if (!mSeeded)
			Seed();

		return typename Distribution<RealType>::type(low, high)(rng_engine);
	}
private:
	static bool mSeeded;
	static std::mt19937 rng_engine;
};

bool Random::mSeeded;
std::mt19937 Random::rng_engine;

#endif /* RANDOM_H_ */

#pragma once

#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 rng(rd());

int get_random_integer(int min, int max) 
{
	std::uniform_int_distribution<int> uni(min, max);
	return uni(rng);
}

float get_random_float(float min, float max)
{
	std::uniform_real_distribution<float> uni(min, max);
	return uni(rng);
}

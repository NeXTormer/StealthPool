#pragma once

struct TimeStep
{
private:
	float timestep;
	float lasttime;
public:

	TimeStep(float initialTime)
		: timestep(0.0f), lasttime(initialTime)
	{

	}

	void Update(float currentTime)
	{
		timestep = currentTime - lasttime;
		lasttime = currentTime;
	}

	float GetMillis() 
	{ 
		return timestep; 
	}
	
	float GetSeconds() 
	{ 
		return timestep * 0.001f;
	}
};
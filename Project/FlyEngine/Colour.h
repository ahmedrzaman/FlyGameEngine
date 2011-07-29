#ifndef _FLYENGINE_COLOUR_H
#define _FLYENGINE_COLOUR_H

#include <math.h>

struct Colour
{
private:
	int R, G, B, A;
public:
	// Initialises all the colour components to 255
	Colour();

	// Returns the value of the R component
	int GetRi();
	// Returns the normalised value of R
	float GetRf();
	// Returns the value of the G component
	int GetGi();
	// Returns the normalised  value of G
	float GetGf();
	// Returns the value of the B component
	int GetBi();
	// Returns the normalised  value of B
	float GetBf();
	// Returns the value of the A component
	int GetAi();
	// Returns the normalised  value of A
	float GetAf();

	// Sets the value of R
	void SetR(int value);
	// Sets the value of R, between 0 and 1
	void SetR(float value);
	// Sets the value of G
	void SetG(int value);
	// Sets the value of G, between 0 and 1
	void SetG(float value);
	// Sets the value of B
	void SetB(int value);
	// Sets the value of B, between 0 and 1
	void SetB(float value);
	// Sets the value of A
	void SetA(int value);
	// Sets the value of A, between 0 and 1
	void SetA(float value);
};

#endif
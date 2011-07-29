#include "Colour.h"

Colour::Colour()
{
	R = G = B = A = 255;
}


	int Colour::GetRi()
	{
		return R;
	}
	float Colour::GetRf()
	{
		float normalised = R;
		float length = float(sqrt( float(normalised * normalised) ));
		if (length == 0.0f)
			length = 1.0f;

		normalised = normalised / length;
		return normalised;
	}
	int Colour::GetGi()
	{
		return G;
	}
	float Colour::GetGf()
	{
		float normalised = G;
		float length = float(sqrt( float(normalised * normalised) ));
		if (length == 0.0f)
			length = 1.0f;

		normalised = normalised / length;
		return normalised;
	}
	int Colour::GetBi()
	{
		return B;
	}
	float Colour::GetBf()
	{
		float normalised = B;
		float length = float(sqrt( float(normalised * normalised) ));
		if (length == 0.0f)
			length = 1.0f;

		normalised = normalised / length;
		return normalised;
	}
	int Colour::GetAi()
	{
		return A;
	}
	float Colour::GetAf()
	{
		float normalised = A;
		float length = float(sqrt( float(normalised * normalised) ));
		if (length == 0.0f)
			length = 1.0f;

		normalised = normalised / length;

		return normalised;
	}

	void Colour::SetR(int value)
	{
		if (value < 0)	value = 0;
		if (value > 255) value = 255;

		R = value;
	}
	void Colour::SetR(float value)
	{
		if (value < 0.0f)	value = 0.0f;
		if (value > 1.0f) value = 1.0f;

		value = value * 255;

		R = value;
	}
	void Colour::SetG(int value)
	{
		if (value < 0)	value = 0;
		if (value > 255) value = 255;

		G = value;
	}
	void Colour::SetG(float value)
	{
		if (value < 0.0f)	value = 0.0f;
		if (value > 1.0f) value = 1.0f;

		value = value * 255;

		G = value;
	}
	void Colour::SetB(int value)
	{
		if (value < 0)	value = 0;
		if (value > 255) value = 255;

		B = value;
	}
	void Colour::SetB(float value)
	{
		if (value < 0.0f)	value = 0.0f;
		if (value > 1.0f) value = 1.0f;

		value = value * 255;

		B = value;
	}
	void Colour::SetA(int value)
	{
		if (value < 0)	value = 0;
		if (value > 255) value = 255;

		A = value;
	}
	void Colour::SetA(float value)
	{
		if (value < 0.0f)	value = 0.0f;
		if (value > 1.0f) value = 1.0f;

		value = value * 255;

		A = value;
	}
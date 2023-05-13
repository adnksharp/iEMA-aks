struct EMA 
{
	float alpha = 0.5, normal;
	float pass[2] = {0, 0};

	void filter (float value, float max)
	{
		value = value < max ? value : max;
		normal = value;
		pass[0] = (value * alpha) + (pass[0] * (1 - alpha));
		pass[1] = value - pass[0];
	}

	float hard ()
	{
		return pass[1];
	}

	float soft ()
	{
		return pass[0];
	}
	void print (float extra)
	{
		Serial.println(String(normal) + "," + String(pass[0]) + "," + String(pass[1]) + "," + String(extra));
	}
};

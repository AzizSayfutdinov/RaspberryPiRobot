#pragma once
class Motor
{
public: 
	virtual ~Motor() {};
	virtual double getPower() = 0;
	virtual void setPower(double power) = 0;		// power from -100% up to +100% for forwards and backwards movement

};


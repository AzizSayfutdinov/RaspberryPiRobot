#pragma once
class Motor
{
public: 
	virtual ~Motor() {};
	virtual double getPower() = 0;
	virtual void setPower(double power) = 0;

};


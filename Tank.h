#pragma once
#ifndef _TANK_H_
#include "opencv.hpp"
#include <string>
#include <list>

class Bullet
{
public:
	Bullet(const cv::Point& pos, double size_, int speed_)
	{
		position = pos;
		size = size_;
		speed = speed_;
		loop = 0;
		is_in_sight = true;
	}

	cv::Mat Draw(cv::Mat canvus);
	bool IsInSight() { return is_in_sight; }

private:
	cv::Point		position;
	double			size;
	int				speed;
	unsigned long   loop;
	bool			is_in_sight;
};

class Tank
{
public:
	Tank(cv::Mat canvus_, const cv::Size& tank_size_, int step_) : 
		canvus(canvus_), x(canvus_.cols / 2), y(canvus_.rows / 2), tank_size(tank_size_), step(step_){}
	
	void Move(const char key);
	cv::Mat Draw();

private:
	cv::Mat					canvus;
	cv::Size				tank_size;
	int						x, y;
	int						step;
	std::list<Bullet>		bullets;

private:
	void MoveLeft();
	void MoveUp();
	void MoveRight();
	void MoveDown();
};

#endif // !_TANK_H_

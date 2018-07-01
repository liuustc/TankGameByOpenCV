#pragma once
#ifndef _TANK_H_
#include "opencv.hpp"
#include <string>
#include <list>

class Bullet
{
public:
	Bullet(const cv::Point& pos, int size_, int speed_)
	{
		position = pos;
		size = size_;
		speed = speed_;
		loop = 0;
		is_in_sight = true;
	}

	void Draw(cv::Mat& canvus);
	bool IsInSight() { return is_in_sight; }

private:
	cv::Point		position;
	int				size;
	unsigned long   loop;
	int				speed;
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
	void DrawTank(cv::Mat&);
	void DrawBullets(cv::Mat&);
};

#endif // !_TANK_H_

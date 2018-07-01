#include "Tank.h"

cv::Mat Tank::Draw()
{
	cv::Mat drawed_canvus = canvus.clone();
	this->DrawTank(drawed_canvus);
	this->DrawBullets(drawed_canvus);
	return drawed_canvus;
}

void Tank::DrawBullets(cv::Mat& drawed_canvus)
{
	for (auto& it : bullets)
	{
		if (it.IsInSight())
			it.Draw(drawed_canvus);
	}

	for (auto it = bullets.begin(); it != bullets.end();)
	{
		if (it->IsInSight())
			it++;
		else
			it = bullets.erase(it);
	}
}

void Tank::DrawTank(cv::Mat& drawed_canvus)
{
	const int cannon_length = 30;
	cv::Point pt1(x - tank_size.width / 2, y + tank_size.height / 2);
	cv::Point pt2(x + tank_size.width / 2, y - (tank_size.height / 2 - cannon_length));
	cv::rectangle(drawed_canvus, pt1, pt2, CV_RGB(255, 255, 255), CV_FILLED);

	const int cannon_width = 10;
	cv::Point pt3(x - cannon_width / 2, cvRound(y - tank_size.height / 2));
	cv::Point pt4(x + cannon_width / 2, cvRound(y + tank_size.height / 2));
	cv::rectangle(drawed_canvus, pt3, pt4, CV_RGB(255, 255, 255), CV_FILLED);
}


void Tank::MoveRight()
{
	x += step;
	if (x > canvus.cols - tank_size.width / 2)
		x = canvus.cols - tank_size.width / 2;
}

void Tank::MoveUp()
{
	y -= step;
	if (y < tank_size.height / 2)
		y = tank_size.height / 2;
}

void Tank::MoveLeft()
{
	x -= step;
	if (x < tank_size.width / 2)
		x = tank_size.width / 2;
}

void Tank::MoveDown()
{
	y += step;
	if (y > canvus.rows - tank_size.height / 2)
		y = canvus.rows - tank_size.height / 2;
}

void Tank::Move(const char key)
{
	if (key == 'w')
	{
		this->MoveUp();
	}
	else if (key == 's')
	{
		this->MoveDown();
	}
	else if (key == 'a')
	{
		this->MoveLeft();
	}
	else if (key == 'd')
	{
		this->MoveRight();
	}
	else if (key == 'j')
	{
		bullets.push_back(Bullet(cv::Point(x, y - tank_size.height / 2), 3, 5));
	}
}
void Bullet::Draw(cv::Mat& canvus)
{
	loop += 1;
	position.y -= speed;
	if (position.y < 0 || !is_in_sight)
	{
		is_in_sight = false;// 子弹已经跑出视野
	}

	cv::circle(canvus, position, size, CV_RGB(255, 255, 255), CV_FILLED);
}
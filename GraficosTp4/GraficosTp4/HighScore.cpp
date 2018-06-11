#include "HighScore.h"

HighScore::HS::HS()
{
	_HS = new list<score>();
}

HighScore::HS::~HS()
{
	delete _HS;
}

void HighScore::HS::addHS(const int point, const string name)
{
	score add;
	add.point = point;
	add.name = name;
	_HS->push_back(add);
	_HS->sort();
}

void HighScore::HS::getMin(int &point, string &name)
{
	name = _HS->back().name;
	point = _HS->back().point;
}

void HighScore::HS::getMax(int &point, string &name)
{
	name = _HS->front().name;
	point = _HS->front().point;
}

int HighScore::HS::getCant()
{
	return _HS->size();
}

bool HighScore::HS::getScore(const int pos, int & point, string & name)
{
	if ((int)_HS->size() < pos)
		return false;
	list<score>::iterator it = _HS->begin();
	advance(it, pos);
	name = it->name;
	point = it->point;
	return true;
}

void HighScore::HS::clearScore()
{
	_HS->clear();
}

list<int>* HighScore::HS::getPoints()
{
	list<int>* listPoints = new list<int>();
	for (list<score>::iterator it = _HS->begin(); it != _HS->end(); ++it) {
		listPoints->push_back(it->point);
	}
	return listPoints;
}

list<string>* HighScore::HS::getNames()
{
	list<string>* listPoints = new list<string>();
	for (list<score>::iterator it = _HS->begin(); it != _HS->end(); ++it) {
		listPoints->push_back(it->name);
	}
	return listPoints;
}

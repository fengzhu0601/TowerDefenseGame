#include "WayPoint.h"

bool WayPoint::init()
{
	if (!Node::init())
	{
		return false;
	}

	return true;
}
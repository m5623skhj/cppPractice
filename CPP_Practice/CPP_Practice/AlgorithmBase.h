#pragma once
#include <iostream>

void IOSyncOff()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}
// √‚√≥ : https://openmynotepad.tistory.com/90

#include "ThreadSafeSinglyLinkedList.h"
#include <thread>
#include <iostream>

std::atomic<std::shared_ptr<int>> ptr{ std::make_shared<int>(0) };

int main() {

	uint32_t maxThread{ thread::hardware_concurrency() };

	std::cout << maxThread << std::endl;

	for (int i = 0; i < maxThread; ++i) 
	{
		std::thread([] {
			for (int j = 0; j < 2000000; ++j) 
			{
				ptr = std::make_shared<int>(*ptr.load() + 1);
			}
		}).join();
	}

	std::cout << *ptr.load() << std::endl;
}
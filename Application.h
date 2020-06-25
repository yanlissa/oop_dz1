#pragma once
#include "Set.h"

class Application {
private:
	Set m_a;
private:
	void PrintMenu();
	void TestAll();
	void AddToA();
	void RemoveFromA();
public:
	Application()
	{};

	void Run();
};

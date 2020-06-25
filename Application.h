#pragma once
#include "Set.h"

class Application {
private:
	Set m_a;
	Set m_b;
private:
	void PrintMenu();
	void TestAll();
	void AddToA();
	void RemoveFromA();
	void CopyAToB();
public:
	Application()
	{};

	void Run();
};

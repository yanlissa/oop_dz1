#pragma once
#include "Set.h"

class Application {
private:
	Set m_a;
	Set m_b;
	Set m_c;
private:
	void PrintMenu();
	void TestAll();
	void AddToA();
	void RemoveFromA();
	void CopyAToB();
	void MergeAandB();
public:
	Application()
	{};

	void Run();
};

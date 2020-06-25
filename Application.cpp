#include <iostream>

#include "Application.h"

using namespace std;

void Application::TestAll()
{
	BitString bx;
	BitString b0(1);
	BitString b32(0, 1);
	cout << bx << endl;
	cout << b0 << endl;
	cout << b32 << endl;
	cout << ~bx << endl;
	cout << ~b0 << endl;
	cout << (~b0 & b0) << endl;
	cout << (b32 | b0) << endl;
	cout << (b0 << 32) << endl;
	cout << (b0 << 32 == b32) << endl;

	Set s;
	cout << s << endl;
	s.add(1);
	cout << s << endl;
	s.add(5);
	s.add(3);
	cout << s << endl;
	s.remove(1);
	cout << s << endl;

	Set a, b;
	a.add(1);
	a.add(11);
	a.add(21);
	a.add(31);
	cout << "a = " << a << endl;
	b.add(7);
	b.add(14);
	b.add(21);
	b.add(28);
	cout << "b = " << b << endl;

	s = a;
	s.merge(b);
	cout << " a ∪ b = " << s << endl;
	cout << "|a ∪ b|= " << s.power() << endl;

	s = a;
	s.intersect(b);
	cout << " a ∩ b = " << s << endl;
	cout << "|a ∩ b|= " << s.power()<< endl;

	s = a;
	s.subtract(b);
	cout << " a - b = " << s << endl;
	cout << "|a - b|= " << s.power() << endl;

	cout << "a " << (a.is_empty() ? "=" : "≠") << " ∅ \n";
	s = a;
	s.subtract(s);
	cout << "a - a " << (s.is_empty() ? "=" : "≠") << " ∅ \n";
}

void Application::AddToA()
{
	unsigned int num = 64;
	while (num > 63) {
		cout << "Введите целое 0..63: ";
		cin >> num;
		cout << num << endl;
	}
	m_a.add(num);
}

void Application::RemoveFromA()
{
	unsigned int num = 64;
	while (num > 63) {
		cout << "Введите целое 0..63: ";
		cin >> num;
		cout << num << endl;
	}
	m_a.remove(num);
}

void Application::CopyAToB()
{
	m_b = m_a;
}

void Application::MergeAandB()
{
	m_c = m_a;
	m_c.merge(m_b);
}

void Application::IntersectAandB()
{
	m_c = m_a;
	m_c.intersect(m_b);
}

void Application::PrintMenu()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "A: " << m_a << endl;
	cout << "B: " << m_b << endl;
	cout << "C: " << m_c << endl;
	cout << "0: Выход" << endl;
	cout << "1: Отладочный вывод" << endl;
	cout << "2: Добавить элемент в A" << endl;
	cout << "3: Исключить элемент из A" << endl;
	cout << "4: Скопировать A в B" << endl;
	cout << "5: C = A ∪ B" << endl;
	cout << "6: C = A ∩ B" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Выберите пункт: ";
}

void Application::Run()
{
	bool keks = true;
	int ex;
	while (keks)
	{
		PrintMenu();
		cin >> ex;
		cout << ex << endl;
		switch (ex) {
		case 0:
			keks = false;
			break;
		case 1:
			TestAll();
			break;
		case 2:
			AddToA();
			break;
		case 3:
			RemoveFromA();
			break;
		case 4:
			CopyAToB();
			break;
		case 5:
			MergeAandB();
			break;
		case 6:
			IntersectAandB();
			break;
		default:
			break;
		}
	}
}

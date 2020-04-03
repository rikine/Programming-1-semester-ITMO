#include <string>
#include <iostream>
#pragma once
// ��������� "�������������� ������".
class IGeoFig {
public:
	// �������.
	virtual double square() const = 0;
	// ��������.
	virtual double perimeter() const = 0;
};
// ������
class Vector2D {
public:
	double x, y;
};
// ��������� "���������� ������".
class IPhysObject {
public:
	// �����, ��.
	virtual double mass() const = 0;
	// ���������� ������ ����, �.
	virtual Vector2D position() const = 0;
	// ��������� �� �����.
	virtual bool operator== (const IPhysObject& ob) const = 0;
	// ��������� �� �����.
	virtual bool operator< (const IPhysObject& ob) const = 0;
};
// ��������� "������������"
class IPrintable {
public:
	// ���������� �� ������
	// (�������� � ��������� ���� ��������� ������).
	virtual void draw() const = 0;
};
// ��������� ��� �������, ������� ����� ������ ����� ������ � �������������.
class IDialogInitiable {
public:
	// ������ ��������� ������� � ������� ������� � �������������.
	virtual void initFromDialog() = 0;
};
// ��������� "�����"
class IBaseCObject {
public:
	// ��� ������ (���� ������).
	virtual const std::string classname() const = 0;
	// ������ ���������� ������.
	virtual unsigned int size() const = 0;
};

class IFigure : public IGeoFig, public IPhysObject, public IPrintable, 
public IDialogInitiable, public IBaseCObject {
public:

};

class Rectangle : public IFigure {
private:
	const std::string name = "Rectangle";
	double a, b;
	double mass_;
	Vector2D position_;

public:
	double square() const override;
	double perimeter() const override;

	double mass() const override;
	Vector2D position() const override;

	bool operator== (const IPhysObject& ob) const override;
	bool operator< (const IPhysObject& ob) const override;

	void draw() const override;

	void initFromDialog() override;

	const std::string classname() const override;
	unsigned int size() const override;
};

class Circle : public IFigure {
private:
	const std::string name = "Circle";
	double r;
	double mass_;
	Vector2D position_;

public:
	double square() const override;
	double perimeter() const override;

	double mass() const override;
	Vector2D position() const override;

	bool operator== (const IPhysObject& ob) const override;
	bool operator< (const IPhysObject& ob) const override;

	void draw() const override;

	void initFromDialog() override;

	const std::string classname() const override;
	unsigned int size() const override;
};
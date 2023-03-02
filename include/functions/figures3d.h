#pragma once

static const int SIZE = 5;

enum  FigureType
{
	BALL, CYLINDER, PARALLELEPIPED
};

class Figure3D {
	FigureType type;
	double radius;
	double height;
	double lenght;

public:
	Figure3D();
	Figure3D(FigureType, double);
	Figure3D(FigureType, double, double);
	Figure3D(FigureType, double, double, double);

	double get_square_figure();
	double get_volume_figure();
	FigureType get_type();
};

class Space {
	Figure3D figures[SIZE];
	int count;

public:
	Space();
	Figure3D operator[](int) const;
	Figure3D& operator[](int);
	Figure3D get_figure_with_max_volume();
	void add_figure(Figure3D, int);
	void delete_figure(int);
	int get_count();
};

void print(Figure3D);
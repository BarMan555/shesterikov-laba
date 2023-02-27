#pragma once

static const int SIZE = 5;

enum  FigureType
{
	BALL, CYLINDER, PARALLELEPIPED
};

//class Point {
//	double x, y, z;
//
//public:
//	Point();
//	Point(double);
//	Point(double, double, double);
//
//	double get_x();
//	double get_y();
//	double get_z();
//
//	void set_x(double);
//	void set_y(double);
//	void set_z(double);
//};

class Figure3D {
	//Point points[6] = { 0 };
	FigureType type;
	double radius;
	double height;
	double lenght;

public:
	Figure3D();
	Figure3D(FigureType, double);
	Figure3D(FigureType, double, double);
	Figure3D(FigureType, double, double, double);
	//Figure3D(FigureType, Point[], int);

	double get_square_figure();
	double get_volume_figure();
	FigureType get_type();
	//Point get_point_by_index(int);
};

class Space {
	Figure3D figures[SIZE];

public:
	Figure3D get_figure_with_max_volume();
};

void print(Figure3D);
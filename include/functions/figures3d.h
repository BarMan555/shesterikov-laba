#pragma once
#include <iostream>
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
	Figure3D(Figure3D&);
	Figure3D(FigureType, double);
	Figure3D(FigureType, double, double);
	Figure3D(FigureType, double, double, double);

	Figure3D& operator=(Figure3D);
	
	void swap(Figure3D&) noexcept;
	double get_square_figure();
	double get_volume_figure();
	double get_radius();
	double get_height();
	double get_lenght();
	FigureType get_type();
};

class Space {
	Figure3D** figures;
	int size;

public:
	Space();
	Space(const Space&);
	~Space();

	Figure3D operator[](int) const;
	Figure3D& operator[](int);
	Space& operator=(Space);

	Figure3D& get_figure_with_max_volume();
	void swap(Space&) noexcept;
	void add_figure(Figure3D, int);
	void delete_figure(int);
	int get_size();
};

	std::ostream& operator<<(std::ostream& stream, Space& space);
    std::ostream& operator<<(std::ostream& stream, Figure3D& figure);
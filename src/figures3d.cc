#include "functions/figures3d.h"
#include <stdexcept>
#include <cmath>
#include <cstdio>
#define PI 3.1415

// Определение класса Figure3D -------
Figure3D::Figure3D() : type(BALL), radius(0), height(0), lenght(0) {}
Figure3D::Figure3D(FigureType BALL, double radius) : type(BALL), radius(radius), height(0), lenght(0) {}
Figure3D::Figure3D(FigureType CYLINDER, double radius, double height) : type(CYLINDER), radius(radius), height(height), lenght(0) {}
Figure3D::Figure3D(FigureType PARALLELEPIPED, double a, double b, double c) : type(PARALLELEPIPED), radius(a), height(b), lenght(c) {}

double Figure3D::get_square_figure() {
	switch (type)
	{
	case BALL: return 4 * PI * pow(radius, 2);
		break;
	case CYLINDER: return 2 * PI * radius * (radius + height);
		break;
	case PARALLELEPIPED: return 2 * (radius * height + radius * lenght + height * lenght);
		break;
	default: throw std::runtime_error("Invalid type");
		break; 
	}
}
double Figure3D::get_volume_figure() {
	switch (type)
	{
	case BALL: return (4. / 3) * (PI * pow(radius, 3));
		break;
	case CYLINDER: return PI * pow(radius, 2) * height;
		break;
	case PARALLELEPIPED: return radius * height * lenght;
		break;
	default: throw std::runtime_error("Invalid type");
		break;
	}
}
FigureType Figure3D::get_type() { return type; }
//-----------------------------------

// Определение класса Space -------
Space::Space() : count(0) {}
Figure3D Space::operator[](int index) {
	if (index < 0 || index >= count) {
		throw std::runtime_error("Invalid index");
	}
	return figures[index];
}
Figure3D Space::get_figure_with_max_volume(){
	int max = 0;
	int index_max = 0;
	for (int i = 0; i < count; ++i) {
		if ((*this)[i].get_volume_figure() > max) {
			max = (*this)[i].get_volume_figure();
			index_max = i;
		}
	}
	return (*this)[index_max];
}
void Space::add_figure(Figure3D figure, int index) {
	if (count == SIZE) throw std::runtime_error("Array if full");
	if (index >= SIZE || index < 0) throw std::runtime_error("Invalid index");
	
	for (int i = SIZE-1; i > index; i--) {
		figures[i] = figures[i - 1];
	}

	figures[index] = figure;
	count++;
}

void Space::delete_figure(int index) {
	if (index >= count || index < 0) throw std::runtime_error("Invalid index");
	for (int i = index; i < count; ++i) {
		figures[i] = figures[i + 1];
	}
	count--;
}

int Space::get_count() {
	return count;
}

//-----------------------------------
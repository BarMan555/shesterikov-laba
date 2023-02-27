#include "functions/figures3d.h"
#include <stdexcept>
#include <cmath>
#include <cstdio>
#define PI 3.1415

// Определение класса Point -------------
//Point::Point() { x = 0; y = 0; z = 0; }
//Point::Point(double c) { x = y = z = c; }
//Point::Point(double x, double y, double z) {
//	this->x = x;
//	this->y = y;
//	this->z = z;
//}
//
//double Point::get_x() { return x; }
//double Point::get_y() { return y; }
//double Point::get_z() { return z; }
//
//void Point::set_x(double x) { this->x = x; }
//void Point::set_y(double y) { this->y = y; }
//void Point::set_z(double z) { this->z = z; }
//----------------------------------------

// Определение класса Figure3D -------

Figure3D::Figure3D() : type(BALL), radius(0), height(0), lenght(0) {}
Figure3D::Figure3D(FigureType BALL, double radius) : type(BALL), radius(radius) {}
Figure3D::Figure3D(FigureType CYLINDER, double radius, double height) : type(CYLINDER), radius(radius), height(height) {}
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
	case BALL: return 4 / 3 * (PI * pow(radius, 3));
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
//Figure3D::Figure3D() {
//	type = BALL;
//	points[0] = Point(0);
//	points[1] = Point(0, 0, 1);
//}
//Figure3D::Figure3D(FigureType type, Point p[], int count) {
//	this->type = type;
//	for (int i = 0; i < count; i++) {
//		points[i] = Point(p[i].get_x(), p[i].get_y(), p[i].get_z());
//	}
//}

//Point Figure3D::get_point_by_index(int index) { return points[index]; }
//double Figure3D::get_square_figure() {
//	switch (type) {
//		case BALL: 
//			double vector[3] = {
//				points[0].get_x() - points[1].get_x(),
//				points[0].get_y() - points[1].get_y(),
//				points[0].get_z() - points[1].get_z()
//			};
//			double radius = sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
//			return 4 * PI * pow(radius, 2);
//			break;
//		case CYLINDER: 
//			
//			break;
//		case PARALLELEPIPED: break;
//	}
//}

Figure3D Space::get_figure_with_max_volume() {

}

int main() {

	return 0;
}
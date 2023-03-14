#include "functions/figures3d.h"
#include <stdexcept>
#include <cmath>
#define PI 3.1415

std::ostream& operator<<(std::ostream& stream, Space& space) {
	for (int i = 0; i < space.get_size(); ++i) {
		stream << "Figure #" << i << "\n\tType of Figure: "; 
		switch (space[i].get_type()) {
		case 0:
			stream << "Ball\n";
			break;
		case 1:
			stream << "Cylinder\n";
			break;
		case 2:
			stream << "Parallelepiped\n";
		}
		
		switch (space[i].get_type()) {
		case BALL:
			stream << "\tRadius: " << space[i].get_radius() << std::endl;
			break;
		case CYLINDER:
			stream << "\tRadius: " << space[i].get_radius() << "\n\tHeight: " << space[i].get_height() << std::endl;
			break;
		case PARALLELEPIPED:
			stream << "\tFirst line: " << space[i].get_radius() << "\n\tSecond line: " <<
				space[i].get_height() << "\n\tThird line: " << space[i].get_lenght() << std::endl;
			break;
		}
		stream << std::endl;
	}
	return stream;
}
std::ostream& operator<<(std::ostream& stream, Figure3D& figure) {
	stream << "\tType of Figure: ";
	switch (figure.get_type()) {
	case 0:
		stream << "Ball\n";
		break;
	case 1:
		stream << "Cylinder\n";
		break;
	case 2:
		stream << "Parallelepiped\n";
	}

	switch (figure.get_type()) {
	case BALL:
		stream << "\tRadius: " << figure.get_radius() << std::endl;
		break;
	case CYLINDER:
		stream << "\tRadius: " << figure.get_radius() << "\n\tHeight: " << figure.get_height() << std::endl;
		break;
	case PARALLELEPIPED:
		stream << "\tFirst line: " << figure.get_radius() << "\n\tSecond line: " <<
			figure.get_height() << "\n\tThird line: " << figure.get_lenght() << std::endl;
		break;
	}
	return stream;
}

// определение класса Figure3D -------
Figure3D::Figure3D() : type(BALL), radius(0), height(0), lenght(0) {}
Figure3D::Figure3D(Figure3D& fig){
	type = fig.get_type();
	radius = fig.get_radius();
	height = fig.get_height();
	lenght = fig.get_lenght();
}
Figure3D::Figure3D(FigureType type, double radius) : type(type), radius(radius), height(0), lenght(0) {}
Figure3D::Figure3D(FigureType type, double radius, double height) : type(type), radius(radius), height(height), lenght(0) {}
Figure3D::Figure3D(FigureType type, double a, double b, double c) : type(type), radius(a), height(b), lenght(c) {}

Figure3D& Figure3D::operator=(Figure3D figure) {
	swap(figure);
	return *this;
}

void Figure3D::swap(Figure3D& rhs) noexcept{
	std::swap(type, rhs.type);
	std::swap(radius, rhs.radius);
	std::swap(height, rhs.height);
	std::swap(lenght, rhs.lenght);
}
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
double Figure3D::get_radius() { return radius; }
double Figure3D::get_height() { return height; }
double Figure3D::get_lenght() { return lenght; }
FigureType Figure3D::get_type() { return type; }
//-----------------------------------

// определение класса Space -------
Space::Space() : figures(nullptr), size(0) {} // Конструктор по умолчанию
Space::Space(const Space& space) {
	this->size = space.size;
	this->figures = new Figure3D * [size]();
	for (int i = 0; i < size; ++i) {
		this->figures[i] = new Figure3D(space[i].get_type(), space[i].get_radius(),
			space[i].get_height(), space[i].get_lenght());
	}
}
Space::~Space() {
	for (int i = 0; i < size; ++i) {
		delete figures[i];
	}
	delete[] figures;
}

Figure3D Space::operator[](int index) const {
	if (index < 0 || index >= size) {
		throw std::runtime_error("Invalid index");
	}
	return *figures[index];
}
Figure3D& Space::operator[](int index) {
	if (index < 0 || index >= size) {
		throw std::runtime_error("Invalid index");
	}
	return *figures[index];
}
Space& Space::operator=(Space space) {
	swap(space);
	return *this;
}

Figure3D& Space::get_figure_with_max_volume() {
	int max = 0;
	int index_max = 0;
	for (int i = 0; i < size; ++i) {
		if ((*this)[i].get_volume_figure() > max) {
			max = (*this)[i].get_volume_figure();
			index_max = i;
		}
	}
	return (*this)[index_max];
}
void Space::swap(Space& rhs) noexcept {
	std::swap(figures, rhs.figures);
	std::swap(size, rhs.size);
}
void Space::add_figure(Figure3D figure, int index) {
	if (index < 0 || index > size) throw std::runtime_error("Invalid index");
	++size;
	
	Figure3D** figures_tmp = new Figure3D * [size]();

	for (int i = 0; i < index; ++i) {
		figures_tmp[i] = new Figure3D(*figures[i]);
	}

	for (int i = size - 1; i > index; i--) {
		figures_tmp[i] = new Figure3D(*figures[i - 1]);
	}

	figures_tmp[index] = new Figure3D(figure);

	std::swap(figures, figures_tmp);
}
void Space::delete_figure(int index) {
	if (index < 0 || index > size) throw std::runtime_error("Invalid index");
	--size;
	Figure3D** figures_tmp = new Figure3D * [size]();

	for (int i = 0; i < index; ++i) {
		figures_tmp[i] = new Figure3D(*figures[i]);
	}

	for (int i = index; i < size; ++i) {
		figures_tmp[i] = new Figure3D(*figures[i + 1]);
	}

	std::swap(figures, figures_tmp);
}
int Space::get_size() { return size; }
//-----------------------------------
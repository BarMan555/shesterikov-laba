#include "functions/figures3d.h"
#include <stdexcept>
#include <cmath>

#define PI 3.1415

std::ostream& operator<<(std::ostream& stream, Space& space) {
	for (int i = 0; i < space.get_size(); ++i) {
		stream << space[i] << "\n";
	}
	return stream;
}





// Figure3D //

Figure3D::Figure3D() : radius(0), height(0), lenght(0) {}
Figure3D::Figure3D(double r) : radius(r) {};
Figure3D::Figure3D(double r, double h) : radius(r), height(h) {};
Figure3D::Figure3D(double r, double h, double l) : radius(r), height(h), lenght(l) {};

void Figure3D::swap(Figure3D& fig) {
	std::swap(radius, fig.radius);
	std::swap(height, fig.height);
	std::swap(lenght, fig.lenght);
}

//---------//






// BALL //
BALL::BALL() : Figure3D() {}
BALL::BALL(double radius) : Figure3D(radius){}
BALL::BALL(const BALL& fig) : Figure3D(fig) {}

BALL& BALL::operator=(BALL fig) {
	swap(fig);
	return *this;
}

double BALL::get_square_figure() const{ return 4 * PI * pow(radius, 2); }
double BALL::get_volume_figure() const{ return (4. / 3) * (PI * pow(radius, 3)); }
void BALL::print(std::ostream& stream) const{
	stream << "\tType of Figure: BALL" << std::endl; 
	stream << "\tRadius: " << this->radius << std::endl;
}
FigurePtr BALL::clone() const{
	FigurePtr ptr = std::make_shared<BALL>(new BALL(*this));
	return ptr;
}
//-----//




// CYLINDER //
CYLINDER::CYLINDER(): Figure3D() {}
CYLINDER::CYLINDER(double radius, double height) : Figure3D(radius, height) {}
CYLINDER::CYLINDER(const CYLINDER& fig) : Figure3D(fig) {}

CYLINDER& CYLINDER::operator=(CYLINDER fig) {
	swap(fig);
	return *this;
}

double CYLINDER::get_square_figure() const { return 2 * PI * radius * (radius + height); }
double CYLINDER::get_volume_figure() const { return PI * pow(radius, 2) * height; }
void CYLINDER::print(std::ostream& stream) const {
	stream << "\tType of Figure: CYLINDER" << std::endl;
	stream << "\tRadius: " << this->radius << std::endl;
	stream << "\tHeight: " << this->height << std::endl;
}
FigurePtr CYLINDER::clone() const {
	FigurePtr ptr = std::make_shared<CYLINDER>(new CYLINDER(*this));
	return ptr;
}
//---------//




// PARALLELEPIPED //
PARALLELEPIPED::PARALLELEPIPED() : Figure3D() {}
PARALLELEPIPED::PARALLELEPIPED(double radius, double hegiht, double lenght) : Figure3D(radius, height, lenght) {}
PARALLELEPIPED::PARALLELEPIPED(const PARALLELEPIPED& fig) : Figure3D(fig) {}

PARALLELEPIPED& PARALLELEPIPED::operator=(PARALLELEPIPED fig) {
	swap(fig);
	return *this;
}

double PARALLELEPIPED::get_square_figure() const { return 2 * (radius * height+ radius* lenght+ height* lenght); }
double PARALLELEPIPED::get_volume_figure() const { return radius * height* lenght; }
void PARALLELEPIPED::print(std::ostream& stream) const {
	stream << "\tType of Figure: PARALLELEPIPED" << std::endl;
	stream << "\t1st side: " << this->radius << std::endl;
	stream << "\t2nd side: " << this->height << std::endl;
	stream << "\t3rd side: " << this->lenght << std::endl;
}
FigurePtr PARALLELEPIPED::clone() const {
	FigurePtr ptr = std::make_shared<PARALLELEPIPED>(new PARALLELEPIPED(*this));
	return ptr;
}
//---------//





// определение класса Space -------
Space::Space(const Space& space) {
	this->figures.resize(space.figures.size());
	for (int i = 0; i < space.figures.size(); ++i) {
		this->figures[i] = space.figures[i];
	}
}
Space& Space::operator=(const Space& space) {
	this->figures.clear();
	this->figures.resize(space.figures.size());
	for (int i = 0; i < space.figures.size(); ++i) {
		this->figures[i] = space.figures[i];
	}
	return *this;
}

FigurePtr Space::operator[](int index) {
	if (index < 0 || index >= figures.size()) {
		throw std::runtime_error("Invalid index");
	}
	return figures[index];
}

Figure3D& Space::get_figure_with_max_volume() {
	int max = 0;
	int index_max = 0;
	for (int i = 0; i < figures.size(); ++i) {
		if (figures[i].get()->get_volume_fugure() > max) {
			max = this[i].get()->get_volume_figure();
			index_max = i;
		}
	}
	return (*this)[index_max];
}
void Space::swap(Space& rhs) noexcept {
	std::swap(figures, rhs.figures);
}
void Space::add_figure(const Figure3D& fig, int index) {
	if (index < 0 || index > figures.size()) throw std::runtime_error("Invalid index");
	
	auto tmp = std::make_shared<Figure3D>(fig);
	figures.insert(figures.begin()+index, tmp);
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
int Space::get_size() { return figures.size(); }
//-----------------------------------
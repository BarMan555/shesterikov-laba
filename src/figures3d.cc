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
Figure3D::Figure3D(double r) : radius(r), height(0), lenght(0) {};
Figure3D::Figure3D(double r, double h) : Figure3D(r) { height = h; };
Figure3D::Figure3D(double r, double h, double l) : Figure3D(r, h) { lenght = l; };

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
	this->swap(fig);
	return *this;
}

double BALL::get_square_figure() const{ return 4 * PI * pow(radius, 2); }
double BALL::get_volume_figure() const{ return (4. / 3) * (PI * pow(radius, 3)); }
void BALL::print(std::ostream& stream) const{
	stream << "\tType of Figure: BALL" << std::endl; 
	stream << "\tRadius: " << this->radius << std::endl;
}
std::unique_ptr<Figure3D> BALL::clone() const{
	return std::make_unique<Figure3D>(new BALL(*this));
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
std::unique_ptr<Figure3D> CYLINDER::clone() const {
	return std::make_unique<Figure3D>(new CYLINDER(*this));
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
std::unique_ptr<Figure3D> PARALLELEPIPED::clone() const {
	return std::make_unique<Figure3D>(new PARALLELEPIPED(*this));
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

FigurePtr Space::operator[](int index){
	if (index < 0 || index >= figures.size()) {
		throw std::runtime_error("Invalid index");
	}
	return figures[index];
}

Figure3D& Space::get_figure_with_max_volume() {
	int max = 0;
	int index_max = 0;
	for (int i = 0; i < figures.size(); ++i) {
		if (figures[i]->get_volume_figure() > max) {
			max = figures[i]->get_volume_figure();
			index_max = i;
		}
	}
	return *(figures[index_max]);
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
	if (index < 0 || index > figures.size()) throw std::runtime_error("Invalid index");

	figures.erase(figures.begin() + index);
}
size_t Space::get_size() { return figures.size(); }
//-----------------------------------
#include "functions/figures3d.h"
#include <stdexcept>
#include <memory>
#include <vector>
#include <cmath>

#define PI 3.1415

using namespace std;

// -- Ball -- //
Ball::Ball(double r) { _radius = r; };
Ball& Ball::operator=(Ball fig) {
	swap(fig);
	return *this;
}

void Ball::swap(Ball& ball) {
	std::swap(_radius, ball._radius);
}
FigurePtr Ball::clone() { return make_shared<Ball>(*this); }
double Ball::get_square_figure() const { return 4 * PI * pow(_radius, 2); }
double Ball::get_volume_figure() const { return (4. / 3) * (PI * pow(_radius, 3)); }
void Ball::print(ostream& stream) const {
	stream << "\tType of Figure: Ball" << endl
	<< "\tRadius: " << this->_radius << endl;
}
// -- -- -- //

// -- Cylinder -- //
Cylinder::Cylinder(double r, double h) { _radius = r, _height = h; }
Cylinder& Cylinder::operator=(Cylinder fig) {
	swap(fig);
	return *this;
}

void Cylinder::swap(Cylinder& cylinder) {
	std::swap(_radius, cylinder._radius);
	std::swap(_height, cylinder._height);
}
FigurePtr Cylinder::clone() { return make_shared<Cylinder>(*this); }
double Cylinder::get_square_figure() const { return 2 * PI * _radius * (_radius + _height); }
double Cylinder::get_volume_figure() const { return PI * pow(_radius, 2) * _height; }
void Cylinder::print(ostream& stream) const {
	stream << "\tType of Figure: Cylinder" << endl
	<< "\tRadius: " << this->_radius << endl
	<< "\tHeight: " << this->_height <<endl;
}
// -- -- -- //

// -- Parallelepiped -- //
Parallelepiped::Parallelepiped(double l1, double l2, double l3) { _line1 = l1; _line2 = l2; _line3 = l3; }
Parallelepiped& Parallelepiped::operator=(Parallelepiped fig) {
	swap(fig);
	return *this;
}

void Parallelepiped::swap(Parallelepiped& paral) {
	std::swap(_line1, paral._line1);
	std::swap(_line2, paral._line2);
	std::swap(_line3, paral._line3);
}
FigurePtr Parallelepiped::clone() { return make_shared<Parallelepiped>(*this); }
double Parallelepiped::get_square_figure() const { return 2 * (_line1 * _line2 + _line1 * _line3 + _line2 * _line3); }
double Parallelepiped::get_volume_figure() const { return _line1 * _line2 * _line3; }
void Parallelepiped::print(ostream& stream) const {
	stream << "\tType of Figure: Parallelepiped" << endl
	<< "\t1st side: " << this->_line1 << endl
	<< "\t2nd side: " << this->_line2 << endl
	<< "\t3rd side: " << this->_line3 << endl;
}
// -- -- -- //

// -- Space -- //
Space::Space(vector<FigurePtr> other) {
	figures.clear();
	figures.reserve(other.size());
	for (auto i : other) this->figures.push_back(i->clone());
}
Space::Space(Space& other) {
	figures.clear();
	figures.reserve(other.figures.size());
	for (auto i : other.figures) this->figures.push_back(i->clone());
}
Space& Space::operator=(Space& space) {
	swap(space);
	return *this;
}
void Space::swap(Space& other)
{
	std::swap(figures, other.figures);
}
FigurePtr Space::operator[](int index) const {
	return figures[index];
}
FigurePtr& Space::operator[](int index) {
	return figures[index];
}

void Space::add_figure(FigurePtr fig, int index) {
	if (index < 0 || index > figures.size()) throw std::runtime_error("Invalid index");
	figures.insert(figures.begin() + index, fig);
}

void Space::delete_figure(int index) {
	if (index < 0 || index > figures.size()) throw std::runtime_error("Invalid index");
	figures.erase(figures.begin() + index);
}

void Space::clear() { figures.clear(); }
void Space::print_figures(int index) const{
	figures[index]->print(cout);
}
int Space::get_figure_with_max_volume() const {
	double max = 0;
	int index = 0;
	for (int i = 0; i < figures.size(); ++i) {
		double calc_volume = figures[i]->get_volume_figure();
		if (calc_volume > max) {
			max = calc_volume;
			index = i;
		}
	}
	return index;
}
size_t Space::get_size() { return figures.size(); }
#include "functions/figures3d.h"
#include <stdexcept>
#include <memory>
#include <vector>
#include <cmath>

#define PI 3.1415

using namespace std;

// -- BALL -- //
BALL::BALL(double r) { radius = r; };
BALL& BALL::operator=(BALL& fig) {
	swap(fig);
	return *this;
}

void BALL::swap(BALL& ball) {
	std::swap(radius, ball.radius);
}
FigurePtr BALL::clone() { return make_shared<BALL>(*this); }
double BALL::get_square_figure() const { return 4 * PI * pow(radius, 2); }
double BALL::get_volume_figure() const { return (4. / 3) * (PI * pow(radius, 3)); }
void BALL::print(ostream& stream) const {
	stream << "\tType of Figure: BALL" << endl
	<< "\tRadius: " << this->radius << endl;
}
// -- -- -- //

// -- CYLINDER -- //
CYLINDER::CYLINDER(double r, double h) { radius = r, height = h; }
CYLINDER& CYLINDER::operator=(CYLINDER& fig) {
	swap(fig);
	return *this;
}

void CYLINDER::swap(CYLINDER& cylinder) {
	std::swap(radius, cylinder.radius);
	std::swap(height, cylinder.height);
}
FigurePtr CYLINDER::clone() { return make_shared<CYLINDER>(*this); }
double CYLINDER::get_square_figure() const { return 2 * PI * radius * (radius + height); }
double CYLINDER::get_volume_figure() const { return PI * pow(radius, 2) * height; }
void CYLINDER::print(ostream& stream) const {
	stream << "\tType of Figure: CYLINDER" << endl
	<< "\tRadius: " << this->radius << endl
	<< "\tHeight: " << this->height <<endl;
}
// -- -- -- //

// -- PARALLELEPIPED -- //
PARALLELEPIPED::PARALLELEPIPED(double r, double h, double l) { radius = r; height = h; lenght = l; }
PARALLELEPIPED& PARALLELEPIPED::operator=(PARALLELEPIPED& fig) {
	swap(fig);
	return *this;
}

void PARALLELEPIPED::swap(PARALLELEPIPED& paral) {
	std::swap(radius, paral.radius);
	std::swap(height, paral.height);
	std::swap(lenght, paral.lenght);
}
FigurePtr PARALLELEPIPED::clone() { return make_shared<PARALLELEPIPED>(*this); }
double PARALLELEPIPED::get_square_figure() const { return 2 * (radius * height + radius * lenght + height * lenght); }
double PARALLELEPIPED::get_volume_figure() const { return radius * height* lenght; }
void PARALLELEPIPED::print(ostream& stream) const {
	stream << "\tType of Figure: PARALLELEPIPED" << endl
	<< "\t1st side: " << this->radius << endl
	<< "\t2nd side: " << this->height << endl
	<< "\t3rd side: " << this->lenght << endl;
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
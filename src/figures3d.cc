#include "functions/figures3d.h"
#include <stdexcept>
#include <cmath>


using namespace std;

// -- Ball -- //
Ball::Ball(double r) { _radius = r; };

void Ball::swap(Ball& ball) noexcept {
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

void Cylinder::swap(Cylinder& cylinder) noexcept {
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

void Parallelepiped::swap(Parallelepiped& paral) noexcept {
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
	_figures.clear();
	_figures.reserve(other.size());
	for (auto i : other) this->_figures.push_back(i->clone());
}

Space::Space(const Space& other) {
	const auto n = other.get_size();
	_figures.reserve(n);
	for (int i = 0; i < n; ++i) {
		_figures.push_back(other[i]->clone());
	}
}

Space& Space::operator=(const Space& space) {
	Space tmp(space);
	swap(tmp);
	return *this;
}

void Space::swap(Space& other){
	std::swap(_figures, other._figures);
}

FigurePtr Space::operator[](int index) const {
	return _figures.at(index);
}
FigurePtr& Space::operator[](int index) {
	return _figures.at(index);
}

void Space::add_figure(FigurePtr fig, int index) {
	if (index < 0 || index > _figures.size()) throw std::runtime_error("Invalid index");
	_figures.insert(_figures.begin() + index, fig);
}

void Space::delete_figure(int index) {
	if (index < 0 || index > _figures.size()) throw std::runtime_error("Invalid index");
	_figures.erase(_figures.begin() + index);
}

void Space::clear() { _figures.clear(); }

void Space::print_figures(int index) const{
	_figures[index]->print(cout);
}

int Space::get_figure_with_max_volume() const {
	double max = 0;
	int index = 0;
	for (int i = 0; i < _figures.size(); ++i) {
		double calc_volume = _figures[i]->get_volume_figure();
		if (calc_volume > max) {
			max = calc_volume;
			index = i;
		}
	}
	return index;
}

size_t Space::get_size() const { return _figures.size(); }
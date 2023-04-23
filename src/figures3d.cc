#include "functions/figures3d.h"
#include <stdexcept>
#include <cmath>



#define PI 3.1415

using namespace std;


//std::ostream& operator<<(std::ostream& stream, Space& space) {
//	for (int i = 0; i < space.get_size(); ++i) {
//		space[i]->print(std::cout);
//	}
//	return stream;
//}
//
//
//
//
//
//// Figure3D //
//
//void Figure3D::swap(Figure3D& fig) {
//	std::swap(radius, fig.radius);
//	std::swap(height, fig.height);
//	std::swap(lenght, fig.lenght);
//}
//
////---------//
//
//
//
//
//// BALL //
//BALL::BALL() : Figure3D() {}
//BALL::BALL(double r) { radius = r; height = 0; lenght = 0; };
//BALL::BALL(const BALL& fig) : Figure3D(fig) {}
//
//BALL& BALL::operator=(BALL fig) {
//	this->swap(fig);
//	return *this;
//}
//
//double BALL::get_square_figure() const{ return 4 * PI * pow(radius, 2); }
//double BALL::get_volume_figure() const{ return (4. / 3) * (PI * pow(radius, 3)); }
//void BALL::print(std::ostream& stream) const{
//	stream << "\tType of Figure: BALL" << std::endl; 
//	stream << "\tRadius: " << this->radius << std::endl;
//}
//FigurePtr BALL::clone() {
//	return std::make_unique<Figure3D>(new BALL(*this));
//}
////--------------//
//
//
//
//
//// CYLINDER //
//CYLINDER::CYLINDER(): Figure3D() {}
//CYLINDER::CYLINDER(double r, double h) { radius = r; height = h; lenght = 0; };
//CYLINDER::CYLINDER(const CYLINDER& fig) : Figure3D(fig) {}
//
//CYLINDER& CYLINDER::operator=(CYLINDER fig) {
//	swap(fig);
//	return *this;
//}
//
//double CYLINDER::get_square_figure() const { return 2 * PI * radius * (radius + height); }
//double CYLINDER::get_volume_figure() const { return PI * pow(radius, 2) * height; }
//void CYLINDER::print(std::ostream& stream) const {
//	stream << "\tType of Figure: CYLINDER" << std::endl;
//	stream << "\tRadius: " << this->radius << std::endl;
//	stream << "\tHeight: " << this->height << std::endl;
//}
//FigurePtr CYLINDER::clone() {
//	return std::make_unique<Figure3D>(new CYLINDER(*this));
//}
////---------//
//
//
//
//// PARALLELEPIPED //
//PARALLELEPIPED::PARALLELEPIPED() : Figure3D() {}
//PARALLELEPIPED::PARALLELEPIPED(double r, double h, double l) { radius = r; height = h; lenght = l; };
//PARALLELEPIPED::PARALLELEPIPED(const PARALLELEPIPED& fig) : Figure3D(fig) {}
//
//PARALLELEPIPED& PARALLELEPIPED::operator=(PARALLELEPIPED fig) {
//	swap(fig);
//	return *this;
//}
//
//double PARALLELEPIPED::get_square_figure() const { return 2 * (radius * height+ radius* lenght+ height* lenght); }
//double PARALLELEPIPED::get_volume_figure() const { return radius * height* lenght; }
//void PARALLELEPIPED::print(std::ostream& stream) const {
//	stream << "\tType of Figure: PARALLELEPIPED" << std::endl;
//	stream << "\t1st side: " << this->radius << std::endl;
//	stream << "\t2nd side: " << this->height << std::endl;
//	stream << "\t3rd side: " << this->lenght << std::endl;
//}
//FigurePtr PARALLELEPIPED::clone() {
//	return std::make_unique<Figure3D>(new PARALLELEPIPED(*this));
//}
////---------//
//
//
//
//
//
//// определение класса Space -------
//Space::Space(const Space& space) {
//	this->figures.resize(space.figures.size());
//	for (int i = 0; i < space.figures.size(); ++i) {
//		this->figures[i] = space.figures[i];
//	}
//}
//Space& Space::operator=(const Space& space) {
//	this->figures.clear();
//	this->figures.resize(space.figures.size());
//	for (int i = 0; i < space.figures.size(); ++i) {
//		this->figures[i] = space.figures[i];
//	}
//	return *this;
//}
//
//FigurePtr Space::operator[](int index){
//	if (index < 0 || index >= figures.size()) {
//		throw std::runtime_error("Invalid index");
//	}
//	return figures[index];
//}
//
//Figure3D& Space::get_figure_with_max_volume() {
//	double max = 0;
//	int index_max = 0;
//	for (int i = 0; i < figures.size(); ++i) {
//		if (figures[i]->get_volume_figure() > max) {
//			max = figures[i]->get_volume_figure();
//			index_max = i;
//		}
//	}
//	return *(figures[index_max]);
//}
////void Space::swap(Space& rhs) noexcept {
////	std::swap(figures, rhs.figures);
////}
//void Space::add_figure(const Figure3D& fig, int index) {
//	if (index < 0 || index > figures.size()) throw std::runtime_error("Invalid index");
//	
//	auto tmp = std::make_shared<Figure3D>(fig);
//	figures.insert(figures.begin()+index, tmp);
//}
//void Space::delete_figure(int index) {
//	if (index < 0 || index > figures.size()) throw std::runtime_error("Invalid index");
//
//	figures.erase(figures.begin() + index);
//}
//size_t Space::get_size() { return figures.size(); }
//-----------------------------------

// -- Figure3D -- //
void Figure::swap(Figure& fig){
	std::swap(radius, fig.radius);
	std::swap(height, fig.height);
	std::swap(lenght, fig.lenght);
}
// -- -- -- //

// -- BALL -- //
BALL::BALL(double r) { radius = r; height = 0; lenght = 0; };
FigurePtr BALL::clone() { return make_shared<Figure>(new BALL(*this)); }
double BALL::get_square_figure() const { return 4 * PI * pow(radius, 2); }
double BALL::get_volume_figure() const { return (4. / 3) * (PI * pow(radius, 3)); }
void BALL::print(ostream& stream) const {
	stream << "\tType of Figure: BALL" << endl
	<< "\tRadius: " << this->radius << endl;
}
// -- -- -- //

// -- CYLINDER -- //
CYLINDER::CYLINDER(double r, double h) { radius = r, height = h, lenght = 0; }
FigurePtr CYLINDER::clone() { return make_shared<Figure>(new CYLINDER(*this)); }
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
FigurePtr PARALLELEPIPED::clone() { return make_shared<Figure>(new PARALLELEPIPED(*this)); }
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
Space::Space(vector<FigurePtr> figs) {
	figures.insert(figures.begin(), figs.begin(), figs.end());
}
Space::Space(Space& space) : Space(space.figures) {}
Space& Space::operator=(Space& space) {
	figures.clear();
	figures.insert(figures.begin(), space.figures.begin(), space.figures.end());
}
FigurePtr Space::operator[](int index) const {
	return figures[index];
}
FigurePtr& Space::operator[](int index) {
	return figures[index];
}
void Space::add_figure(const Figure& fig, int index) {
	if (index < 0 || index > figures.size()) throw std::runtime_error("Invalid index");

	auto tmp = make_shared<Figure>(fig);
	this->figures.insert(this->figures.begin() + index, tmp);
}
void Space::delete_figure(int index) {
	if (index < 0 || index > figures.size()) throw std::runtime_error("Invalid index");
	this->figures.erase(this->figures.begin() + index);
}
void Space::clear() { figures.clear(); }
void Space::print_figures(int index) const{
	figures[index]->print(cout);
}
FigurePtr Space::get_figure_with_max_volume() const {
	double max = 0;
	int index = 0;
	for (int i = 0; i < figures.size(); ++i) {
		if (figures[i]->get_volume_figure() > max) {
			max = figures[i]->get_volume_figure();
			index = i;
		}
	}

	return figures[index];
}
size_t Space::get_size() { return figures.size(); }
#pragma once
#include <iostream>
#include <memory>
#include <vector>
#define FigurePtr std::shared_ptr<Figure>

//using FigurePtr = std::shared_ptr<Figure3D>;

//class Figure3D {
//protected:
//	double radius;
//	double height;
//	double lenght;
//
//	Figure3D() = default;
//	/*Figure3D(double);
//	Figure3D(double, double);
//	Figure3D(double, double, double);*/
//	Figure3D(const Figure3D&) = default;
//	Figure3D& operator=(const Figure3D&) = default;
//
//public:
//	virtual ~Figure3D() = default;
//	virtual FigurePtr clone() = 0; // Method of clone
//	virtual void print(std::ostream&) const = 0; // Print info of figure
//	virtual double get_square_figure() const = 0;
//	virtual double get_volume_figure() const = 0;
//	void swap(Figure3D&);
//};
//
//class BALL : public Figure3D {
//public:
//	BALL();
//	BALL(double);
//	BALL(const BALL&);
//	~BALL() {};
//
//	BALL& operator=(BALL);
//	FigurePtr clone() override;
//	
//	void print(std::ostream&) const override;
//	double get_square_figure() const override;
//	double get_volume_figure() const override;
//};
//
//class CYLINDER : public Figure3D {
//public:
//	CYLINDER();
//	CYLINDER(double, double);
//	CYLINDER(const CYLINDER&);
//	~CYLINDER() {};
//
//	CYLINDER& operator=(CYLINDER);
//	FigurePtr clone() override;
//
//	void print(std::ostream&) const override;
//	double get_square_figure() const override;
//	double get_volume_figure() const override;
//};
//
//class PARALLELEPIPED : public Figure3D {
//public:
//	PARALLELEPIPED();
//	PARALLELEPIPED(double, double, double);
//	PARALLELEPIPED(const PARALLELEPIPED&);
//	~PARALLELEPIPED() {};
//
//	PARALLELEPIPED& operator=(PARALLELEPIPED);
//	FigurePtr clone() override;
//
//	void print(std::ostream&) const override;
//	double get_square_figure() const override;
//	double get_volume_figure() const override;
//};
//
//
//class Space {
//	std::vector<FigurePtr> figures;
//
//public:
//	Space() = default;
//	Space(const Space&);
//
//	FigurePtr operator[](int);
//	Space& operator=(const Space&);
//
//	Figure3D& get_figure_with_max_volume();
//	void swap(Space&) noexcept;
//	void add_figure(const Figure3D&, int);
//	void delete_figure(int);
//	size_t get_size();
//};
//
//std::ostream& operator<<(std::ostream& stream, Space& space);

class Figure {
protected:
	double radius, height, lenght;
public:
	void swap(Figure&);
	virtual ~Figure() = default;
	virtual FigurePtr clone() = 0;
	virtual double get_square_figure() const = 0;
	virtual double get_volume_figure() const = 0;
	virtual void print(std::ostream&) const = 0;

protected:
	Figure() = default;
	Figure(const Figure&) = default;
	Figure& operator=(const Figure&) = default;
};

class BALL : public Figure {
public:
	BALL() = default;
	BALL(double r);
	BALL(const BALL&) = default;
	
	FigurePtr clone() override;
	double get_square_figure() const override;
	double get_volume_figure() const override;
	void print(std::ostream&) const override;
};

class CYLINDER : public Figure {
public:
	CYLINDER() = default;
	CYLINDER(double r, double h);
	CYLINDER(const CYLINDER&) = default;

	FigurePtr clone() override;
	double get_square_figure() const override;
	double get_volume_figure() const override;
	void print(std::ostream&) const override;
};

class PARALLELEPIPED : public Figure {
public:
	PARALLELEPIPED() = default;
	PARALLELEPIPED(double r, double h, double l);
	PARALLELEPIPED(const PARALLELEPIPED&) = default;

	FigurePtr clone() override;
	double get_square_figure() const override;
	double get_volume_figure() const override;
	void print(std::ostream&) const override;
};

class Space {
private:
	std::vector<FigurePtr> figures;
public:
	Space() = default;
	Space(std::vector<FigurePtr> figs);
	Space(Space&);
	Space& operator=(Space&);

	FigurePtr operator[](int index) const;
	FigurePtr& operator[](int index);
	void add_figure(const Figure&, int index);
	void delete_figure(int index);
	void clear();
	void print_figures(int index) const;
	FigurePtr get_figure_with_max_volume() const;
	size_t get_size();
};
#pragma once
#include <iostream>
#include <memory>
#include <vector>

#define FigurePtr std::shared_ptr<Figure>
#define PI 3.1415

class Figure {
public:
	virtual FigurePtr clone() = 0;
	virtual double get_square_figure() const = 0;
	virtual double get_volume_figure() const = 0;
	virtual void print(std::ostream&) const = 0;

	virtual ~Figure() = default;

protected:
	Figure() = default;
	Figure(const Figure&) = default;
	Figure& operator=(const Figure&) = default;
};

class Ball : public Figure {
protected:
	double _radius;
public:
	Ball(double r);

	void swap(Ball& ball) noexcept;

	FigurePtr clone() override;

	double get_square_figure() const override;
	double get_volume_figure() const override;

	void print(std::ostream&) const override;
};

class Cylinder : public Figure {
protected:
	double _radius, _height;
public:
	Cylinder(double r, double h);

	void swap(Cylinder& cylinder) noexcept;

	FigurePtr clone() override;

	double get_square_figure() const override;
	double get_volume_figure() const override;

	void print(std::ostream&) const override;
};

class Parallelepiped : public Figure {
protected:
	double _line1, _line2, _line3;
public:
	Parallelepiped(double l1, double l2, double l3);

	void swap(Parallelepiped& paral) noexcept;

	FigurePtr clone() override;

	double get_square_figure() const override;
	double get_volume_figure() const override;

	void print(std::ostream&) const override;
};

class Space {
private:
	std::vector<FigurePtr> _figures;
public:
	Space() = default;
	Space(std::vector<FigurePtr> figs);
	Space(const Space& other);
	Space& operator=(const Space& space);

	void swap(Space& other);

	FigurePtr operator[](int index) const;
	FigurePtr& operator[](int index);
	void add_figure(FigurePtr, int index);
	void delete_figure(int index);
	void clear();
	void print_figures(int index) const;
	int get_figure_with_max_volume() const;
	size_t get_size() const;
};
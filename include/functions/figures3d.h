#pragma once
#include <iostream>
#include <memory>
#include <vector>
#define FigurePtr std::shared_ptr<Figure>

class Figure {
public:
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
protected:
	double radius;
public:
	BALL() = default;
	BALL(double r);
	BALL(const BALL&) = default;
	BALL& operator=(BALL& fig);

	void swap(BALL& ball);
	FigurePtr clone() override;
	double get_square_figure() const override;
	double get_volume_figure() const override;
	void print(std::ostream&) const override;
};

class CYLINDER : public Figure {
protected:
	double radius, height;
public:
	CYLINDER() = default;
	CYLINDER(double r, double h);
	CYLINDER(const CYLINDER&) = default;
	CYLINDER& operator=(CYLINDER& fig);

	void swap(CYLINDER& cylinder);
	FigurePtr clone() override;
	double get_square_figure() const override;
	double get_volume_figure() const override;
	void print(std::ostream&) const override;
};

class PARALLELEPIPED : public Figure {
protected:
	double radius, height, lenght;
public:
	PARALLELEPIPED() = default;
	PARALLELEPIPED(double r, double h, double l);
	PARALLELEPIPED(const PARALLELEPIPED&) = default;
	PARALLELEPIPED& operator=(PARALLELEPIPED& fig);

	void swap(PARALLELEPIPED& paral);
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

	void swap(Space& other);

	FigurePtr operator[](int index) const;
	FigurePtr& operator[](int index);
	void add_figure(FigurePtr, int index);
	void delete_figure(int index);
	void clear();
	void print_figures(int index) const;
	int get_figure_with_max_volume() const;
	size_t get_size();
};
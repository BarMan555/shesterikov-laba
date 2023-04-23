#pragma once
#include <iostream>
#include <memory>
#include <vector>
#define FigurePtr std::shared_ptr<Figure3D>

//using FigurePtr = std::shared_ptr<Figure3D>;

class Figure3D {
protected:
	double radius;
	double height;
	double lenght;

	Figure3D();
	Figure3D(double);
	Figure3D(double, double);
	Figure3D(double, double, double);
	Figure3D(const Figure3D&) = default;
	Figure3D& operator=(const Figure3D&) = default;

public:
	virtual ~Figure3D() = default;
	virtual std::unique_ptr<Figure3D> clone() const = 0; // Method of clone
	virtual void print(std::ostream&) const = 0; // Print info of figure
	virtual double get_square_figure() const = 0;
	virtual double get_volume_figure() const = 0;
	void swap(Figure3D&);
};

class BALL : public Figure3D {
public:
	BALL();
	BALL(double);
	BALL(const BALL&);

	BALL& operator=(BALL);
	std::unique_ptr<Figure3D> clone() const override;
	
	void print(std::ostream&) const override;
	double get_square_figure() const override;
	double get_volume_figure() const override;
};

class CYLINDER : public Figure3D {
public:
	CYLINDER();
	CYLINDER(double, double);
	CYLINDER(const CYLINDER&);
	
	CYLINDER& operator=(CYLINDER);
	std::unique_ptr<Figure3D> clone() const override;

	void print(std::ostream&) const override;
	double get_square_figure() const override;
	double get_volume_figure() const override;
};

class PARALLELEPIPED : public Figure3D {
public:
	PARALLELEPIPED();
	PARALLELEPIPED(double, double, double);
	PARALLELEPIPED(const PARALLELEPIPED&);

	PARALLELEPIPED& operator=(PARALLELEPIPED);
	std::unique_ptr<Figure3D> clone() const override;

	void print(std::ostream&) const override;
	double get_square_figure() const override;
	double get_volume_figure() const override;
};


class Space {
	std::vector<FigurePtr> figures;

public:
	Space() = default;
	Space(const Space&);

	FigurePtr operator[](int);
	Space& operator=(const Space&);

	Figure3D& get_figure_with_max_volume();
	void swap(Space&) noexcept;
	void add_figure(const Figure3D&, int);
	void delete_figure(int);
	size_t get_size();
};

std::ostream& operator<<(std::ostream& stream, Space& space);

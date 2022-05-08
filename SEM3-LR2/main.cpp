#include <iostream>
#include <cassert>
#include <vector>

class Point {
private:
	int _x;
	int _y;

public:
	Point()
	{
	}
	Point(int x, int y) : _x(x), _y(y)
	{
	}

	void setx(int value) { _x = value; }
	void sety(int value) { _y = value; }

	int x() const { return _x; }
	int y() const { return _y; }

	Point operator+=(const Point& other) {
		return Point(_x += other.x(), _y += other.y());
	}
};

class Figure {
protected:
	std::vector<Point> _points;

public:
	Figure(int vertices_count)
	{
		assert(vertices_count > 0);
		_points.resize(vertices_count);
	}

	Figure(const std::initializer_list<Point>& list)
	{
		_points.resize(list.size());

		int i = 0;
		for (auto& init_point : list) {
			_points[i++] = init_point;
		}
	}

	std::vector<Point> points() const { return _points; }

	void move(const std::vector<Point>& by_points) {
		int i = 0;
		for (auto& point : _points) {
			point += by_points[i++];
		}
	}

	double perimeter() const {
		double per = 0;
		int count = _points.size();

		for (int i = 0; i < count; i++) {
			int first_p = i % count;
			int second_p = (i + 1) % count;

			double t = (_points[first_p].x() - _points[first_p].y()) * (_points[first_p].x() - _points[first_p].y()) +
				(_points[second_p].x() - _points[second_p].y()) * (_points[second_p].x() - _points[second_p].y());

			per += sqrt(t);
		}

		return per;
	};

	friend std::ostream& operator<<(std::ostream& out, const Figure& figure) {
		int p_it = 1;
		for (const auto& point : figure.points()) {
			out << "T" << p_it++ << "(" << point.x() << "; " << point.y() << ") ";
		}

		return out;
	};
};

class Factory {
private:
	std::vector<Figure> _figures;

public:
	Factory()
	{
	}

	void pushBack(Figure figure) {
		_figures.push_back(figure);
	}
	void pushFront(Figure figure) {
		_figures.insert(_figures.begin(), figure);
	}
	void insertInto(Figure figure, int position) {
		_figures.insert(_figures.begin() + position, figure);
	}

	void removeBack() {
		_figures.erase(_figures.end());
	}
	void removeFront() {
		_figures.erase(_figures.begin());
	}
	void removeBy(int index) {
		_figures.erase(_figures.begin() + index);
	}

	Figure& getLast() {
		return _figures[_figures.size() - 1];
	}
	Figure& getFirst() {
		return _figures[0];
	}
	Figure& get(int index) {
		return _figures[index];
	}

	Figure& getAlongSmallestP() {
		int min_i = 0;
		for (int i = 1; i < _figures.size(); i++) {
			if (_figures[i].perimeter() < _figures[min_i].perimeter()) {
				min_i = i;
			}
		}

		return _figures[min_i];
	}

	void print() const {
		int f_it = 1;
		for (const auto& figure : _figures) {
			std::cout << "figure" << f_it++ << ": " << figure << '\n';
		}
	}
};


int main() {

	Factory f;

	// creating figures
	f.pushBack(Figure{
		Point(10, 10),
			Point(-5, 20),
			Point(15, -30)
		});

	f.pushBack(Figure{
		Point(0, 0),
			Point(8, 2),
			Point(-2, 6)
		});

	f.pushBack(Figure{
		Point(20, 0),
			Point(60, 20),
			Point(10, -10),
			Point(20, 0),
			Point(60, 20)
		});

	f.print();

	// move first figure
	f.getFirst().move(std::vector<Point>{
		Point(-10, -10),
			Point(5, -20),
			Point(-15, 30)
	});

	f.print();

	std::cout << "\nThe figure with smallest perimeter:\n";
	std::cout << f.getAlongSmallestP() << "  P = " << f.getAlongSmallestP().perimeter() << '\n';

	return 0;
}

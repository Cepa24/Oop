#include <iostream>
#include <cmath>

struct Point
{
	double x;
	double y;
};

void move_by(Point* p, double dx, double dy) {
	p->x += dx;
	p->y += dy;
}

double dist(const Point* a, const Point* b) {
	double dx = a->x - b->x;
	double dy = a->y - b->y;

	return std::sqrt(dx*dx + dy*dy);
}

void move_by_ref(Point& p, double dx, double dy) {
	p.x += dx;
	p.y += dy;
}

double dist_ref(const Point& a, const Point& b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;

	return std::sqrt(dx * dx + dy * dy);
}

int main(void) {
	Point a = { 7,12 };
	Point b = { 6,16 };

	move_by(&a, 2, 3);
	std::cout << "Nakon pomicanja: " << a.x << ", " << a.y << std::endl;
	std::cout <<"Udaljenost: " << dist(&a, &b)<< std::endl;

	move_by_ref(a, 2, 3);
	std::cout << "Nakon pomicanja: " << a.x << ", " << a.y << std::endl;
	std::cout << "Udaljenost: " << dist_ref(a, b) << std::endl;

	Point points[5]{
		{1,2},
		{4,21},
		{6,14},
		{1,1},
		{5,10}
	};

	int najblizi = 0;
	double najbliza_udaljenost = dist_ref(points[0], Point{ 0,0 });
	int n = sizeof(points) / sizeof(points[0]);
	for (int i = 0;i < n;i++) {
		double udaljenost = dist_ref(points[i], Point{ 0,0 });
		if (udaljenost < najbliza_udaljenost) {
			najbliza_udaljenost = udaljenost;
			najblizi = i;
		}
	}

	std::cout << "Najbliza tocka ishodistu: " << points[najblizi].x << "," << points[najblizi].y << std::endl;

}
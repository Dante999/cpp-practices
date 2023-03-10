#include <iostream>
#include <vector>
#include <memory>
#include <variant>
#include <cstdio>

struct Rectangle {
	int x{0};
	int y{0};
	unsigned int width{1};
	unsigned int height{1};

	Rectangle(int x, int y, unsigned int width, unsigned int height) :  x{x}, y{y}, width{width}, height(height) {}
};

struct Circle {
	int x{0};
	int y{0};
	unsigned int radius{1};

	Circle(int x, int y, unsigned int radio) :  x{x}, y{y}, radius{radius} {}
};

struct Triangle {
};

using Shape = std::variant<Rectangle, Circle, Triangle>;

struct Shape_Drawer {
	void operator() (const Rectangle &rectangle) const 
	{ 
		printf("drawing Rectangle: x=%d y=%d w=%u h=%u\n", rectangle.x, rectangle.y, rectangle.width, rectangle.height);
	}
	
	void operator() (const Circle &circle) const 
	{
		printf("drawing Circle: x=%d y=%d r=%u\n", circle.x, circle.y, circle.radius);
	}

	void operator() (const Triangle &triangle) const 
	{ 
		std::cout << "drawing Triangle\n"; 
	}
};

int main(void)
{
	std::vector<Shape> shapes = {
		Circle{1,1,20},
		Rectangle{2,2,5,25},
		Triangle{}
	};


	for (const auto &shape : shapes) {
		std::visit(Shape_Drawer{}, shape);
	}

}

#include <iostream>
#include <vector>
#include <memory>

struct Shape {
	virtual void draw() = 0;
};


struct Rectangle : public Shape {
	void draw() override { std::cout << "drawing Rectangle\n"; }
};

struct Circle : public Shape {
	void draw() override { std::cout << "drawing Circle\n"; }
};

struct Triangle : public Shape {
	void draw() override { std::cout << "drawing Triangle\n"; }
};

int main(void)
{
	std::vector<std::unique_ptr<Shape>> shapes;

	shapes.emplace_back(std::make_unique<Rectangle>());
	shapes.emplace_back(std::make_unique<Circle>());
	shapes.emplace_back(std::make_unique<Triangle>());

	for (const auto &shape : shapes) {
		shape->draw();
	}

}

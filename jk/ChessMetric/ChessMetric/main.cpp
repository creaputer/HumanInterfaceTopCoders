//
//  main.cpp
//  ChessMetric
//
//  Created by JunKyo on 2016. 8. 20..
//  Copyright © 2016년 JunKyo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory>
#include <array>

template<typename T>
void TestEqual(const T && expected, const T && returns)
{
	if (expected == returns) std::cout << "Passed" << std::endl;
	else std::cout << "Failed: " << returns << ", not: " << expected << std::endl;
}

struct Point {
	explicit Point(const int _x, const int _y)
	: x(_x), y(_y)
	{}
	
	bool checkRange(const int min, const int max) const {
		if (*this < Point{min, min} || Point{max, max} <= *this) return false;
		else return true;
	}
	
	Point operator+(const Point & _p) {
		return Point{this->x + _p.x, this->y + _p.y};
	}
	
	Point& operator+=(const Point & _p) {
		this->x += _p.x;
		this->y += _p.y;
		
		return *this;
	}
	
	Point& operator-=(const Point & _p) {
		this->x -= _p.x;
		this->y -= _p.y;
		
		return *this;
	}
	
	template<typename T>
	bool operator<(T && _p) const {
		return (this->x < _p.x) || (this->y < _p.y);
	}
	
	template<typename T>
	bool operator<=(T && _p) const {
		return (this->x <= _p.x) || (this->y <= _p.y);
	}
	
	template<typename T>
	bool operator==(T && _p) const {
		return (this->x == _p.x) && (this->y == _p.y);
	}
	
public:
	int x, y;
};

class Chess
{
public:
	explicit Chess(int _size, std::vector<int> && _start, std::vector<int> && _end, int _numMoves)
	: m_size(_size), m_start(_start), m_end(_end), m_numMoves(_numMoves){}
	
public:
	long long howMany() {
		long long success = 0;
		Point pos{m_start.at(1), m_start.at(0)};
		Point goal{m_end.at(1), m_end.at(0)};
		
		m_depth = 0;
		
		search(pos, goal, success, m_size);
		
		return success;
	}
	
	bool search(Point & pos, const Point & goal, long long & success, const int size) {
		if (m_numMoves < m_depth) return false;
		if (pos < Point{0, 0}) return false;
		if (Point{size, size} <= pos) return false;
		
		++m_depth;
		
		for (const auto & _2 : m_moveKK) {
			pos += _2;
			if (search(pos, goal, success, size)) {
				if (m_numMoves == m_depth) {
					if (pos == goal) {
						++success;
					}
				}
			}
			
			pos -= _2;
		}

		--m_depth;
		
		return true;
	}
	
	template<typename T> using chess_board = std::vector<std::vector<T>>;
	
	long long howMany2() {
		auto createData = [](const size_t n){return std::vector<std::vector<long long>>(n, std::vector<long long>(n));};
		auto prev = createData(m_size);
		auto curr = decltype(prev){};

		auto goal = Point{m_end.at(1), m_end.at(0)};
		prev.at(m_start.at(1)).at(m_start.at(0)) = 1;

		for (int _1 = 1; _1 <= m_numMoves; ++_1) {
			curr = createData(m_size);
			
			for (int x = 0; x < m_size; ++x) {
				for (int y = 0; y < m_size; ++y) {
					for (const auto & _2 : m_moveKK) {
						auto np = Point{y, x} + _2;

						if (np.checkRange(0, m_size)) {
							curr.at(np.y).at(np.x) += prev.at(y).at(x);
						}
					}
				}
			}
			
			prev = std::move(curr);
		}
		
		return prev.at(goal.y).at(goal.x);
	}
	
private:
	int m_size{};
	std::vector<int> m_start{};
	std::vector<int> m_end{};
	int m_numMoves;
	
private:
	int m_depth{};
	
private:
	static const std::vector<Point> m_moveKK;
};

const std::vector<Point> Chess::m_moveKK{
	// moving like King
	Point(-1, -1),
	Point(0, -1),
	Point(1, -1),
	Point(-1, 0),
	Point(1, 0),
	Point(-1, 1),
	Point(0, 1),
	Point(1, 1),
	
	// moving like Knight
	Point(-2, -1),
	Point(-1, -2),
	Point(1, -2),
	Point(2, -1),
	Point(2, 1),
	Point(1, 2),
	Point(-1, 2),
	Point(-2, 1)
};

int main(int argc, const char * argv[]) {
	auto test0 = std::make_shared<Chess>(3, std::vector<int>{0, 0}, std::vector<int>{1, 0}, 1);
	TestEqual<long long>(test0->howMany2(), 1);

	auto test1 = std::make_shared<Chess>(3, std::vector<int>{0, 0}, std::vector<int>{1, 2}, 1);
	TestEqual<long long>(test1->howMany2(), 1);
	
	auto test2 = std::make_shared<Chess>(3, std::vector<int>{0, 0}, std::vector<int>{2, 2}, 1);
	TestEqual<long long>(test2->howMany2(), 0);
	
	auto test3 = std::make_shared<Chess>(3, std::vector<int>{0, 0}, std::vector<int>{0, 0}, 2);
	TestEqual<long long>(test3->howMany2(), 5);
	
	auto test4 = std::make_shared<Chess>(100, std::vector<int>{0, 0}, std::vector<int>{0, 99}, 50);
	TestEqual<long long>(test4->howMany2(), 243097320072600);
	
    return 0;
}

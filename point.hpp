//
// Copyright (c) 2013 Christoph Malek
//

#ifndef POINT_HPP
#define POINT_HPP


#include <cstdint>


namespace dg
{
	struct point
	{
		std::size_t x{0}, y{0};

	public:
		point() = default;
		point(std::size_t x_, std::size_t y_) :
			x{x_}, y{y_}
		{ }

		point& operator+(std::size_t plus) noexcept
		{x+= plus; y += plus; return *this;}

		point& operator-(std::size_t minus) noexcept
		{x-= minus; y -= minus; return *this;}

		bool operator==(const point& o) const noexcept
		{return ((x == o.x) && y == o.y);}

		bool operator!=(const point& o) const noexcept
		{return !this->operator==(o);}
	};
}


#endif // POINT_HPP

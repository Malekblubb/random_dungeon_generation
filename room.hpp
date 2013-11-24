//
// Copyright (c) 2013 Christoph Malek
//

#ifndef ROOM_HPP
#define ROOM_HPP


#include "point.hpp"

#include <mlk/containers/container_utl.h>

#include <vector>
#include <iostream>


namespace dg
{
	class room
	{
		// params
		point m_ltc_point; // left top corner index
		std::size_t m_height, m_width;

		// calculate owned point
		std::vector<point> m_owned_pnts;

	public:
		room(point ltc_point, std::size_t height, std::size_t width) :
			m_ltc_point{ltc_point},
			m_height{height}, m_width{width}
		{this->calculate_points();}

		bool is_overlapping(const room& o) const noexcept
		{
			for(auto a : m_owned_pnts)
				if(mlk::cnt::find_in(a, o.m_owned_pnts) != o.m_owned_pnts.end())
					return true;
			return false;
		}

	private:
		void calculate_points() noexcept
		{
			for(auto i(m_ltc_point.x); i < m_ltc_point.x + m_width + 1; ++i) // plus 1 fixes wall overlapping
				for(auto j(m_ltc_point.y); j < m_ltc_point.y + m_height + 1; ++j) // plus 1 fixes wall overlapping
					m_owned_pnts.push_back({i, j});
		}
	};
}


#endif // ROOM_HPP

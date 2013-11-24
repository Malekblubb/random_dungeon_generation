//
// Copyright (c) 2013 Christoph Malek
//

#ifndef ROOM_GENERATOR_HPP
#define ROOM_GENERATOR_HPP


#include "point.hpp"
#include "room.hpp"

#include <mlk/log/log.h>
#include <mlk/tools/random_utl.h>
#include <mlk/types/types.h>

#include <vector>


namespace dg
{
	using field_vec = std::vector<std::vector<char>>;

	class room_generator
	{
		field_vec& m_field;
		std::vector<room> m_rooms;

	public:
		room_generator(field_vec& field) :
			m_field(field)
		{ }

		void generate_room(std::size_t height, std::size_t width)
		{
			auto tm_start(mlk::tm::time_pnt());

			auto pnt(this->get_point(height, width));
			room tmp_room{pnt, height, width};

			while(this->is_room_invalid(tmp_room))
			{
				// room would overlap -> generate new
				mlk::lout("dg::room_generator::generate_room") << "room nr." << this->current_room_amount() << " would overlap, generating new...";
				pnt = this->get_point(height, width);
				tmp_room = {pnt, height, width};
			}

			m_rooms.push_back(tmp_room);

			for(auto i(pnt.x); i < width + pnt.x; ++i)
				for(auto j(pnt.y); j < height + pnt.y; ++j)
					m_field[j][i] = ' ';

			auto tm_end(mlk::tm::time_pnt());
			mlk::lout("dg::room_generator::generate_room") << "room nr." << this->current_room_amount() - 1 << " generated in " <<
							 mlk::tm::duration<mlk::micro_s>(tm_start, tm_end) << " micro_s";
		}

	private:
		point get_point(int height, int width)
		{return {mlk::rnd<std::size_t>(1, m_field.size() - width - 1), mlk::rnd<std::size_t>(1, m_field.size() - height - 1)};}

		bool is_room_invalid(const room& r)
		{
			for(auto& a : m_rooms)
				if(a.is_overlapping(r))
					return true;
			return false;
		}

		auto current_room_amount() const noexcept
		-> decltype(m_rooms.size())
		{return m_rooms.size();}
	};
}


#endif // ROOM_GENERATOR_HPP

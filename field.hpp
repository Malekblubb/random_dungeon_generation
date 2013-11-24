//
// Copyright (c) 2013 Christoph Malek
//

#ifndef FIELD_HPP
#define FIELD_HPP


#include "room_generator.hpp"

#include <iostream>
#include <vector>


namespace dg
{
	class field
	{
		using field_vec = std::vector<std::vector<char>>;
		field_vec m_field;
		room_generator m_room_gen;

	public:
		field(std::size_t field_size = 80) :
			m_field(field_size, std::vector<char>(field_size)),
			m_room_gen{m_field}
		{this->fill_default();}

		void show() const noexcept
		{
			std::cout << std::endl;
			for(auto& a : m_field)
			{
				for(auto& b : a)
					std::cout << b;
				std::cout << std::endl;
			}
		}

		bool generate_room(std::size_t height = 2, std::size_t width = 4)
		{
			if(height >= m_field.size() || width >= m_field.size())
			{
				mlk::lout("dg::field::generate_room") << "invalid dimensions passed; ignoring";
				return false; // cant build a room that is bigger than the field
			}

			m_room_gen.generate_room(height, width);
			return true;
		}

	private:
		void fill_default()
		{
			for(auto& a : m_field)
				for(auto& b : a)
					b = '*';
		}
	};
}


#endif // FIELD_HPP

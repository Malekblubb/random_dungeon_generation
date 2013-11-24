//
// Copyright (c) 2013 Christoph Malek
//

#include "field.hpp"

#include <iostream>


int main()
{
	dg::field play_field{10};
	play_field.generate_room();
	play_field.generate_room();
	play_field.show();

	return 0;
}


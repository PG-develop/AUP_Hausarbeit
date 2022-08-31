#include "Utilities.hpp"

namespace AUP_HA
{
	void Utilities::ClearInputStream() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
}
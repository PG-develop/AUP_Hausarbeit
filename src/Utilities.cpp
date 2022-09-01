#include <sstream>

#include "../include/Utilities.hpp"

namespace AUP_HA
{
    /**
    * @brief Leert den Inputstream.
    */
	void Utilities::ClearInputStream() noexcept 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }

    /**
    * @brief Konvertiert einen String zu einer Ganzzahl (int)
    * 
    * @param string String, der zu einer Ganzzahl konvertiert werden soll.
    * 
    * @return std::optional<int> mit geparsten String, wenn erfolgreich gewesen.
    */
    std::optional<int> Utilities::ParseStringToInt(const std::string& string) noexcept
    {
        int parseValue;
        try {
            parseValue = std::stoi(string);
        }
        catch (const std::invalid_argument e) {
            return std::nullopt;
        }
        catch (const std::out_of_range e) {
            return std::nullopt;
        }

        return parseValue;
    }

    /**
    * @brief Konvertiert einen String zu einer Ganzzahl (int) und pr�ft angegebene Grenzen (inlusiv)
    * 
    * @param string String, der zu einer Ganzzahl konvertiert werden soll.
    * @param limits zu pr�fende Grenzen
    *   * Pair.First stellt die untere Grenze dar (inklusiv)
    *   * Pair.Second stellt die obere Grenze dar (inklusiv)
    * 
    * @return std::optional<int> mit geparsten String, wenn erfolgreich gewesen.
    */
    std::optional<int> Utilities::ParseStringToIntWithLimits(const std::string& string, std::pair<int, int> limits) noexcept
    {
        auto parseValue = Utilities::ParseStringToInt(string);

        // Pr�fe, ob der Parsevorgang erfolgreich war
        if (!parseValue)
        {
            return std::nullopt;
        }

        // Pr�fe, ob die festgelegten Grenzen eingehalten wurden
        if ((*parseValue < limits.first) || (*parseValue > limits.second))
        {
            return std::nullopt;
        }

        return parseValue;
    }
}
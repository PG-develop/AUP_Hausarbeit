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
    * @param [string] std::string String, der zu einer Ganzzahl konvertiert werden soll.
    * 
    * @return std::optional<int> mit geparsten String, wenn erfolgreich gewesen.
    */
    std::optional<int> Utilities::ParseStringToInt(const std::string& string) noexcept
    {
        int parseValue;
        try {
            parseValue = std::stoi(string);
        }

        // Keine Zahl 
        catch (const std::invalid_argument e) {
            return std::nullopt;
        }

        // ausserhalb der Datentypgrenzen
        catch (const std::out_of_range e) {
            return std::nullopt;
        }

        return parseValue;
    }

    /**
    * @brief Konvertiert einen String zu einer Ganzzahl (int) und prüft angegebene Grenzen (inlusiv)
    * 
    * @param [string] std::string String, der zu einer Ganzzahl konvertiert werden soll.
    * @param [limits] std::pair<std::int32_t zu prüfende Grenzen\n
    *   * Pair.First stellt die untere Grenze dar (inklusiv)\n
    *   * Pair.Second stellt die obere Grenze dar (inklusiv)
    * 
    * @return std::optional<int> mit geparsten String, wenn erfolgreich gewesen.
    */
    std::optional<std::int32_t> Utilities::ParseStringToIntWithLimits(const std::string& string, std::pair<std::int32_t, std::int32_t> limits) noexcept
    {
        auto parseValue = Utilities::ParseStringToInt(string);

        // Prüfe, ob der Parsevorgang nicht erfolgreich war
        if (!parseValue)
        {
            return std::nullopt;
        }

        // Prüfe, ob die festgelegten Grenzen nicht eingehalten wurden
        if ((*parseValue < limits.first) || (*parseValue > limits.second))
        {
            return std::nullopt;
        }

        return parseValue;
    }
}
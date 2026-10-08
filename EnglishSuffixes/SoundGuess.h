#pragma once

#include <string_view>


namespace ens
{

#pragma region Diphthongs in many dialects. Conceptual diphthongs

/// <summary>
/// /u:/ as in book
/// </summary>
/// <param name="word"></param>
/// <returns></returns>
bool isLongU(std::string_view word);

/// <summary>
/// /i:/ as in read
/// </summary>
/// <param name="word"></param>
/// <returns></returns>
bool isLongI(std::string_view word);

/// <summary>
/// /eɪ/ as in lake
/// </summary>
/// <param name="word"></param>
/// <returns></returns>
bool isEI(std::string_view word, bool isERemoved);

/// <summary>
/// /oʊ/ as in goat, home
/// </summary>
/// <param name="word"></param>
/// <returns></returns>
bool isOU(std::string_view word);

#pragma endregion

#pragma region Full diphthongs

/// <summary>
/// /aɪ/ as in kite, night
/// </summary>
/// <param name="word"></param>
/// <returns></returns>
bool isAI(std::string_view word);


bool isOI(std::string_view word);

/// <summary>
/// /aʊ/ as in mouth
/// </summary>
/// <param name="word"></param>
/// <returns></returns>
bool isAU(std::string_view word);

#pragma endregion

}
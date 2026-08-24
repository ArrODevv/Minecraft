/**
 * @file common.hpp
 * @brief Common includes for ArrODevv/Minecraft.
 * @since 0.0.1-ALPHA
 * @author ArrODevv
 * @copyright 2026 ArrODevv
 */

#pragma once

#ifndef MINECRAFT_COMMON_HPP
#define MINECRAFT_COMMON_HPP

// uint8_t, uint16_t, uint32_t, uint64_t
#include <cstdint>

#if defined(_WIN32) || defined(_WIN64)
/** @brief Win32/64 Platform detected. */
#define PLATFORM_WINDOWS 1
#elif defined(__linux__)
/** @brief Linux Platform detected. */
#define PLATFORM_LINUX 1
#elif defined(__APPLE__)
/** @brief Apple Platform detected. */
#define PLATFORM_APPLE 1
#endif

#endif // !MINECRAFT_COMMON_HPP

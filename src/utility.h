#pragma once

#include <spdlog/spdlog.h>
#include <ostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

using u8 = uint8_t;
using i8 = int8_t;
using u16 = uint16_t;
using i16 = int16_t;
using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using i64 = int64_t;

using real = float;

std::ostream& operator<<(std::ostream& out, const sf::Event& event);
using Vector2r = sf::Vector2<real>;
using RealRect = sf::Rect<real>;

bool jsonToVector2u(const json& j, sf::Vector2u& out);

#pragma once

#include <memory>
#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

namespace lg{

    void init();


    extern std::unique_ptr<spdlog::logger> base;
    extern std::unique_ptr<spdlog::logger> event;
    extern std::unique_ptr<spdlog::logger> gui;
    extern std::unique_ptr<spdlog::logger> phy;
    extern std::unique_ptr<spdlog::logger> history;
    extern std::unique_ptr<spdlog::logger> render;
};


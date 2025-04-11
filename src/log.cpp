#include "log.hpp"

#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Logger::instance = nullptr;

std::shared_ptr<spdlog::logger> Logger::getInstance() {
    if (!instance) {
        instance = spdlog::stdout_color_mt("TW");
        instance->set_pattern("%^[%T][%t] %n: %v%$");
        instance->set_level(spdlog::level::trace);
    }
    return instance;
}

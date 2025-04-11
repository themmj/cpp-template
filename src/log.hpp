#pragma once

#include <memory>

#include "spdlog/logger.h"

class Logger {
    static std::shared_ptr<spdlog::logger> instance;

    Logger() = default;

   public:
    static std::shared_ptr<spdlog::logger> getInstance();
};

#define LOG_TRACE(...) ::Logger::getInstance()->trace(__VA_ARGS__)
#define LOG_DEBUG(...) ::Logger::getInstance()->debug(__VA_ARGS__)
#define LOG_INFO(...)  ::Logger::getInstance()->info(__VA_ARGS__)
#define LOG_WARN(...)  ::Logger::getInstance()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Logger::getInstance()->error(__VA_ARGS__)
#define LOG_FATAL(...) ::Logger::getInstance()->critical(__VA_ARGS__)

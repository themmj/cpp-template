#include <iostream>
#include <memory>
#include "spdlog/logger.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "math/math.h"

int main() {
    spdlog::set_pattern("%^[%T][%t] %n: %v%$");
    std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("APP");
    logger->set_level(spdlog::level::trace);

    logger->info("Adding strings: {0}", Math::add<std::string>("Hello", " World"));
    logger->info("Adding numbers: {0}", Math::add(34, 35));

    return 0;
}

//
// Created by truong on 11/24/26.
//

#include "Config/ConfigValidator.hpp"
#include <stdexcept>
#include "Config/Config.hpp"

namespace Config {
    static void Validate (const AppConfig config) {
        if (config.windowConfig.height < 360 || config.windowConfig.height > 1080) {
            throw std::runtime_error("Invalid windowConfig width");
        }

        if (config.windowConfig.width < 480 || config.windowConfig.width > 1920) {
            throw std::runtime_error("Invalid windowConfig height");
        }

        if (config.windowConfig.logW < 480 || config.windowConfig.logW > config.windowConfig.width) {
            throw std::runtime_error("Invalid log width");
        }

        if (config.windowConfig.logH < 360 || config.windowConfig.logH > config.windowConfig.height) {
            throw std::runtime_error("Invalid log height");
        }
    }
}

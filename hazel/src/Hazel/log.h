#pragma once
#include "core.h"
#include "plog/Appenders/ColorConsoleAppender.h"
#include "plog/Log.h"

// comentada linea 14 de plog/log.h !!!!

namespace hazel {

// Function that initializes the logger in the shared library.
inline void HZ_API initializeLog(plog::Severity severity,
                                 plog::IAppender* appender) {
	plog::init(severity, appender);
}

#define HZ_TRACE(...) LOG_DEBUG << fmt::format(__VA_ARGS__)
#define HZ_INFO(...) LOG_INFO << fmt::format(__VA_ARGS__)
#define HZ_WARN(...) LOG_WARNING << fmt::format(__VA_ARGS__)
#define HZ_ERROR(...) LOG_ERROR << fmt::format(__VA_ARGS__)
#define HZ_FATAL(...) LOG_FATAL << fmt::format(__VA_ARGS__)

}  // namespace hazel

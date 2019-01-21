//////////////////////////////////////////////////////////////////////////
//  Plog - portable and simple log for C++
//  Documentation and sources: https://github.com/SergiusTheBest/plog
//  License: MPL 2.0, http://mozilla.org/MPL/2.0/

#pragma once
#include <plog/Logger.h>
#include <plog/Init.h>

//////////////////////////////////////////////////////////////////////////
// Helper macros that get context info

#if defined(_MSC_VER) && _MSC_VER >= 1600 && !defined(__INTELLISENSE__) && !defined(__INTEL_COMPILER) // >= Visual Studio 2010, skip IntelliSense and Intel Compiler
#   define PLOG_GET_THIS()      __if_exists(this) { this } __if_not_exists(this) { 0 }
#else
#   define PLOG_GET_THIS()      0
#endif

#ifdef _MSC_VER
#   define PLOG_GET_FUNC()      __FUNCTION__
#elif defined(__BORLANDC__)
#   define PLOG_GET_FUNC()      __FUNC__
#else
#   define PLOG_GET_FUNC()      __PRETTY_FUNCTION__
#endif

#ifdef PLOG_CAPTURE_FILE
#   define PLOG_GET_FILE()      __FILE__
#else
#   define PLOG_GET_FILE()      ""
#endif

//////////////////////////////////////////////////////////////////////////
// Log severity level checker

#define P_IF_LOG_(instance, severity)   if (!plog::get<instance>() || !plog::get<instance>()->checkSeverity(severity)) {;} else
#define P_IF_LOG(severity)              P_IF_LOG_(PLOG_DEFAULT_INSTANCE, severity)

//////////////////////////////////////////////////////////////////////////
// Main logging macros

#define P_LOG_(instance, severity)      P_IF_LOG_(instance, severity) (*plog::get<instance>()) += plog::Record(severity, PLOG_GET_FUNC(), __LINE__, PLOG_GET_FILE(), PLOG_GET_THIS())
#define P_LOG(severity)                 P_LOG_(PLOG_DEFAULT_INSTANCE, severity)

#define P_LOG_VERBOSE                     P_LOG(plog::verbose)
#define P_LOG_DEBUG                       P_LOG(plog::debug)
#define P_LOG_INFO                        P_LOG(plog::info)
#define P_LOG_WARNING                     P_LOG(plog::warning)
#define P_LOG_ERROR                       P_LOG(plog::error)
#define P_LOG_FATAL                       P_LOG(plog::fatal)
#define P_LOG_NONE                        P_LOG(plog::none)

#define P_LOG_VERBOSE_(instance)          P_LOG_(instance, plog::verbose)
#define P_LOG_DEBUG_(instance)            P_LOG_(instance, plog::debug)
#define P_LOG_INFO_(instance)             P_LOG_(instance, plog::info)
#define P_LOG_WARNING_(instance)          P_LOG_(instance, plog::warning)
#define P_LOG_ERROR_(instance)            P_LOG_(instance, plog::error)
#define P_LOG_FATAL_(instance)            P_LOG_(instance, plog::fatal)
#define P_LOG_NONE_(instance)             P_LOG_(instance, plog::none)

#define P_LOGV                            P_LOG_VERBOSE
#define P_LOGD                            P_LOG_DEBUG
#define P_LOGI                            P_LOG_INFO
#define P_LOGW                            P_LOG_WARNING
#define P_LOGE                            P_LOG_ERROR
#define P_LOGF                            P_LOG_FATAL
#define P_LOGN                            P_LOG_NONE

#define P_LOGV_(instance)                 P_LOG_VERBOSE_(instance)
#define P_LOGD_(instance)                 P_LOG_DEBUG_(instance)
#define P_LOGI_(instance)                 P_LOG_INFO_(instance)
#define P_LOGW_(instance)                 P_LOG_WARNING_(instance)
#define P_LOGE_(instance)                 P_LOG_ERROR_(instance)
#define P_LOGF_(instance)                 P_LOG_FATAL_(instance)
#define P_LOGN_(instance)                 P_LOG_NONE_(instance)

//////////////////////////////////////////////////////////////////////////
// Conditional logging macros

#define P_LOG_IF_(instance, severity, condition)  if (!(condition)) {;} else P_LOG_(instance, severity)
#define P_LOG_IF(severity, condition)             P_LOG_IF_(PP_LOG_DEFAULT_INSTANCE, severity, condition)

#define P_LOG_VERBOSE_IF(condition)               P_LOG_IF(plog::verbose, condition)
#define P_LOG_DEBUG_IF(condition)                 P_LOG_IF(plog::debug, condition)
#define P_LOG_INFO_IF(condition)                  P_LOG_IF(plog::info, condition)
#define P_LOG_WARNING_IF(condition)               P_LOG_IF(plog::warning, condition)
#define P_LOG_ERROR_IF(condition)                 P_LOG_IF(plog::error, condition)
#define P_LOG_FATAL_IF(condition)                 P_LOG_IF(plog::fatal, condition)
#define P_LOG_NONE_IF(condition)                  P_LOG_IF(plog::none, condition)

#define P_LOG_VERBOSE_IF_(instance, condition)    P_LOG_IF_(instance, plog::verbose, condition)
#define P_LOG_DEBUG_IF_(instance, condition)      P_LOG_IF_(instance, plog::debug, condition)
#define P_LOG_INFO_IF_(instance, condition)       P_LOG_IF_(instance, plog::info, condition)
#define P_LOG_WARNING_IF_(instance, condition)    P_LOG_IF_(instance, plog::warning, condition)
#define P_LOG_ERROR_IF_(instance, condition)      P_LOG_IF_(instance, plog::error, condition)
#define P_LOG_FATAL_IF_(instance, condition)      P_LOG_IF_(instance, plog::fatal, condition)
#define P_LOG_NONE_IF_(instance, condition)       P_LOG_IF_(instance, plog::none, condition)

#define P_LOGV_IF(condition)                      P_LOG_VERBOSE_IF(condition)
#define P_LOGD_IF(condition)                      P_LOG_DEBUG_IF(condition)
#define P_LOGI_IF(condition)                      P_LOG_INFO_IF(condition)
#define P_LOGW_IF(condition)                      P_LOG_WARNING_IF(condition)
#define P_LOGE_IF(condition)                      P_LOG_ERROR_IF(condition)
#define P_LOGF_IF(condition)                      P_LOG_FATAL_IF(condition)
#define P_LOGN_IF(condition)                      P_LOG_NONE_IF(condition)

#define P_LOGV_IF_(instance, condition)           P_LOG_VERBOSE_IF_(instance, condition)
#define P_LOGD_IF_(instance, condition)           P_LOG_DEBUG_IF_(instance, condition)
#define P_LOGI_IF_(instance, condition)           P_LOG_INFO_IF_(instance, condition)
#define P_LOGW_IF_(instance, condition)           P_LOG_WARNING_IF_(instance, condition)
#define P_LOGE_IF_(instance, condition)           P_LOG_ERROR_IF_(instance, condition)
#define P_LOGF_IF_(instance, condition)           P_LOG_FATAL_IF_(instance, condition)
#define P_LOGN_IF_(instance, condition)           P_LOG_NONE_IF_(instance, condition)

#pragma once

#if _MSC_VER && _DEBUG
#define ESDEBUG
#elif !_MSVC_VER && !NDEBUG
#define ESDEBUG
#endif

#ifdef ESDEBUG

#include <iostream>
#include <locale>
#include <string>

struct Trace {
  const char* filename;
  unsigned line;
  std::locale old;

  // guarda el código local y lo cambia al de windows ("")
  Trace(const char* filename, const unsigned line)
      : filename{filename},
        line{line},
        old{std::locale::global(std::locale(""))} {}

	// static_cast por:
	// cppcoreguidelines-pro-bounds-array-to-pointer-decay
	template <typename T>
  void operator()(T&& head) const {
    std::cout << static_cast<std::decay_t<T>>(head); 
		//std::cout << head;
    std::cout << " << " << filename << "(" << line << ")"
              << "\n";
  }

  template <typename T, typename... Args>
  void operator()(T&& head, Args&&... tail) const {
		std::cout << static_cast<std::decay_t<T>>(head) << " ";
		//std::cout << head << " ";
    operator()(std::forward<Args>(tail)...);
  }

  // recupera el código anterior
  ~Trace() { std::locale::global(std::locale(old)); }

  using Self = Trace;
  Trace(const Self&) = delete;
  Trace(Self&&) = delete;
  Self& operator=(const Self&) = delete;
  Self& operator=(Self&&) = delete;
};

#endif  // ESDEBUG

// Versión MSVC // debido las extensiones de clang (define _MSC_VER)
#if _MSC_VER && !__clang__
#ifdef ESDEBUG
#define TRACE Trace(__FUNCSIG__, __LINE__)
#else
#define TRACE __noop
#endif

// Otros compiladores
#else

#ifdef ESDEBUG
#define TRACE Trace(__PRETTY_FUNCTION__, __LINE__)  // NOLINT
#else
template <typename... Args>
void doNothing(Args&&...) {}
#define TRACE doNothing
#endif

#endif  // _MSC_VER

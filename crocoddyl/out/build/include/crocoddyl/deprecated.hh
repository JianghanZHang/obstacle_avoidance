/*
 * This file has been automatically generated by the jrl-cmakemodules.
 * Please see https://github.com/jrl-umi3218/jrl-cmakemodules/blob/master/deprecated.hh.cmake for details.
*/

#ifndef CROCODDYL_DEPRECATED_HH
# define CROCODDYL_DEPRECATED_HH

// Define a suffix which can be used to tag a type, a function or a a
// variable as deprecated (i.e. it will emit a warning when using it).
//
// Tagging a function as deprecated:
//  void foo () CROCODDYL_DEPRECATED;
//
// Tagging a type as deprecated:
//  class Foo {};
//  typedef Foo Bar CROCODDYL_DEPRECATED;
//
// Tagging a variable as deprecated:
//  int a CROCODDYL_DEPRECATED = 0;
//
// The use of a macro is required as this is /not/ a standardized
// feature of C++ language or preprocessor, even if most of the
// compilers support it.
# if defined(__cplusplus) && (__cplusplus >= 201402L)
#  define CROCODDYL_DEPRECATED [[deprecated]]
#  define CROCODDYL_DEPRECATED_MESSAGE(message) [[deprecated(#message)]]
# elif defined(__GNUC__) || defined(__clang__)
#  define CROCODDYL_DEPRECATED __attribute__ ((deprecated))
#  define CROCODDYL_DEPRECATED_MESSAGE(message) __attribute__ (( deprecated(#message) ))
# else
#  if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#   define CROCODDYL_DEPRECATED __declspec (deprecated)
#   define CROCODDYL_DEPRECATED_MESSAGE(message) __declspec ( deprecated(#message) )
#  else
// If the compiler is not recognized, drop the feature.
#   define CROCODDYL_DEPRECATED /* nothing */
#   define CROCODDYL_DEPRECATED_MESSAGE(message)
#  endif // __MSVC__
# endif // __cplusplus

# if defined(__GNUC__) || defined(__clang__)
#  ifndef CROCODDYL_PRAGMA
#   define CROCODDYL_PRAGMA(X) _Pragma(#X)
#  endif
#  define CROCODDYL_DEPRECATED_HEADER(MSG) CROCODDYL_PRAGMA(GCC warning MSG)
# elif defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#  define CROCODDYL_STRINGIZE_(MSG) #MSG
#  define CROCODDYL_STRINGIZE(MSG) CROCODDYL_STRINGIZE_(MSG)
#  define CROCODDYL_DEPRECATED_HEADER(MSG) \
    __pragma(message(__FILE__ "(" CROCODDYL_STRINGIZE(__LINE__) ") : Warning: " MSG))
# else
#  define CROCODDYL_DEPRECATED_HEADER(MSG)
# endif

#endif //! CROCODDYL_DEPRECATED_HH
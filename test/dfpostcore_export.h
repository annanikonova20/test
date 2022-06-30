
#ifndef DFPOSTCORE_EXPORT_H
#define DFPOSTCORE_EXPORT_H

#ifdef DFPOSTCORE_STATIC_DEFINE
#  define DFPOSTCORE_EXPORT
#  define DFPOSTCORE_NO_EXPORT
#else
#  ifndef DFPOSTCORE_EXPORT
#    ifdef dfpostcore_EXPORTS
        /* We are building this library */
#      define DFPOSTCORE_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define DFPOSTCORE_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef DFPOSTCORE_NO_EXPORT
#    define DFPOSTCORE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef DFPOSTCORE_DEPRECATED
#  define DFPOSTCORE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef DFPOSTCORE_DEPRECATED_EXPORT
#  define DFPOSTCORE_DEPRECATED_EXPORT DFPOSTCORE_EXPORT DFPOSTCORE_DEPRECATED
#endif

#ifndef DFPOSTCORE_DEPRECATED_NO_EXPORT
#  define DFPOSTCORE_DEPRECATED_NO_EXPORT DFPOSTCORE_NO_EXPORT DFPOSTCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef DFPOSTCORE_NO_DEPRECATED
#    define DFPOSTCORE_NO_DEPRECATED
#  endif
#endif

#endif /* DFPOSTCORE_EXPORT_H */

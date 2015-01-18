AC_INIT(tntnet-homepage, 0.1, [Tommi Maekitalo <tommi@tntnet.org>])
AM_INIT_AUTOMAKE
LT_INIT([disable-static])

abi_current=0
abi_revision=0
abi_age=0
sonumber=${abi_current}:${abi_revision}:${abi_age}
AC_SUBST(sonumber)

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([lib/config.h])
AC_CONFIG_SRCDIR([lib/tnthp/markdown.cpp])

AC_PROG_CXX
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

AX_BOOST_BASE([1.35], , AC_MSG_ERROR([boost library not found]))
AX_BOOST_REGEX

AC_LANG(C++)
AC_CHECK_HEADER([tnt/tntnet.h], , AC_MSG_ERROR([tntnet headers not found]))
AC_CHECK_HEADER([boost/regex.hpp], , AC_MSG_ERROR([boost regex headers not found]))
AC_CHECK_PROGS(ECPPC, [ecppc])
AC_CHECK_PROGS(GZIP, [gzip])

AC_ARG_ENABLE([md2man],
  AS_HELP_STRING([--enable-md2man], [enable generation of man pages]),
  [enable_md2man=$enableval],
  [enable_md2man=no])

AM_CONDITIONAL(GENMAN, test x$enable_md2man = xyes)

AS_IF([test "$enable_md2man" = "yes"],
    AC_CHECK_PROGS(MD2MAN_HTML, [md2man-html])
)

DOXYGEN_SRC_DIR([cxxtools], [cxxtoolsdir], [include/cxxtools/arg.h])
DOXYGEN_SRC_DIR([tntnet], [tntnetdir], [framework/common/tnt/tntnet.h])
DOXYGEN_SRC_DIR([tntdb], [tntdbdir], [include/tntdb/connect.h])
AC_CONFIG_COMMANDS([mkdir], [$MKDIR_P htdocs/howto; $MKDIR_P htdocs/man])

AC_CONFIG_FILES([Makefile
                 include/Makefile
                 lib/Makefile
                 webapp/Makefile
                 tntnet.xml
                 doxygen/Makefile
                 ])
AC_OUTPUT

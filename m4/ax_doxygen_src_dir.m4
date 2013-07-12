
AC_DEFUN([DOXYGEN_SRC_DIR], [

  AC_ARG_WITH(
    [$1],
    AS_HELP_STRING([--with-$1=directory],
                   [sets source directory of $1 (default: $srcdir/../$1)]),
    [$2=$withval],
    [$2=$srcdir/../$1])

  doxysrcdir=`eval echo \$$2`
  AC_CHECK_FILE($doxysrcdir/$3,, AC_MSG_ERROR([$1 headers not found]))
  AC_SUBST($2)

])


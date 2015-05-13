AC_PREREQ([2.64])

AC_INIT([derive],[1.0],[svschub@gmx.de])
AM_INIT_AUTOMAKE([subdir-objects])
LT_PREREQ([2.2])
LT_INIT([dlopen])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/AST/AST.h])

AC_CONFIG_HEADERS([src/AST/config.h])

AC_CONFIG_FILES([Makefile src/AST/Makefile src/parser/Makefile src/tests/Makefile])

AC_PROG_INSTALL
AC_PROG_CXX
AM_PROG_CC_C_O

AC_LANG(C++)

AC_C_CONST
AC_HEADER_STDC

AC_PROG_YACC
AM_PROG_LEX

AX_CXX_COMPILE_STDCXX_11
AX_BOOST_BASE([], [], [AC_MSG_ERROR(You need the Boost libraries)])

AC_SUBST(LIBS)

AC_OUTPUT


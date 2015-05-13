noinst_LTLIBRARIES = libparser.la

# BUILT_SOURCES = symbolix-parser.hh
AM_YFLAGS = -d

libparser_la_SOURCES = symbolix-scanner.ll symbolix-parser.yy symbolix-driver.C Formula.C FormulaException.C
libparser_la_LIBADD = ../AST/libast.la 
libparser_la_LDFLAGS =

noinst_HEADERS = symbolix-driver.h Formula.h FormulaException.h


symbolix-scanner.cc: symbolix-parser.hh

symbolix-driver.$(OBJEXT): symbolix-parser.hh


CLEANFILES = symbolix-scanner.cc symbolix-parser.cc symbolix-parser.hh stack.hh position.hh location.hh

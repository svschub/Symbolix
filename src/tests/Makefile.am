
bin_PROGRAMS = ast_test differentiate

ast_test_SOURCES = test.C
ast_test_LDADD = ../AST/libast.la
ast_test_LDFLAGS = -lm

differentiate_SOURCES = differentiate.C
differentiate_LDFLAGS = -lm -lboost_system -lboost_program_options -lboost_filesystem
differentiate_LDADD = ../parser/libparser.la

AM_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/include $(BOOST_CPPFLAGS)
AUTOMAKE_OPTIONS = subdir-objects

lib_LTLIBRARIES = libtntnet-homepage.la

libtntnet_homepage_la_LDFLAGS = $(BOOST_LDFLAGS) $(BOOST_REGEX_LIB)
libtntnet_homepage_la_LIBADD =
libtntnet_homepage_la_SOURCES = \
	markdown/markdown.cpp \
	markdown/markdown-tokens.cpp \
	tnthp/markdown.cpp

EXTRA_DIST = \
	markdown/LICENSE.TXT

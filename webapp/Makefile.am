AM_CPPFLAGS = -I$(top_srcdir)/include
AUTOMAKE_OPTIONS = subdir-objects

pkglib_LTLIBRARIES = tntnet-homepage.la

ecppSources = \
	howto.ecpp \
	index.ecpp \
	markdown.ecpp \
	main.ecpp \
	news.ecpp

tntnet_homepage_la_SOURCES = \
	$(ecppSources)

tntnet_homepage_la_LIBADD = $(top_builddir)/lib/libtntnet-homepage.la
tntnet_homepage_la_LDFLAGS = -module -ltntnet

CLEANFILES = $(ecppSources:.ecpp=.cpp)

SUFFIXES=.ecpp .jpg .cpp

.ecpp.cpp:
	$(ECPPC) -I $(top_srcdir)/webapp -p -o $@ $<
.jpg.cpp:
	$(ECPPC) -b -m image/jpeg -o $@ $<

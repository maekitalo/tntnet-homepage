AM_CPPFLAGS = -I$(top_srcdir)/include
AUTOMAKE_OPTIONS = subdir-objects

pkglib_LTLIBRARIES = tntnet-homepage.la

ecppSources = \
	pages/index.ecpp \
	pages/contact.ecpp \
	pages/cxxtools.ecpp \
	pages/download.ecpp \
	pages/faq.ecpp \
	pages/howtos.ecpp \
	pages/man.ecpp \
	pages/news.ecpp \
	pages/repository.ecpp \
	pages/tntdb.ecpp \
	pages/tntnet.ecpp \
	markdown.ecpp \
	main.ecpp

tntnet_homepage_la_SOURCES = \
	$(ecppSources)

tntnet_homepage_la_LIBADD = $(top_builddir)/lib/libtntnet-homepage.la
tntnet_homepage_la_LDFLAGS = -module -ltntnet

CLEANFILES = $(ecppSources:.ecpp=.cpp)

SUFFIXES=.ecpp .jpg .cpp

.ecpp.cpp:
	$(ECPPC) -I $(top_srcdir)/web -p -o $@ $<
.jpg.cpp:
	$(ECPPC) -b -m image/jpeg -o $@ $<

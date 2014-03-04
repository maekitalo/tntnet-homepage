noinst_DATA = Doxyfile

Doxyfile: Doxyfile.in
	$(SED) -e 's,@top_builddir\@,$(top_builddir),' \
	       -e 's,@top_srcdir\@,$(top_srcdir),' \
	       -e 's,@cxxtoolsdir\@,$(top_builddir)/$(cxxtoolsdir),' \
	       -e 's,@tntnetdir\@,$(top_builddir)/$(tntnetdir),' \
	       -e 's,@tntdbdir\@,$(top_builddir)/$(tntdbdir),' \
	       < $(top_srcdir)/doxygen/Doxyfile.in > Doxyfile
	doxygen

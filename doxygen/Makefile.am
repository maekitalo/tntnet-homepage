noinst_DATA = Doxyfile

Doxyfile: Doxyfile.in
	$(SED) -e 's,@top_builddir\@,$(abs_top_builddir),' \
	       -e 's,@top_srcdir\@,$(abs_top_srcdir),' \
	       -e 's,@cxxtoolsdir\@,$(abs_top_srcdir)/$(cxxtoolsdir),' \
	       -e 's,@tntnetdir\@,$(abs_top_srcdir)/$(tntnetdir),' \
	       -e 's,@tntdbdir\@,$(abs_top_srcdir)/$(tntdbdir),' \
		   <Doxyfile.in >Doxyfile

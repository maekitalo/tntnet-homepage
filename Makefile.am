ACLOCAL_AMFLAGS = -I m4

SUBDIRS = 	include 	lib 	webapp

if GENMAN

MANPAGES = \
	htdocs/man/tntnet.8.html \
	htdocs/man/tntnet-defcomp.1.html \
	htdocs/man/ecpp.7.html \
	htdocs/man/ecppc.1.html \
	htdocs/man/tntnet.xml.7.html \
	htdocs/man/tntnet-project.1.html \
	htdocs/man/ecppll.1.html \
	htdocs/man/ecppl.1.html

endif

noinst_DATA =  \
	htdocs/quick-start-guide.markdown \
	htdocs/howto/argument-parsing-howto.markdown \
	htdocs/howto/binaryrpc-howto.markdown \
	htdocs/howto/csv-howto.markdown \
	htdocs/howto/jquery-howto.markdown \
	htdocs/howto/json-howto.markdown \
	htdocs/howto/jsonquick-howto.markdown \
	htdocs/howto/jsonrpc-howto.markdown \
	htdocs/howto/propertiesquick-howto.markdown \
	htdocs/howto/logging-howto.markdown \
	htdocs/howto/rpc-howto.markdown \
	htdocs/howto/serialization-howto.markdown \
	htdocs/howto/static-howto.markdown \
	htdocs/howto/tntdb.markdown \
	htdocs/howto/upload-howto.markdown \
	htdocs/howto/xmlrpc-howto.markdown \
	htdocs/tntnet.css.gz \
	htdocs/tntnet.css \
	$(MANPAGES)

$(top_builddir)/htdocs/tntnet.css.gz: $(top_srcdir)/htdocs/tntnet.css
	$(GZIP) < htdocs/tntnet.css > htdocs/tntnet.css.gz

htdocs/quick-start-guide.markdown: @tntnetdir@/doc/quick-start-guide.markdown
	cp @tntnetdir@/doc/quick-start-guide.markdown htdocs/quick-start-guide.markdown

htdocs/howto/argument-parsing-howto.markdown: @cxxtoolsdir@/doc/argument-parsing-howto.markdown
	cp @cxxtoolsdir@/doc/argument-parsing-howto.markdown htdocs/howto/argument-parsing-howto.markdown

htdocs/howto/binaryrpc-howto.markdown: @cxxtoolsdir@/doc/binaryrpc-howto.markdown
	cp @cxxtoolsdir@/doc/binaryrpc-howto.markdown htdocs/howto/binaryrpc-howto.markdown

htdocs/howto/csv-howto.markdown: @cxxtoolsdir@/doc/csv-howto.markdown
	cp @cxxtoolsdir@/doc/csv-howto.markdown htdocs/howto/csv-howto.markdown

htdocs/howto/json-howto.markdown: @cxxtoolsdir@/doc/json-howto.markdown
	cp @cxxtoolsdir@/doc/json-howto.markdown htdocs/howto/json-howto.markdown

htdocs/howto/jsonquick-howto.markdown: @cxxtoolsdir@/doc/jsonquick-howto.markdown
	cp @cxxtoolsdir@/doc/jsonquick-howto.markdown htdocs/howto/jsonquick-howto.markdown

htdocs/howto/jsonrpc-howto.markdown: @cxxtoolsdir@/doc/jsonrpc-howto.markdown
	cp @cxxtoolsdir@/doc/jsonrpc-howto.markdown htdocs/howto/jsonrpc-howto.markdown

htdocs/howto/propertiesquick-howto.markdown: @cxxtoolsdir@/doc/propertiesquick-howto.markdown
	cp @cxxtoolsdir@/doc/propertiesquick-howto.markdown htdocs/howto/propertiesquick-howto.markdown

htdocs/howto/serialization-howto.markdown: @cxxtoolsdir@/doc/serialization-howto.markdown
	cp @cxxtoolsdir@/doc/serialization-howto.markdown htdocs/howto/serialization-howto.markdown

htdocs/howto/logging-howto.markdown: @cxxtoolsdir@/doc/logging-howto.markdown
	cp @cxxtoolsdir@/doc/logging-howto.markdown htdocs/howto/logging-howto.markdown

htdocs/howto/rpc-howto.markdown: @cxxtoolsdir@/doc/rpc-howto.markdown
	cp @cxxtoolsdir@/doc/rpc-howto.markdown htdocs/howto/rpc-howto.markdown

htdocs/howto/jquery-howto.markdown: @tntnetdir@/doc/jquery-howto.markdown
	cp @tntnetdir@/doc/jquery-howto.markdown htdocs/howto/jquery-howto.markdown

htdocs/howto/static-howto.markdown: @tntnetdir@/doc/static-howto.markdown
	cp @tntnetdir@/doc/static-howto.markdown htdocs/howto/static-howto.markdown

htdocs/howto/tntdb.markdown: @tntdbdir@/doc/tntdb.markdown
	cp @tntdbdir@/doc/tntdb.markdown htdocs/howto/tntdb.markdown

htdocs/howto/upload-howto.markdown: @tntnetdir@/doc/upload-howto.markdown
	cp @tntnetdir@/doc/upload-howto.markdown htdocs/howto/upload-howto.markdown

htdocs/howto/xmlrpc-howto.markdown: @cxxtoolsdir@/doc/xmlrpc-howto.markdown
	cp @cxxtoolsdir@/doc/xmlrpc-howto.markdown htdocs/howto/xmlrpc-howto.markdown

#
# man pages
#

htdocs/man/tntnet.8.html: @tntnetdir@/doc/man/tntnet.8.markdown
	@MD2MAN_HTML@ @tntnetdir@/doc/man/tntnet.8.markdown >htdocs/man/tntnet.8.html

htdocs/man/tntnet-defcomp.1.html: @tntnetdir@/doc/man/tntnet-defcomp.1.markdown
	@MD2MAN_HTML@ @tntnetdir@/doc/man/tntnet-defcomp.1.markdown >htdocs/man/tntnet-defcomp.1.html

htdocs/man/ecpp.7.html: @tntnetdir@/doc/man/ecpp.7.markdown
	@MD2MAN_HTML@ @tntnetdir@/doc/man/ecpp.7.markdown >htdocs/man/ecpp.7.html

htdocs/man/ecppc.1.html: @tntnetdir@/doc/man/ecppc.1.markdown
	@MD2MAN_HTML@ @tntnetdir@/doc/man/ecppc.1.markdown >htdocs/man/ecppc.1.html

htdocs/man/tntnet.xml.7.html: @tntnetdir@/doc/man/tntnet.xml.7.markdown
	@MD2MAN_HTML@ @tntnetdir@/doc/man/tntnet.xml.7.markdown >htdocs/man/tntnet.xml.7.html

htdocs/man/tntnet-project.1.html: @tntnetdir@/doc/man/tntnet-project.1.markdown
	@MD2MAN_HTML@ @tntnetdir@/doc/man/tntnet-project.1.markdown >htdocs/man/tntnet-project.1.html

htdocs/man/ecppll.1.html: @tntnetdir@/doc/man/ecppll.1.markdown
	@MD2MAN_HTML@ @tntnetdir@/doc/man/ecppll.1.markdown >htdocs/man/ecppll.1.html

htdocs/man/ecppl.1.html: @tntnetdir@/doc/man/ecppl.1.markdown
	@MD2MAN_HTML@ @tntnetdir@/doc/man/ecppl.1.markdown >htdocs/man/ecppl.1.html


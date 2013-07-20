ACLOCAL_AMFLAGS = -I m4

SUBDIRS = 	include 	lib 	webapp

noinst_DATA =  \
	htdocs/quick-start-guide.markdown \
	htdocs/howto/argument-parsing-howto.markdown \
	htdocs/howto/json-howto.markdown \
	htdocs/howto/logging-howto.markdown \
	htdocs/howto/rpc-howto.markdown \
	htdocs/howto/static-howto.markdown \
	htdocs/howto/tntdb.markdown

htdocs/quick-start-guide.markdown:
	cp @tntnetdir@/doc/quick-start-guide.markdown htdocs/quick-start-guide.markdown

htdocs/howto/argument-parsing-howto.markdown:
	cp @cxxtoolsdir@/doc/argument-parsing-howto.markdown htdocs/howto/argument-parsing-howto.markdown

htdocs/howto/json-howto.markdown:
	cp @cxxtoolsdir@/doc/json-howto.markdown htdocs/howto/json-howto.markdown

htdocs/howto/logging-howto.markdown:
	cp @cxxtoolsdir@/doc/logging-howto.markdown htdocs/howto/logging-howto.markdown

htdocs/howto/rpc-howto.markdown:
	cp @cxxtoolsdir@/doc/rpc-howto.markdown htdocs/howto/rpc-howto.markdown

htdocs/howto/static-howto.markdown:
	cp @tntnetdir@/doc/static-howto.markdown htdocs/howto/static-howto.markdown

htdocs/howto/tntdb.markdown:
	cp @tntdbdir@/doc/tntdb.markdown htdocs/howto/tntdb.markdown

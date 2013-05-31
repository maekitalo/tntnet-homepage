////////////////////////////////////////////////////////////////////////
// howtos.cpp
// generated with ecppc
//

#include <tnt/ecpp.h>
#include <tnt/httprequest.h>
#include <tnt/httpreply.h>
#include <tnt/httpheader.h>
#include <tnt/http.h>
#include <tnt/data.h>
#include <tnt/componentfactory.h>
#include <cxxtools/log.h>
#include <stdexcept>

log_define("component.howtos")

// <%pre>
#line 1 "howtos.ecpp"

#include <cxxtools/directory.h>
#include <cxxtools/regex.h>
#include <fstream>

// </%pre>

namespace
{
class _component_ : public tnt::EcppComponent
{
    _component_& main()  { return *this; }

  protected:
    ~_component_();

  public:
    _component_(const tnt::Compident& ci, const tnt::Urlmapper& um, tnt::Comploader& cl);

    unsigned operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam);
};

static tnt::EcppComponentFactoryImpl<_component_> Factory("howtos");

static const char* rawData = "\024\000\000\000$\000\000\0003\000\000\000:\000\000\000C\000\000\000<h1>Howto</h1>\n\n<a "
  "href=\"howto/.html\"></a><br>\n";

// <%shared>
// </%shared>

// <%config>
// </%config>

#define SET_LANG(lang) \
     do \
     { \
       request.setLang(lang); \
       reply.setLocale(request.getLocale()); \
     } while (false)

_component_::_component_(const tnt::Compident& ci, const tnt::Urlmapper& um, tnt::Comploader& cl)
  : EcppComponent(ci, um, cl)
{
  // <%init>
  // </%init>
}

_component_::~_component_()
{
  // <%cleanup>
  // </%cleanup>
}

unsigned _component_::operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam)
{
  log_trace("howtos " << qparam.getUrl());

  tnt::DataChunks data(rawData);

  // <%cpp>
#line 6 "howtos.ecpp"


cxxtools::Directory dir("htdocs/howto");
static cxxtools::Regex re("htdocs/howto/(.*).markdown");


  reply.out() << data[0]; // <h1>Howto</h1>\n\n
#line 14 "howtos.ecpp"

for (cxxtools::Directory::const_iterator it = dir.begin(); it != dir.end(); ++it)
{
  std::ifstream in(it.path().c_str());
  std::string title;
  cxxtools::RegexSMatch m;
  if (re.match(it.path(), m) && std::getline(in, title))
  {

  reply.out() << data[1]; // <a href="howto/
#line 23 "howtos.ecpp"
  reply.sout() << ( m[1] );
  reply.out() << data[2]; // .html">
#line 23 "howtos.ecpp"
  reply.sout() << ( title );
  reply.out() << data[3]; // </a><br>\n
#line 24 "howtos.ecpp"

  }
}

  // <%/cpp>
  return HTTP_OK;
}

} // namespace

/*
 * Copyright (C) 2013 Tommi Maekitalo
 *
 */

#include <tnthp/markdown.h>
#include <markdown/markdown.h>
#include <tnt/httprequest.h>
#include <tnt/httpreply.h>
#include <tnt/http.h>
#include <tnt/httperror.h>
#include <cxxtools/cache.h>
#include <cxxtools/log.h>
#include <fstream>
#include <sstream>
#include <sys/stat.h>

log_define("tnthp.markdown")

namespace tnthp
{

namespace
{
  struct Page
  {
    time_t mtime;
    std::string htmlContent;
  };

  cxxtools::Cache<std::string, Page> renderedPages(32);
}

unsigned Markdown::operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam)
{
  std::string fname = request.getArg("file", request.getPathInfo());

  log_debug("read markdown file \"" << fname << '"');

  std::ifstream in(fname.c_str());
  if (!in)
  {
    log_debug("could not read markdown file");
    return DECLINED;
  }

  /*
  markdown::Document doc;
  doc.read(in);
  doc.write(reply.out());
  return HTTP_OK;
  */

  struct stat st;
  int ret = ::stat(fname.c_str(), &st);

  std::pair<bool, Page> r = renderedPages.getx(fname);

  if (!r.first || ret != 0 || st.st_mtime != r.second.mtime)
  {
    log_debug("r.first=" << r.first << " ret=" << ret << " st.st_mtime=" << st.st_mtime << " mtime=" << r.second.mtime);
    log_debug("cache miss or modified");
    std::ostringstream out;
    markdown::Document doc;
    doc.read(in);
    doc.write(out);

    r.second.htmlContent = out.str();
    r.second.mtime = st.st_mtime;
    renderedPages.erase(fname);
    renderedPages.put(fname, r.second);
  }
  else
    log_debug("cache hit");

  reply.out() << r.second.htmlContent;
  return HTTP_OK;
}

}

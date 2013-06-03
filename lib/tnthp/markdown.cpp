/*
 * Copyright (C) 2013 Tommi Maekitalo
 *
 */

#include <tnthp/markdown.h>
#include <markdown/markdown.h>

#include <cxxtools/cache.h>
#include <cxxtools/log.h>

#include <stdexcept>
#include <fstream>
#include <sstream>

#include <sys/stat.h>

log_define("tnthp.markdown")

namespace tnthp
{

#ifdef NO_MARKDOWN_CACHE
void Markdown::toHtml(std::ostream& out, const std::string& fname)
{
  log_debug("read markdown file \"" << fname << '"');

  std::ifstream in(fname.c_str());
  if (!in)
  {
    log_debug("could not read markdown file");
    throw std::runtime_error("could not read markdown file \"" + fname + '"');
  }

  markdown::Document doc;
  doc.read(in);
  doc.write(reply.out());
}

std::string Markdown::toHtml(const std::string& fname)
{
  std::ostringstream s;
  toHtml(s, fname);
  return s.str();
}
#else

namespace
{
  struct Page
  {
    time_t mtime;
    std::string htmlContent;
  };

  cxxtools::Cache<std::string, Page> renderedPages(32);
}

void Markdown::toHtml(std::ostream& out, const std::string& fname)
{
  out << toHtml(fname);
}

std::string Markdown::toHtml(const std::string& fname)
{
  log_debug("read markdown file \"" << fname << '"');

  std::ifstream in(fname.c_str());
  if (!in)
  {
    log_debug("could not read markdown file");
    throw std::runtime_error("could not read markdown file \"" + fname + '"');
  }

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

  return r.second.htmlContent;
}

#endif

}

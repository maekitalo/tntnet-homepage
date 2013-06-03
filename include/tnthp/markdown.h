/*
 * Copyright (C) 2013 Tommi Maekitalo
 *
 */

#ifndef TNTHP_MARKDOWN_H
#define TNTHP_MARKDOWN_H

#include <iosfwd>
#include <string>

namespace tnthp
{
  class Markdown
  {
    public:
      void toHtml(std::ostream& out, const std::string& fname);
      std::string toHtml(const std::string& fname);
  };

}

#endif // TNTHP_MARKDOWN_H


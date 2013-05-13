/*
 * Copyright (C) 2013 Tommi Maekitalo
 *
 */

#ifndef TNTHP_MARKDOWN_H
#define TNTHP_MARKDOWN_H

#include <tnt/component.h>

namespace tnthp
{
  class Markdown : public tnt::Component
  {
    public:
      unsigned operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam);
  };

}

#endif // TNTHP_MARKDOWN_H


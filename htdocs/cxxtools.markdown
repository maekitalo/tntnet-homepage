Cxxtools
========

Cxxtools is a comprehensive C++ class library for Unix and Linux.

The library includes classes for serialization, unicode text, multi threading,
networking, rpc, http client and server, xml, logging and many more.

While providing a large amount of features it is still very easy to use.

The use of modern C++ makes cxxtools very efficient while offering a high level
abstraction.

Cxxtools is published under the LGPL with extensions, which allows you to use
cxxtools in commercial applications as well.

Highlights
----------

A generic serialization framework makes it easy to convert C++ objects to
various formats including *xml*, *json*, *binary* or *csv*. With just 2 easy to
write operators for serialization and deserialization of user defined classes
opens a whole new world of formatting.

Based on that serialization framework a easy to use and high performance rpc
framework with multi protocol support is available. This makes it easy to call
functions and make functions available over the network.

A logging framework is always good to have. The cxxtools one is very easy to use
and lightweight.

Networking classes makes it easy to implement own protocols for communicating
over the network.

A unicode string class with utf8 support helps writing internationalized
applications.

Parsing command line arguments using *getline(3)* is very common while ugly and
error prone. A much easier helper class makes it a no-brainer.

Asynchronous I/O is hard on the low level. Cxxtools implements a robust
abstraction which makes it unnecessary to dive down into the hard parts of
*poll(2)* or *select(2)*.

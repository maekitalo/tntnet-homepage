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

Examples
--------

Since cxxtools has so many different features it is difficult to give you that
one example. But the rpc system is one of the big highlights. It is really easy
to write a simple application server, where service functions are callable
through the network. So lets assume see how it is done. We choose json rpc as
the transport protocol here.

    #include <iostream>
    #include <cxxtools/arg.h>
    #include <cxxtools/log.h>
    #include <cxxtools/json/rpcserver.h>
    #include <cxxtools/eventloop.h>

    ////////////////////////////////////////////////////////////////////////
    // This defines functions, which we want to be called remotely.
    //

    // Parameters and return values of the functions, which can be exported must be
    // serializable and deserializable with the cxxtools serialization framework.
    // For all standard types including container classes in the standard library
    // proper operators are defined in cxxtools.
    //

    std::string echo(const std::string& message)
    {
      std::cout << message << std::endl;
      return message;
    }

    double add(double a1, double a2)
    {
      return a1 + a2;
    }

    ////////////////////////////////////////////////////////////////////////
    // main
    //
    int main(int argc, char* argv[])
    {
      try
      {
        // initialize logging - this reads the file log.xml from the current directory
        log_init();

        // read the command line options

        // option -i <ip-address> defines the ip address of the interface, where the
        // server waits for connections. Default is empty, which tells the server to
        // listen on all local interfaces
        cxxtools::Arg<std::string> ip(argc, argv, 'i');

        // option -p <number> specifies the port, where jsonrpc requests are expected.
        // The default port is 7004 here.
        cxxtools::Arg<unsigned short> port(argc, argv, 'p', 7004);

        // create an event loop
        cxxtools::EventLoop loop;

        ////////////////////////////////////////////////////////////////////////
        // Json rpc

        // for the json rpc server we define a json server
        cxxtools::json::RpcServer jsonServer(loop, ip, port);

        // and register the functions in the server
        jsonServer.registerFunction("echo", echo);
        jsonServer.registerFunction("add", add);

        ////////////////////////////////////////////////////////////////////////
        // Run

        // now start the servers by running the event loop
        loop.run();
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what() << std::endl;
      }
    }

The client is even easier. We want to use the *add* function from our
application server to add 2 numbers.

    #include <iostream>
    #include <cxxtools/arg.h>
    #include <cxxtools/remoteprocedure.h>
    #include <cxxtools/json/rpcclient.h>

    ////////////////////////////////////////////////////////////////////////
    // main
    //
    int main(int argc, char* argv[])
    {
      try
      {
        log_init();

        cxxtools::Arg<std::string> ip(argc, argv, 'i');
        cxxtools::Arg<unsigned short> port(argc, argv, 'p', 7004);

        // and a json rpc client
        cxxtools::json::RpcClient client(ip, port);

        // Define remote procedure with dobule return value and a 2 double
        // parameters.
        cxxtools::RemoteProcedure<double, double, double> add(client, "add");

        // and now call the remote function
        double result = add(1.609, 42.195);

        std::cout << result << std::endl;
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what() << std::endl;
      }
    }

Both programs must be linked against `cxxtools` and `cxxtools-json`:

    g++ -lcxxtools -lcxxtools-json -o myprogram myprogram.cpp

Features
--------

* Easy to use RPC (XML-RPC, JSON-RPC, binary-RPC)
* Serialization framework (XML, JSON, CSV, Properties, binary)
* Asynchronous I/O with performant signal/slot mechanismus
* Logging
* Unicode support
* Multithreading, atomic operationen
* Timer
* Date, time, datetime, timestamp
* MD5/HMAC/Base64/uuencode
* String utility function (join, split)
* Unit testing framework
* File handling (directory, file attribut query)
* Hexdumper
* Policy based smart pointer (default: intrusive ref counted)

Further reading
---------------

To learn more about Cxxtools read [the Cxxtools howto's](howto.html)

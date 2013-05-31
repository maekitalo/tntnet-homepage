## Basics

### Is tntnet stable?
Tntnet has been in active development since 2003. Code quality is one of the main things, which was held in mind when tntnet was developed. It was used in several commercial applications with high demand for stability.

### Who uses tntnet?

Unfortunately there is no long list of known users of tntnet. We hope to get more users in the future.

Just to name some, here is a short list:

  * http://www.hotspotcenter.de/
  * http://www.vdr-wiki.de/wiki/index.php/Live-plugin
  * http://www.openzim.org/

### Is tntnet fast?

Tntnet applications are compiled into native code at compile time. So they run with a minimum overhead with the fastest possible speed.

Tntnet itself is multithreaded, so that requests are processed in parallel. It is also highly optimized for speed. Benchmarks has shown its excellent performance.

### Why do you use a template language instead of a servlet like interface?

When a web developer designs web sites, he writes html code. The task of the application developer in the tntnet world is to add application logic into the web pages. That is easily done by just adding the program logic using ecpp tags. There is no need to translate the actual html code produced from the designer into long lists of print statements or similar.

### Do I need to recompile, when I change the content of my web site?

You need to recompile only if your application logic changes but not the content. Take for example a image browser. It may read images from the file system or a database. If you add images, the application will be able to serve the new images without recompile or restart. But if you change the navigation logic, you need to recompile your application. This should not happen that often.

### Can tntnet serve static pages?

Tntnet has a standard component called static@tntnet, which can serve static pages.

### I changed by web application but the changes do not come through until I restart tntnet. Is there a way to do that?

No. You must really recompile and restart your tntnet application server. There are no plans to add logic to tntnet to handle something like a hot swap.

There are good technical reasons, why it is not possible to do that safely. Tntnet can't know, if applications still reference code, held in the original library and if you change the binary representation of your library, you do really have to delete your existing classes.

### I would like to separate my application logic from the presentation layer. Is that possible with tntnet?

It is not only possible, but you should really do that.

You can use #include in tntnet applications to import you application logic classes into your ecpp template. There are only few lines of glue code needed to access your application logic in the ecpp template.

### Can I reuse my existing C++ code?

Of course you can. It is just easy to “web enable” existing C++ code. That's one of the great things about tntnet, that you can just reuse your existing code. There are so many C++-applications out there, which use other languages to add a web interface to the application. This leads to the problem, how to transfer the data into the other world.

With tntnet you can just use the existing C++ classes in the web application. No rewrite or interfacing is needed.

### Does tntnet support databases?

Tntnet does not support databases. It does not need to, since you can use existing C++ classes and libraries. We suggest to look at tntdb, which is a easy to use database abstraction layer.

### JSP/Perl/PHP/Ruby/whatever is better than tntnet.

Well, go with it. If it fits better into your application it is perfectly OK to use that. Tntnet do not want to replace every existing web technology but offer only another alternative. We think, tntnet has to offer unique features and there are plenty of use cases, where tntnet will be the best choice.

### Does tntnet run under Windows?

No. Tntnet do not run under windows. Until now nobody was willing to port tntnet to windows. But if you really want to have it, you can volunteer.

### Does tntnet run under other operating systems?

Tntnet run under posix compatible systems. I know applications running under various kinds of linux, open-BSD, AIX and Solaris.

## C++

### Why C++?

C++ is a great programming language with very sophisticated features. It is just great to use a programming language with such rich features in web development.

### C++ programs have often buffer overflows and memory leaks. How that fit into web development?

The programming language, which is sensitive to buffer overflows and memory leaks is called C. C++ is a different kind. If C++ is used correctly, you do not have to bother much about buffer overflows and memory leaks.

To prevent buffer overflows, use e.g. std::string instead of a fixed size character array.

To prevent memory leaks, avoid pointers. Prefer stack objects. Or take care, that you have you destruction code in a destructor. Put every object in some suitable scope.

And most important: learn C++. Read good books about C++.

### C++ is dead. Nobody uses C++ any more. Why should I bother?

When you read this, it is very presumable, that you sit in front of a program, written in C++. Most of the applications we use in our day to day work are written in C++. The problem is, that C++ programs do not tell, that they are written in C++. They do not need to install a C++ run time engine to run C++ applications. C++ programs also look just as programs should look like.

## Infrastructure

### How many developers tntnet has?

Almost all of tntnet was developed by a single person - Tommi Mäkitalo.

Normally you should really think if you really want to trust a application written and maintained by a single person.

A single person assures, that you have the same code quality all over the system. Also since tntnet is open source, you can really verify the code quality and if some day Tommi is gone or has lost his interest in tntnet, you have the source of tntnet.

### Why www.tntnet.org is not running tntnet?

This is not any more the case - www.tntnet.org runs with tntnet since in
December 2012. It was not possible before since we did not have the
infrastructure.

Now we have a shiny new homepage with modern design and architecture running
tntnet. The software, which runs the homepage can be found at github as well. It
is also a showcase for using tntnet as a web server with dynamic content.

### Can I use tntnet in commercial applications?

Tntnet is licensed under the LGPL with a template exception. This makes it possible to use tntnet in commercial closed source applications.

### Do I need to publish my source code, when I use tntnet in my application?

Most web applications are written in interpreted languages like PHP, Ruby, Python or Perl, where the source is the application itself. So it is technologically necessary to deliver the source for your uses. That is not the case with tntnet. Tntnet applications are compiled into binary code and the source is not needed at run time. This makes it possible to deliver your application binary only. And the LGPL allows you to do that also.

## Development

### After adding tntdb (or something else) to my tntnet application, the page is not loaded any more. What can I do?

Most probably there are unresolved external symbols. Maybe you forgot to link the application against tntdb. Not that you can link a shared library without error messages although there are unresolved symbols.

Try "ldd -r myapplication.so". This checks for unresolved symbols. If you get an error message, you also get a hint, what may be missing


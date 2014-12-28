<a name="top"></a>
Frequently Asked Questions (FAQ)
================================

Updated January 2015

- - -

* [1 - Introduction](#introduction)
 * [1.1 - What is Tntnet?](#introduction-1)
 * [1.2 - What are the goals of Tntnet?](#introduction-2)
 * [1.3 - How is Tntnet licensed?](#introduction-3)
 * [1.4 - How does Tntnet work?](#introduction-4)
 * [1.5 - Which operating systems does Tntnet run on?](#introduction-5)
 * [1.6 - Does tntnet run under Windows?](#introduction-6)
 * [1.7 - Who developed Tntnet?](#introduction-7)
 * [1.8 - When should I use Tntnet?](#introduction-8)
 * [1.9 - Where can I get Tntnet?](#introduction-9)

* [2 - Development](#development)
 * [2.1 - What are the first steps?](#development-1)
 * [2.2 - Where do I find the documentation?](#development-2)
 * [2.3 - Where do I find an example application?](#development-3)
 * [2.4 - Why does Tntnet use a template engine?](#development-4)
 * [2.5 - Can I reuse my existing C++ code?](#development-5)

* [3 - Contributing](#contributing)
 * [3.1 - How can I contribute?](#contributing-1)
 * [3.2 - Where can I find the source code?](#contributing-2)
 * [3.3 - How do I report a bug or submit a patch?](#contributing-3)
 * [3.4 - I'm a package maintainer, what do i need to know?](#contributing-4)

- - -

<a name="introduction"></a>
1 - Introduction
----------------

<a name="introduction-1"></a>
## 1.1 - What is Tntnet?

Tntnet is a [web application framework](http://en.wikipedia.org/wiki/Web_application_framework) for C++.

Here a short overview:

- [Tntnet](tntnet.html) represents the base function for [web application server](http://en.wikipedia.org/wiki/Comparison_of_application_servers),  [web template system](http://en.wikipedia.org/wiki/Web_template_system). It can be used as application server or as a standalone application.

- [Cxxtools](cxxtools.html) is a C++ library providing basic and advanced system and network functionalities.

- [Tntdb](tntdb.html) is C++ library which makes it really easy and safe to access SQL database systems.

[back to top](#top)

<a name="introduction-2"></a>
## 1.2 - What are the goals of Tntnet?

The goal is to provide an easy and convenient way to create web applications in C++ by embedding the code into HTML. With Tntnet web applications can be structured as desired. Tntnet is *policy free*, i.e. it lets developers the freedom to structure their applications as needed. Our components use ISO standards and are developed according to POSIX guidelines. This offers *investment protection*, i.e. a secure and reliable basis. Another important goal is stability of the API: Tntnet is already deployed in several commercial applications with high demand for stability. Thus good code quality is also essential for Tntnet's development.

[back to top](#top)

<a name="introduction-3"></a>
## 1.3 - How is Tntnet licensed?

Tntnet is licensed under the Lesser General Public Licence (LGPL) with a template extension. It can be used in both open source and closed source scenarios. For more information please read the [License information](license.html).

[back to top](#top)

<a name="introduction-4"></a>
## 1.4 - How does Tntnet work?

The first program from Tntnet that is called when building a web app is the ecpp compiler (ecppc), which compiles your ecpp pages into C++ classes. These are then compiled into native code using a C++ compiler. This code can either reside in a shared library (.so) or in an own executable linked against libtntnet (for details, see the [quick start guide](quick-start-guide.html)). Tntnet does not require to use a specific C++ compiler, you can use the compiler which fits best to your needs. Tntnet itself is multithreaded, so that requests are processed in parallel. It is highly optimized for speed. Benchmarks have shown its excellent performance.

[back to top](#top)

<a name="introduction-5"></a>
## 1.5 - Which operating systems does Tntnet run on?

Tntnet is usable in all POSIX compliant systems. It is known to work on various GNU/Linux distributions and BSD derivatives, as well as on AIX and Solaris.

[back to top](#top)

<a name="introduction-6"></a>
## 1.6 - Does tntnet run under Windows?

No. Tntnet do not run under Windows. Until now nobody was willing to port tntnet to Windows. If someone want to port it to Windows, we'll love to support it.

[back to top](#top)

<a name="introduction-7"></a>
## 1.7 - Who developed Tntnet?

Tntnet is developed and maintained by Tommi Mäkitalo, the main developer and some contributors under open source development rules.

[back to top](#top)

<a name="introduction-8"></a>
## 1.8 - When should I use Tntnet?

If your web application/service needs:

* Good scalability with high performance
* High security standards
* Integration into existing C++ applications
* Closed source
* Low CPU performance like embedded systems

[back to top](#top)

<a name="introduction-9"></a>
## 1.9 - Where can I get Tntnet?

Currently there are three ways to get Tntnet and its components.

1. Through the package manager in your operating system
2. Through the [download page](download.html)
3. Through [GitHub](https://github.com/maekitalo/tntnet), mainly if you want to have to absolutely latest version

**Note:** For productive use the best option is **1**, but you should fall back to **2** if those packages are outdated.

[back to top](#top)

<a name="development"></a>
2 - Development
---------------

<a name="development-1"></a>
## 2.1 - What are the first steps?

The  [Quick Start Guide](quick-start-guide.html) includes everything you need to get started. If you have any further questions, we are available via mailing list and IRC (details can be found on the [contact  page](contact.html)).

[back to top](#top)

<a name="development-2"></a>
## 2.2 - Where do I find the documentation?

We have howto's, an API  documentation, man pages and a quick start guide. It can be found on our homepage and in the source code.

[back to top](#top)

<a name="development-3"></a>
## 2.3 - Where do I find an example application?

There are many small demos available on [GitHub](https://github.com/maekitalo/tntnet/tree/master/demo/).
This website serves as an example too, you can find its source code on GitHub as well: [maekitalo/tntnet-homepage](https://github.com/maekitalo/tntnet-homepage)

[back to top](#top)

<a name="development-4"></a>
## 2.4 - Why does Tntnet use a template engine?

When  a web developer designs web sites, he writes HTML code. The task of the application developer in the Tntnet world is to add application logic to the web pages. That is easily done by just adding the program logic using ecpp tags. There is no need to translate the actual html code produced from the designer into long lists of print statements or similar. You can use `#include` in Tntnet applications to import you application logic classes into your ecpp template. There are only few lines of glue code needed to access your application logic in the ecpp template.

[back to top](#top)

<a name="development-5"></a>
## 2.5 - Can I reuse my existing C++ code?

Of  course you can. It is just easy to "web enable" existing C++ code.  Thats one of the great things about Tntnet, that you can just reuse your existing code. There are so many C++ applications out there, which use other languages to add a web interface to the application. This leads to the problem, how to transfer the data into the other world. With Tntnet you can just use the existing C++ classes in the web application. No rewrite or interfacing is needed.

[back to top](#top)

<a name="contributing"></a>
3 - Contributing
----------------

<a name="contributing-1"></a>
## 3.1 - How can I contribute?

We appreciate all efforts to improve Tntnet itself or any other part of this project.

You can help in several ways:

* If you find a bug, [report it](#contributing-3)
* Give general feedback or submit ideas [via IRC or email](contact.html)
* If you are a developer and like Tntnet, it would be great if you just told others about it!

[back to top](#top)

<a name="contributing-2"></a>
## 3.2 - Where can I find the source code?

The source code is available on GitHub. Links to all repositories can be found on the [development](development.html) page.

**Note:** In 2013 we moved the source code from SourceForge to GitHub. Don't use the code from SourceForge, it is outdated!

[back to top](#top)

<a name="contributing-3"></a>
## 3.3 - How do I report a bug or submit a patch?

You can write an email to the main developer directly or use the mailing list, see the [contact](contact.html) page.

[back to top](#top)

<a name="contributing-4"></a>
## 3.4 - I'm a package maintainer, what do i need to know?

We use GNU autotools for a build system and we develop according to the POSIX standards.
Cxxtools and tntdb are shared libraries and are treated as such. Tntnet needs cxxtools as a requirement. 
Tntnet itself can be used as a shared libraries and as a runtime environment like JavaServer Pages (JSP). 
Therefore, it is important to distinguish between a development platform and hosting (deployment) platform.

Typical structure of packages:

cxxtools:
- Include
- Develop
- Demos

tntnet:
- Runtime
- Include
- Develop
- Demos

tntdb:
- Include
- Develop
- Demos

Tntdb requires a database (Oracle, SQLite, MySQL, Postgres) and can be configured for one specific database, e.g.: tntdb-sqlite, to avoid having all those databases installed.

**Note:** GNU/TLS, OpenSSL will be enabled in the source tarball configurations as standard.

[back to top](#top)

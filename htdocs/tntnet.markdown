Tntnet
======

Tntnet is a web server which allows users to develop web applications using C++.
It has a template language *ecpp* where C++ code can be embedded into html
similar to php or jsp. The pages are compiled and linked into a shared library.
The result is a native web application which is compact and fast.

Example
-------

This example shows a little web form and processes the input of that by adding
or subtracting a value to a session variable.

    <%args>
    // define variables which are filled from the form

    double value = 0;  // default value is 0
    bool add;
    bool sub;
    </%args>
    <%session>
    // define a session variable of type double with a initial value of 0
    double currentValue = 0;
    </%session>
    <%cpp>

      if (add)
        currentValue += value;
      if (sub)
        currentValue -= value;

    </%cpp>
    <!DOCTYPE html>
    <html>
     <head>
      <title>Tntnet accumulator</title>
     </head>
     <body>
      <h1>Accumulator</h1>
      <# this prints the session variable into the screen
         (and btw: this is a comment) #>
      The current value is <$ currentValue $>.
      <form method='post'>
       <input type='number' name='value' value='<$ value $>'><br>

       <input type='submit' name='add' value='add value'>
       <input type='submit' name='sub' value='subtract value'><br>
      </form>
     </body>
    </html>

Features
--------

* Template engine for HTML
* SSL support
* Url mapping
* API for http, http upload, authentifikation,
* Setting for http headers and cookies
* Automatical session management

Further reading
---------------

To learn more about Tntnet read [the Tntnet man pages](man.html)

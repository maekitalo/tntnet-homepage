Tntdb
=====

Tntdb is a C++ library which makes accessing SQL databases easy and robust.
Just a few lines of code is enough to connect to the database and accessing
data.

Tntdb has drivers for *postgresql*, *sqlite3*, *mysql* and
*oracle*.

Resources are handled automatically. The developer can't forget to free
resources like disconnecting from the database. All objects used in tntdb are
internally reference counted so that copying around objects is cheap and
easy.

Prepared statements are fully supported to prevent problems with SQL
injection. Where prepared statements are not supported by the database, tntdb
emulates the use.

Tntdb is thread safe and supports connection pooling and caches prepared
statements for best performance.

Errors are handles by throwing exceptions, which makes developing robust
database applications a no brainer.

To learn more about tntdb read [the tntdb howto](howto/tntdb.html)

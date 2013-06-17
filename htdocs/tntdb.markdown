Tntdb
=====

Tntdb is a C++ library which makes accessing SQL databases easy and robust.
Just a few lines of code is enough to connect to the database and accessing
data.

Tntdb has drivers for *postgresql*, *sqlite3*, *mysql* and *oracle*. A special
*replication* driver writes data to multiple databases and read from one. It is
some kind of 'poor mans database replication'.

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

Example
-------

To read data from a database just a few lines of code is needed. We assume a
wiki database table *pages* with the columns *id* as a integer, *title* as text
and a timestamp field *ts*. Lets read all data where the timestamp is later than
2013-05-01. and print the table to *std::cout*. The database is *postgresql* but
may well be one the other databases by just replacing the database url passed to
the *tntdb::connect* function.

    void printPages()
    {
      // We need a connection
      tntdb::Connection conn = tntdb::connect("postgresql:dbname=mydb");

      // ... and prepare a statement on that
      tntdb::Statement sel = conn.prepare(
        "select id, title, ts"
        "  from pages"
        " where ts >= :ts");

      // Set the one input variable
      sel.set("ts", tntdb::Date(2013, 5, 1));

      // Now read the data by iterating through the statement
      // The call to sel.begin() actually executes the query
      for (tntdb::Statement::const_iterator it = sel.begin();
        it != sel.end(); ++it)
      {
        tntdb::Row r = *it;  // dereferencing the iterator gives us a result row

        int id;              // define variables for each column
        std::string title;
        tntdb::Date ts;

        r[0].get(id);     // get is overloaded for different types
        r[1].get(title);
        r[2].get(ts);

        // print the data out
        std::cout << id << '\t' << title << '\t' << ts.getIso() << std::endl;
      }
    }

If anything gets wrong there, a exception of type *tntdb::Error* is thrown.

Further reading
---------------

To learn more about tntdb read [the tntdb howto](howto/tntdb.html)

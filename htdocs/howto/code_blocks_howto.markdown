Using Code::Blocks as IDE for Tntnet
====================================

*Carsten Arnholm*

*Updated, January 2014*

Introduction
------------
In this tutorial, we explain the basics of using the Code::Blocks as the IDE (Integrated Development Environment) for projects using Tntnet.


Why not simply use makefiles?
-----------------------------
If you are used to using makefiles and don't see the need for anything else, this tutorial is not for you, you may stop reading here. But if you think makefiles are difficult to understand and use, you may find this information useful.


What is Code::Blocks?
---------------------
In its own words, Code::Blocks is "a free C, C++ and Fortran IDE built to meet the most demanding needs of its users. It is designed to be very extensible and fully configurable". It has special support for developing GUI applications using wxWidgets <http://www.wxwidgets.org/>, but the IDE is completely general and well suited for Tntnet work. You can download C::B from <http://www.codeblocks.org/>. Precompiled binaries for many platforms are available (recommended) and the complete source code is available also.

Like most IDE's, C::B allows you to create projects containing your source files. It has a nice editor and project browser, and it provides an intuitive build system that eliminates the need for makefiles. You set up the include paths and libraries to link your application, and simply build and run. Also very important is the integrated GUI debugger.

<img src="cb/cb_main.png" title="Code::Blocks main window" width="700" />

Especially useful are the so called "global variables". They are mostly used for defining the location of 3rd party components. This way, the project files become extremely portable and easy to share, because there is no need to put hard coded paths into the project files. Read more about C::B global variables in the [C::B Wiki][cbwgv]. There is also an active [User Forum][cbforum] with a lot of useful information on most aspects of C::B use.

   [cbwgv]: http://wiki.codeblocks.org/index.php?title=Global_compiler_variables
   [cbforum]: http://forums.codeblocks.org/


Getting Started
===============

After installing C::B, read the documentation and become familiar with how to build applications. For Tntnet, you can use the Project Wizard to set up your project. The wizard is available via
  
    File -> New -> Project ...

There are many project types to choose from, but for use with Tntnet, it is mostly the "Console application" and "Shared Library" projects that are of interest. Here, we show a Console application example, so select "Console application" and press the "Go" button: 
<img src="cb/cb_wizard.png" title="Creating a console application" width="700" />

Make sure to select C++ as the project language:
<img src="cb/cb_wizard_con1.png" title="Select C++ as project programming language"" width="700" />

Give the project a name and define the project location. Observe that the project is being generated in a subfolder with the same name as the project. The project file is found in this folder and has file type .cbp (Code::Blocks Project). The .cbp file is in XML format. It is updated using the Code::Blocks GUI, but it is also easy to modify using a simple text editor, if needed.
<img src="cb/cb_wizard_con2.png" title="Project name and location" width="700" />

Choose a compiler for C++ (Code::Blocks may be used with many different compilers). For Linux, GNU GCC is the default and the obvious choice. When complete, press the "Finish" button.
<img src="cb/cb_wizard_con3.png" title="Select the project programming language" width="700" />

The result is a project with a main.cpp file, containing the familiar "Hello World". 

<img src="cb/cb_wizard_con4.png" title="Hello world sample generated" width="700" />

To run it, choose 

    Build -> Build and run ...
    
The output is shown in a small X-terminal window. You may also run it from a standard command shell, of course. 

Using Tntnet in the application
-------------------------------

We then modify the code to include Tntnet header files and call Tntnet code, much like in the "Creating a standalone web application" on the Tntnet quick starter guide.

If Tntnet was installed in the standard way, the header files will be found automatically under /usr/local/include, and Tntnet libraries will be found under /usr/local/lib, but you may also find it useful to define for example a TNTNET global variable in the Code::Blocks IDE and refer to the .include and .lib paths explicitely in the project.

Once this modification is done, try to build and run again, as before. Typically, you will see that the build fails:

<img src="cb/cb_build_error.png" title="Build error" width="700" />

The reason for the error is that we have not added a reference to the tntnet and cxxtools libraries in our project. This is therefore our next step, select 

    Project -> Build Options ...
    
Select first the "Tntnet_hello" project name in the left pane, to make the settings valid for both Release and Debug build targets. Alternatively, select the required build target and set the specific settings on them individually.

Next, choose the "Linker Settings" tab, and add tntnet and cxxtools libraries.

<img src="cb/cb_link_libraries.png" title="Configuring Tntnet ecpp support in Code::Blocks" width="700" />

The application now compiles, links and runs successfully as a stand alone Tntnet web application, except that it doesn't actually do anything else but listen to the designated port.


Adding ecpp support to Code::blocks
-----------------------------------

The ecppc compiler and .ecpp files are specific to tntnet, so Code::Blocks has no intrinsic knowledge of the compiler or such files. Before you can use ecpp files and the associated compiler, you have to teach Code::Blocks what they are and how things should work. This step is slightly advanced, so take your time and make sure to do it exactly as shown below. First, select the menu item

    Settings -> Compiler ...
    
make sure "Global Compiler Settings" is chosen in the left pane. Then click the arrow to the right of the tabs and move all the way to the end, until you see the other "Other Settings" tab. Select it. At bottom right, press "Advanced Options..." button:

<img src="cb/cb_compiler_other_settings.png" title="Configuring Tntnet ecpp support in Code::Blocks" width="700" />

Confirm that you want to proceed, and you will soon see the dialog below. Please edit the items in the order indicated, exactly as shown. When complete, finish by pressing the "OK" button. 

<img src="cb/cb_ecpp.png" title="Configuring Tntnet ecpp support in Code::Blocks" width="700" />

You have now told Code::Blocks that files ending with file extension .ecpp shall be compiled by the ecppc compiler found in /usr/local/bin and the output shall be stored in same folder and using same name as the original .ecpp file, but using a file extension .cpp. After completing the generation of the .cpp file, Code::Blocks is instructed to compile the resulting .cpp file using the ordinary C++ compiler.


Adding ecpp files to a C::B project
-----------------------------------

There are a couple of ways you can do it. One way is to use tntnet-config and generate some .ecpp files and copy them to the C::B project folder. Then use 
    
    Project -> Add files ...
    
To add the .ecpp files. Another way is to use 

    File -> New -> Empty File ... 
    
Answer yes to add the file to the project, and then save the file as an .ecpp file with a useful name. Add the ecpp tags in the file manually to create the code.

Note: Once the .ecpp files have been added to the project it is recommended to always close the project and reopen it before you do anything else. 

You can now edit the files and build as normal. You will find that the generated .cpp files become visible in the project. Remember to never edit these files, edit only the original .ecpp files! If you remove the .ecpp files from the project, the .cpp files are automatically removed also.


Concluding remarks
------------------

The Code::Blocks IDE is very capable and can be configured to support Tntnet in a useful and practical manner, eliminating the need for makefiles, and providing an integrated editing, build and debugging environment for Tntnet projects.


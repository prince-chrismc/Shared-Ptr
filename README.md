<h1 align="center">Shared-Ptr</h1>
<p align="center">An analysis of modern C++ std::shared_ptr</p>
<p align="center"><img src ="https://github.com/prince-chrismc/Shared-Ptr/blob/master/Docs/Images/shared_ptr_diagram.png" /></p>

## Goal of this project
Working full time as a software developper I face the envitable challenge of working with legacy code; code that existed before I even statered programming, before I was even born. A side affect of this is my peers often have little to no experience using modern C++. This has blown up in our faces. In preperation of the SDK release we realized the usage of `std::shared_ptr` was a crippiling factor breaking a fundamental interprocess library ( which I originally wrote a few years back ).

This repository aim to outline the basics of `std::shared_ptr` primarily in C++17, working to a more real world application, and highlighting the differences that came over time.

#### Attributes
* [ISO CPP CORE](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-resource)
* [CPP Reference](http://en.cppreference.com/w/cpp/memory/shared_ptr)
* [MSDN Guide](https://msdn.microsoft.com/en-us/library/hh279669.aspx)
* [CPP Reference](http://en.cppreference.com/w/cpp/memory/enable_shared_from_this)

#### Inspiration
* [blog 1](https://www.bfilipek.com/2013/02/smart-pointers-gotchas.html)
* [blog 2](https://herbsutter.com/2012/06/05/gotw-105-smart-pointers-part-3-difficulty-710/)

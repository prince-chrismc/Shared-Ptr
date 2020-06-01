<h1 align="center">Shared-Ptr</h1>
<p align="center">An brief note on C++ std::shared_ptr</p>
<p align="center"><img src ="https://github.com/prince-chrismc/Shared-Ptr/blob/master/Docs/Images/shared_ptr_diagram.png" /></p>

### Goal of this project
Having worked for several years with c++98 to C++03 era code at work, it's finally around the corner that we will be able to develop our SDK using _modern C++_. This comes with many advantages however one very big issue is not everyone has expereience using a more modern approach and this knowledge gap can limit the quality of the product. In and attempt to correct this, I have revived this project in order to have some [simple guidence](Introdution.md) for those who are new to C++11's managed pointers.

### Executive Summary
- [ ] Fill in summary...

###### Default Advice
> I just want to look at the object... (const)
- `const T&` will be your friend, use the underlying type as if it were no a shared pointer
> I want to manipulate the object being pointed to in my function...
- `T*` if you arent sharing in the ownership ( ie keeping a copy ) and you are working down a callstack go back to basics and use a raw pointer; it saves the overhead and complexity of using a shared putter.
> I also want to use the object in a seperate thread...
- `shared_ptr<T>` pass-by value will most likely what you need if both threads will use the object. 
> I created my object with `std::make_shared` and I want to store it in my container...
- `shared_ptr<T>&&` is the optimal solution; it avoids the atomic ( aka slow ) increment/decrement of the ref counter. However move sematics are an optimization and pass-by value `T` will be more then sufficient.

##### Attributes
* [ISO CPP CORE](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-resource)
* [CPP Reference](http://en.cppreference.com/w/cpp/memory/shared_ptr)
* [MSDN Guide](https://msdn.microsoft.com/en-us/library/hh279669.aspx)
* [CPP Reference](http://en.cppreference.com/w/cpp/memory/enable_shared_from_this)
* [atomic performance](https://stackoverflow.com/a/41874953/8480874)

##### Inspiration
* [blog 1](https://www.bfilipek.com/2013/02/smart-pointers-gotchas.html)
* [blog 2](https://herbsutter.com/2012/06/05/gotw-105-smart-pointers-part-3-difficulty-710/)
* [stackoverflow](https://stackoverflow.com/a/77893/8480874)
* [Great References](https://stackoverflow.com/a/8741626/8480874)

##### Similar Guides
* [Easy Read](https://github.com/CodesBay/CplusPlus_SmartPointer)
* [Updated examination](https://www.internalpointers.com/post/move-smart-pointers-and-out-functions-modern-c)

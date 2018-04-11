# Introduction
What are pointers?

### Table of Contents
1. C++03 and raw pointers
2. Shared Pointer

## C++03's Raw Pointer
Pointers in C++ are memory localations restricted by a type. Seen as `int* counters;` 

## Shared Pointers
`std::shared_ptr<T>` are wonderful tools when used correctly, but firstly waht are they comprised of and how do they work?

Shared pointers are comprised of two componets, an object pointer and a control block. The control block consists on the following:
- managed object (in-place or as a pointer depending on instantiation)
- allocator
- deletor
- shared ref count
- weak ref count
 **NOTE**: When instatiated with `std::make_shared` or `std::allocate` the object is a member of the control block whereas with the constructors of a shared pointer it is a pointer to the object given.
 

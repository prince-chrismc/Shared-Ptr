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
- weak ref count // TODO: explain what are weak ptrs

 **NOTE**: When instatiated with `std::make_shared` or `std::allocate` the object is a member of the control block whereas with the constructors of a shared pointer it is a pointer to the object given.
 
<p align="center"><img src ="https://github.com/prince-chrismc/Shared-Ptr/blob/master/Docs/Images/shared_ptr_diagram.png" /></p>
 
#### Pseudo Implementations
Note the actual compiler implementatsions may vary but this provides a visual to how they may work.

###### From `make_shared()`
```c++
template type Object
class shared_ptr<Object>
{
 private:
    Object obj;
    Controlllock cblk;
};
```

###### From `shared_ptr` ctor
```c++
template type Object
class shared_ptr<Object>
{
public:
    shared_ptr(void* raw)
    {
        obj = dynamic_cast<Obj>(raw);
    }
    
private:
    Object* obj;
    Controlllock cblk;
};
```

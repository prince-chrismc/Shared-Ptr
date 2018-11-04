# Implementation-Details

### Table of Contents
1. [Pseudo Implementations](#Pseudo-Implementations)
2. [Known Issues](#Known-Issues-(-2010-))

### Pseudo Implementations
Note the actual compiler implementatsions may vary but this provides a visual to how they may work.

###### From `make_shared()`
```c++
template<class Object>
class shared_ptr<Object>
{
 private:
    Object obj;
    Controlblock cblk;
};
```

###### From `shared_ptr` ctor
```c++
template<class Object>
class shared_ptr<Object>
{
public:
    shared_ptr(void* raw)
    {
        obj = dynamic_cast<Object>(raw);
    }
    
private:
    Object* obj;
    Controlblock cblk;
};
```

### Known Issues ( 2010 )
Issues with shared_ptr in MCVS2010
* double control blocks with make_shared + enable_shared_from_this - [ref](http://en.cppreference.com/w/cpp/memory/enable_shared_from_this)
>[A shared pointer] holds a weak reference to `this`. Constructing a std::shared_ptr for an object that is already managed by another std::shared_ptr will not consult the internally stored weak reference and thus will lead to undefined behavior.

* different control block when duplicating shared_ptr of raw [ref]

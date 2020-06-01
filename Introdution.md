# Introduction
What are the various types of pointers?

#### To Do
- [ ] explain weak ptrs
- [ ] default advice
- [ ] dynamic pointer cast

### Table of Contents
1. [C++03 and raw pointers](Raw-Pointer)
2. [Shared Pointer Introduction](Shared-Pointers)

## Raw Pointer
Pointers in C++ are memory localations restricted by a type. Seen as `Type* object;` They are usually allocated/released blocks of memory; done using `new`, `delete` and/or `delete[]`. Memory mangement can become crucuial to application performance. Lack of understanding or unfamiliarity with best-practices can introduce runtime failures either through `NULL` pointers or read/write access violation ( accessing memory which has been freed ).

It was the only way for a very long done. The most challenging scenario in highly object-oriented deisgn is when an elemented is 'owned' but multiple instances.

Here's a smaple `C` program...
> I choose a `C` program because there are far more ways with objects ( non-virtual dtor or polymorphism ), exceptions, etc... That making an example to show common mistakes would be too long and not add clarity to this guide.

```c
struct toyMouse
{
   float weight;
};

struct cat
{
  int legs;
  struct toyMouse* toy;
};

void catPlaysWithToy( struct cat* cat, struct toyMouse* mouse)
{
    cat->toy = mouse;
    
    if(cat->legs == 4)
    {
        // plays with mouse
    }
    else
    {
        // plays with mouse
    }
    
    free(mouse);
}

float catLosesMouse( struct cat* cat )
{
    float mouseWeight = cat->toy->weight;
    
    cat->toy = 0;
    
    return mouseWeight;
}

int main()
{
   
   struct toyMouse mouse;
   mouse.weight = 14;
      
   struct cat* Teddy = malloc(sizeof(struct cat));
   Teddy->legs = 4;
   
   struct cat Daisy;
   Daisy.legs = 3;
   
   catPlaysWithToy( &Daisy, &mouse );
   
   // A litte later...
   
   catPlaysWithToy( &Teddy, &mouse );
   catLosesMouse( &Teddy );
   
   Teddy = malloc(sizeof(struct cat));
   
    return -1;
}
```

I managed to squeeze every kind of problem in one small snippet! Mistakes:
- calling `free()` on local variable
- calling `free()` on the same memory twice
- access memory which has been `free()`
- changing pointers adress without freeing original memory

It's _very easy_ to make these kinds of mistakes. 

In this example both `cat`s have ownership of the sam `toyMouse` and when ever they are done playing with it they disgard ( or in our case `free` ) the toy. This however doesn't account for the other `catPlaysWithToy()` later on; who will enveitably get board of the mouse and `free` it as well.

## Shared Pointers
`std::shared_ptr<T>` are wonderful tools when used correctly, but firstly waht are they comprised of and how do they work?

Shared pointers are comprised of two componets, an object pointer and a control block. The control block consists on the following:
- managed object (in-place or as a pointer depending on instantiation)
- allocator
- deletor
- shared ref count
- weak ref count

 **NOTE**: When instatiated with `std::make_shared` or `std::allocate` the object is a member of the control block whereas with the constructors of a shared pointer it is a pointer to the object given.
 
<p align="center"><img src ="https://github.com/prince-chrismc/Shared-Ptr/blob/master/Docs/Images/shared_ptr_diagram.png" /></p>

why to pass-by value...

You will want your second thread to have a copy of the reference to the object. Both threads will partage in the life cycle of the object. This avoids handling `nullptr`s and who delete's the object and when. How will they synchronize... etc...
 

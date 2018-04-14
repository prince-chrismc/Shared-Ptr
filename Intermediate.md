# Intermediate

Issues with shared_ptr in MCVS2010
* double control blocks with make_shared + enable_shared_from_this - [ref](http://en.cppreference.com/w/cpp/memory/enable_shared_from_this)
>... hold a weak reference to `this`. Constructing a std::shared_ptr for an object that is already managed by another std::shared_ptr will not consult the internally stored weak reference and thus will lead to undefined behavior.

* different control block when duplicating shared_ptr of raw [ref]

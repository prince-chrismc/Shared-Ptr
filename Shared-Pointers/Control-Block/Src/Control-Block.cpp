/*
MIT License

Copyright (c) 2018 Chris McArthur, prince.chrismc(at)gmail(dot)com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Song.h"
#include <memory>

int main(int argc, char* argv[])
{
   Song* pSong = new Song("Every Programmer", "Hello World");

   {
      std::shared_ptr<Song> ptr1;
      std::shared_ptr<Song> ptr2(new Song("Every Programmer", "Hello World"));
      std::shared_ptr<Song> ptr3(std::make_shared<Song>("Every Programmer", "Hello World"));
   }

   {
      // Doesnt work since its not allocated
      SongEnabled oSong("Every Programmer", "Hello World");
      std::shared_ptr<SongEnabled> ptr = oSong.GetShared();
   }

   {
      std::shared_ptr<SongEnabled> ptr1 = std::make_shared<SongEnabled>("Every Programmer", "Hello World");
      std::shared_ptr<SongEnabled> ptr2 = ptr1->GetShared();
   }

   delete pSong;
   return 0;
}

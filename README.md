# Learning cpp

## Resources

* books
  * accelerated c++ by Andrew Koenig & Barbara E. Moo
* nvim setup
  * [jdhao - setting up neovim for c++ development with lsp](https://jdhao.github.io/2020/11/29/neovim_cpp_dev_setup/)
  * [idie - using (neo)vim for c++ development](https://idie.ru/posts/vim-modern-cpp/)
* opengl
  * [opengl-tutorial.org](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-1-opening-a-window/)
  * [learnopengl.com](https://learnopengl.com/Getting-started/Hello-Window)
  * [freecodecamp - opengl course (YT)](https://www.youtube.com/watch?v=45MIykWJ-C4)

## Notes

```sh 
# finding the right includes
pkg-config --libs glew

# compiling multiple cpp files
g++ file1.cpp file2.cpp -o main && ./main
```

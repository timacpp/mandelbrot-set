# What is Mandelbrot set?

It's a set of all possible **complex** values of some number c, such that for function f described as

<p align="center">
  f(z) = z^2 + c
</p>

sequence of consecutive compositions of f(0) stays bounded. Single composition is defined as f(f(0)).

# What's the point?

The set itself represents a **fractal** which is a geometric shape with property of self-similarity. Not only it
is aesthetically pleasing to admire such objects but they are also useful to study for image compression branch.
One can find more information about [fractals](https://en.wikipedia.org/wiki/Fractal)
or [Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set) on our beloved wikipedia.

# How to plot it?

Main problem lies under the idea of checking whether the sequence is bounded. Obviously, we can not compute infinitely many compositions,
therefore we set some bounding number of iterations. Each number inside the set is located within a circle |z| <= 2.
Putting all together, we iterate at most fixed number of times and exclude numbers that have norm greater than 4.

# What is SFML?

**S**imple and **F**ast **M**ultimedia **L**ibary - full naming says everything for itself. [Here](https://www.sfml-dev.org/) you can find detailed
information concerning the library, including handy documentation. Windows installation is covered on their website. As for Linux you directly install package:

<p align="center">
  sudo apt-get install libsfml-dev
</p>

and include it's content to CMake as shown in source code of my CMakeLists.txt.

          

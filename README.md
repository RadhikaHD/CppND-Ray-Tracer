# CppND Ray Tracer

This Computer Graphics Ray Tracer, created using C++, is my submission for the final project of Udacity's C++ Nanodegree program. 
A ray tracer uses a rendering technique where it traces the path of light as pixels in an image frame to generate a final image. It also simulates the 
interaction of the ray of light with the other virtual objects in the scene. Ray tracing has been around for decades and is used to generate realistic visual 
images. However, it is computationally expensive and takes a long time to generate an image. Hence, it is more suitable for applications where still 
computer generated images are used versus applications that need real time rendering of their scenes. 

In this project, I have implemented Path Tracing which is a type of Ray tracing technique. In Ray Tracing, when a single ray of light hits an object, it can 
multiply and generate more rays of light. This increase in the number of rays is exponential and expensive to compute. But path tracing generates only a 
single ray of light which randomly bounces off when it hits an object in the scene. Ultimately, the path tracing algorithm, takes a random sampling of all 
the rays and generates the final image. I consider this a simple implementation of a Ray Tracer and hope to add more features in the future. 
In this submission, I have applied diffuse materials to the objects in the scene and implemented anti-aliasing to make them look smoother. 

I followed Peter Shirley's article Peter Shirley's article ["Ray Tracing in One Weekend"] (https://www.realtimerendering.com/raytracing/Ray%20Tracing%20in%20a%20Weekend.pdf) for 
this project and it definitely took me longer than one weekend to implement this.

## Dependencies

This project depends on the following libraries:

1. The [OpenGL Mathematics library](https://glm.g-truc.net/0.9.9/index.html) (GLM),
a header only C++ library for graphics mathematics.

2. The [lodepng](https://github.com/lvandeve/lodepng) library for writing to
PNG format.

The dependencies **do not** have to be installed manually. lodepng is included
in the source code for the project, and the build process below will automatically
download and include GLM.

## Building

First, clone the project repository and change directory to it:

```
git clone https://github.com/RadhikaHD/CppND-Ray-Tracer
cd CppND-Ray-Tracer
```

Next, build the project using CMake and Make:

```
mkdir build
cd build
cmake ..
make
```

## Running

After building the project, the `RayTracer` executable is found in the `build` folder.
Running the program produces the output file `output.ppm`:

```
./RayTracer
```

The `output.png` file can be viewed using an image viewer.

## Project Specification

### The project demonstrates an understanding of C++ functions and control structures.
https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/master/main.cpp#L31

### The project reads data from a file and process the data, or the program writes data to a file.

### The project uses Object Oriented Programming techniques.

### Classes use appropriate access specifiers for class members.

### Class constructors utilize member initialization lists.

### Classes encapsulate behavior.

### Classes follow an appropriate inheritance hierarchy.

### Derived class functions override virtual base class functions.

### The project makes use of references in function declarations.

### The project uses smart pointers instead of raw pointers.

## License 

This project is licensed under the [MIT License](LICENSE.md) Creative Commons License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Peter Shirley's article ["Ray Tracing in One Weekend"] (https://www.realtimerendering.com/raytracing/Ray%20Tracing%20in%20a%20Weekend.pdf)
* OpenGL Mathematics library [GLM] (https://glm.g-truc.net/0.9.9/index.html)
* PNG encoder and decoder in C and C++ [lodepng] (https://github.com/lvandeve/lodepng)
* PurpleBooth README file [template] (https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)

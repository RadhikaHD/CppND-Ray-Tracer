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

I followed Peter Shirley's article Peter Shirley's 
article ["Ray Tracing in One Weekend"](https://www.realtimerendering.com/raytracing/Ray%20Tracing%20in%20a%20Weekend.pdf) 
for this project and it definitely took me longer than one weekend to implement this.

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

## Project Description

This image below shows how a ray tracer works,

![Ray Trace Diagram](https://upload.wikimedia.org/wikipedia/commons/8/83/Ray_trace_diagram.svg)

The ray tracer traces a path from an imaginary eye or a camera through each pixel in a virtual screen and calculates the color of the object visible through it. A ray is 
sent outward from the camera and towards the objects in the scene. It then bounces off of them and the pixel values are calculated to generate the final image.

The following class structure is used to implement the setup mentioned above,

### File and Class Structure

1) Camera class (`camera.h & camera.cpp`)
   
   Description - A simple positionable camera that looks at the scene.

2) Ray class (`ray.h`)
   
   Description - A class that represents a ray with an origin and a direction.

3) Hittable class (`Hittable.h`)
   
   Description - An abstract class to represent anything that can be hit by a ray.

4) Sphere class (`Sphere.h & Sphere.cpp`)
   
   Description - A class that represents a sphere object in the scene. It inherits from the abstract Hittable class. Hence, a Sphere object is Hittable.
   

Other files -

1) main.cpp - The entire scene is set up in this file. The color of each point in the scene is also calculated in this file and finally, the results are written 
to the output png file. 
2) types.h - In this project, a 3D vector is used to define a position type as well as color type. This file is used to declare the various types a 
3D vector represents in this project.
3) constants.h - Defines all the constant values used across the project.
4) lodepng.h & lodepng.cpp - Taken from the [lodepng](https://github.com/lvandeve/lodepng) library specifically for the lodepng_encode_file function to write the result of the
program to a png file. Please refer to this line of code where the function is being used -
https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/bdbb5f47ffd960b109d9029d3fdb19d42adc20de/main.cpp#L112 

### Expected Output

![Output image](https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/master/images/output.png)

The scene has 5 spheres in total. The largest sphere serves as a surface on which the other 4 spheres are placed. A diffused or matte material 
is applied on all the spheres. These diffused objects take on the color of their surroundings and modulate it with their own color. As a result, you can 
see the parts of the spheres which are facing other spheres, have a darker color, sort of like a shadow. This is a result of the diffused material. 
The background in the scene has a light blue color that mimics the color of the sky on a clear day.
The final rendered image in .png format can be found in the build folder. Please note that the rendering takes a few minutes to complete once the program is run.

## Project Specification

Listed below are all the rubric points or criteria that this project satisfies. Also, included is one example for each criteria, even though 
there might be more instances of the criteria throughout the project.

### The project demonstrates an understanding of C++ functions and control structures.

https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/45ece7b4c16b1c3a6dca3f93d727a4233ab1868e/main.cpp#L40

### The project reads data from a file and process the data, or the program writes data to a file.

https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/45ece7b4c16b1c3a6dca3f93d727a4233ab1868e/main.cpp#L112

Program writes to a png file to generate the final output image.

### The project uses Object Oriented Programming techniques.

https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/45ece7b4c16b1c3a6dca3f93d727a4233ab1868e/camera.cpp#L4

There are other classes in the project that fulfill this criteria. This is just one example.

### Classes use appropriate access specifiers for class members.

https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/45ece7b4c16b1c3a6dca3f93d727a4233ab1868e/sphere.h#L18

This class has both public and private members.

### Class constructors utilize member initialization lists.

https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/45ece7b4c16b1c3a6dca3f93d727a4233ab1868e/sphere.h#L9

### Classes encapsulate behavior.

https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/45ece7b4c16b1c3a6dca3f93d727a4233ab1868e/sphere.h#L11

Member variables can be accessed through getter functions in this class.

### Classes follow an appropriate inheritance hierarchy.

https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/45ece7b4c16b1c3a6dca3f93d727a4233ab1868e/sphere.h#L5

A Sphere is a Hittable object and this relation has been implemented through inheritance.

### Derived class functions override virtual base class functions.

https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/45ece7b4c16b1c3a6dca3f93d727a4233ab1868e/hittable.h#L15

### The project makes use of references in function declarations.

https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/45ece7b4c16b1c3a6dca3f93d727a4233ab1868e/main.cpp#L32

A vector of hittable objects is being passed by reference.

### The project uses smart pointers instead of raw pointers.

https://github.com/RadhikaHD/CppND-Ray-Tracer/blob/45ece7b4c16b1c3a6dca3f93d727a4233ab1868e/main.cpp#L32

A vector of unique pointers to Hittable objects is passed by reference.

## License 

This project is licensed under the [MIT License](LICENSE.md) Creative Commons License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Peter Shirley's article ["Ray Tracing in One Weekend"](https://www.realtimerendering.com/raytracing/Ray%20Tracing%20in%20a%20Weekend.pdf)
* OpenGL Mathematics library [GLM](https://glm.g-truc.net/0.9.9/index.html)
* PNG encoder and decoder in C and C++ [lodepng](https://github.com/lvandeve/lodepng)
* PurpleBooth README file [template](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)

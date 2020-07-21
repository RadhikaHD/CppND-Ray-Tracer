# CppND Ray Tracer

This Computer Graphics Ray Tracer, created using C++, is my submission for the final project of Udacity's C++ Nanodegree program. A ray tracer uses a rendering technique where it traces the path of light as pixels in an image frame to generate a final image. It also simulates the interaction of the ray of light with the other virtual objects in the scene. Ray tracing has been around for decades and is used to generate realistic visual images. However, it is computationally expensive and takes a long time to generate an image. Hence, it is more suitable for applications where still computer generated images are used versus applications that need real time rendering of their scenes. In this project, I have implemented Path Tracing which is a type of Ray tracing technique. In Ray Tracing, when a single ray of light hits an object, it can multiply and generate more rays of light. This increase in the number of rays is exponential and expensive to compute. But path tracing generates only a single ray of light which randomly bounces off when it hits an object in the scene. Ultimately, the path tracing algorithm, takes a random sampling of all the rays and generates the final image. I consider this a simple implementation of a Ray Tracer and hope to add more features in the future. In this submission, I have applied diffuse materials to the objects in the scene and implemented anti-aliasing to make them look smoother. I followed Peter Shirley's article "Ray Tracing in One Weekend" https://www.realtimerendering.com/raytracing/Ray%20Tracing%20in%20a%20Weekend.pdf for this project and it definitely took me longer than one weekend to implement this.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

```
Give examples
```

### Installing

A step by step series of examples that tell you how to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags). 

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc

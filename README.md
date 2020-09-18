# miniRT
Simple ray-tracer program written in C. Takes a scene file and renders its content on a Xorg instance, or export it to a bitmap file.

## Motivation
This project was made as part of the 42 São Paulo curriculum, with the main pedagogic focus on the computer graphics branch. A [raytracer](https://en.wikipedia.org/wiki/Ray_tracing_(graphics)) is a special algorithm, developed to render tridimensional scenes with the highest level of realism. To acheive this result, a raytracer calculates the intersection of a ray if light, originated from the camera of the spectator, to the objects in the scene. The physical properties of the ray can be simulated with precision, so a modest raytracer can render lights, shadows and surfaces with a reasonable degree of fidelity.

## Dependencies

## Compilation and Execution

The compilation is made upon the execution of the `make` command on the root directory. The `minilibx`, `libft` and `libvector` libraries will be compiled, with further linking to main project in the sequence. The execution of this program can be made with two different commands:

    ./miniRT <scene-file.rt>
    ./miniRT <scene-file.rt> --save
    
The first command takes a scene file and renderizes it with a new X Server instance. By using this method, the user can iterate through several cameras on the scene, changing the perspective in any way desired. If the scene resolution is greater than the screen dimensions, the window will be resized to the maximum screen size.

The second command doesn't open a new window with a live scene, but renders the image present at the first camera available and export the image to a *bitmap* file. The bitmap header follows the 40 bit DIB size standard (BITMAPINFOHEADER), with 24 bits color. The screen size restriction does not apply to this rendering option, so it's possible to generate scene images with resolution greater than the screen.

# The RayTracer

## General Information

This program can render the following primitive euclidian objects:

- Spheres
- Planes
- Squares
- Cylinders
- Triangles

Besides the primitives, the raytracer takes information of *cameras*, *spherical lights*, *ambient light* and *screen resolution* into the scene. Only one resolution and ambient lighting may be declared into the scene; less or more will raise execution errors.

### Coordinates System
The entire vecotr space in which this program is built is a cartesian tridimensional space, based on an orthonormal basis. Therefore, the distance between unit interval along all axis is the same, and, with a camera with viewport based on the *x* and *y* axis, the orientation vector will point to the *-z* axis. As counterintuitive it seems, it's easy to proof with the right-hand rule. The following image describes how a camera sees the viewport, with an inverted *-z* axis. 

![Image created by Kamil Kielczewski, available under CC BY-SA 4.0 license](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b2/RaysViewportSchema.png/511px-RaysViewportSchema.png)

## Describing a Scene


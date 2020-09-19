## Describing a Scene

A mini raytracing scene can be identified by several elements, described on different lines on a `<.rt>` file. Each line must be initiated with an element identifier, which could comprises one or two characters, followed by parameters separated by one or more whitespaces.

Vector, point or color parameters must have each component separated by commas. All the color components must be in the range `[0; 255]`.

Empty lines on the scene file will not be accounted, and lines starting with `#` will be considered comments.

Here are some boilerplates to create a scene based on the `miniRT` scene identifiers. I'm gonna show up with examples and then explain briefly its effect on the scene and possible restrictions.

##### Resolution

    R    x    y

- `R` (**char**): Resolution identifier;
- `x` (**unsigned int**): Image resolution on the X axis;
- `y` (**unsigned int**): Image resolution on the Y axis.

Example: `R  800  600`

Note: This element is mandatory, and must be unique.

##### Ambient Lighting

    A    intensity    color

- `A` (**char**): Ambient lighting identifier;
- `intensity` (**float in range [0; 1]**): Ambient light overall intensity;
- `color` (**int[3] in range [0; 255]**): Ambient lighting color in RGB format.

Example: `A   0.4   255,255,255`

Note: This element is mandatory, and must be unique.

##### Cameras

    c    origin    orientation    fov

- `c` (**char**): Camera identifier;
- `origin` (**float[3]**): Camera origin point in the vector space
- `orientation` (**float[3] in range [-1; 1]**): Normalized camera orientation vector in the vector space.
- `fov` (**float**): Camera field of view, in degrees.

Example: `c    0,1,1    0,-0.25,-0.75    66`

##### Lights

    l    origin    intensity    color

- `l` (**char**): Light identifier;
- `origin` (**float[3]**): Point of origin of the spherical light;
- `intensity` (**float in range [0; 1]**): Light overall intensity, decreasing with the square of the distance;
- `color` (**int[3] in range [0; 255]**): Light color in RGB format.

Example: `l    0,4,3    0.25    0,255,0`

##### Planes

    pl    origin    normal    color

- `pl` (**char \***): Plane identifier;
- `origin` (**float[3]**): Plane origin point in the vector space;
- `normal` (**float[3] in range [-1; 1]**): Normalized plane orientation vector in the vector space;
- `color` (**int[3] in range [0; 255]**): Plane color in RGB format.

Example: `pl    0,-1,0    0,1,0    255,255,0`

##### Spheres

    sp    origin    diameter    color

- `sp` (**char \***): Sphere identifier;
- `origin` (**float[3]**): Sphere origin point in the vector space;
- `diameter` (**float**): Sphere diameter;
- `color` (**int[3] in range [0; 255]**): Sphere color in RGB format.

Example: `sp    0,0,-2    1.0    0,255,0`

##### Squares

    sq    center    normal    side_size    color

- `sq` (**char \***): Square identifier;
- `center` (**float[3]**): Square center point in the vector space;
- `normal` (**float[3] in range [-1; 1]**): Normalized plane orientation vector;
- `side_size` (**float**): Square side size;
- `color` (**int[3] in range [0; 255]**): Square color in RGB format.

Example: `sq    0,0,-6    0,0,1    5.0    127,127,255`

##### Cylinders

    cy    origin    normal    diameter    height    color

- `cy` (**char \***): Cylinder identifier;
- `origin` (**float[3]**): Cylinder origin point in the vector space;
- `normal` (**float[3] in range [-1; 1]**): Normalized cylinder orientation vector;
- `diameter` (**float**): Cylinder diameter;
- `height` (**float**): Cylinder height;
- `color` (**int[3] in range [0; 255]**): Cylinder color in RGB format.

Example: `sq    0,0,-6    0,0,1    5.0    127,127,255`

##### Triangles

    cy    vertex   vertex    vertex    color

- `tr` (**char \***): Triangle identifier;
- `vertex` (**float[3]**): Each one of the triangle vertex, must be three;
- `color` (**int[3] in range [0; 255]**): Triangle color in RGB format.

Example: `tr    -2,-0.5,0    2,-0.5,0    0,-0.5,-5    0,127,255`

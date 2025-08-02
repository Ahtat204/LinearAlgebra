1. Vector Classes
   Vector2, Vector3, and Vector4

Common operations: addition, subtraction, dot product, cross product (for 3D), magnitude, normalization, scaling

2. Matrix Classes
   Matrix2x2, Matrix3x3, Matrix4x4

Operations: transpose, determinant, inverse

Matrix multiplication

Identity, zero, and transformation matrices (rotation, scaling, translation)

➕ Additional Utilities
3. Quaternion Class
   Rotation representation without gimbal lock

Convert to/from rotation matrices or Euler angles

Quaternion multiplication, normalization, slerp (spherical linear interpolation)

4. Transform Utilities
   Combine translation, rotation, and scale

Useful for game engines and 3D graphics

5. Geometric Utilities
   Line-plane intersection

Ray-sphere and ray-AABB intersections (for ray casting)

Distance from point to line, segment, plane

Barycentric coordinates

6. Math Helpers
   Clamp, lerp, smoothstep, angle conversions (degrees ↔ radians)

Fast math approximations (optional, for performance)


🧮 Intermediate Math Utilities (Highly Useful)
✅ Trigonometric and Exponential Functions
Wrappers around std::sin, std::cos, std::tan, std::exp, std::log, etc.

Degree/radian versions

Angle normalization (wrapAngle, shortestAngleBetween)

✅ Projection and View Matrix Generators
Perspective and orthographic projection matrices

LookAt view matrix (useful in 3D engines, like glm’s lookAt)

Frustum extraction helpers (for view frustum culling later)

✅ Interpolation Functions
lerp() for floats, vectors

nlerp() and slerp() for quaternions

catmullRom(), bezier() for spline interpolation

✅ Easing Functions
For animation and UI transitions:

easeIn, easeOut, easeInOut, etc.

Could be used for tweening animations in games

✅ Plane Class
Defined by normal and distance from origin

Plane from three points

Distance from point to plane

Reflect a vector off a plane

🔷 Spatial Tools
✅ Bounding Volumes
AABB (Axis-Aligned Bounding Box) with:

intersects(other), contains(point)

expandToInclude(point) / merge with another AABB

Circle (2D), Sphere (3D)

Bounding Frustum (basic version)

✅ Ray Class
Origin + direction

Raycasting utilities:

intersectsSphere()

intersectsPlane()

intersectsAABB()

✅ Basic Collision Checks
Circle vs Circle (2D)

AABB vs AABB

Point in triangle (use barycentric coords)

🔢 Math Types & Constants
mathlib::PI, TAU, EPSILON

Common vectors: ZERO, ONE, UP, RIGHT, FORWARD

Constants for float precision comparison



How to Extend Your Project with Linear Applications
1. Represent Linear Transformations
   Implement a Matrix class (e.g., 2x2, 3x3, 4x4) that acts on your vector types.

This matrix will represent a linear map
𝑇
:
𝑉
→
𝑉
T:V→V.

2. Apply Transformations to Vectors
   Add functionality for matrix-vector multiplication to transform vectors.

Example: rotate, scale, shear, reflect, or project vectors by multiplying them with matrices.

3. Composition of Linear Maps
   Support matrix-matrix multiplication to compose linear transformations.

This shows how transformations combine and gives a solid foundation for understanding transformation chains.

4. Linear Map Properties and Utilities
   Implement functions to compute:

The determinant (check if the transformation is invertible).

The inverse of a matrix (when it exists).

The transpose (useful for adjoints and symmetric maps).

5. Special Linear Maps
   Implement common linear transformations such as:

Rotation matrices (2D and 3D).

Scaling matrices.

Reflection matrices.

Projection matrices (orthogonal projection onto a subspace).

Shear transformations.

6. Eigenvalues and Eigenvectors (Advanced)
   For a challenge, add basic routines to compute eigenvalues and eigenvectors.

This would showcase understanding of diagonalization and invariant directions.

7. Affine Transformations (Bonus)
   Extend linear maps by adding translation, creating affine transformations.

Represent with augmented matrices or separate translation vectors.


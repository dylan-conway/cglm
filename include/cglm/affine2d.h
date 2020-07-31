/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:

 */

#ifndef cglm_affine2d_h
#define cglm_affine2d_h

#include "common.h"
#include "util.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include "mat3.h"
#include "affine-mat.h"

/*!
 * @brief translate existing 2d transform matrix by v vector
 *        and stores result in same matrix
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       v  translate vector [x, y]
 */
CGLM_INLINE
void
glm_translate2d(mat3 m, vec2 v) {
  m[2][0] = m[0][0] * v[0] + m[1][0] * v[1] + m[2][0];
  m[2][1] = m[0][1] * v[0] + m[1][1] * v[1] + m[2][1];
  m[2][2] = m[0][2] * v[0] + m[1][2] * v[1] + m[2][2];
}

/*!
 * @brief translate existing 2d transform matrix by v vector
 *        and store result in dest
 *
 * source matrix will remain same
 *
 * @param[in]  m    affine transfrom
 * @param[in]  v    translate vector [x, y]
 * @param[out] dest translated matrix
 */
CGLM_INLINE
void
glm_translate2d_to(mat3 m, vec2 v, mat3 dest) {
  glm_mat3_copy(m, dest);
  glm_translate2d(dest, v);
}

/*!
 * @brief translate existing 2d transform matrix by x factor
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       x  x factor
 */
CGLM_INLINE
void
glm_translate2d_x(mat3 m, float x) {
  m[2][0] = m[0][0] * x + m[2][0];
  m[2][1] = m[0][1] * x + m[2][1];
  m[2][2] = m[0][2] * x + m[2][2];
}

/*!
 * @brief translate existing 2d transform matrix by y factor
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       y  y factor
 */
CGLM_INLINE
void
glm_translate2d_y(mat3 m, float y) {
  m[2][0] = m[1][0] * y + m[2][0];
  m[2][1] = m[1][1] * y + m[2][1];
  m[2][2] = m[1][2] * y + m[2][2];
}

/*!
 * @brief creates NEW translate 2d transform matrix by v vector
 *
 * @param[out]  m  affine transfrom
 * @param[in]   v  translate vector [x, y]
 */
CGLM_INLINE
void
glm_translate2d_make(mat3 m, vec2 v) {
  glm_mat3_identity(m);
  m[2][0] = v[0];
  m[2][1] = v[1];
}

/*!
 * @brief scale existing 2d transform matrix by v vector
 *        and store result in dest
 *
 * @param[in]  m    affine transfrom
 * @param[in]  v    scale vector [x, y]
 * @param[out] dest scaled matrix
 */
CGLM_INLINE
void
glm_scale2d_to(mat3 m, vec2 v, mat3 dest) {
  dest[0][0] = m[0][0] * v[0];
  dest[0][1] = m[0][1] * v[0];
  dest[0][2] = m[0][2] * v[0];
  
  dest[1][0] = m[1][0] * v[1];
  dest[1][1] = m[1][1] * v[1];
  dest[1][2] = m[1][2] * v[1];
  
  dest[2][0] = m[2][0];
  dest[2][1] = m[2][1];
  dest[2][2] = m[2][2];
}

/*!
 * @brief creates NEW 2d scale matrix by v vector
 *
 * @param[out]  m  affine transfrom
 * @param[in]   v  scale vector [x, y]
 */
CGLM_INLINE
void
glm_scale2d_make(mat3 m, vec2 v) {
  glm_mat3_identity(m);
  m[0][0] = v[0];
  m[1][1] = v[1];
}

/*!
 * @brief scales existing 2d transform matrix by v vector
 *        and stores result in same matrix
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       v  scale vector [x, y]
 */
CGLM_INLINE
void
glm_scale2d(mat3 m, vec2 v) {
  m[0][0] = m[0][0] * v[0];
  m[0][1] = m[0][1] * v[0];
  m[0][2] = m[0][2] * v[0];

  m[1][0] = m[1][0] * v[1];
  m[1][1] = m[1][1] * v[1];
  m[1][2] = m[1][2] * v[1];
}

/*!
 * @brief applies uniform scale to existing 2d transform matrix v = [s, s]
 *        and stores result in same matrix
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       s  scale factor
 */
CGLM_INLINE
void
glm_scale2d_uni(mat3 m, float s) {
  m[0][0] = m[0][0] * s;
  m[0][1] = m[0][1] * s;
  m[0][2] = m[0][2] * s;

  m[1][0] = m[1][0] * s;
  m[1][1] = m[1][1] * s;
  m[1][2] = m[1][2] * s;
}

/*!
 * @brief creates NEW rotation matrix by angle and axis
 *
 * axis will be normalized so you don't need to normalize it
 *
 * @param[out] m     affine transfrom
 * @param[in]  angle angle (radians)
 */
CGLM_INLINE
void
glm_rotate2d_make(mat3 m, float angle) {
  float c, s;

  s = sinf(angle);
  c = cosf(angle);
  
  m[0][0] = m[0][0] * c + m[1][0] * s;
  m[0][1] = m[0][1] * c + m[1][1] * s;
  m[0][2] = m[0][2] * c + m[1][2] * s;
  
  m[1][0] = m[0][0] * -s + m[1][0] * c;
  m[1][1] = m[0][1] * -s + m[1][1] * c;
  m[1][2] = m[0][2] * -s + m[1][2] * c;
  
  m[2][0] = 0.0f;
  m[2][1] = 0.0f;
  m[2][2] = 1.0f;
}

/*!
 * @brief rotate existing 2d transform matrix around given axis by angle
 *
 * @param[in, out]  m      affine transfrom
 * @param[in]       angle  angle (radians)
 */
CGLM_INLINE
void
glm_rotate2d(mat3 m, float angle) {
  float c, s;

  s = sinf(angle);
  c = cosf(angle);
  
  m[0][0] = m[0][0] * c + m[1][0] * s;
  m[0][1] = m[0][1] * c + m[1][1] * s;
  m[0][2] = m[0][2] * c + m[1][2] * s;
  
  m[1][0] = m[0][0] * -s + m[1][0] * c;
  m[1][1] = m[0][1] * -s + m[1][1] * c;
  m[1][2] = m[0][2] * -s + m[1][2] * c;
}

/*!
 * @brief rotate existing 2d transform matrix around given axis by angle
 *        and store result in dest
 *
 * @param[in]  m      affine transfrom
 * @param[in]  angle  angle (radians)
 * @param[out] dest   destination
 */
CGLM_INLINE
void
glm_rotate2d_to(mat3 m, float angle, mat3 dest) {
  float c, s;

  s = sinf(angle);
  c = cosf(angle);
  
  dest[0][0] = m[0][0] * c + m[1][0] * s;
  dest[0][1] = m[0][1] * c + m[1][1] * s;
  dest[0][2] = m[0][2] * c + m[1][2] * s;
  
  dest[1][0] = m[0][0] * -s + m[1][0] * c;
  dest[1][1] = m[0][1] * -s + m[1][1] * c;
  dest[1][2] = m[0][2] * -s + m[1][2] * c;
  
  dest[2][0] = m[0][0];
  dest[2][1] = m[0][1];
  dest[2][2] = m[0][2];
}

#endif /* cglm_affine2d_h */

#ifndef HW2_DEFS_H
#define HW2_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define Cos(th) cos(3.1415927/180*(th))
#define Sin(th) sin(3.1415927/180*(th))

#ifdef __cplusplus
extern "C" {
#endif

// AUXILIARY
void Print(const char* format , ...);
void Project(int fov,double asp,double dim,int mode);
void Params(int th,int ph,int mode,double l_theta,double l_phi,
	        double lookat_x,double lookat_y,double lookat_z,
	        double cam_x,double cam_z,
	        float fx, float fy, float fz,
	        float rx, float ry, float rz,
	        double ambient,double diffuse,double specular,
	        double moon_emission,float moon_shininess);
unsigned int LoadTexBMP(const char* file);
void ErrCheck(const char* where);
void Fatal(const char* format , ...);
void Vertex(int th,int ph,int out);
void lighting(float ambient,float diffuse,float specular);

// OBJECTS
void cube(double x,double y,double z,
	      double dx,double dy,double dz,
	      double th);
void axes(float len);
void plane(double x,double y,double z,
	      float r,float g,float b,
	      double dim,
	      double thx,double thy,double thz,
	      unsigned int tex);
void grass_blade(double x,double y,double z,
	             double dx,double dy,double dz,
	             double th,
	             unsigned int tex);
void grass_block(double x,double y,double z,
	             double dx_mat[7][7],double th_mat[7][7],
	             unsigned int tex);
void fencepost(double x,double y,double z,
	           double dx,double dy,double dz);
void fence(double x,double y,double z,double th,unsigned int tex);
void moon(double x,double y,double z,double r,
	      double thx,double thy,double thz,
	      unsigned int tex,
	      double moon_emission,float moon_shinyvec[1]);
void sky(double x,double y,double z,double r,
	     double thx,double thy,double thz,
	     unsigned int tex);

#ifdef __cplusplus
}
#endif

#endif
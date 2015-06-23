#include "../hw3_defs.h"

void lighting(float ambient,float diffuse,float specular,
	          double moon_zh,unsigned int tex,
	          double moon_emission,float moon_shinyvec[1],
            double moon_y) {
  glEnable(GL_NORMALIZE);

  // Translate intensity to color vectors
  float Ambient[] = {0.01*ambient ,0.01*ambient ,0.01*ambient};
  float Diffuse[] = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse};
  float Specular[] = {0.01*specular ,0.01*specular ,0.01*specular};
  glShadeModel(GL_SMOOTH);
  // Light direction
  float Position[] = {8.0*Cos(moon_zh),8.0*Sin(moon_zh),0};
  // The moon is the light source
  moon(8.0*Cos(moon_zh),8.0*Sin(moon_zh),0,.9,
       0,moon_zh,0,
       tex,
       moon_emission,moon_shinyvec);
  // OpenGL should normalize normal vectors
  glEnable(GL_NORMALIZE);
  // Enable lighting
  glEnable(GL_LIGHTING);
  // glColor sets ambient and diffuse color materials
  glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);
  // Light zero
  glEnable(GL_LIGHT0);
  // Set ambient, diffuse, specular and position for light zero.
  glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
  glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
  glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
  glLightfv(GL_LIGHT0,GL_POSITION,Position);
  // The material of the light
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular);
  glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambient);
  glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
}
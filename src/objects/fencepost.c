#include "../hw3_defs.h"

void fencepost(double x,double y,double z,
	           double dx,double dy,double dz) {
  // Fence materials
  float white[] = {1.0,1.0,1.0,1.0};
  float Diffuse[] = {1.0,1.0,0.0};
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
  glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
  // Save transformation
  glPushMatrix();
  // Offset
  glTranslated(x,y,z);
  glScaled(dx,dy,dz);
  // Fencepost
  glColor3f(1,1,1);
  glBegin(GL_QUADS);
  // Normal points straight forward
  glNormal3d(0,0,1);
  // Fencepost base
  glTexCoord2d(1,0);
  glVertex3f(.25,0,0);

  glTexCoord2d(0,0);
  glVertex3f(0,0,0);

  glTexCoord2d(0,1);
  glVertex3f(0,.75,0);

  glTexCoord2d(1,1);
  glVertex3f(.25,.75,0);
  // Fencepost cap
  glTexCoord2d(1,0);
  glVertex3f(.25,.75,0);

  glTexCoord2d(0,0);
  glVertex3f(0,.75,0);

  glTexCoord2d(.52,1);
  glVertex3f(.124,1,0);

  glTexCoord2d(.48,1);
  glVertex3f(.126,1,0);
  //End
  glEnd();
  // Undo Transformations
  glPopMatrix();
}
#include "../hw3_defs.h"

/*
  Draws a plane centered at (x,y,z)
  with color (r,g,b)
  side length dim
  rotations thx, thy, thz
*/

void plane(double x,double y,double z,
	      float r,float g,float b,
	      double dim,
	      double thx,double thy,double thz,
        unsigned int tex) {
  // Save transformation
  glPushMatrix();
  // Texture
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,tex);
  // Offset
  glTranslated(x,y,z);
  glRotated(thx,1,0,0);
  glRotated(thy,0,1,0);
  glRotated(thz,0,0,1);
  glScaled(dim,1,dim);
  // Plane
  glBegin(GL_QUADS);
  // Color specified by user
  glColor3f(r,g,b);
  // Centered around origin, then transform
  glNormal3d(0,1,0);
  glVertex3f(+1,0,+1);
  glTexCoord2d(dim,dim);

  glVertex3f(-1,0,+1);
  glTexCoord2d(0,dim);

  glVertex3f(-1,0,-1);
  glTexCoord2d(0,0);

  glVertex3f(+1,0,-1);
  glTexCoord2d(dim,0);

  // End
  glEnd();
  // Undo transformations
  glPopMatrix();
  // We don't want everything else to look like grass!
  glDisable(GL_TEXTURE_2D);
}
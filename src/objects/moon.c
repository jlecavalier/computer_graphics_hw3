#include "../hw3_defs.h"

void moon(double x,double y,double z,double r,
	      double thx,double thy,double thz,
        unsigned int tex) {
  const int d=5;
  int th,ph;

  // Save transformation
  glPushMatrix();
  // Offset
  glTranslated(x,y,z);
  glRotated(thx,1,0,0);
  glRotated(thy,0,1,0);
  glRotated(thz,0,0,1);
  glScaled(r,r,r);

  // Texture for the moon
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,tex);

  // Latitude bands
  for (ph=-90;ph<90;ph+=d) {
    glColor3f(1,1,1);
  	glBegin(GL_QUAD_STRIP);
  	for (th=0;th<=360;th+=d) {
  	  Vertex(th,ph);
  	  Vertex(th,ph+5);
  	}
  	glEnd();
  }

  // Undo transformations
  glPopMatrix();
  // We don't want the moon texture to appear on anything else!
  glDisable(GL_TEXTURE_2D);
}
#include "../hw3_defs.h"

void moon(double x,double y,double z,double r,
	      double thx,double thy,double thz,
        unsigned int tex,
        double moon_emission, float moon_shinyvec[1]) {
  const int d=5;
  int th,ph;

  // Set specular color to white
  float white[] = {.78,.78,.78,1};
  float Emission[] = {0.0,0.0,0.01*moon_emission};
  float Diffuse[] = {.85,.85,.85};
  glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,moon_shinyvec);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
  glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,Emission);
  glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);

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
  	  Vertex(th,ph,1);
  	  Vertex(th,ph+5,1);
  	}
  	glEnd();
  }

  // Undo transformations
  glPopMatrix();
  // We don't want the moon texture to appear on anything else!
  glDisable(GL_TEXTURE_2D);
}
#include "../hw3_defs.h"

void fence(double x,double y,double z,double th,unsigned int tex) {
  // Save transformation
  glPushMatrix();
  // Offset
  glTranslated(x,y,z);
  glRotated(th,0,1,0);
  // Texture
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,tex);
  // Fence
  fencepost(0,0,0 , .5,.5,2);
  fencepost(.127,0,0 , .5,.5,1);
  fencepost(.254,0,0 , .5,.5,1);
  fencepost(.381,0,0 , .47,.5,1);
  // Undo Transformations
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}
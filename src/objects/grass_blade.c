#include "../hw3_defs.h"

void grass_blade(double x,double y,double z,
	             double dx,double dy,double dz,
	             double th,
               unsigned int tex) {
  // Grass blade materials
  float Diffuse[] = {(122.0/255.0),(230.0/255.0),(206.0/255.0)};
  glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
  // Save transformation
  glPushMatrix();
  // Texture
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,tex);
  // Transform as desired
  glTranslated(x,y,z);
  glRotated(th,0,1,0);
  glScaled(dx,dy,dz);
  // Quadstrip
  glBegin(GL_QUAD_STRIP);
  float i;
  float mpi6 = M_PI/6;
  float mpi3 = M_PI/3;
  float r = 58.0/255.0;
  float g = 92.0/255.0;
  float b = 48.0/255.0;
  // First, we draw the base of the blade.
  for (i=(-M_PI/6);i <= mpi3;i+=0.25) {
  	glColor3f(r,g,b);
  	float cosi = cos(i);
  	float z_pos = pow((mpi6+i)/1.5,2);
    float y_norm = -(.001*((2*cosi)-1));
    float z_norm = .01*((2*cosi)-1);

    //glNormal3d(z_pos,z_pos,-z_pos);
    glNormal3d(0,y_norm,-z_norm);
    glTexCoord2d((cosi)/mpi3,(i+mpi6)/(mpi3+mpi6));
  	glVertex3f(cosi,i+mpi6,z_pos);

    //glNormal3d(z_pos,z_pos,-z_pos);
    glNormal3d(0,y_norm,-z_norm);
    glTexCoord2d((1-cosi)/mpi3,(i+mpi6)/(mpi3+mpi6));
  	glVertex3f(1-cosi,i+mpi6,z_pos);

    //glNormal3d(z_pos+.001,z_pos+.001,-(z_pos+.001));
    glNormal3d(0,y_norm,-z_norm);
    glTexCoord2d((cosi)/mpi3,(i+.01+mpi6)/(mpi3+mpi6));
  	glVertex3f(cosi,i+.01+mpi6,z_pos+.001);

    //glNormal3d(z_pos+.001,z_pos+.001,-(z_pos+.001));
    glNormal3d(0,y_norm,-z_norm);
    glTexCoord2d((1-cosi)/mpi3,(i+.01+mpi6)/(mpi3+mpi6));
  	glVertex3f(1-cosi,i+.01+mpi6,z_pos+.001);

  	r = r + .01;
  	g = g + .025;
  }
  glEnd();
  // Now, we draw the tip of the blade.
  glPopMatrix();
  // We don't want everything else to look like a grass blade!
  glDisable(GL_TEXTURE_2D);
}
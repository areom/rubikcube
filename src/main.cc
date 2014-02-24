#if defined(__APPLE__) || defined(MACOSX)
#   include <GLUT/glut.h>
#else
#   include <GL/glut.h>
#endif

#include <cstdlib>
#include <iostream>

#define BUFFER_LENGTH 64

static GLfloat spin{0.0};
double rotate_y{0}; 
double rotate_x{0};

double rotate_slice_a0{0};
double rotate_slice_a1{0};
double rotate_slice_a2{0};

double rotate_slice_b0{0};
double rotate_slice_b1{0};
double rotate_slice_b2{0};

double rotate_slice_c0{0};
double rotate_slice_c1{0};
double rotate_slice_c2{0};

void piece(void)
{
    // FRONT
    glBegin(GL_POLYGON);
        glColor3ub( 255, 000, 000 );  // red
        glVertex3f( 2.0, 0.0, 2.0 );
        glVertex3f( 2.0, 2.0, 2.0 );
        glVertex3f( 0.0, 2.0, 2.0 );
        glVertex3f( 0.0, 0.0, 2.0 );
    glEnd();
        
    // BACK
    glBegin(GL_POLYGON);
        glColor3ub( 255, 165, 000 );  // orange
        glVertex3f( 2.0, 0.0, 0.0 );      
        glVertex3f( 2.0, 2.0, 0.0 );      
        glVertex3f( 0.0, 2.0, 0.0 );      
        glVertex3f( 0.0, 0.0, 0.0 );     
    glEnd();
 
    // RIGHT
    glBegin(GL_POLYGON);
        glColor3ub( 000, 255, 000 );  // green
        glVertex3f( 2.0, 0.0, 0.0 );
        glVertex3f( 2.0, 2.0, 0.0 );
        glVertex3f( 2.0, 2.0, 2.0 );
        glVertex3f( 2.0, 0.0, 2.0 );
    glEnd();
 
    // LEFT
    glBegin(GL_POLYGON);
        glColor3ub( 000, 000, 255 );  // blue
        glVertex3f( 0.0, 0.0, 2.0 );
        glVertex3f( 0.0, 2.0, 2.0 );
        glVertex3f( 0.0, 2.0, 0.0 );
        glVertex3f( 0.0, 0.0, 0.0 );
    glEnd();
 
    // TOP
    glBegin(GL_POLYGON);
        glColor3ub( 255, 255, 000 );  // yellow
        glVertex3f( 2.0, 2.0, 2.0 );
        glVertex3f( 2.0, 2.0, 0.0 );
        glVertex3f( 0.0, 2.0, 0.0 );
        glVertex3f( 0.0, 2.0, 2.0 );
    glEnd();
 
    // BOTTOM
    glBegin(GL_POLYGON);
        glColor3ub( 255, 255, 255 ); // white
        glVertex3f( 2.0, 0.0, 0.0 );
        glVertex3f( 2.0, 0.0, 2.0 );
        glVertex3f( 0.0, 0.0, 2.0 );
        glVertex3f( 0.0, 0.0, 0.0 );
    glEnd();
}

void init (void) 
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.2, 1.0);
    //glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
}


void specialKeys( int key, int x, int y ) {
 
    switch(key){
        case GLUT_KEY_RIGHT:
            rotate_y += 5;
            break;
        case GLUT_KEY_LEFT:
            rotate_y -= 5;
            break;
        case GLUT_KEY_UP:
            rotate_x += 5;
            break;
        case GLUT_KEY_DOWN:
            rotate_x -= 5;
            break;
    }
 
    glutPostRedisplay();
 
}

void spinDisplay(void)
{
    spin = spin + 2.0;
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(double)w/(double)h,1.0,200);
    gluLookAt(0.0f,5.5f, 15.0f,
              0.0f,0.0f,0.0f,
              0.0f,1.0f,0.0f);
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 27:
            exit(0);
        case 'q':
            rotate_slice_a0 += 90;
            break;
        case 'w':
            rotate_slice_a1 += 90;
            break;
        case 'e':
            rotate_slice_a2 += 90;
            break;

        case 'a':
            rotate_slice_b0 += 90;
            break;
        case 's':
            rotate_slice_b1 += 90;
            break;
        case 'd':
            rotate_slice_b2 += 90;
            break;
        
        case 'z':
            rotate_slice_c0 += 90;
            break;
        case 'x':
            rotate_slice_c1 += 90;
            break;
        case 'c':
            rotate_slice_c2 += 90;
            break;
    }
    glutPostRedisplay();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glTranslatef(0,-5,-10);
    //glRotatef(-_angle, 2.0f, 2.0f, 0.0f);
    glTranslatef(-3.1, -3.1, -3.1);

    glTranslatef(0.0, 3.1, 3.1);
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glTranslatef(0.0, -3.1, -3.1);
    glTranslatef(3.1, 0.0, 3.1);
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glTranslatef(-3.1, 0.0, -3.1);

    for(GLfloat x = 0; x < 5; x += 2.1){
        for(GLfloat y = 0; y < 5; y += 2.1){
            for(GLfloat z = 0; z < 5; z += 2.1){
                glPushMatrix();
                
    glTranslatef(3.1, 3.1, 3.1);
                if(x < 2.0){
                    glRotatef(rotate_slice_a0, 1.0, 0.0, 0.0);
                }else if(x < 3.0){
                    glRotatef(rotate_slice_a1, 1.0, 0.0, 0.0);
                }else if(x < 5.0){
                    glRotatef(rotate_slice_a2, 1.0, 0.0, 0.0);
                }                
                 
                if(y < 2.0){
                    glRotatef(rotate_slice_b0, 0.0, 1.0, 0.0);
                }else if(y < 3.0){
                    glRotatef(rotate_slice_b1, 0.0, 1.0, 0.0);
                }else if(y < 5.0){
                    glRotatef(rotate_slice_b2, 0.0, 1.0, 0.0);
                }                

                if(z < 2.0){
                    glRotatef(rotate_slice_c0, 0.0, 0.0, 1.0);
                }else if(z < 3.0){
                    glRotatef(rotate_slice_c1, 0.0, 0.0, 1.0);
                }else if(z < 5.0){
                    glRotatef(rotate_slice_c2, 0.0, 0.0, 1.0);
                }
    glTranslatef(-3.1, -3.1, -3.1);
                glTranslatef(x, y, z);
                                
                piece();
                glPopMatrix();
            }
        }
    }
    glutSwapBuffers();
}


void setupRC(){
    GLfloat camRotX{350.0f};
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Rubik's Cube");
    glutFullScreen();
    //setupRC();

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    //glutMouseFunc(mouse);
   // glutMotionFunc(motion);

    glutMainLoop();
    
    return 0;
}

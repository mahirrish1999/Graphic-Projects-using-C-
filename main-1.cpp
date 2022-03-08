#include<windows.h>
#include<mmsystem.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include<iostream>
#define PI 3.1416
//#include<MMSystem.h>
using namespace std;
void introscreen();

static float	tx= 0.0, cloudleftx=0,cloudmiddlex=0,cloudrightx=0,cloudrightupx=0;
static float    ty=0.0;

static float txA=0.0;
static float tyA=0.0;

static float txB2=0.0;
static float tyB2=0.0;

static float txC=0.0;
static float tyC=0.0;

static float txS=0.0;
static float tyS=0.0;


static float txR=0.0;
static float tyR=0.0;

void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle1 = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle1 = 2 * PI * i / 100;
			glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
		}

	glEnd();
}



void HalfCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle1 = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i <50; i++)
		{
			angle1 = 2 * PI * i / 150;
			glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
		}

	glEnd();
}

void renderbitmap(float x, float y, void *font, char *string){
    char *c;
    glRasterPos2f(x,y);
    for(c=string; *c!= '\0'; c++){

        glutBitmapCharacter(font, *c);
    }

}
void introscreen(){
glColor3ub(41,106,119);
char buf[100]={0};
sprintf(buf, "This is a view of the city");
renderbitmap(-10,30, GLUT_BITMAP_TIMES_ROMAN_24,buf);

sprintf(buf, "press 'r', 'd' and 'n' to see the different views of the city");
renderbitmap(-19,10, GLUT_BITMAP_TIMES_ROMAN_24,buf);


}

void screen(){

     glBegin(GL_QUADS);

       glColor3ub(234, 243, 245);

	glVertex2f(-50.0f, 110.0f);
	glColor3ub(210, 233, 238);
	glVertex2f(50.0f, 110.0f);
	glColor3ub(151, 191, 208);
	glVertex2f(50.0f, -90.0f);
	glColor3ub(111, 191, 208);
    glVertex2f(-50.0f, -90.0f);

            glEnd();


}



void sun(){
    glPushMatrix();
        glTranslated(-10,98,0);
        glScaled(0.5,1.5,0);
        glColor3f(1,0.843,0);
        circle(4,4);
    glPopMatrix();
}



void sunR(){
    glPushMatrix();
        glTranslated(-10,98,0);
        glScaled(0.5,1.5,0);
        glColor3ub(248,253,111);
        circle(4,4);
    glPopMatrix();
}

void moon(){
    glPushMatrix();
        glTranslated(-30,98,0);
        glScaled(0.5,1.5,0);
        glColor3ub(255,255,51);
        HalfCircle(4,4);
    glPopMatrix();
}


void cloudLeft(){
    cloudleftx=cloudleftx-0.05;
    if(cloudleftx<-50){
        cloudleftx=50;
    }



    glPushMatrix();
        glTranslated(-3.5+cloudleftx,8.5,3);
        glScaled(1,1,1);
        glColor3f(1.0f,1.0f,1.0f);


        glPushMatrix();
            glTranslated(1.5,90,0),
            circle(2,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(4,90.5,0),
            circle(2,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(4.5,89.7,0),
            circle(2.5,2.0);
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,89,0),
            circle(1.5,2.5);
        glPopMatrix();
    glPopMatrix();

    glutPostRedisplay();


}




void cloudRight(){

    cloudrightx=cloudrightx-0.02;
    if(cloudrightx<-50){
        cloudrightx=50;
    }


    glPushMatrix();
        glTranslated(-3.5+cloudrightx,2.5,-5);
        glScaled(1,1,1);
        glColor3f(1.0f,1.0f,1.0f);


        glPushMatrix();
            glTranslated(1.5,84,0),
            circle(2,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(4,84.5,0),
            circle(2,3);
        glPopMatrix();

        glPushMatrix();
            glTranslated(4.5,83.7,0),
            circle(2.5,2.0);
        glPopMatrix();

        glPushMatrix();
            glTranslated(2.0,83,0),
            circle(1.5,2.5);
        glPopMatrix();
    glPopMatrix();

    glutPostRedisplay();

}



void cloudMiddle(){
    cloudmiddlex=cloudmiddlex-0.04;
    if(cloudmiddlex<-50){
        cloudmiddlex=50;
            }



    glPushMatrix();
    glTranslated(-3.5+cloudmiddlex,9,1);
    glScaled(1,1,1);
    glColor3f(1.0f,1.0f,1.0f);
    glPushMatrix();
    glTranslated(0,83.5,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,86.5,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,86.5,1),
    circle(2,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.5,84,1),
    circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,83,1),
    circle(1.5,2.5);
    glPopMatrix();
glPopMatrix();

glutPostRedisplay();


}

void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(202, 235, 245);
	glVertex2f(-50.0f, 110.0f);
	glVertex2f(50.0f, 110.0f);
	glColor3ub(197, 233, 238);
    glVertex2f(50.0f, -10.0f);
	glVertex2f(-50.0f, -10.0f);
    glEnd();
}


void skyN()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 102);
	glVertex2f(-50.0f, 110.0f);
	 glColor3ub(51, 51, 255);
	glVertex2f(50.0f, 110.0f);
	glColor3ub(153, 204, 255);
    glVertex2f(50.0f, -10.0f);
     glColor3ub(204, 229, 255);
	glVertex2f(-50.0f, -10.0f);
    glEnd();
}

void skyR(){

     glBegin(GL_QUADS);
    glColor3ub(224, 224, 224);
	glVertex2f(-50.0f, 110.0f);
	 //glColor3ub(51, 51, 255);
	glVertex2f(50.0f, 110.0f);
	glColor3ub(160, 160, 160);
    glVertex2f(50.0f, -10.0f);
     //glColor3ub(204, 229, 255);
	glVertex2f(-50.0f, -10.0f);
    glEnd();


}
void Roadborder(){

glBegin(GL_QUADS);
    glColor3ub(19, 19, 20);
	glVertex2f(-50.0f, -10.0f);
	glVertex2f(-40.0f, -10.0f);
    glVertex2f(-40.0f, -13.0f);
	glVertex2f(-50.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
	glVertex2f(-40.0f, -10.0f);
	glVertex2f(-30.0f, -10.0f);
    glVertex2f(-30.0f, -13.0f);
	glVertex2f(-40.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(19, 19, 20);
	glVertex2f(-30.0f, -10.0f);
	glVertex2f(-20.0f, -10.0f);
    glVertex2f(-20.0f, -13.0f);
	glVertex2f(-30.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
	glVertex2f(-20.0f, -10.0f);
	glVertex2f(-10.0f, -10.0f);
    glVertex2f(-10.0f, -13.0f);
	glVertex2f(-20.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(19, 19, 20);
	glVertex2f(-10.0f, -10.0f);
	glVertex2f(0.0f, -10.0f);
    glVertex2f(0.0f, -13.0f);
	glVertex2f(-10.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
	glVertex2f(0.0f, -10.0f);
	glVertex2f(10.0f, -10.0f);
    glVertex2f(10.0f, -13.0f);
	glVertex2f(0.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(19, 19, 20);
	glVertex2f(10.0f, -10.0f);
	glVertex2f(20.0f, -10.0f);
    glVertex2f(20.0f, -13.0f);
	glVertex2f(10.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
	glVertex2f(20.0f, -10.0f);
	glVertex2f(30.0f, -10.0f);
    glVertex2f(30.0f, -13.0f);
	glVertex2f(20.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(19, 19, 20);
	glVertex2f(30.0f, -10.0f);
	glVertex2f(40.0f, -10.0f);
    glVertex2f(40.0f, -13.0f);
	glVertex2f(30.0f, -13.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
	glVertex2f(40.0f, -10.0f);
	glVertex2f(50.0f, -10.0f);
    glVertex2f(50.0f, -13.0f);
	glVertex2f(40.0f, -13.0f);
    glEnd();

}


void Road(){
glBegin(GL_QUADS);
    glColor3ub(96, 96, 96);
	glVertex2f(-50.0f, -13.0f);
	glVertex2f(50.0f, -13.0f);
    glVertex2f(50.f, -90.0f);
	glVertex2f(-50.0f, -90.0f);

    glEnd();
}

void footpath(){

    glBegin(GL_QUADS);
    glColor3ub(224, 224, 224);
	glVertex2f(-36.6f, -42.0f);
	glVertex2f(-26.6f, -42.0f);
    glVertex2f(-25.0f, -44.5f);
	glVertex2f(-35.0f, -44.5f);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(224, 224, 224);
	glVertex2f(-6.6f, -42.0f);
	glVertex2f(3.4f, -42.0f);
    glVertex2f(5.0f, -44.5f);
	glVertex2f(-5.0f, -44.5f);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(224, 224, 224);
	glVertex2f(23.4f, -42.0f);
	glVertex2f(33.4f, -42.0f);
    glVertex2f(35.0f, -44.5f);
	glVertex2f(25.0f, -44.5f);

    glEnd();
}

void FirstBuild(){

 glBegin(GL_POLYGON);
    glColor3ub(218, 65, 147);

	glVertex2f(-38.0f, -10.0f);
	glVertex2f(-36.0f, -10.0f);
	glVertex2f(-36.0f, 74.0f);
    glVertex2f(-38.0f, 77.0f);
    glColor3ub(236, 197, 218);
    glVertex2f(-38.0f, 77.0f);
    glVertex2f(-45.0f, 77.0f);
    glVertex2f(-45.0f, -10.0f);
     glVertex2f(-38.0f, -10.0f);
      glEnd();
    }
    void FrstBuildWindow(){
        glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);  //1st window

	glVertex2f(-44.0f, 73.0f);
	glVertex2f(-42.5f, 73.0f);
	glVertex2f(-42.5f, 68.0f);
    glVertex2f(-44.0f, 68.0f);

            glEnd();



            glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //2nd window

	glVertex2f(-41.0f, 73.0f);
	glVertex2f(-39.5f, 73.0f);
	glVertex2f(-39.5f, 68.0f);
    glVertex2f(-41.0f, 68.0f);

            glEnd();

          glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);  //3rd window

	glVertex2f(-44.0f, 62.0f);
	glVertex2f(-42.5f, 62.0f);
	glVertex2f(-42.5f, 57.0f);
    glVertex2f(-44.0f, 57.0f);

            glEnd();



      glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //4rth window

	glVertex2f(-41.0f, 62.0f);
	glVertex2f(-39.5f, 62.0f);
	glVertex2f(-39.5f, 57.0f);
    glVertex2f(-41.0f, 57.0f);

            glEnd();


            glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);  //5th window

	glVertex2f(-44.0f, 51.0f);
	glVertex2f(-42.5f, 51.0f);
	glVertex2f(-42.5f, 46.0f);
    glVertex2f(-44.0f, 46.0f);

            glEnd();


             glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //6th window

	glVertex2f(-41.0f, 51.0f);
	glVertex2f(-39.5f, 51.0f);
	glVertex2f(-39.5f, 46.0f);
    glVertex2f(-41.0f, 46.0f);

            glEnd();

}

void SecondBuilding(){
          glBegin(GL_POLYGON);

           glColor3ub(38, 17, 97);
    glVertex2f(-23.0, 79.0f);
    glVertex2f(-21.0f, 76.0f);
    glVertex2f(-21.0f, -10.0f);
     glVertex2f(-23.0f, -10.0f);
    glColor3ub(191, 185, 208);
	glVertex2f(-23.0f, -10.0f);
	glVertex2f(-30.0f, -10.0f);
	glVertex2f(-30.0f, 79.0f);
    glVertex2f(-23.0f, 79.0f);

      glEnd();
      }

      void secndBuildWindow(){

      glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //1st window

	glVertex2f(-29.0f, 75.0f);
	glVertex2f(-27.5f, 75.0f);
	glVertex2f(-27.5f, 70.0f);
    glVertex2f(-29.0f, 70.0f);
         glEnd();


        glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //2nd window

	glVertex2f(-26.0f, 75.0f);
	glVertex2f(-24.5f, 75.0f);
	glVertex2f(-24.5f, 70.0f);
    glVertex2f(-26.0f, 70.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //3rd window

	glVertex2f(-29.0f, 63.0f);
	glVertex2f(-27.5f, 63.0f);
	glVertex2f(-27.5f, 58.0f);
    glVertex2f(-29.0f, 58.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //4rth window

	glVertex2f(-26.0f, 63.0f);
	glVertex2f(-24.5f, 63.0f);
	glVertex2f(-24.5f, 58.0f);
    glVertex2f(-26.0f, 58.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //5th window

	glVertex2f(-29.0f, 52.0f);
	glVertex2f(-27.5f, 52.0f);
	glVertex2f(-27.5f, 47.0f);
    glVertex2f(-29.0f, 47.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //6th window

	glVertex2f(-26.0f, 52.0f);
	glVertex2f(-24.5f, 52.0f);
	glVertex2f(-24.5f, 47.0f);
    glVertex2f(-26.0f, 47.0f);
         glEnd();
       }

       void thrdBuilding(){

           glBegin(GL_POLYGON);

           glColor3ub(135, 73, 19);
    glVertex2f(-10.0, 79.0f);
    glVertex2f(-8.0f, 76.0f);
    glVertex2f(-8.0f, -10.0f);
     glVertex2f(-10.0f, -10.0f);
    glColor3ub(205, 146, 94);
	glVertex2f(-10.0f, -10.0f);
	glVertex2f(-17.0f, -10.0f);
	glVertex2f(-17.0f, 79.0f);
    glVertex2f(-10.0f, 79.0f);

      glEnd();


       }

       void thirdBildWindow(){

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //1st window

	glVertex2f(-16.0f, 75.0f);
	glVertex2f(-14.5f, 75.0f);
	glVertex2f(-14.5f, 70.0f);
    glVertex2f(-16.0f, 70.0f);
         glEnd();
            glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //2nd window

	glVertex2f(-13.0f, 75.0f);
	glVertex2f(-11.5f, 75.0f);
	glVertex2f(-11.5f, 70.0f);
    glVertex2f(-13.0f, 70.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //3rd window

	glVertex2f(-16.0f, 63.0f);
	glVertex2f(-14.5f, 63.0f);
	glVertex2f(-14.5f, 58.0f);
    glVertex2f(-16.0f, 58.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //4rth window

	glVertex2f(-13.0f, 63.0f);
	glVertex2f(-11.5f, 63.0f);
	glVertex2f(-11.5f, 58.0f);
    glVertex2f(-13.0f, 58.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //5th window

	glVertex2f(-16.0f, 52.0f);
	glVertex2f(-14.5f, 52.0f);
	glVertex2f(-14.5f, 47.0f);
    glVertex2f(-16.0f, 47.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //6th window

	glVertex2f(-13.0f, 52.0f);
	glVertex2f(-11.5f, 52.0f);
	glVertex2f(-11.5f, 47.0f);
    glVertex2f(-13.0f, 47.0f);
         glEnd();


       }
       void FrthBuilding(){

           glBegin(GL_POLYGON);
    glColor3ub(29,122,97);

	 glVertex2f(3.0, 90.0f);
    glVertex2f(5.0f, 87.0f);
    glVertex2f(5.0f, -10.0f);
     glVertex2f(3.0f, -10.0f);
    glColor3ub(108,220,190);
	glVertex2f(3.0f, -10.0f);
	glVertex2f(-4.0f, -10.0f);
	glVertex2f(-4.0f, 90.0f);
    glVertex2f(3.0f, 90.0f);

      glEnd();

      }

      void frthBuildingWindow(){

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //1st1st window

	glVertex2f(-3.0f, 87.0f);
	glVertex2f(-1.5f, 87.0f);
	glVertex2f(-1.5f, 82.5f);
    glVertex2f(-3.0f, 82.5f);
         glEnd();
            glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //2nd2nd window

	glVertex2f(0.0f, 87.0f);
	glVertex2f(1.5f, 87.0f);
	glVertex2f(1.5f, 82.5f);
    glVertex2f(0.0f, 82.5f);
         glEnd();






      glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //1st window

	glVertex2f(-3.0f, 78.0f);
	glVertex2f(-1.5f, 78.0f);
	glVertex2f(-1.5f, 73.0f);
    glVertex2f(-3.0f, 73.0f);
         glEnd();
            glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //2nd window

	glVertex2f(0.0f, 78.0f);
	glVertex2f(1.5f, 78.0f);
	glVertex2f(1.5f, 73.0f);
    glVertex2f(0.0f, 73.0f);
         glEnd();


             glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //3rd window

	glVertex2f(-3.0f, 68.0f);
	glVertex2f(-1.5f, 68.0f);
	glVertex2f(-1.5f, 63.0f);
    glVertex2f(-3.0f, 63.0f);
         glEnd();

         glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //4rth window

	glVertex2f(0.0f, 68.0f);
	glVertex2f(1.5f, 68.0f);
	glVertex2f(1.5f, 63.0f);
    glVertex2f(0.0f, 63.0f);
         glEnd();

          glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //5th window

	glVertex2f(-3.0f, 57.0f);
	glVertex2f(-1.5f, 57.0f);
	glVertex2f(-1.5f, 52.0f);
    glVertex2f(-3.0f, 52.0f);
         glEnd();

         glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //6th window

	glVertex2f(0.0f, 57.0f);
	glVertex2f(1.5f, 57.0f);
	glVertex2f(1.5f, 52.0f);
    glVertex2f(0.0f, 52.0f);
         glEnd();


         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //7th window

	glVertex2f(-3.0f, 47.0f);
	glVertex2f(-1.5f, 47.0f);
	glVertex2f(-1.5f, 42.5f);
    glVertex2f(-3.0f, 42.5f);
         glEnd();

         glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //8th window

	glVertex2f(0.0f, 47.0f);
	glVertex2f(1.5f, 47.0f);
	glVertex2f(1.5f, 42.5f);
    glVertex2f(0.0f, 42.5f);
         glEnd();

      }

      void fthBuilding(){
          glBegin(GL_POLYGON);
    glColor3ub(148,35,23);

	 glVertex2f(16.0, 82.0f);
    glVertex2f(18.0f, 79.0f);
    glVertex2f(18.0f, -10.0f);
     glVertex2f(16.0f, -10.0f);
    glColor3ub(218,101,88);
	glVertex2f(16.0f, -10.0f);
	glVertex2f(9.0f, -10.0f);
	glVertex2f(9.0f, 82.0f);
    glVertex2f(16.0f, 82.0f);

      glEnd();

      }

      void fthBuildingWindow(){
           glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //1st window

	glVertex2f(10.0f, 78.0f);
	glVertex2f(11.5f, 78.0f);
	glVertex2f(11.5f, 73.0f);
    glVertex2f(10.0f, 73.0f);
         glEnd();
            glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //2nd window

	glVertex2f(13.0f, 78.0f);
	glVertex2f(14.5f, 78.0f);
	glVertex2f(14.5f, 73.0f);
    glVertex2f(13.0f, 73.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //3rd window

	glVertex2f(10.0f, 68.0f);
	glVertex2f(11.5f, 68.0f);
	glVertex2f(11.5f, 63.0f);
    glVertex2f(10.0f, 63.0f);
         glEnd();

         glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //4rth window

	glVertex2f(13.0f, 68.0f);
	glVertex2f(14.5f, 68.0f);
	glVertex2f(14.5f, 63.0f);
    glVertex2f(13.0f, 63.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //5th window

	glVertex2f(10.0f, 57.0f);
	glVertex2f(11.5f, 57.0f);
	glVertex2f(11.5f, 52.0f);
    glVertex2f(10.0f, 52.0f);
         glEnd();

         glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //6th window

	glVertex2f(13.0f, 57.0f);
	glVertex2f(14.5f, 57.0f);
	glVertex2f(14.5f, 52.0f);
    glVertex2f(13.0f, 52.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //7th window

	glVertex2f(10.0f, 47.0f);
	glVertex2f(11.5f, 47.0f);
	glVertex2f(11.5f, 42.5f);
    glVertex2f(10.0f, 42.5f);
         glEnd();

         glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //8th window

	glVertex2f(13.0f, 47.0f);
	glVertex2f(14.5f, 47.0f);
	glVertex2f(14.5f, 42.5f);
    glVertex2f(13.0f, 42.5f);
         glEnd();

       }

       void SixBuilding(){

            glBegin(GL_POLYGON);
    glColor3ub(128,128,128);

	 glVertex2f(29.0, 86.0f);
    glVertex2f(31.0f, 83.0f);
    glVertex2f(31.0f, -10.0f);
     glVertex2f(29.0f, -10.0f);
    glColor3ub(192,192,192);
	glVertex2f(29.0f, -10.0f);
	glVertex2f(22.0f, -10.0f);
	glVertex2f(22.0f, 86.0f);
    glVertex2f(29.0f, 86.0f);

      glEnd();


       }

       void SxthBuildingWindow(){
           glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //1st window

	glVertex2f(23.0f, 82.0f);
	glVertex2f(24.5f, 82.0f);
	glVertex2f(24.5f, 77.0f);
    glVertex2f(23.0f, 77.0f);
         glEnd();
            glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //2nd window

	glVertex2f(26.0f, 82.0f);
	glVertex2f(27.5f, 82.0f);
	glVertex2f(27.5f, 77.0f);
    glVertex2f(26.0f, 77.0f);
         glEnd();



       glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //3rd window

	glVertex2f(23.0f, 71.0f);
	glVertex2f(24.5f, 71.0f);
	glVertex2f(24.5f, 66.0f);
    glVertex2f(23.0f, 66.0f);
         glEnd();

         glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //4rth window

	glVertex2f(26.0f, 71.0f);
	glVertex2f(27.5f, 71.0f);
	glVertex2f(27.5f, 66.0f);
    glVertex2f(26.0f, 66.0f);
         glEnd();

          glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //5th window

	glVertex2f(23.0f, 60.0f);
	glVertex2f(24.5f, 60.0f);
	glVertex2f(24.5f, 55.0f);
    glVertex2f(23.0f, 55.0f);
         glEnd();

          glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //6th window

	glVertex2f(26.0f, 60.0f);
	glVertex2f(27.5f, 60.0f);
	glVertex2f(27.5f, 55.0f);
    glVertex2f(26.0f, 55.0f);
         glEnd();

          glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //7th window

	glVertex2f(23.0f, 49.0f);
	glVertex2f(24.5f, 49.0f);
	glVertex2f(24.5f, 44.0f);
    glVertex2f(23.0f, 44.0f);
         glEnd();

          glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //8th window

	glVertex2f(26.0f, 49.0f);
	glVertex2f(27.5f, 49.0f);
	glVertex2f(27.5f, 44.0f);
    glVertex2f(26.0f, 44.0f);
         glEnd();
      }

      void sevenBuilding(){

               glBegin(GL_POLYGON);
    glColor3ub(153,153,0);

	 glVertex2f(41.0, 78.0f);
    glVertex2f(43.0f, 75.0f);
    glVertex2f(43.0f, -10.0f);
     glVertex2f(41.0f, -10.0f);
    glColor3ub(204,204,0);
	glVertex2f(41.0f, -10.0f);
	glVertex2f(34.0f, -10.0f);
	glVertex2f(34.0f, 78.0f);
    glVertex2f(41.0f, 78.0f);

      glEnd();

     }

     void sevenBuildingWindow(){

          glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //1st window

	glVertex2f(35.0f, 74.0f);
	glVertex2f(36.5f, 74.0f);
	glVertex2f(36.5f, 69.0f);
    glVertex2f(35.0f, 69.0f);
         glEnd();

          glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //2nd window

	glVertex2f(38.0f, 74.0f);
	glVertex2f(39.5f, 74.0f);
	glVertex2f(39.5f, 69.0f);
    glVertex2f(38.0f, 69.0f);
         glEnd();

          glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //3rd window

	glVertex2f(35.0f, 63.0f);
	glVertex2f(36.5f, 63.0f);
	glVertex2f(36.5f, 58.0f);
    glVertex2f(35.0f, 58.0f);
         glEnd();

          glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //4th window

	glVertex2f(38.0f, 63.0f);
	glVertex2f(39.5f, 63.0f);
	glVertex2f(39.5f, 58.0f);
    glVertex2f(38.0f, 58.0f);
         glEnd();

          glBegin(GL_QUADS);

       glColor3ub(50, 46, 48);   //5th window

	glVertex2f(35.0f, 52.0f);
	glVertex2f(36.5f, 52.0f);
	glVertex2f(36.5f, 47.0f);
    glVertex2f(35.0f, 47.0f);
         glEnd();

          glBegin(GL_QUADS);

         glColor3ub(50, 46, 48);   //6th window

	glVertex2f(38.0f, 52.0f);
	glVertex2f(39.5f, 52.0f);
	glVertex2f(39.5f, 47.0f);
    glVertex2f(38.0f, 47.0f);
         glEnd();



     }

     void Bus2(){

         txB2=txB2-0.2;
         if(txB2<-50){
        txB2=50;
            }

     glBegin(GL_QUADS);  //red
    glColor3ub(139,69,19);
	glVertex2f(-29.0f, -40.0f);
	glVertex2f(-13.0f, -40.0f);
    glVertex2f(-13.0f, -52.0f);
	glVertex2f(-31.0f, -52.0f);

    glEnd();


     glBegin(GL_QUADS); //blue
    glColor3ub(255,59, 0);
	glVertex2f(-31.0f, -52.0f);
	glVertex2f(-13.0f, -52.0f);
    glVertex2f(-13.0f, -67.0f);
	glVertex2f(-31.0f, -67.0f);

    glEnd();



     glBegin(GL_QUADS); //front glass
    glColor3ub(128, 217, 245);
	glVertex2f(-29.0f, -41.0f);
	glVertex2f(-26.0f, -41.0f);
    glVertex2f(-26.0f, -51.0f);
	glVertex2f(-31.0f, -51.0f);

    glEnd();

     glBegin(GL_QUADS); //r8 window
    glColor3ub(128, 217, 245);
	glVertex2f(-25.0f, -41.0f);
	glVertex2f(-22.0f, -41.0f);
    glVertex2f(-22.0f, -51.0f);
	glVertex2f(-25.0f, -51.0f);

    glEnd();

    glBegin(GL_QUADS); //middle window
    glColor3ub(128, 217, 245);
	glVertex2f(-21.0f, -41.0f);
	glVertex2f(-18.0f, -41.0f);
    glVertex2f(-18.0f, -51.0f);
	glVertex2f(-21.0f, -51.0f);

    glEnd();

    glBegin(GL_QUADS); //right window
    glColor3ub(128, 217, 245);
	glVertex2f(-17.0f, -41.0f);
	glVertex2f(-14.0f, -41.0f);
    glVertex2f(-14.0f, -51.0f);
	glVertex2f(-17.0f, -51.0f);

    glEnd();




    glPushMatrix(); //wheel
        glTranslated(-28,-67,0);
        glScaled(0.5,1.5,0);
        glColor3f(0.0,0.0,0.0);
        circle(3,3);
    glPopMatrix();


    glPushMatrix(); //whee2
        glTranslated(-16,-67,0);
        glScaled(0.5,1.5,0);
        glColor3f(0.0,0.0,0.0);
        circle(3,3);
    glPopMatrix();

glPopMatrix();

glutPostRedisplay();
     }

     void Car(){

          txC=txC+0.3;
         if(txC>90){
            txC=-30;
         }


     glBegin(GL_QUADS);  //upper part
    glColor3ub(205,95,95);
	glVertex2f(-3.0f, -11.0f);
	glVertex2f(3.0f, -11.0f);
    glVertex2f(4.0f, -17.0f);
	glVertex2f(-4.0f, -17.0f);

    glEnd();


     glBegin(GL_QUADS);  //lower part
    glColor3ub(50,205,50);
	glVertex2f(-6.0f, -17.0f);
	glVertex2f(6.0f, -17.0f);
    glVertex2f(7.0f, -27.0f);
	glVertex2f(-6.0f, -27.0f);

    glEnd();


     glBegin(GL_QUADS);  //window1
    glColor3ub(128,117,245);
	glVertex2f(-2.0f, -14.0f);
	glVertex2f(-1.0f,-14.0f);
    glVertex2f(-1.0f,-16.0f);
	glVertex2f(-2.0f, -16.0f);

    glEnd();

         glBegin(GL_QUADS);  //window2
    glColor3ub(128,117,245);
	glVertex2f(1.0f, -14.0f);
	glVertex2f(2.0f, -14.0f);
    glVertex2f(2.0f, -16.0f);
	glVertex2f(1.0f, -16.0f);

    glEnd();

     glBegin(GL_QUADS);  //middle border
    glColor3ub(34,139,34);
	glVertex2f(0.0f, -17.0f);
	glVertex2f(0.3f, -17.0f);
    glVertex2f(0.3f, -25.0f);
	glVertex2f(0.0f, -25.0f);

    glEnd();


    glPushMatrix(); //wheel
        glTranslated(-4,-27,0);
        glScaled(0.5,1.5,0);
        glColor3f(0.0,0.0,0.0);
        circle(2,2);
    glPopMatrix();


    glPushMatrix(); //wheel
        glTranslated(4,-27,0);
        glScaled(0.5,1.5,0);
        glColor3f(0.0,0.0,0.0);
        circle(2,2);
    glPopMatrix();

glPopMatrix();

 glutPostRedisplay();

}



    void FrstBuildWindowN(){
        glBegin(GL_QUADS);

      glColor3ub(243, 243, 57);  //1st window

	glVertex2f(-44.0f, 73.0f);
	glVertex2f(-42.5f, 73.0f);
	glVertex2f(-42.5f, 68.0f);
    glVertex2f(-44.0f, 68.0f);

            glEnd();



            glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //2nd window

	glVertex2f(-41.0f, 73.0f);
	glVertex2f(-39.5f, 73.0f);
	glVertex2f(-39.5f, 68.0f);
    glVertex2f(-41.0f, 68.0f);

            glEnd();

          glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);  //3rd window

	glVertex2f(-44.0f, 62.0f);
	glVertex2f(-42.5f, 62.0f);
	glVertex2f(-42.5f, 57.0f);
    glVertex2f(-44.0f, 57.0f);

            glEnd();



      glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);  //4rth window

	glVertex2f(-41.0f, 62.0f);
	glVertex2f(-39.5f, 62.0f);
	glVertex2f(-39.5f, 57.0f);
    glVertex2f(-41.0f, 57.0f);

            glEnd();


            glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);  //5th window

	glVertex2f(-44.0f, 51.0f);
	glVertex2f(-42.5f, 51.0f);
	glVertex2f(-42.5f, 46.0f);
    glVertex2f(-44.0f, 46.0f);

            glEnd();


             glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);
	glVertex2f(-41.0f, 51.0f);
	glVertex2f(-39.5f, 51.0f);
	glVertex2f(-39.5f, 46.0f);
    glVertex2f(-41.0f, 46.0f);

            glEnd();

}


      void secndBuildWindowN(){

      glBegin(GL_QUADS);

      glColor3ub(243, 243, 57);   //1st window

	glVertex2f(-29.0f, 75.0f);
	glVertex2f(-27.5f, 75.0f);
	glVertex2f(-27.5f, 70.0f);
    glVertex2f(-29.0f, 70.0f);
         glEnd();


        glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //2nd window

	glVertex2f(-26.0f, 75.0f);
	glVertex2f(-24.5f, 75.0f);
	glVertex2f(-24.5f, 70.0f);
    glVertex2f(-26.0f, 70.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //3rd window

	glVertex2f(-29.0f, 63.0f);
	glVertex2f(-27.5f, 63.0f);
	glVertex2f(-27.5f, 58.0f);
    glVertex2f(-29.0f, 58.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //4rth window

	glVertex2f(-26.0f, 63.0f);
	glVertex2f(-24.5f, 63.0f);
	glVertex2f(-24.5f, 58.0f);
    glVertex2f(-26.0f, 58.0f);
         glEnd();

         glBegin(GL_QUADS);

      glColor3ub(243, 243, 57);   //5th window

	glVertex2f(-29.0f, 52.0f);
	glVertex2f(-27.5f, 52.0f);
	glVertex2f(-27.5f, 47.0f);
    glVertex2f(-29.0f, 47.0f);
         glEnd();

         glBegin(GL_QUADS);

     glColor3ub(243, 243, 57);   //6th window

	glVertex2f(-26.0f, 52.0f);
	glVertex2f(-24.5f, 52.0f);
	glVertex2f(-24.5f, 47.0f);
    glVertex2f(-26.0f, 47.0f);
         glEnd();
       }



       void thirdBildWindowN(){

         glBegin(GL_QUADS);

      glColor3ub(243, 243, 57);   //1st window

	glVertex2f(-16.0f, 75.0f);
	glVertex2f(-14.5f, 75.0f);
	glVertex2f(-14.5f, 70.0f);
    glVertex2f(-16.0f, 70.0f);
         glEnd();
            glBegin(GL_QUADS);

        glColor3ub(243, 243, 57);   //2nd window

	glVertex2f(-13.0f, 75.0f);
	glVertex2f(-11.5f, 75.0f);
	glVertex2f(-11.5f, 70.0f);
    glVertex2f(-13.0f, 70.0f);
         glEnd();

         glBegin(GL_QUADS);

     glColor3ub(243, 243, 57);   //3rd window

	glVertex2f(-16.0f, 63.0f);
	glVertex2f(-14.5f, 63.0f);
	glVertex2f(-14.5f, 58.0f);
    glVertex2f(-16.0f, 58.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //4rth window

	glVertex2f(-13.0f, 63.0f);
	glVertex2f(-11.5f, 63.0f);
	glVertex2f(-11.5f, 58.0f);
    glVertex2f(-13.0f, 58.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //5th window

	glVertex2f(-16.0f, 52.0f);
	glVertex2f(-14.5f, 52.0f);
	glVertex2f(-14.5f, 47.0f);
    glVertex2f(-16.0f, 47.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //6th window

	glVertex2f(-13.0f, 52.0f);
	glVertex2f(-11.5f, 52.0f);
	glVertex2f(-11.5f, 47.0f);
    glVertex2f(-13.0f, 47.0f);
         glEnd();


       }

      void frthBuildingWindowN(){

         glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);  //1st1st window

	glVertex2f(-3.0f, 87.0f);
	glVertex2f(-1.5f, 87.0f);
	glVertex2f(-1.5f, 82.5f);
    glVertex2f(-3.0f, 82.5f);
         glEnd();
            glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //2nd2nd window

	glVertex2f(0.0f, 87.0f);
	glVertex2f(1.5f, 87.0f);
	glVertex2f(1.5f, 82.5f);
    glVertex2f(0.0f, 82.5f);
         glEnd();






      glBegin(GL_QUADS);

      glColor3ub(243, 243, 57);  //1st window

	glVertex2f(-3.0f, 78.0f);
	glVertex2f(-1.5f, 78.0f);
	glVertex2f(-1.5f, 73.0f);
    glVertex2f(-3.0f, 73.0f);
         glEnd();
            glBegin(GL_QUADS);

         glColor3ub(243, 243, 57);   //2nd window

	glVertex2f(0.0f, 78.0f);
	glVertex2f(1.5f, 78.0f);
	glVertex2f(1.5f, 73.0f);
    glVertex2f(0.0f, 73.0f);
         glEnd();


             glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //3rd window

	glVertex2f(-3.0f, 68.0f);
	glVertex2f(-1.5f, 68.0f);
	glVertex2f(-1.5f, 63.0f);
    glVertex2f(-3.0f, 63.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);  //4rth window

	glVertex2f(0.0f, 68.0f);
	glVertex2f(1.5f, 68.0f);
	glVertex2f(1.5f, 63.0f);
    glVertex2f(0.0f, 63.0f);
         glEnd();

          glBegin(GL_QUADS);

      glColor3ub(243, 243, 57);   //5th window

	glVertex2f(-3.0f, 57.0f);
	glVertex2f(-1.5f, 57.0f);
	glVertex2f(-1.5f, 52.0f);
    glVertex2f(-3.0f, 52.0f);
         glEnd();

         glBegin(GL_QUADS);

         glColor3ub(243, 243, 57);   //6th window

	glVertex2f(0.0f, 57.0f);
	glVertex2f(1.5f, 57.0f);
	glVertex2f(1.5f, 52.0f);
    glVertex2f(0.0f, 52.0f);
         glEnd();


         glBegin(GL_QUADS);
glColor3ub(243, 243, 57);   //7th window

	glVertex2f(-3.0f, 47.0f);
	glVertex2f(-1.5f, 47.0f);
	glVertex2f(-1.5f, 42.5f);
    glVertex2f(-3.0f, 42.5f);
         glEnd();

         glBegin(GL_QUADS);

        glColor3ub(243, 243, 57);  //8th window

	glVertex2f(0.0f, 47.0f);
	glVertex2f(1.5f, 47.0f);
	glVertex2f(1.5f, 42.5f);
    glVertex2f(0.0f, 42.5f);
         glEnd();

      }



      void fthBuildingWindowN(){
           glBegin(GL_QUADS);

      glColor3ub(243, 243, 57);  //1st window

	glVertex2f(10.0f, 78.0f);
	glVertex2f(11.5f, 78.0f);
	glVertex2f(11.5f, 73.0f);
    glVertex2f(10.0f, 73.0f);
         glEnd();
            glBegin(GL_QUADS);

         glColor3ub(243, 243, 57);   //2nd window

	glVertex2f(13.0f, 78.0f);
	glVertex2f(14.5f, 78.0f);
	glVertex2f(14.5f, 73.0f);
    glVertex2f(13.0f, 73.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //3rd window

	glVertex2f(10.0f, 68.0f);
	glVertex2f(11.5f, 68.0f);
	glVertex2f(11.5f, 63.0f);
    glVertex2f(10.0f, 63.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //4rth window

	glVertex2f(13.0f, 68.0f);
	glVertex2f(14.5f, 68.0f);
	glVertex2f(14.5f, 63.0f);
    glVertex2f(13.0f, 63.0f);
         glEnd();

         glBegin(GL_QUADS);

     glColor3ub(243, 243, 57);  //5th window

	glVertex2f(10.0f, 57.0f);
	glVertex2f(11.5f, 57.0f);
	glVertex2f(11.5f, 52.0f);
    glVertex2f(10.0f, 52.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //6th window

	glVertex2f(13.0f, 57.0f);
	glVertex2f(14.5f, 57.0f);
	glVertex2f(14.5f, 52.0f);
    glVertex2f(13.0f, 52.0f);
         glEnd();

         glBegin(GL_QUADS);

      glColor3ub(243, 243, 57);   //7th window

	glVertex2f(10.0f, 47.0f);
	glVertex2f(11.5f, 47.0f);
	glVertex2f(11.5f, 42.5f);
    glVertex2f(10.0f, 42.5f);
         glEnd();

         glBegin(GL_QUADS);

         glColor3ub(243, 243, 57);   //8th window

	glVertex2f(13.0f, 47.0f);
	glVertex2f(14.5f, 47.0f);
	glVertex2f(14.5f, 42.5f);
    glVertex2f(13.0f, 42.5f);
         glEnd();

       }



       void SxthBuildingWindowN(){
           glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //1st window

	glVertex2f(23.0f, 82.0f);
	glVertex2f(24.5f, 82.0f);
	glVertex2f(24.5f, 77.0f);
    glVertex2f(23.0f, 77.0f);
         glEnd();
            glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //2nd window

	glVertex2f(26.0f, 82.0f);
	glVertex2f(27.5f, 82.0f);
	glVertex2f(27.5f, 77.0f);
    glVertex2f(26.0f, 77.0f);
         glEnd();



       glBegin(GL_QUADS);

      glColor3ub(243, 243, 57);   //3rd window

	glVertex2f(23.0f, 71.0f);
	glVertex2f(24.5f, 71.0f);
	glVertex2f(24.5f, 66.0f);
    glVertex2f(23.0f, 66.0f);
         glEnd();

         glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //4rth window

	glVertex2f(26.0f, 71.0f);
	glVertex2f(27.5f, 71.0f);
	glVertex2f(27.5f, 66.0f);
    glVertex2f(26.0f, 66.0f);
         glEnd();

          glBegin(GL_QUADS);

     glColor3ub(243, 243, 57);   //5th window

	glVertex2f(23.0f, 60.0f);
	glVertex2f(24.5f, 60.0f);
	glVertex2f(24.5f, 55.0f);
    glVertex2f(23.0f, 55.0f);
         glEnd();

          glBegin(GL_QUADS);

        glColor3ub(243, 243, 57);   //6th window

	glVertex2f(26.0f, 60.0f);
	glVertex2f(27.5f, 60.0f);
	glVertex2f(27.5f, 55.0f);
    glVertex2f(26.0f, 55.0f);
         glEnd();

          glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //7th window

	glVertex2f(23.0f, 49.0f);
	glVertex2f(24.5f, 49.0f);
	glVertex2f(24.5f, 44.0f);
    glVertex2f(23.0f, 44.0f);
         glEnd();

          glBegin(GL_QUADS);

         glColor3ub(243, 243, 57);   //8th window

	glVertex2f(26.0f, 49.0f);
	glVertex2f(27.5f, 49.0f);
	glVertex2f(27.5f, 44.0f);
    glVertex2f(26.0f, 44.0f);
         glEnd();
      }



     void sevenBuildingWindowN(){

          glBegin(GL_QUADS);

     glColor3ub(243, 243, 57);   //1st window

	glVertex2f(35.0f, 74.0f);
	glVertex2f(36.5f, 74.0f);
	glVertex2f(36.5f, 69.0f);
    glVertex2f(35.0f, 69.0f);
         glEnd();

          glBegin(GL_QUADS);

        glColor3ub(243, 243, 57);   //2nd window

	glVertex2f(38.0f, 74.0f);
	glVertex2f(39.5f, 74.0f);
	glVertex2f(39.5f, 69.0f);
    glVertex2f(38.0f, 69.0f);
         glEnd();

          glBegin(GL_QUADS);

     glColor3ub(243, 243, 57);   //3rd window

	glVertex2f(35.0f, 63.0f);
	glVertex2f(36.5f, 63.0f);
	glVertex2f(36.5f, 58.0f);
    glVertex2f(35.0f, 58.0f);
         glEnd();

          glBegin(GL_QUADS);

       glColor3ub(243, 243, 57);   //4th window

	glVertex2f(38.0f, 63.0f);
	glVertex2f(39.5f, 63.0f);
	glVertex2f(39.5f, 58.0f);
    glVertex2f(38.0f, 58.0f);
         glEnd();

          glBegin(GL_QUADS);

     glColor3ub(243, 243, 57);   //5th window

	glVertex2f(35.0f, 52.0f);
	glVertex2f(36.5f, 52.0f);
	glVertex2f(36.5f, 47.0f);
    glVertex2f(35.0f, 47.0f);
         glEnd();

          glBegin(GL_QUADS);

        glColor3ub(243, 243, 57);   //6th window

	glVertex2f(38.0f, 52.0f);
	glVertex2f(39.5f, 52.0f);
	glVertex2f(39.5f, 47.0f);
    glVertex2f(38.0f, 47.0f);
         glEnd();



     }

void CarN(){

          txC=txC+.3;
         if(txC>90){
            txC=-30;
         }


     glBegin(GL_QUADS);  //upper part
    glColor3ub(205,95,95);
	glVertex2f(-3.0f, -11.0f);
	glVertex2f(3.0f, -11.0f);
    glVertex2f(4.0f, -17.0f);
	glVertex2f(-4.0f, -17.0f);

    glEnd();


     glBegin(GL_QUADS);  //lower part
    glColor3ub(50,205,50);
	glVertex2f(-6.0f, -17.0f);
	glVertex2f(6.0f, -17.0f);
    glVertex2f(7.0f, -27.0f);
	glVertex2f(-6.0f, -27.0f);

    glEnd();


     glBegin(GL_QUADS);  //window1
   glColor3ub(243, 243, 57);
	glVertex2f(-2.0f, -14.0f);
	glVertex2f(-1.0f,-14.0f);
    glVertex2f(-1.0f,-16.0f);
	glVertex2f(-2.0f, -16.0f);

    glEnd();

         glBegin(GL_QUADS);  //window2
   glColor3ub(243, 243, 57);
	glVertex2f(1.0f, -14.0f);
	glVertex2f(2.0f, -14.0f);
    glVertex2f(2.0f, -16.0f);
	glVertex2f(1.0f, -16.0f);

    glEnd();

     glBegin(GL_QUADS);  //middle border
    glColor3ub(34,139,34);
	glVertex2f(0.0f, -17.0f);
	glVertex2f(0.3f, -17.0f);
    glVertex2f(0.3f, -25.0f);
	glVertex2f(0.0f, -25.0f);

    glEnd();


    glPushMatrix(); //wheel
        glTranslated(-4,-27,0);
        glScaled(0.5,1.5,0);
        glColor3f(0.0,0.0,0.0);
        circle(2,2);
    glPopMatrix();


    glPushMatrix(); //wheel
        glTranslated(4,-27,0);
        glScaled(0.5,1.5,0);
        glColor3f(0.0,0.0,0.0);
        circle(2,2);
    glPopMatrix();

glPopMatrix();

 glutPostRedisplay();

}

void Bus2N(){

         txB2=txB2-0.2;
         if(txB2<-50){
        txB2=50;
            }

     glBegin(GL_QUADS);  //red
    glColor3ub(139,69,19);
	glVertex2f(-29.0f, -40.0f);
	glVertex2f(-13.0f, -40.0f);
    glVertex2f(-13.0f, -52.0f);
	glVertex2f(-31.0f, -52.0f);

    glEnd();


     glBegin(GL_QUADS); //blue
    glColor3ub(255,59, 0);
	glVertex2f(-31.0f, -52.0f);
	glVertex2f(-13.0f, -52.0f);
    glVertex2f(-13.0f, -67.0f);
	glVertex2f(-31.0f, -67.0f);

    glEnd();



     glBegin(GL_QUADS); //front glass
   glColor3ub(243, 243, 57);
	glVertex2f(-29.0f, -41.0f);
	glVertex2f(-26.0f, -41.0f);
    glVertex2f(-26.0f, -51.0f);
	glVertex2f(-31.0f, -51.0f);

    glEnd();

     glBegin(GL_QUADS); //r8 window
   glColor3ub(243, 243, 57);
	glVertex2f(-25.0f, -41.0f);
	glVertex2f(-22.0f, -41.0f);
    glVertex2f(-22.0f, -51.0f);
	glVertex2f(-25.0f, -51.0f);

    glEnd();

    glBegin(GL_QUADS); //middle window
    glColor3ub(243, 243, 57);
	glVertex2f(-21.0f, -41.0f);
	glVertex2f(-18.0f, -41.0f);
    glVertex2f(-18.0f, -51.0f);
	glVertex2f(-21.0f, -51.0f);

    glEnd();

    glBegin(GL_QUADS); //right window
  glColor3ub(243, 243, 57);
	glVertex2f(-17.0f, -41.0f);
	glVertex2f(-14.0f, -41.0f);
    glVertex2f(-14.0f, -51.0f);
	glVertex2f(-17.0f, -51.0f);

    glEnd();




    glPushMatrix(); //wheel
        glTranslated(-28,-67,0);
        glScaled(0.5,1.5,0);
        glColor3f(0.0,0.0,0.0);
        circle(3,3);
    glPopMatrix();


    glPushMatrix(); //whee2
        glTranslated(-16,-67,0);
        glScaled(0.5,1.5,0);
        glColor3f(0.0,0.0,0.0);
        circle(3,3);
    glPopMatrix();

glPopMatrix();

glutPostRedisplay();
     }


void Rain(){

     tyR=tyR-11;
         if(tyR<-190){
            tyR=100;
         }


         glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-49.0f, 110.0f);
	glVertex2f(-48.5f, 110.0f);
	glVertex2f(-48.5f, 100.0f);
	glVertex2f(-49.0f, 110.0f);
        glEnd();



        glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-49.0f, 30.0f);
	glVertex2f(-48.5f, 30.0f);
	glVertex2f(-48.5f, 20.0f);
	glVertex2f(-49.0f, 30.0f);
        glEnd();


        glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-49.0f, -50.0f);
	glVertex2f(-48.5f, -50.0f);
	glVertex2f(-48.5f, -60.0f);
	glVertex2f(-49.0f, -50.0f);
        glEnd();



         glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-45.0f, 70.0f);
	glVertex2f(-44.5f, 70.0f);
	glVertex2f(-44.5f, 60.0f);
	glVertex2f(-45.0f, 70.0f);
        glEnd();


        glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-45.0f, -10.0f);
	glVertex2f(-44.5f, -10.0f);
	glVertex2f(-44.5f, -20.0f);
	glVertex2f(-45.0f, -10.0f);
        glEnd();




           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-41.0f, 70.0f);
	glVertex2f(-40.5f, 70.0f);
	glVertex2f(-40.5f, 60.0f);
	glVertex2f(-41.0f, 70.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-41.0f, -10.0f);
	glVertex2f(-40.5f, -10.0f);
	glVertex2f(-40.5f, -20.0f);
	glVertex2f(-41.0f, -10.0f);
           glEnd();




            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-37.0f, 70.0f);
	glVertex2f(-36.5f, 70.0f);
	glVertex2f(-36.5f, 60.0f);
	glVertex2f(-37.0f, 70.0f);
           glEnd();





            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-37.0f, -10.0f);
	glVertex2f(-36.5f, -10.0f);
	glVertex2f(-36.5f, -20.0f);
	glVertex2f(-37.0f, -10.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-33.0f, 70.0f);
	glVertex2f(-32.5f, 70.0f);
	glVertex2f(-32.5f, 60.0f);
	glVertex2f(-33.0f, 70.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-33.0f, -10.0f);
	glVertex2f(-32.5f, -10.0f);
	glVertex2f(-32.5f, -20.0f);
	glVertex2f(-33.0f, -10.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-29.0f, 70.0f);
	glVertex2f(-28.5f, 70.0f);
	glVertex2f(-28.5f, 60.0f);
	glVertex2f(-29.0f, 70.0f);
           glEnd();



            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-29.0f, -10.0f);
	glVertex2f(-28.5f, -10.0f);
	glVertex2f(-28.5f, -20.0f);
	glVertex2f(-29.0f, -10.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-25.0f, 70.0f);
	glVertex2f(-24.5f, 70.0f);
	glVertex2f(-24.5f, 60.0f);
	glVertex2f(-25.0f, 70.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-25.0f, -10.0f);
	glVertex2f(-24.5f, -10.0f);
	glVertex2f(-24.5f, -20.0f);
	glVertex2f(-25.0f, -10.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-21.0f, 70.0f);
	glVertex2f(-20.5f, 70.0f);
	glVertex2f(-20.5f, 60.0f);
	glVertex2f(-21.0f, 70.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-21.0f, -10.0f);
	glVertex2f(-20.5f, -10.0f);
	glVertex2f(-20.5f, -20.0f);
	glVertex2f(-21.0f, -10.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-17.0f, 70.0f);
	glVertex2f(-16.5f, 70.0f);
	glVertex2f(-16.5f, 60.0f);
	glVertex2f(-17.0f, 70.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-17.0f, -10.0f);
	glVertex2f(-16.5f, -10.0f);
	glVertex2f(-16.5f, -20.0f);
	glVertex2f(-17.0f, -10.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-13.0f, 70.0f);
	glVertex2f(-12.5f, 70.0f);
	glVertex2f(-12.5f, 60.0f);
	glVertex2f(-13.0f, 70.0f);
           glEnd();


           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-13.0f, -10.0f);
	glVertex2f(-12.5f, -10.0f);
	glVertex2f(-12.5f, -20.0f);
	glVertex2f(-13.0f, -10.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-9.0f, 70.0f);
	glVertex2f(-8.5f, 70.0f);
	glVertex2f(-8.5f, 60.0f);
	glVertex2f(-9.0f, 70.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-9.0f, -10.0f);
	glVertex2f(-8.5f, -10.0f);
	glVertex2f(-8.5f, -20.0f);
	glVertex2f(-9.0f, -10.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-5.0f, 70.0f);
	glVertex2f(-4.5f, 70.0f);
	glVertex2f(-4.5f, 60.0f);
	glVertex2f(-5.0f, 70.0f);
           glEnd();


           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-5.0f, -10.0f);
	glVertex2f(-4.5f, -10.0f);
	glVertex2f(-4.5f, -20.0f);
	glVertex2f(-5.0f, -10.0f);
           glEnd();


           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-1.0f, 70.0f);
	glVertex2f(-0.5f, 70.0f);
	glVertex2f(-0.5f, 60.0f);
	glVertex2f(-1.0f, 70.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(-1.0f, -10.0f);
	glVertex2f(-0.5f, -10.0f);
	glVertex2f(-0.5f, -20.0f);
	glVertex2f(-1.0f, -10.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(3.0f, 70.0f);
	glVertex2f(3.5f, 70.0f);
	glVertex2f(3.5f, 60.0f);
	glVertex2f(3.0f, 70.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(3.0f, -10.0f);
	glVertex2f(3.5f, -10.0f);
	glVertex2f(3.5f, -20.0f);
	glVertex2f(3.0f, -10.0f);
           glEnd();


           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(7.0f, 70.0f);
	glVertex2f(7.5f, 70.0f);
	glVertex2f(7.5f, 60.0f);
	glVertex2f(7.0f, 70.0f);
           glEnd();


           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(7.0f, -10.0f);
	glVertex2f(7.5f, -10.0f);
	glVertex2f(7.5f, -20.0f);
	glVertex2f(7.0f, -10.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(11.0f, 70.0f);
	glVertex2f(11.5f, 70.0f);
	glVertex2f(11.5f, 60.0f);
	glVertex2f(11.0f, 70.0f);
           glEnd();


           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(11.0f, -10.0f);
	glVertex2f(11.5f, -10.0f);
	glVertex2f(11.5f, -20.0f);
	glVertex2f(11.0f, -10.0f);
           glEnd();


           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(15.0f, 70.0f);
	glVertex2f(15.5f, 70.0f);
	glVertex2f(15.5f, 60.0f);
	glVertex2f(15.0f, 70.0f);
           glEnd();


           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(15.0f, -10.0f);
	glVertex2f(15.5f, -10.0f);
	glVertex2f(15.5f, -20.0f);
	glVertex2f(15.0f, -10.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(19.0f, 70.0f);
	glVertex2f(19.5f, 70.0f);
	glVertex2f(19.5f, 60.0f);
	glVertex2f(19.0f, 70.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(19.0f, -10.0f);
	glVertex2f(19.5f, -10.0f);
	glVertex2f(19.5f, -20.0f);
	glVertex2f(19.0f, -10.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(23.0f, 70.0f);
	glVertex2f(23.5f, 70.0f);
	glVertex2f(23.5f, 60.0f);
	glVertex2f(23.0f, 70.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(23.0f, -10.0f);
	glVertex2f(23.5f, -10.0f);
	glVertex2f(23.5f, -20.0f);
	glVertex2f(23.0f, -10.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(27.0f, 70.0f);
	glVertex2f(27.5f, 70.0f);
	glVertex2f(27.5f, 60.0f);
	glVertex2f(27.0f, 70.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(27.0f, -10.0f);
	glVertex2f(27.5f, -10.0f);
	glVertex2f(27.5f, -20.0f);
	glVertex2f(27.0f, -10.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(31.0f, 70.0f);
	glVertex2f(31.5f, 70.0f);
	glVertex2f(31.5f, 60.0f);
	glVertex2f(31.0f, 70.0f);
           glEnd();

           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(31.0f, -10.0f);
	glVertex2f(31.5f, -10.0f);
	glVertex2f(31.5f, -20.0f);
	glVertex2f(31.0f, -10.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(35.0f, 70.0f);
	glVertex2f(35.5f, 70.0f);
	glVertex2f(35.5f, 60.0f);
	glVertex2f(35.0f, 70.0f);
           glEnd();

            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(35.0f, -10.0f);
	glVertex2f(35.5f, -10.0f);
	glVertex2f(35.5f, -20.0f);
	glVertex2f(35.0f, -10.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(39.0f, 70.0f);
	glVertex2f(39.5f, 70.0f);
	glVertex2f(39.5f, 60.0f);
	glVertex2f(39.0f, 70.0f);
           glEnd();


            glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(39.0f, -10.0f);
	glVertex2f(39.5f, -10.0f);
	glVertex2f(39.5f, -20.0f);
	glVertex2f(39.0f, -10.0f);
           glEnd();



           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(43.0f, 70.0f);
	glVertex2f(43.5f, 70.0f);
	glVertex2f(43.5f, 60.0f);
	glVertex2f(43.0f, 70.0f);
           glEnd();


           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(43.0f, -10.0f);
	glVertex2f(43.5f, -10.0f);
	glVertex2f(43.5f, -20.0f);
	glVertex2f(43.0f, -10.0f);
           glEnd();


           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(47.0f, 70.0f);
	glVertex2f(47.5f, 70.0f);
	glVertex2f(47.5f, 60.0f);
	glVertex2f(47.0f, 70.0f);
           glEnd();


           glBegin(GL_QUADS);

       glColor3ub(160, 160, 160);

	glVertex2f(47.0f, -10.0f);
	glVertex2f(47.5f, -10.0f);
	glVertex2f(47.5f, -20.0f);
	glVertex2f(47.0f, -10.0f);
           glEnd();


            glutPostRedisplay();


}





    void Daydisplay(void){

    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    Roadborder();
    Road();
    footpath();
    sun();


     glPushMatrix(); // Draws The Bus1
    glTranslatef(tx,ty,0);
    glPopMatrix();


  glPushMatrix(); // Draws The Bus1
    glTranslatef(txB2,tyB2,0);
     Bus2();
    glPopMatrix();

    glPushMatrix(); // Draws The Car
    glTranslatef(txC,tyC,0);
     Car();
    glPopMatrix();


    glPushMatrix(); // Draws The ship
    glTranslatef(txS,tyS,0);
    glPopMatrix();

     cloudLeft();
    cloudRight();

    glPushMatrix(); // Draws The airoplane
    glTranslatef(txA,tyA,0);

    glPopMatrix();

    cloudMiddle();

    FirstBuild();

      FrstBuildWindow();
      SecondBuilding();
      secndBuildWindow();
      thrdBuilding();
      thirdBildWindow();
      FrthBuilding();
      frthBuildingWindow();
      fthBuilding();
      fthBuildingWindow();
      SixBuilding();
      SxthBuildingWindow();
       sevenBuilding();
       sevenBuildingWindow();




	glFlush();
}

void NightDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    skyN();
    Roadborder();
    Road();
    footpath();



     glPushMatrix(); // Draws The Bus1
    glTranslatef(tx,ty,0);
    glPopMatrix();


  glPushMatrix(); // Draws The Bus1
    glTranslatef(txB2,tyB2,0);
     Bus2N();
    glPopMatrix();

    glPushMatrix(); // Draws The Car
    glTranslatef(txC,tyC,0);
     CarN();
    glPopMatrix();


    glPushMatrix(); // Draws The ship
    glTranslatef(txS,tyS,0);
    glPopMatrix();
       moon();
     cloudLeft();
    cloudRight();

    glPushMatrix(); // Draws The airoplane
    glTranslatef(txA,tyA,0);

    glPopMatrix();

    cloudMiddle();


    FirstBuild();

      FrstBuildWindowN();
      SecondBuilding();
      secndBuildWindowN();
      thrdBuilding();
      thirdBildWindowN();
      FrthBuilding();
      frthBuildingWindowN();
      fthBuilding();
      fthBuildingWindowN();
      SixBuilding();
      SxthBuildingWindowN();
       sevenBuilding();
       sevenBuildingWindowN();

	glFlush();
}

void RainDisplay(){

     glClear(GL_COLOR_BUFFER_BIT);
    skyR();
    Roadborder();
    Road();
    footpath();
    sunR();


     glPushMatrix(); // Draws The Bus1
    glTranslatef(tx,ty,0);
    glPopMatrix();


  glPushMatrix(); // Draws The Bus1
    glTranslatef(txB2,tyB2,0);
     Bus2();
    glPopMatrix();

    glPushMatrix(); // Draws The Car
    glTranslatef(txC,tyC,0);
     Car();
    glPopMatrix();


    glPushMatrix(); // Draws The ship
    glTranslatef(txS,tyS,0);
    glPopMatrix();

     cloudLeft();
    cloudRight();

    glPushMatrix(); // Draws The airoplane
    glTranslatef(txA,tyA,0);

    glPopMatrix();

    cloudMiddle();

    FirstBuild();

      FrstBuildWindow();
      SecondBuilding();
      secndBuildWindow();
      thrdBuilding();
      thirdBildWindow();
      FrthBuilding();
      frthBuildingWindow();
      fthBuilding();
      fthBuildingWindow();
      SixBuilding();
      SxthBuildingWindow();
      sevenBuilding();
      sevenBuildingWindow();

        glPushMatrix(); // Draws The Rain
    glTranslatef(txR,tyR,0);
     Rain();
    glPopMatrix();
   glFlush();
   }

   void Display(){
       screen();
       introscreen();
       glFlush();
       glutPostRedisplay();


   }

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GLUT_SINGLE| GLUT_RGB);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -90.0, 110.0, -50.0, 50.0);
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'd':

			glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	     glutInitWindowSize (1600, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Day scenerio");
      init();
	glutKeyboardFunc(my_keyboard);

	glutDisplayFunc(Daydisplay);
	PlaySound("music.wav",NULL,SND_FILENAME|SND_ASYNC);
	glutPostRedisplay();
			break;

		case 'n':
			glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	     glutInitWindowSize (1600, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Night scenerio");
    init();
	glutKeyboardFunc(my_keyboard);
	glutDisplayFunc(NightDisplay);
     PlaySound("music.wav",NULL,SND_FILENAME|SND_ASYNC);
	glutPostRedisplay();
			break;

			case 'r':
			glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	     glutInitWindowSize (1600, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Rain scenerio");
    init();
	glutKeyboardFunc(my_keyboard);
	glutDisplayFunc(RainDisplay);
    PlaySound("rain-02.wav",NULL,SND_FILENAME|SND_ASYNC);
	glutPostRedisplay();
			break;



	  default:
			break;
	}
}

int main(int arg, char **argv)
{
    glutInit(&arg, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1600, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("City View");
	init();
	glutKeyboardFunc(my_keyboard);
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}



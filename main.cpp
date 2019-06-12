#include <iostream>
#include <GL/glut.h>

using namespace std;

void drawLine();
void inputData();
void CoordinateAxes();

float x1, y1, x2, y2, x, y, dx, dy, stepsize, xInc, yInc;

int main(int argc, char** argv)
{
    inputData();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500,500);

    glutCreateWindow("DDA Algorithm");
    glutDisplayFunc(drawLine);

    glutMainLoop();
    return 0;
}

void drawLine()
{
    glClear(GL_COLOR_BUFFER_BIT);
    CoordinateAxes();

    glColor3ub(255 ,255,255);
    glBegin(GL_POINTS);

        dx = x2 - x1;
        dy = y2 - y1;

        if(abs(dx) > abs(dy))
        {
            stepsize = abs(dx);
        }
        else
        {
            stepsize = abs(dy);
        }
        xInc = dx/stepsize;
        yInc = dy/stepsize;

        x = x1;
        y = y1;

        for(int i = 0; i < stepsize; i++)
        {
            glVertex2f(x/500, y/500);
            x += xInc;
            y += yInc;
        }

    glEnd();
    glFlush();
}


void inputData()
{
    cout << "Enter (x1,y1): ";
    cin >> x1 >> y1;

    cout << "Enter (x2,y2): ";
    cin >> x2 >> y2;
}

void CoordinateAxes()
{
    glColor3ub(0,0,255);
    glBegin(GL_LINES);
        glVertex2f(0,1);
        glVertex2f(0,-1);
        glVertex2f(-1,0);
        glVertex2f(1,0);
    glEnd();
}

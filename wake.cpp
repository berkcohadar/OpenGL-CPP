#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <map>

using namespace std;

map<int, int> mouseLocations;

/* Initialize OpenGL Graphics */
void initGL() {
   // Set "clearing" or background color
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode (GL_PROJECTION);        //Viewport
    gluOrtho2D( 0.0,400.0,0.0,400.0);
}

void processMouseButton(int button, int state, int x, int y) {
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    
    if (button == GLUT_LEFT_BUTTON && state == 0) {
        cout << x << " " << y << " " << state << endl;
        mouseLocations.insert(pair<int, int>(x,y));
    }

    if (button == GLUT_RIGHT_BUTTON && state == 1) {
        map<int, int>::iterator it1;
        map<int, int>::iterator it2;
        it2 = mouseLocations.begin();
        it2 ++;
        for (it1 = mouseLocations.begin(); it2 != mouseLocations.end(); it1++)
        {
            glBegin(GL_LINES);          // Each set of 3 vertices form a triangle

            glVertex3f(it1->first*(5/3), abs((it1->second*(5/3))-300), 0.0);
            glVertex3f(it2->first*(5/3), abs((it2->second*(5/3))-300), 0.0);
            it2++;

            glEnd();
            glFlush();

        }
        mouseLocations.clear();
    }

}

void printMap() {
    for(const auto& elem : mouseLocations) {
        std::cout << elem.first << " " << elem.second << "\n";
    }
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInitWindowSize(500, 300);   // Set the window's initial width & height
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    glutInit(&argc, argv);          // Initialize GLUT

    glutCreateWindow("MAIN FRAME");  // Create window with the given title

    glutMouseFunc(processMouseButton);

    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}



//#include <GLFW/glfw3.h>
//#include<Windows.h>
//#include<cmath>
//
////void sonysf();
////void drawLine(float cx, float cy, float n);
////void rotatecube();
////void scalesqure();
////void reflection();
////void transsqure();
////void drawAstroid();
//void  rotatesqure();
//int main(void)
//{
//    GLFWwindow* window;
//
//    //  Initialize the library 
//    if (!glfwInit())
//        return -1;
//
//    // Create a windowed mode window and its OpenGL context 
//    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    // Make the window's context current 
//    glfwMakeContextCurrent(window);
//
//    glOrtho(-25, 25, -25, 25, 25, 25);
//    // glScalef(3, 3, 3);
//   // glRotatef(45, 0.0f, 1.0f, 1.0f);
//    glEnable(GL_DEPTH_TEST);
//    // Loop until the user closes the window 
//    while (!glfwWindowShouldClose(window))
//    {
//        // Render here 
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glColor3f(1.0, 1.0, 1.0);
//
//        glRotatef(30, 0.5f, 0.5f, 0.5f);
//        // Set the point size to a big value, for example, 10.0
//
//        glBegin(GL_QUADS);
//
//        // Back face
//
//        glColor3f(0.0, 1.0, 0.0); // Green
//        glVertex3f(-0.5, -0.5, -0.5);
//        glVertex3f(0.5, -0.5, -0.5);
//
//        glVertex3f(0.5, 0.5, -0.5);
//
//        glVertex3f(-0.5, 0.5, -0.5);
//
//
//
//        // Front face
//
//        glColor3f(1.0, 0.0, 0.0); // Red
//        glVertex3f(-0.5, -0.5, 0.5);
//        glVertex3f(0.5, -0.5, 0.5);
//        glVertex3f(0.5, 0.5, 0.5);
//        glVertex3f(-0.5, 0.5, 0.5);
//        glEnd();
//
//        // Top face
//        glBegin(GL_QUADS);
//        glColor3f(0.0, 0.0, 1.0); // Blue
//        glVertex3f(-0.5, 0.5, -0.5);
//        glVertex3f(-0.5, 0.5, 0.5);
//        glVertex3f(0.5, 0.5, 0.5);
//        glVertex3f(0.5, 0.5, -0.5);
//        glEnd();
//
//        // Bo ttom face
//        glBegin(GL_QUADS);
//        glColor3f(1.0, 1.0, 0.0); // Yellow
//        glVertex3f(-0.5, -0.5, -0.5);
//        glVertex3f(-0.5, -0.5, 0.5);
//        glVertex3f(0.5, -0.5, 0.5);
//        glVertex3f(0.5, -0.5, -0.5);
//        //glEnd();
//
//        // Left face
//        glBegin(GL_QUADS);
//        glColor3f(1.0, 0.0, 1.0); // Magenta
//        glVertex3f(-0.5, -0.5, -0.5);
//        glVertex3f(-0.5, -0.5, 0.5);
//        glVertex3f(-0.5, 0.5, 0.5);
//        glVertex3f(-0.5, 0.5, -0.5);
//        //glEnd();
//
//        // Right face
//        glBegin(GL_QUADS);
//        glColor3f(1.0, 1.0, 1.0); // Cyan
//        glVertex3f(0.5, 0.5, 0.5);
//        glVertex3f(0.5, -0.5, 0.5);
//        glVertex3f(0.5, -0.5, -0.5);
//        glVertex3f(0.5, 0.5, -0.5);
//
//
//
//        glEnd();
//        Sleep(1000);
//
//        glFlush();
//
//        glfwSwapBuffers(window);
//
//        // Poll for and process events 
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}
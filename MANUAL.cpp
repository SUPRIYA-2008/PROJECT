//#include<string>
//#include<iostream>
//#include<fstream>
//#include<sstream>
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include<glm/gtc/type_ptr.hpp>
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<stb_image.h>
//#define STB_IMAGE_IMPLEMENTATION
//
////	FragPos = model * vec4(aPos,1.0);
//// out vec3 FragCord;
////in vec3 FragCord;
//
////vertexshadersource
//
//const char* vertexShaderSource = R"(
//#version 330 core
//
//layout(location=0) in vec3 aPos;
//layout(location=1) in vec3 aTexCord;
//
//out vec3 TexCord;
//
//uniform mat4 model;
//uniform mat4 view;
//unifrom mat4 projection;
//
//
//
//void main(){
//	gl_Position=projaction * view * model * vec4(aPos,1.0);
//	TexCord = aTexCord;
//}
//)";
//
//
//const char* fragmentShaderSource = R"(
//#version 330 core
//
//in vec3 TexCord;
//out vec4 FragColor;
//
//unifrom sample2D mytexture;
//
//void main(){
//	FragColor= vec4(texture(mytexture,TexCord));
//}
//)";
//
//
//float position[] = {
//        -0.5f, -0.5f, -0.5f,
//     0.5f, -0.5f, -0.5f,
//     0.5f,  0.5f, -0.5f,
//     0.5f,  0.5f, -0.5f,
//    -0.5f,  0.5f, -0.5f,
//    -0.5f, -0.5f, -0.5f,
//
//    -0.5f, -0.5f,  0.5f,
//     0.5f, -0.5f,  0.5f,
//     0.5f,  0.5f,  0.5f,
//     0.5f,  0.5f,  0.5f,
//    -0.5f,  0.5f,  0.5f,
//    -0.5f, -0.5f,  0.5f,
//
//    -0.5f,  0.5f,  0.5f,
//    -0.5f,  0.5f, -0.5f,
//    -0.5f, -0.5f, -0.5f,
//    -0.5f, -0.5f, -0.5f,
//    -0.5f, -0.5f,  0.5f,
//    -0.5f,  0.5f,  0.5f,
//
//     0.5f,  0.5f,  0.5f,
//     0.5f,  0.5f, -0.5f,
//     0.5f, -0.5f, -0.5f,
//     0.5f, -0.5f, -0.5f,
//     0.5f, -0.5f,  0.5f,
//     0.5f,  0.5f,  0.5f,
//
//    -0.5f, -0.5f, -0.5f,
//     0.5f, -0.5f, -0.5f,
//     0.5f, -0.5f,  0.5f,
//     0.5f, -0.5f,  0.5f,
//    -0.5f, -0.5f,  0.5f,
//    -0.5f, -0.5f, -0.5f,
//
//    -0.5f,  0.5f, -0.5f,
//     0.5f,  0.5f, -0.5f,
//     0.5f,  0.5f,  0.5f,
//     0.5f,  0.5f,  0.5f,
//    -0.5f,  0.5f,  0.5f,
//    -0.5f,  0.5f, -0.5f,
//};
//
//// Texture coordinate data
//float texCoords[] = {
//    0.0f, 0.0f,
//    1.0f, 0.0f,
//    1.0f, 1.0f,
//    1.0f, 1.0f,
//    0.0f, 1.0f,
//    0.0f, 0.0f,
//
//    0.0f, 0.0f,
//    1.0f, 0.0f,
//    1.0f, 1.0f,
//    1.0f, 1.0f,
//    0.0f, 1.0f,
//    0.0f, 0.0f,
//
//    1.0f, 0.0f,
//    1.0f, 1.0f,
//    0.0f, 1.0f,
//    0.0f, 1.0f,
//    0.0f, 0.0f,
//    1.0f, 0.0f,
//
//    0.0f, 1.0f,
//    1.0f, 1.0f,
//    1.0f, 0.0f,
//    1.0f, 0.0f,
//    0.0f, 0.0f,
//    0.0f, 1.0f,
//
//    0.0f, 1.0f,
//    1.0f, 1.0f,
//    1.0f, 0.0f,
//    1.0f, 0.0f,
//    0.0f, 0.0f,
//    0.0f, 1.0f,
//
//    0.0f, 0.0f,
//    1.0f, 0.0f,
//    1.0f, 1.0f,
//    1.0f, 1.0f,
//    0.0f, 1.0f,
//    0.0f, 0.0f,
//
//    0.0f, 0.0f,
//    1.0f, 0.0f,
//    1.0f, 1.0f,
//    1.0f, 1.0f,
//    0.0f, 1.0f,
//    0.0f, 0.0f,
//};
//
//
//
//int main() {
//    //initialize window
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,1);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
//    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "hellow", NULL, NULL);
//
//    glfwMakeContextCurrent(window);
//
//        // Initialize GLAD
//        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//            std::cerr << "Failed to initialize GLAD" << std::endl;
//            return -1;
//        }
//
//        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//        glShaderSource(vertexShader,1,)
//
//
//
//}
//
//

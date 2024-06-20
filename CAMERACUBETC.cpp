//#include <GLAD/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#define STB_IMAGE_IMPLEMENTATION
//#include"stb_image.h"
//
//using namespace glm;
//
//const char* vertexSource = R"(
//#version 330 core
//layout (location =0) in vec3 aPos;
//layout(location = 1) in vec3 aColor;
//layout(location=2)  in vec2 aTexCord;
//
//out vec2 TexCord;
//out vec3 ColorCord;
//
//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;
//
//void main(){
//    gl_Position = projection * view * model * vec4(aPos, 1.0);
//    TexCord= aTexCord;
//    ColorCord=aColor;
//}
//)";
//
//const char* fragmentSource = R"(
//#version 330 core
//
//in vec2 TexCord;
//in vec3  ColorCord;
//
//uniform sampler2D myTexture;
//out vec4 FragColor;
//
//
//void main(){
//    FragColor = texture(myTexture,TexCord)*vec4(ColorCord,1.0);
//}
//)";
//
//
//
//
//int main() {
//    // Initialize GLFW
//    if (!glfwInit()) {
//        std::cerr << "Failed to initialize GLFW" << std::endl;
//        return -1;
//    }
//
//    // Create a GLFW window
//    GLFWwindow* window = glfwCreateWindow(1000, 800, "Hello World", nullptr, nullptr);
//    if (!window) {
//        std::cerr << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//
//    // Initialize GLAD
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//        std::cerr << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // Compile vertex shader
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
//    glCompileShader(vertexShader);
//
//    // Compile fragment shader
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
//    glCompileShader(fragmentShader);
//
//    // Create shader program
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    glUseProgram(shaderProgram);
//
//    // Define cube vertices
//    float vertices[] = {
//        // positions        //color                      // texture coordinates                   
//     0.5f,  0.5f,  0.5f,    1,0,0,               0,0,// front top right    
//     0.5f, -0.5f,  0.5f,     1,0,0,              0,1,// front bottom right
//     -0.5f, -0.5f,  0.5f,    1,0,0,              1,0,// front bottom left
//      0.5f,  0.5f,  0.5f,    1,0,0,              0,1,
//     -0.5f, -0.5f,  0.5f,    1,0,0,              1,0,
//     -0.5f,  0.5f,  0.5f,    1,0,0,              1,1,// front top left
//
//     0.5f,  0.5f, -0.5f,     1,1,0,              0,0,// back top right
//     0.5f, -0.5f, -0.5f,     1,1,0,              0,1,// back bottom right
//     -0.5f, -0.5f, -0.5f,    1,1,0,             1,0,// back bottom left
//     0.5f,  0.5f, -0.5f,      1,1,0,             0,1,
//      -0.5f, -0.5f, -0.5f,    1,1,0,             1,0,
//     -0.5f,  0.5f, -0.5f,     1,1,0,             1,1,// back top left
//
//     -0.5f, -0.5f,  0.5f,      1,1,1,              0,0,// Bottom-left
//     -0.5f, -0.5f,  -0.5f,   1,1,1,              0,1,// Bottom-right
//     -0.5f,  0.5f,   0.5f,   1,1,1,              1,0,// Top-right
//    -0.5f, -0.5f,  -0.5f,      1,1,1,             0,1,
//    -0.5f,  0.5f,   0.5f,     1,1,1,             1,0,
//     -0.5f,  0.5f,  -0.5f,    1,1,1,             1,1,
//
//     0.5f, -0.5f,  0.5f,    1,0.5,1,             0,0,// Bottom-left
//     0.5f, -0.5f,  -0.5f,   1,0.5,1,             0,1,// Bottom-right
//     0.5f,  0.5f,   -0.5f,  1,0.5,1,              1,0,// Top-right
//      0.5f, -0.5f,  0.5f,   1,0.5,1,              0,1,
//      0.5f,  0.5f,   0.5f,  1,0.5,1,              1,0,
//     0.5f,  0.5f,  -0.5f,   1,0.5,1,              1,1,
//
//     -0.5f,0.5f,0.5f,      1,1,0.5,             0,0,
//     -0.5,0.5,-0.5,        1,1,0.5,             0,1,
//     0.5,0.5,-0.5,         1,1,0.5,             1,0,
//     -0.5,0.5,0.5,        1,1,0.5,             0,1,
//     0.5,0.5,0.5,          1,1,0.5,             1,0,
//     0.5,0.5,-0.5,         1,1,0.5,             1,1,
//
//
//     -0.5,-0.5,0.5,        1,1,0.5,             0,0,
//     -0.5,-0.5,-0.5,       1,1,0.5,             0,1,
//     0.5,-0.5,-0.5,        1,1,0.5,             1,0,
//      0.5,-0.5,-0.5,       1,1,0.5,             0,1,
//         -0.5,-0.5,0.5,    1,1,0.5,             1,0,
//        0.5,-0.5,0.5,      1,1,0.5,             1,1 // top left
//    };
//
//    glm::vec3 cubePositions[] = {
//      glm::vec3(0.0f,  0.0f,  0.0f),
//      glm::vec3(2.0f,  5.0f, -5.0f),
//      glm::vec3(1.5f,  0.2f, -1.5f),
//      glm::vec3(-1.3f,  1.0f, -1.5f)
//    };
//
//    // Generate VAO and VBO
//    unsigned int VAO, VBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    // Bind VAO and VBO
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    // Set vertex attribute pointers
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2,2, GL_FLOAT, GL_FALSE, 8* sizeof(float), (void*)(6 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//    // Unbind VAO and VBO
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    //    // Load and create texture
//    unsigned int texture1;
//    glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1);
//    // Set texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
//    // Set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    // Load image and generate texture
//    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true); // Tell stb_image.h to flip loaded texture's on the y-axis
//    unsigned char* data = stbi_load("C:/Users/ADMIN/Downloads/image2.jpg", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cerr << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//
//
//
//    // Enable depth testing
//    glEnable(GL_DEPTH_TEST);
//
//    // Render loop
//    while (!glfwWindowShouldClose(window)) {
//        // Clear the color and depth buffer
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        // Set up view matrix
//        //glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
//        // camera/view transformation
//        const float radius = 10.0f;
//        float camX = sin(glfwGetTime()) * radius;
//        float camZ = cos(glfwGetTime()) * radius;
//        glm::mat4 view;
//        view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
//        // Set up projection matrix
//        int width, height;
//        glfwGetFramebufferSize(window, &width, &height);
//        glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(width) / static_cast<float>(height), 0.1f, 100.0f);
//
//
//
//        // Set uniforms
//        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//
//        // Draw cube
//        glBindVertexArray(VAO);
//        glm::mat4 model = glm::mat4(1.0f);
//        unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
//        for (unsigned int i = 0; i <4 ; i++)  //for multiple objects
//        {
//            // calculate the model matrix for each object and pass it to shader before drawing
//            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::scale(model, glm::vec3(-0.6,-0.6,-0.6));
//            model = glm::translate(model, cubePositions[i]);
//
//            // Set up model matrix with rotation
//            static float angle = 0.0f;
//            angle += 0.005f;
//        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0, 1.0, 1.0));  //rotate model matrix
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
//
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//         }
//        glBindVertexArray(0);
//
//        // Swap buffers and poll events
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // Cleanup
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteProgram(shaderProgram);
//    glfwTerminate();
//    return 0;
//}

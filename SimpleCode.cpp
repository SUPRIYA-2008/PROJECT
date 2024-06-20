//#include <fstream>
//#include <string>
//#include <sstream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
//#include <iostream>
//using namespace glm;
//
//const char* vertexShaderSource = R"(
//  #version 330 core
//  layout (location=0) in vec3 aPos;
//  layout (location=1) in vec2 aTexCoord;
//
//  uniform mat4 model;
//  uniform mat4 view;
//  uniform mat4 projection;
//
//  out vec2 TexCoord;
//
//  void main()
//  {
//     gl_Position=model*vec4(aPos,1.0f);
//     TexCoord=aTexCoord;
//  }
// 
//)";
//
//const char* fragmentShaderSource = R"(
//  #version 330 core
//  in vec2 TexCoord;
//  out vec4 FragColor;
//
//  uniform sampler2D textureSampler;
//
//  void main()
//  {
//    FragColor=texture(textureSampler,TexCoord);
//  }
//)";
//
//int main()
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef APPLE
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif // DEBUG
//
//    GLFWwindow* window = glfwCreateWindow(800, 680, "cube", nullptr, nullptr);
//    glfwMakeContextCurrent(window);
//
//    // Initialize GLAD
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
//
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    float vertices[] = {
//
//        -0.5f,  -0.5f,  0.5f,  0.0f,  0.0f,
//         0.5f,  -0.5f,  0.5f,  1.0f,  0.0f,
//         0.5f,   0.5f,  0.5f,  1.0f,  1.0f,
//         0.5f,   0.5f,  0.5f,  1.0f,  1.0f,
//        -0.5f,  -0.5f,  0.5f,  0.0f,  0.0f,
//        -0.5f,   0.5f,  0.5f,  0.0f,  1.0f,
//
//        -0.5f,  -0.5f, -0.5f,  0.0f,  0.0f,
//         0.5f,  -0.5f, -0.5f,  1.0f,  0.0f,
//         0.5f,   0.5f, -0.5f,  1.0f,  1.0f,
//         0.5f,   0.5f, -0.5f,  1.0f,  1.0f,
//        -0.5f,  -0.5f, -0.5f,  0.0f,  0.0f,
//        -0.5f,   0.5f, -0.5f,  0.0f,  1.0f,
//
//
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//    };
//
//
//
//
//    float vertices2[] = {
//
//        -0.5f,  -0.5f,  0.5f,  0.0f,  0.0f,
//         0.5f,  -0.5f,  0.5f,  1.0f,  0.0f,
//         0.5f,   0.5f,  0.5f,  1.0f,  1.0f,
//         0.5f,   0.5f,  0.5f,  1.0f,  1.0f,
//        -0.5f,  -0.5f,  0.5f,  0.0f,  0.0f,
//        -0.5f,   0.5f,  0.5f,  0.0f,  1.0f,
//
//        -0.5f,  -0.5f, -0.5f,  0.0f,  0.0f,
//         0.5f,  -0.5f, -0.5f,  1.0f,  0.0f,
//         0.5f,   0.5f, -0.5f,  1.0f,  1.0f,
//         0.5f,   0.5f, -0.5f,  1.0f,  1.0f,
//        -0.5f,  -0.5f, -0.5f,  0.0f,  0.0f,
//        -0.5f,   0.5f, -0.5f,  0.0f,  1.0f,
//
//
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//    };
//
//
//    //vertices
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    //vertices2
//    unsigned int VBO2, VAO2;
//    glGenVertexArrays(1, &VAO2);
//    glGenBuffers(1, &VBO2);
//    glBindVertexArray(VAO2);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//
//    unsigned int texture;
//    glGenTextures(1, &texture);
//    glBindTexture(GL_TEXTURE_2D, texture);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    int width, height, nrChannels;
//    unsigned char* data = stbi_load("C:/Users/ADMIN/Downloads/image2.jpg", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//
//    stbi_image_free(data);
//
//    while (!glfwWindowShouldClose(window))
//    {
//        glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, texture);
//        //glActiveTexture(GL_TEXTURE1);
//
//        glm::mat4 model = mat4(1.0f);
//        model = rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 1.0f));
//        unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
//
//        glBindVertexArray(VAO);
//        glBindVertexArray(VAO2);
//
//
//        glUseProgram(shaderProgram);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        glfwPollEvents(); 
//            glfwSwapBuffers(window);
//    }
//
//    glfwTerminate();
//    return 0;
//}
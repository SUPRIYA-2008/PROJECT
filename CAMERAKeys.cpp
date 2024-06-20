//#include <GLAD/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//
//using namespace glm;
//
//const char* vertexSource = R"(
//#version 330 core
//layout (location = 0) in vec3 aPos;
//layout(location = 1) in vec3 aColor;
//layout(location = 2) in vec2 aTexCord;
//
//out vec2 TexCord;
//out vec3 ColorCord;
//out vec3 FragPos;
//
//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;
//
//void main(){
//    gl_Position = projection * view * model * vec4(aPos, 1.0);
//    TexCord = aTexCord;
//    FragPos = vec3(model * vec4(aPos, 1.0));
//    ColorCord = aColor;
//}
//)";
//
//const char* fragmentSource = R"(
//#version 330 core
//
//in vec2 TexCord;
//in vec3  ColorCord;
//in vec3 FragPos;
//uniform vec3 lightPos;
//uniform vec3 viewPos;
//uniform vec3 lightAmbient;
//uniform vec3 lightDiffuse;
//uniform vec3 lightSpecular;
//
//uniform sampler2D myTexture;
//out vec4 FragColor;
//
//void main(){
//    vec3 materialAmbient = vec3(0.0, 0.5, 0.0);
//    vec3 materialDiffuse = vec3(0.2, 0.5, 0.0);
//    vec3 materialSpecular = vec3(0.0, 0.5, 0.0);
//    float shininess = 2.0;
//
//    vec3 normals = normalize(normalize(cross(dFdx(FragPos), dFdy(FragPos))));
//
//    vec3 ambient = lightAmbient * materialAmbient;
//
//    vec3 norm = normalize(normals);
//    vec3 lightDir = normalize(lightPos - FragPos);
//    float diff = max(dot(norm, lightDir), 0.0);
//    vec3 diffuse = lightDiffuse * (diff * materialDiffuse);
//
//    vec3 viewDir = normalize(vec3(viewPos - FragPos));
//    vec3 reflectDir = reflect(-lightDir, norm);
//    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
//    vec3 specular = lightSpecular * (spec * materialSpecular);
//
//    vec3 result = ambient + diffuse + specular;
//    FragColor = texture(myTexture, TexCord) * vec4(result, 1.0);
//}
//)";
//
//
//
//// camera
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//int main() {
//    if (!glfwInit()) {
//        std::cerr << "Failed to initialize GLFW" << std::endl;
//        return -1;
//    }
//
//    GLFWwindow* window = glfwCreateWindow(1000, 800, "Hello World", nullptr, nullptr);
//    if (!window) {
//        std::cerr << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//        std::cerr << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
//    glCompileShader(vertexShader);
//
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
//    glCompileShader(fragmentShader);
//
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    glUseProgram(shaderProgram);
//
//    float vertices[] = {
//        // positions        //color                      // texture coordinates                   
//0.5f,  0.5f,  0.5f,    1,0,0,               0,0,// front top right    
//0.5f, -0.5f,  0.5f,     1,0,0,              0,1,// front bottom right
//-0.5f, -0.5f,  0.5f,    1,0,0,              1,0,// front bottom left
// 0.5f,  0.5f,  0.5f,    1,0,0,              0,1,
//-0.5f, -0.5f,  0.5f,    1,0,0,              1,0,
//-0.5f,  0.5f,  0.5f,    1,0,0,              1,1,// front top left
//
//0.5f,  0.5f, -0.5f,     1,1,0,              0,0,// back top right
//0.5f, -0.5f, -0.5f,     1,1,0,              0,1,// back bottom right
//-0.5f, -0.5f, -0.5f,    1,1,0,             1,0,// back bottom left
//0.5f,  0.5f, -0.5f,      1,1,0,             0,1,
// -0.5f, -0.5f, -0.5f,    1,1,0,             1,0,
//-0.5f,  0.5f, -0.5f,     1,1,0,             1,1,// back top left
//
//-0.5f, -0.5f,  0.5f,      1,1,1,              0,0,// Bottom-left
//-0.5f, -0.5f,  -0.5f,   1,1,1,              0,1,// Bottom-right
//-0.5f,  0.5f,   0.5f,   1,1,1,              1,0,// Top-right
//-0.5f, -0.5f,  -0.5f,      1,1,1,             0,1,
//-0.5f,  0.5f,   0.5f,     1,1,1,             1,0,
// -0.5f,  0.5f,  -0.5f,    1,1,1,             1,1,
//
// 0.5f, -0.5f,  0.5f,    1,0.5,1,             0,0,// Bottom-left
// 0.5f, -0.5f,  -0.5f,   1,0.5,1,             0,1,// Bottom-right
// 0.5f,  0.5f,   -0.5f,  1,0.5,1,              1,0,// Top-right
//  0.5f, -0.5f,  0.5f,   1,0.5,1,              0,1,
//  0.5f,  0.5f,   0.5f,  1,0.5,1,              1,0,
// 0.5f,  0.5f,  -0.5f,   1,0.5,1,              1,1,
//
// -0.5f,0.5f,0.5f,      1,1,0.5,             0,0,
// -0.5,0.5,-0.5,        1,1,0.5,             0,1,
// 0.5,0.5,-0.5,         1,1,0.5,             1,0,
// -0.5,0.5,0.5,        1,1,0.5,             0,1,
// 0.5,0.5,0.5,          1,1,0.5,             1,0,
// 0.5,0.5,-0.5,         1,1,0.5,             1,1,
//
//
// -0.5,-0.5,0.5,        1,1,0.5,             0,0,
// -0.5,-0.5,-0.5,       1,1,0.5,             0,1,
// 0.5,-0.5,-0.5,        1,1,0.5,             1,0,
//  0.5,-0.5,-0.5,       1,1,0.5,             0,1,
//     -0.5,-0.5,0.5,    1,1,0.5,             1,0,
//    0.5,-0.5,0.5,      1,1,0.5,             1,1 // top left
//    };
//
//
//    // Vertex data for light cube positions
//    float lightCubeVertices[] = {
//        -0.1f, -0.1f, -0.1f,
//        -0.1f, -0.1f,  0.1f,
//        -0.1f,  0.1f,  0.1f,
//        0.1f,  0.1f, -0.1f,
//        -0.1f, -0.1f, -0.1f,
//        -0.1f,  0.1f, -0.1f,
//        0.1f, -0.1f,  0.1f,
//        -0.1f, -0.1f, -0.1f,
//        0.1f, -0.1f, -0.1f,
//        0.1f,  0.1f, -0.1f,
//        0.1f, -0.1f, -0.1f,
//        -0.1f, -0.1f, -0.1f,
//        -0.1f, -0.1f, -0.1f,
//        -0.1f,  0.1f,  0.1f,
//        -0.1f,  0.1f, -0.1f,
//        0.1f, -0.1f,  0.1f,
//        -0.1f, -0.1f,  0.1f,
//        -0.1f, -0.1f, -0.1f,
//        -0.1f,  0.1f,  0.1f,
//        -0.1f, -0.1f,  0.1f,
//        0.1f, -0.1f,  0.1f,
//        0.1f,  0.1f,  0.1f,
//        0.1f, -0.1f, -0.1f,
//        0.1f,  0.1f, -0.1f,
//        0.1f, -0.1f, -0.1f,
//        0.1f,  0.1f,  0.1f,
//        0.1f, -0.1f,  0.1f,
//        0.1f,  0.1f,  0.1f,
//        0.1f,  0.1f, -0.1f,
//        -0.1f,  0.1f, -0.1f,
//        0.1f,  0.1f,  0.1f,
//        -0.1f,  0.1f, -0.1f,
//        -0.1f,  0.1f,  0.1f,
//        0.1f,  0.1f,  0.1f,
//        -0.1f,  0.1f,  0.1f,
//        0.1f, -0.1f,  0.1f
//    };
//
//    // world space positions of our cubes
//    glm::vec3 cubePositions[] = {
//        glm::vec3(0.0f,  0.0f,  0.0f),
//        glm::vec3(2.0f,  5.0f, -15.0f),
//        glm::vec3(-1.5f, -2.2f, -2.5f),
//        glm::vec3(-3.8f, -2.0f, -12.3f),
//        glm::vec3(2.4f, -0.4f, -3.5f),
//        glm::vec3(-1.7f,  3.0f, -7.5f),
//        glm::vec3(1.3f, -2.0f, -2.5f),
//        glm::vec3(1.5f,  2.0f, -2.5f),
//        glm::vec3(1.5f,  0.2f, -1.5f),
//        glm::vec3(-1.3f,  1.0f, -1.5f)
//    };
//
//
//    unsigned int VAO, VBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//
//
//    // Create Vertex Buffer Object (VBO) and Vertex Array Object (VAO) for light cube
//    unsigned int lightCubeVAO, lightCubeVBO;
//    glGenVertexArrays(1, &lightCubeVAO);
//    glGenBuffers(1, &lightCubeVBO);
//    glBindVertexArray(lightCubeVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, lightCubeVBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(lightCubeVertices), lightCubeVertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    // Load and create texture
//    unsigned int texture1;
//    glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true);
//    unsigned char* data = stbi_load("C:/Users/ADMIN/Downloads/image2.jpg", &width, &height, &nrChannels, 0);
//    if (data) {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else {
//        std::cerr << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//    glEnable(GL_DEPTH_TEST);
//
//    // Set up light properties
//    vec3 lightPos(0.0f, 0.0f, 0.7f);
//    vec3 lightAmbient(0.0f, 0.3f, 0.0f); // Green light
//    vec3 lightDiffuse(1.0f, 0.0f, 0.0f);
//    vec3 lightSpecular(0.0f, 1.0f, 0.0f);
//    float shininess = 32.0f;
//
//
//    float lightSpeed = 0.001f; // Speed of light movement
//
// //   float cameraSpeed = 0.05f;
//
//    float deltaTime = 0.0f;	// Time between current frame and last frame
//    float lastFrame = 0.0f; // Time of last frame
//
//    while (!glfwWindowShouldClose(window)) {
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
//
//        int width, height;
//        glfwGetFramebufferSize(window, &width, &height);
//        glm::mat4 projection = glm::perspective(glm::radians(90.0f), static_cast<float>(width) / static_cast<float>(height), 0.1f, 100.0f);
//
//
//        //Light Movement
//        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//            lightPos.y += lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//            lightPos.y -= lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
//            lightPos.x -= lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
//            lightPos.x += lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
//            lightPos.z += lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
//            lightPos.z -= lightSpeed;
//
//        //Cam Movement
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        float cameraSpeed = 5.0f * deltaTime;
//        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//            cameraPos += cameraSpeed * cameraFront;
//        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//            cameraPos -= cameraSpeed * cameraFront;
//        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
//            cameraPos += cameraSpeed * cameraUp;
//        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
//            cameraPos -= cameraSpeed * cameraUp;
//
//
//
//        int lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
//        glUniform3fv(lightPosLoc, 1, glm::value_ptr(lightPos));
//        int lightAmbientLoc = glGetUniformLocation(shaderProgram, "lightAmbient");
//        glUniform3fv(lightAmbientLoc, 1, glm::value_ptr(lightAmbient));
//        int lightDiffuseLoc = glGetUniformLocation(shaderProgram, "lightDiffuse");
//        glUniform3fv(lightDiffuseLoc, 1, glm::value_ptr(lightDiffuse));
//        int lightSpecularLoc = glGetUniformLocation(shaderProgram, "lightSpecular");
//        glUniform3fv(lightSpecularLoc, 1, glm::value_ptr(lightSpecular));
//
//        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//
//        glBindVertexArray(VAO);
//
//        for (unsigned int i = 0; i < 10; i++) {
//
//            // calculate the model matrix for each object and pass it to shader before drawing
//           
//
//            glm::mat4 model = glm::mat4(1.0f);
//
//            model = glm::translate(model, cubePositions[i]);
//
//            unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
//            static float angle = 0.0f;
//            angle += 0.005f;
//            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0, 1.0, 1.0));
//            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
//            glDrawArrays(GL_TRIANGLES, 0, 36);
//        }
//        // Draw light cube
//        glBindVertexArray(lightCubeVAO);
//        glm::mat4 lightCubeModel = glm::mat4(1.0f);
//        lightCubeModel = glm::translate(lightCubeModel, lightPos);
//        lightCubeModel = glm::scale(lightCubeModel, glm::vec3(0.6f));
//        unsigned int lightCubeModelLoc = glGetUniformLocation(shaderProgram, "model");
//        glUniformMatrix4fv(lightCubeModelLoc, 1, GL_FALSE, glm::value_ptr(lightCubeModel));
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteProgram(shaderProgram);
//    glfwTerminate();
//    return 0;
//}

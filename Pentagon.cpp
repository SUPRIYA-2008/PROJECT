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
//layout (location = 1) in vec2 aTexCoord;
//
//out vec2 TexCoord;
//
//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;
//
//void main(){
//    gl_Position = projection * view * model * vec4(aPos, 1.0);
//    TexCoord = aTexCoord;
//}
//)";
//
//const char* fragmentSource = R"(
//#version 330 core
//
//in vec2 TexCoord;
//uniform sampler2D myTexture;
//
//out vec4 FragColor;
//
//void main(){
//    FragColor = texture(myTexture, TexCoord);
//}
//)";
//
//int main() {
//    // Initialize GLFW
//    if (!glfwInit()) {
//        std::cerr << "Failed to initialize GLFW" << std::endl;
//        return -1;
//    }
//
//    // Create a GLFW window
//    GLFWwindow* window = glfwCreateWindow(800, 600, "Pentagon Rotation", nullptr, nullptr);
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
//        // Define pentagon vertices
//        float positions[] = {
//                     1,0.5,0,         //front
//                    -1,0.5,0,
//                    0,1,0,
//                    1,0.5,0,
//                    -0.5,-0.5,0,
//                    -1,0.5,0,
//                    1,0.5,0,
//                    0.5,-0.5,0,
//                    -0.5,-0.5,0,
//        
//                    0,1,0,         // righttop
//                    0,1,1,
//                    1,0.5,1,
//                    1,0.5,1,
//                    1,0.5,0,
//                    0,1,0, 
//        
//                    1,0.5,0,       //right bottom
//                    1,0.5,1,
//                    0.5,-0.5,1,
//                    0.5,-0.5,1,
//                    0.5,-0.5,0,
//                    1,0.5,0,
//        
//        
//                    0.5,-0.5,1,   //bottom
//                    0.5,-0.5,0,
//                    -0.5,-0.5,1,
//                    -0.5,-0.5,1,
//                    0.5,-0.5,0,
//                    -0.5,-0.5,0,
//        
//                    -0.5,-0.5,1,   //leftbottom
//                    -0.5,-0.5,0,
//                    -1,0.5,0,
//                    -1,0.5,0,
//                    -1,0.5,1,
//                    -0.5,-0.5,1,
//        
//                    -1,0.5,1,         //lefttop
//                    -1,0.5,0,
//                     0,1,0,
//                    0,1,0,
//                    -1,0.5,1,
//                    0,1,1,
//        
//        
//                     1,0.5,1,         //back
//                    -1,0.5,1,
//                    0,1,1,
//                    1,0.5,1,
//                    -0.5,-0.5,1,
//                    -1,0.5,1,
//                    1,0.5,1,
//                    0.5,-0.5,1,
//                    -0.5,-0.5,1
//        };
//    
//        // Texture coordinate data
//        float texCoords[] = {
//            0.0f, 0.0f,
//            1.0f, 0.0f,
//            1.0f, 1.0f,
//            1.0f, 1.0f,
//            0.0f, 1.0f,
//            0.0f, 0.0f,
//    
//            0.0f, 0.0f,
//            1.0f, 0.0f,
//            1.0f, 1.0f,
//            1.0f, 1.0f,
//            0.0f, 1.0f,
//            0.0f, 0.0f,
//    
//            1.0f, 0.0f,
//            1.0f, 1.0f,
//            0.0f, 1.0f,
//            0.0f, 1.0f,
//            0.0f, 0.0f,
//            1.0f, 0.0f,
//    
//            0.0f, 1.0f,
//            1.0f, 1.0f,
//            1.0f, 0.0f,
//            1.0f, 0.0f,
//            0.0f, 0.0f,
//            0.0f, 1.0f,
//    
//            0.0f, 1.0f,
//            1.0f, 1.0f,
//            1.0f, 0.0f,
//            1.0f, 0.0f,
//            0.0f, 0.0f,
//            0.0f, 1.0f,
//    
//            0.0f, 0.0f,
//            1.0f, 0.0f,
//            1.0f, 1.0f,
//            1.0f, 1.0f,
//            0.0f, 1.0f,
//            0.0f, 0.0f,
//    
//            0.0f, 0.0f,
//            1.0f, 0.0f,
//            1.0f, 1.0f,
//            1.0f, 1.0f,
//            0.0f, 1.0f,
//            0.0f, 0.0f,
//    
//            0.0f, 0.0f,
//            1.0f, 0.0f,
//            1.0f, 1.0f,
//            1.0f, 1.0f,
//            0.0f, 1.0f,
//            0.0f, 0.0f,
//    
//    
//            0.0f, 0.0f,
//            1.0f, 0.0f,
//            1.0f, 1.0f,
//            1.0f, 1.0f,
//            0.0f, 1.0f,
//            0.0f, 0.0f,
//        };
//
//
//
//        glm::vec3 cubePositions[] = {
//
//            glm::vec3(-3.7f,  3.0f, -8.5f),
//            glm::vec3(0.3f,  1.0f, -1.5f)
//        };
//
//    // Create Vertex Buffer Object (VBO) and Vertex Array Object (VAO) for cube
//    unsigned int VBO_positions, VBO_texCoords, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO_positions);
//    glGenBuffers(1, &VBO_texCoords);
//
//    // Bind and specify data for positions
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO_positions);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    // Bind and specify data for texture coordinates
//    glBindBuffer(GL_ARRAY_BUFFER, VBO_texCoords);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(1);
//
//    // Load and create texture
//    unsigned int texture1;
//    glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1);
//    // Set texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // Set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
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
//    // Enable depth testing
//    glEnable(GL_DEPTH_TEST);
//
//    // Render loop
//    while (!glfwWindowShouldClose(window)) {
//        // Clear the color and depth buffer
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        // Set up view matrix
//        glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//
//        // Set up projection matrix
//        int width, height;
//        glfwGetFramebufferSize(window, &width, &height);
//        glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(width) / static_cast<float>(height), 0.1f, 100.0f);
//
//        // Set uniforms
//        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//
//        // Draw pentagon
//        glBindVertexArray(VAO);
//
//        for (unsigned int i = 0; i < 2; i++)
//        {
//            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::translate(model, cubePositions[i]);
//
//            // Update the rotation angle
//            static float angle = 0.0f;
//            angle += 0.01f;
//
//
//            // Apply rotation to the model matrix
//            model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
//            glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
//
//            glDrawArrays(GL_TRIANGLES, 0, 48); // Draw the pentagon
//        }
//        glBindVertexArray(0);
//
//        // Swap buffers and poll events
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // Cleanup
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO_positions);
//    glDeleteBuffers(1, &VBO_texCoords);
//    glDeleteTextures(1, &texture1);
//    glDeleteProgram(shaderProgram);
//    glfwTerminate();
//    return 0;
//}

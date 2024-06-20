//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
//
//const char* vertexShaderSource = R"(
//    #version 330 core
//    layout (location = 0) in vec3 aPos;
//    layout (location = 1) in vec2 aTexCoord;
//    
//    out vec2 TexCoord;
//
//    uniform mat4 model;
//    uniform mat4 view;
//    uniform mat4 projection;
//   
//    void main()
//    {
//        gl_Position =  model  * vec4(aPos, 1.0);
//        TexCoord = aTexCoord;
//    }
//)";
//
//const char* fragmentShaderSource = R"(
//    #version 330 core
//    in vec2 TexCoord;
//    out vec4 FragColor;
//
//   uniform sampler2D textureFront;
//
//    void main()
//{
//     FragColor = texture(textureFront, TexCoord);
//}
//)";
//
//int main()
//{
//    // glfw: initialize and configure
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef APPLE
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//    // glad: load all OpenGL function pointers
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//    //glViewport(0, 0,1000,1000);
//
//    // build and compile our shader program 
//    // vertex shader
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//
//    // fragment shader
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    // link shaders
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    //Delete Shaders
//   /* glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);*/
//
//    //// Vertex Data for cube positions
//    float vertices[] = {
//        //Front 
//       -0.5,-0.5,0.5,   0.0,0.0,
//       -0.5,0.5,0.5,    0.0,1.0,
//       0.5,-0.5,0.5,    1.0,0.0,
//    
//       -0.5,0.5,0.5,    0.0,1.0,
//       0.5,-0.5,0.5,    1.0,0.0,
//       0.5,0.5,0.5,     1.0,1.0,
//    
//       //Right
//       0.5,0.5,0.5,     0.0,1.0,
//       0.5,-0.5,0.5,    0.0,0.0,
//       0.5,-0.5,-0.5,   1.0,0.0,
//    
//       0.5,0.5,0.5,     0.0,1.0,
//       0.5,0.5,-0.5,    1.0,1.0,
//       0.5,-0.5,-0.5,   1.0,0.0,
//    
//       //Back
//       0.5,0.5,-0.5,    0.0,1.0,
//       0.5,-0.5,-0.5,   0.0,0.0,
//       -0.5,-0.5,-0.5,  1.0,0.0,
//    
//       0.5,0.5,-0.5,    0.0,1.0,
//       -0.5,0.5,-0.5,   1.0,1.0,
//       -0.5,-0.5,-0.5,  1.0,0.0,
//    
//       //Left
//       -0.5,0.5,-0.5,   0.0,1.0,
//       -0.5,-0.5,-0.5,  0.0,0.0,
//       -0.5,-0.5,0.5,   1.0,0.0,
//    
//       -0.5,0.5,-0.5,   0.0,1.0,
//       -0.5,0.5,0.5,    1.0,1.0,
//       -0.5,-0.5,0.5,   1.0,0.0,
//    
//       //Top
//       -0.5,0.5,0.5,    0.0,1.0,
//       0.5,0.5,0.5,     0.0,0.0,
//       0.5,0.5,-0.5,    1.0,0.0,
//    
//       -0.5,0.5,0.5,    0.0,1.0,
//       -0.5,0.5,-0.5,   1.0,1.0,
//       0.5,0.5,-0.5,    1.0,0.0,
//    
//       //Bottom
//       -0.5,-0.5,0.5,   0.0,1.0,
//       0.5,-0.5,0.5,    0.0,0.0,
//       0.5,-0.5,-0.5,   1.0,0.0,
//    
//       -0.5,-0.5,0.5,   0.0,1.0,
//       -0.5,-0.5,-0.5,  1.0,1.0,
//       0.5,-0.5,-0.5,   1.0,0.0
//    };
//
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO); // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    
//    // Load and create texture
//    unsigned int textureFront;
//    glGenTextures(1, &textureFront);
//    glBindTexture(GL_TEXTURE_2D, textureFront);
//    // Set texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // Set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // Load image, create texture and generate mipmaps
//    int width, height, nrChannels;
//    unsigned char* data = stbi_load("C:/Users/ADMIN/Downloads/IMG_6262.JPG", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//    //Texture 2
//    // Load and create texture
//    unsigned int textureRight;
//    glGenTextures(1, &textureRight);
//    glBindTexture(GL_TEXTURE_2D, textureRight);
//    // Set texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // Set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // Load image, create texture and generate mipmaps
//    //int width, height, nrChannels;
//    data = stbi_load("C:/Users/ADMIN/Downloads/IMG_6262.JPG", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//    //Texture 3
//    // Load and create texture
//    unsigned int textureBack;
//    glGenTextures(1, &textureBack);
//    glBindTexture(GL_TEXTURE_2D, textureBack);
//    // Set texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // Set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // Load image, create texture and generate mipmaps
//    //int width, height, nrChannels;
//    data = stbi_load("C:/Users/ADMIN/Downloads/IMG_6262.JPG", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//    //Texture 4
//    // Load and create texture
//    unsigned int textureLeft;
//    glGenTextures(1, &textureLeft);
//    glBindTexture(GL_TEXTURE_2D, textureLeft);
//    // Set texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // Set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // Load image, create texture and generate mipmaps
//    //int width, height, nrChannels;
//    data = stbi_load("C:/Users/ADMIN/Downloads/IMG_6262.JPG", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//    //Texture 5
//    // Load and create texture
//    unsigned int textureTop;
//    glGenTextures(1, &textureTop);
//    glBindTexture(GL_TEXTURE_2D, textureTop);
//    // Set texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // Set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // Load image, create texture and generate mipmaps
//    //int width, height, nrChannels;
//    data = stbi_load("C:/Users/ADMIN/Downloads/20240526_180237.jpg", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//    //Texture 6
//    // Load and create texture
//    unsigned int textureBottom;
//    glGenTextures(1, &textureBottom);
//    glBindTexture(GL_TEXTURE_2D, textureBottom);
//    // Set texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // Set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // Load image, create texture and generate mipmaps
//    //int width, height, nrChannels;
//    data = stbi_load("C:/Users/ADMIN/Downloads/IMG_6262.JPG", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//
//    glm::mat4 model = glm::mat4(1.0f); // Initialize identity matrix for model transformation
//    glm::mat4 view = glm::mat4(1.0f);
//    glm::mat4 projection = glm::mat4(1.0f);
//    glEnable(GL_DEPTH_TEST);
//    while (!glfwWindowShouldClose(window))
//    {
//        int width, height;
//        glfwGetFramebufferSize(window, &width, &height);
//        glViewport(0, 0, width, height);
//        
//        // render
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//
//        glUseProgram(shaderProgram);
//
//        // Translate
//        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//            model = glm::translate(model, glm::vec3(0.0f, 0.001f, 0.0f));
//        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//            model = glm::translate(model, glm::vec3(0.0f, -0.001f, 0.0f));
//        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//            model = glm::translate(model, glm::vec3(-0.001f, 0.0f, 0.0f));
//        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//            model = glm::translate(model, glm::vec3(0.001f, 0.0f, 0.0f));
//
//        //Scale
//        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//            model = glm::scale(model, glm::vec3(1.001f, 1.001f, 1.001f));
//        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//            model = glm::scale(model, glm::vec3(0.999f, 0.999f, 0.999f));
//
//        //Rotation
//        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
//            model = glm::rotate(model, glm::radians(0.5f), glm::vec3(1, 1, 1)); // Rotate the object by 'angle' degrees around the axis (axisX, axisY, axisZ)
//        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
//            model = glm::rotate(model, glm::radians(-0.5f), glm::vec3(1, 1, 1)); // Rotate the object by 'angle' degrees around the axis (axisX, axisY, axisZ)
//        
//        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//        projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
//        // Retrieve uniform location and set model matrix
//        // retrieve the matrix uniform locations
//        unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
//        unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
//        unsigned int projLoc = glGetUniformLocation(shaderProgram, "projection");
//         // pass matrices to shader
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//        
//        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//        
//        glBindTexture(GL_TEXTURE_2D, textureFront);
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//
//        glBindTexture(GL_TEXTURE_2D, textureRight);
//        glDrawArrays(GL_TRIANGLES, 6, 6);
//
//        glBindTexture(GL_TEXTURE_2D, textureBack);
//        glDrawArrays(GL_TRIANGLES, 12, 6);
//
//        glBindTexture(GL_TEXTURE_2D, textureLeft);
//        glDrawArrays(GL_TRIANGLES, 18, 6);
//
//        glBindTexture(GL_TEXTURE_2D, textureTop);
//        glDrawArrays(GL_TRIANGLES, 24, 6);
//
//        glBindTexture(GL_TEXTURE_2D, textureBottom);
//        glDrawArrays(GL_TRIANGLES, 30, 6);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//   /* glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteProgram(shaderProgram);*/
//
//    glfwTerminate();
//    return 0;
//}
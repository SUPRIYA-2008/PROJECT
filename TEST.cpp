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
//   
//    out vec3 FragPos;
//    out vec2 TexCoord;
//   
//   
//    uniform mat4 model;
//    uniform mat4 view;
//    uniform mat4 projection;
//
//    void main()
//    {
//        gl_Position =projection*view* model * vec4(aPos, 1.0);
//        FragPos = vec3(model * vec4(aPos, 1.0));
//        TexCoord = aTexCoord;
//       
//    }
//)";
//
//// Fragment Shader Source Code
//const char* fragmentShaderSource = R"(
//    #version 330 core
//    in vec3 FragPos;
//    in vec2 TexCoord;
//    
//    out vec4 FragColor;
//    out vec4 FragColor1;
//
//    uniform vec3 lightPos;
//    uniform vec3 lightPos1;
//    uniform vec3 viewPos;
//    uniform vec3 lightColor;
//    uniform vec3 lightColor1;
//    uniform vec3 objectColor;
//    uniform sampler2D ourTexture;
//
//    void main()
//    {
//       float ambientStrength = 0.1;
//       vec3 ambient = ambientStrength * lightColor;
//       vec3 ambient1 = ambientStrength * lightColor1;
//       
//       vec3 Normal = normalize(cross(dFdx(FragPos), dFdy(FragPos)));
//       vec3 norm = Normal;
//       vec3 lightDir = normalize(lightPos - FragPos);
//       vec3 lightDir1 = normalize(lightPos1 - FragPos);
//       float diff = max(dot(norm, lightDir), 0.0);
//       float diff1 = max(dot(norm, lightDir1), 0.0);
//       vec3 diffuse = diff * lightColor;
//       vec3 diffuse1 = diff * lightColor1;
//
//       float specularStrength = 0.5;
//       vec3 viewDir = normalize(viewPos - FragPos);
//       vec3 reflectDir = reflect(-lightDir, norm);
//       vec3 reflectDir1 = reflect(-lightDir1, norm);
//
//       float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
//       float spec1 = pow(max(dot(viewDir, reflectDir1), 0.0), 32);
//
//       vec3 specular = specularStrength * spec * lightColor;
//       vec3 specular1 = specularStrength * spec1 * lightColor1;
//
//       vec3 lighting = ambient + diffuse + specular;
//       vec3 lighting1 = ambient1 + diffuse1 + specular1;
//       vec4 textureColor = texture(ourTexture, TexCoord);
//
//       vec3 result = lighting * textureColor.rgb * objectColor;
//       vec3 result1 = lighting1 * textureColor.rgb * objectColor;
//       FragColor = vec4(result, textureColor.a);
//       FragColor1 = vec4(result1, textureColor.a);
//    }
//)";
//
//// camera
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
////void mouse_callback(GLFWwindow* window, double xpos, double ypos);
////void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//// timing
//float deltaTime = 0.0f;	// time between current frame and last frame
//float lastFrame = 0.0f;
//
//bool firstMouse = true;
////float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
////float pitch = 0.0f;
////float lastX = 800.0f / 2.0;
////float lastY = 600.0 / 2.0;
//float fov = 45.0f;
//
//// glfw: whenever the mouse moves, this callback is called
//// -------------------------------------------------------
//
//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
//{
//    float xpos = static_cast<float>(xposIn);
//    float ypos = static_cast<float>(yposIn);
//    float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
//    float pitch = 0.0f;
//    float lastX = 800.0f / 2.0;
//    float lastY = 600.0 / 2.0;
//
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
//    lastX = xpos;
//    lastY = ypos;
//
//    float sensitivity = 0.1f; // change this value to your liking
//    xoffset *= sensitivity;
//    yoffset *= sensitivity;
//
//    yaw += xoffset;
//    pitch += yoffset;
//
//    // make sure that when pitch is out of bounds, screen doesn't get flipped
//    if (pitch > 89.0f)
//        pitch = 89.0f;
//    if (pitch < -89.0f)
//        pitch = -89.0f;
//
//    glm::vec3 front;
//    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//    front.y = sin(glm::radians(pitch));
//    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//    cameraFront = glm::normalize(front);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    //static float fov = 45.0f;
//
//    fov -= (float)yoffset;
//    if (fov < 1.0f)
//        fov = 1.0f;
//    if (fov > 45.0f)
//        fov = 45.0f;
//}
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
//    GLFWwindow* window = glfwCreateWindow(1920, 1080, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//    // tell GLFW to capture our mouse
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
//
//    // glad: load all OpenGL function pointers
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // build and compile our shader program 
//    // vertex shader
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//
//    // Check for vertex shader compilation errors
//    int success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
//        std::cout << "Vertex shader compilation failed\n" << infoLog << std::endl;
//    }
//
//    // fragment shader
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    // Check for fragment shader compilation errors
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
//        std::cout << "Fragment shader compilation failed\n" << infoLog << std::endl;
//    }
//    // link shaders
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if (!success)
//    {
//        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
//        std::cout << "Shader program linking failed\n" << infoLog << std::endl;
//    }
//
//    //Delete Shaders
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    float vertices[] = {
//        //Front
//               0.0,0.5,0.2,     0.5,1.0,
//               -0.5,0.0,0.2,    0.0,0.0,
//               0.5,0.0,0.2,     1.0,0.0,
//
//               -0.5,0.0,0.2,    0.0,1.0,
//               -0.3,-0.5,0.2,   0.2,0.0,    //
//               0.3,-0.5,0.2,    1.0,0.0,
//
//               -0.5,0.0,0.2,    0.0,1.0,
//               0.3,-0.5,0.2,    0.8,0.0,    //
//               0.5,0.0,0.2,     1.0,1.0,
//
//               //Back
//                      0.0,0.5,-0.2,    0.5,1.0,
//                      -0.5,0.0,-0.2,   0.0,0.0,
//                      0.5,0.0,-0.2,    1.0,0.0,
//
//                      -0.5,0.0,-0.2,   0.0,1.0,
//                      -0.3,-0.5,-0.2,  0.2,0.0,
//                      0.3,-0.5,-0.2,   1.0,0.0,
//
//                      -0.5,0.0,-0.2,   0.0,1.0,
//                      0.3,-0.5,-0.2,   0.8,0.0,
//                      0.5,0.0,-0.2,    1.0,1.0,
//
//                      //Connecting
//                      //Top Right
//                             0.0,0.5,0.2,     0.0,1.0,
//                             0.5,0.0,0.2,     0.0,0.0,
//                             0.5,0.0,-0.2,    1.0,0.0,
//
//                             0.0,0.5,0.2,     0.0,1.0,
//                             0.5,0.0,-0.2,    1.0,0.0,
//                             0.0,0.5,-0.2,    1.0,1.0,
//
//                             //Right
//                                    0.5,0.0,0.2,     0.0,1.0,
//                                    0.3,-0.5,0.2,    0.0,0.0,
//                                    0.3,-0.5,-0.2,   1.0,0.0,
//
//                                    0.5,0.0,0.2,     0.0,1.0,
//                                    0.5,0.0,-0.2,    1.0,1.0,
//                                    0.3,-0.5,-0.2,   1.0,0.0,
//
//                                    //Bottom
//                                           -0.3,-0.5,0.2,   0.0,1.0,
//                                           0.3,-0.5,0.2,    0.0,0.0,
//                                           0.3,-0.5,-0.2,   1.0,0.0,
//
//                                           -0.3,-0.5,0.2,   0.0,1.0,
//                                           -0.3,-0.5,-0.2,  1.0,1.0,
//                                           0.3,-0.5,-0.2,   1.0,0.0,
//
//                                           //Left
//                                                  -0.5,0.0,0.2,    1.0,1.0,
//                                                  -0.3,-0.5,0.2,   1.0,0.0,
//                                                  -0.3,-0.5,-0.2,  0.0,0.0,
//
//                                                  -0.5,0.0,0.2,    1.0,1.0,
//                                                  -0.5,0.0,-0.2,   0.0,1.0,
//                                                  -0.3,-0.5,-0.2,  0.0,0.0,
//
//                                                  //Top Left
//                                                         0.0,0.5,0.2,     1.0,1.0,
//                                                         -0.5,0.0,0.2,    1.0,0.0,
//                                                         -0.5,0.0,-0.2,   0.0,0.0,
//
//                                                         0.0,0.5,0.2,     1.0,1.0,
//                                                         0.0,0.5,-0.2,    0.0,1.0,
//                                                         -0.5,0.0,-0.2,   0.0,0.0
//    };
//
//    float lightCubeVertices[] = {
//    0.0,0.0,0.0,
//    0.0,0.1,0.0,
//    0.1,0.0,0.0,
//
//    0.0,0.1,0.0,
//    0.1,0.0,0.0,
//    0.1,0.1,0.0
//    };
//
//    glm::vec3 pentagonPositions[] = {
//      glm::vec3(2.4f, -0.4f, -3.5f),
//      glm::vec3(-1.7f,  1.0f, -4.5f),
//    };
//
//    //glm::vec3 lightPositions[] = {
//    /*glm::vec3(1.0f,  1.0f,  1.0f),
//    glm::vec3(-1.5f, -2.2f, -2.5f),
//    };*/
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
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
//    // Create Vertex Buffer Object (VBO) and Vertex Array Object (VAO) for light cube
//    unsigned int lightCubeVAO, lightCubeVBO;
//    glGenVertexArrays(1, &lightCubeVAO);
//    glGenBuffers(1, &lightCubeVBO);
//
//    glBindVertexArray(lightCubeVAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, lightCubeVBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(lightCubeVertices), lightCubeVertices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    // Load and create a texture 
//    unsigned int texture;
//    glGenTextures(1, &texture);
//    glBindTexture(GL_TEXTURE_2D, texture);
//    // Set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // Set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // Load image, create texture and generate mipmaps
//    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true);
//    unsigned char* data = stbi_load("C:/OpenGL/container.jpg", &width, &height, &nrChannels, 0);
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
//    glm::vec3 lightPos(0.7f, 0.7f, 0.7f);
//    glm::vec3 lightPos1(0.3f, 0.3f, 0.3f);
//    glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
//    glm::vec3 lightColor1(1.0f, 1.0f, 1.0f);
//
//    glm::vec3 viewPos(0.0f, 0.0f, 0.0f);
//
//    glm::mat4 model = glm::mat4(1.0f);
//
//    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f); // Camera position
//    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f); // Look-at position
//    glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f); // Up direction
//    glm::mat4 view = glm::lookAt(cameraPos, cameraTarget, upVector);
//
//    float aspectRatio = 1920.0f / 1080.0f; // Adjust this according to your window size
//    float fov = glm::radians(45.0f); // Field of view (in radians)
//    float nearPlane = 0.1f; // Near clipping plane
//    float farPlane = 100.0f; // Far clipping plane
//    glm::mat4 projection = glm::perspective(fov, aspectRatio, nearPlane, farPlane);
//
//    glEnable(GL_DEPTH_TEST);
//
//    float lightSpeed = 0.01f; // Speed of light movement
//
//    float cameraSpeed = 0.05f;
//
//    float deltaTime = 0.0f;	// Time between current frame and last frame
//    float lastFrame = 0.0f; // Time of last frame
//
//    while (!glfwWindowShouldClose(window))
//    {
//        // Inside the while loop, before rendering
//        int width, height;
//        glfwGetFramebufferSize(window, &width, &height);
//        glViewport(0, 0, width, height);
//
//        //// render
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
//
//        //// Bind Texture
//        //glBindTexture(GL_TEXTURE_2D, texture);
//
//        // Bind textures
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, texture);
//        //glUniform1i(glGetUniformLocation(shaderProgram, "ourTexture"), 4);
//
//        // draw our first triangle
//        glUseProgram(shaderProgram);
//
//        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//            lightPos.y += lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//            lightPos.y -= lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//            lightPos.x -= lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//            lightPos.x += lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
//            lightPos.z += lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
//            lightPos.z -= lightSpeed;
//
//        if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
//            lightPos1.y += lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
//            lightPos1.y -= lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
//            lightPos1.x -= lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
//            lightPos1.x += lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
//            lightPos1.z += lightSpeed;
//        if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
//            lightPos1.z -= lightSpeed;
//        //Cam Movement
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        float cameraSpeed = 5.0f * deltaTime;
//        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//            cameraPos += cameraSpeed * cameraFront;
//        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//            cameraPos -= cameraSpeed * cameraFront;
//        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
//            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
//            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//        if (glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
//            cameraPos += cameraSpeed * cameraUp;
//        if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
//            cameraPos -= cameraSpeed * cameraUp;
//        // Set uniforms
//        glUniform3f(glGetUniformLocation(shaderProgram, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
//        glUniform3f(glGetUniformLocation(shaderProgram, "lightPos1"), lightPos1.x, lightPos1.y, lightPos1.z);
//        glUniform3f(glGetUniformLocation(shaderProgram, "viewPos"), viewPos.x, viewPos.y, viewPos.z);
//        //glUniform3f(glGetUniformLocation(shaderProgram, "lightColor"), 1.0f, 1.0f, 1.0f);
//        //glUniform3f(glGetUniformLocation(shaderProgram, "lightColor1"), 1.0f, 0.0f, 0.0f);
//        glUniform3f(glGetUniformLocation(shaderProgram, "objectColor"), 1.0f, 1.0f, 1.0f);
//
//        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
//            lightColor.x = sin(glfwGetTime() * 2.0f);
//        if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
//            lightColor.y = sin(glfwGetTime() * 0.7f);
//        if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
//            lightColor.z = sin(glfwGetTime() * 1.3f);
//        // Define transformations
//        glm::mat4 model = glm::mat4(1.0f); // Identity matrix
//        glm::mat4 view = glm::mat4(1.0f);
//        glm::mat4 projection = glm::mat4(1.0f);
//        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f)); // Move the camera backwards
//        projection = glm::perspective(glm::radians(45.0f), 1920.0f / 1080.0f, 0.1f, 100.0f); // Apply perspective projection
//
//        // Rotate the model around its vertical axis
//        float angle = glfwGetTime() * 50.0f; // Adjust rotation speed as needed
//        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 1.0f, 1.0f));
//
//        // Get their uniform location values
//        unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
//        unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
//        unsigned int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
//        unsigned int lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
//        unsigned int lightPosLoc1 = glGetUniformLocation(shaderProgram, "lightPos1");
//        unsigned int lightColorLoc = glGetUniformLocation(shaderProgram, "lightColor");
//        unsigned int lightColorLoc1 = glGetUniformLocation(shaderProgram, "lightColor1");
//
//        //// Pass them to the shaders
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
//        glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
//        glUniform3f(lightPosLoc1, lightPos1.x, lightPos1.y, lightPos1.z);
//        glUniform3f(lightColorLoc, lightColor.x, lightColor.y, lightColor.z);
//        glUniform3f(lightColorLoc1, lightColor1.x, lightColor1.y, lightColor1.z);
//        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//
//        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//
//        for (unsigned int i = 0; i < 10; i++)
//        {
//            // calculate the model matrix for each object and pass it to shader before drawing
//            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::translate(model, pentagonPositions[i]);
//            float angle = 20.0f * i;
//            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//            glDrawArrays(GL_TRIANGLES, 0, 48);
//        }
//
//        //glDrawElements(GL_TRIANGLES, 108,GL_UNSIGNED_INT,0); //Rasterization
//        //glDrawArrays(GL_TRIANGLES, 0, 144);
//
//        // Use shader program for rendering light cube
//        glUseProgram(shaderProgram);
//
//        // Set model matrix for light cube
//        //Light Source 1
//        model = glm::translate(glm::mat4(1.0f), lightPos);
//        model = glm::scale(model, glm::vec3(0.2f)); // Make light cube smaller
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glBindVertexArray(lightCubeVAO);
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//
//        //Light Source 2
//        model = glm::translate(glm::mat4(1.0f), lightPos1);
//        model = glm::scale(model, glm::vec3(0.2f)); // Make light cube smaller
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//        glBindVertexArray(lightCubeVAO);
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//    glfwTerminate();
//    return 0;
//}
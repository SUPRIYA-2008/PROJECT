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
//// Vertex Shader Source Code
//const char* vertexShaderSource = R"(
//    #version 330 core
//    layout (location = 0) in vec3 aPos;
//    layout (location = 1) in vec2 aTexCoord;
//
//    out vec2 TexCoord;
//    out vec3 FragPos;
//
//    uniform mat4 model;
//    uniform mat4 view;
//    uniform mat4 projection;
//
//    void main()
//    {
//        gl_Position = projection * view * model * vec4(aPos, 1.0);
//         FragPos = vec3(model * vec4(aPos, 1.0));
//        TexCoord = aTexCoord;
//    }
//)";
//
//// Fragment Shader Source Code
//const char* fragmentShaderSource = R"(
//    #version 330 core
//    in vec2 TexCoord;
//    in vec3 FragPos;
//    out vec4 FragColor;
//
//    uniform sampler2D textureSampler;
//    uniform vec3 lightPos;
//    uniform vec3 viewPos;
//    uniform vec3 lightAmbient;
//    uniform vec3 lightDiffuse;
//    uniform vec3 lightSpecular;
//
//    void main()
//    {
//        // Material properties (temporary, you may want to use uniforms)
//        vec3 materialAmbient = vec3(1.0, 0.5, 0.31);
//        vec3 materialDiffuse = vec3(1.0, 0.5, 0.31);
//        vec3 materialSpecular = vec3(0.5, 0.5, 0.5);
//        float shininess = 32.0;
//
//        vec3 normals = normalize(normalize(cross(dFdx(FragPos), dFdy(FragPos))));
//
//        // Ambient
//        vec3 ambient = lightAmbient * materialAmbient;
//
//        // Diffuse
//        vec3 norm = normalize(normals); // normal vector (temporary)
//        vec3 lightDir = normalize(lightPos - FragPos); // direction to light source (temporary)
//        float diff = max(dot(norm, lightDir), 0.0);
//        vec3 diffuse = lightDiffuse * (diff * materialDiffuse);
//
//        // Specular
//        vec3 viewDir = normalize(vec3(viewPos - FragPos)); // view direction (temporary)
//        vec3 reflectDir = reflect(-lightDir, norm);
//        float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
//        vec3 specular = lightSpecular * (spec * materialSpecular);
//
//        vec3 result = ambient + diffuse + specular;
//        FragColor = texture(textureSampler, TexCoord) * vec4(result, 1.0);
//    }
//)";
//
////camera
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//
//
//// timing
//float deltaTime = 0.0f;	// time between current frame and last frame
//float lastFrame = 0.0f;
//
//bool firstMouse = true;
//
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
//// glfw: whenever the mouse scroll wheel scrolls, this callback is called
//// ----------------------------------------------------------------------
//
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
//
//// Vertex Data for cube positions
//float positions[] = {
//                     1,0.5,0,         //front
//                -1,0.5,0,
//                0,1,0,
//                1,0.5,0,
//                -0.5,-0.5,0,
//                -1,0.5,0,
//                1,0.5,0,
//                0.5,-0.5,0,
//                -0.5,-0.5,0,
//
//                0,1,0,         // righttop
//                0,1,1,
//                1,0.5,1,
//                1,0.5,1,
//                1,0.5,0,
//                0,1,0,
//
//                1,0.5,0,       //right bottom
//                1,0.5,1,
//                0.5,-0.5,1,
//                0.5,-0.5,1,
//                0.5,-0.5,0,
//                1,0.5,0,
//
//
//                0.5,-0.5,1,   //bottom
//                0.5,-0.5,0,
//                -0.5,-0.5,1,
//                -0.5,-0.5,1,
//                0.5,-0.5,0,
//                -0.5,-0.5,0,
//
//                -0.5,-0.5,1,   //leftbottom
//                -0.5,-0.5,0,
//                -1,0.5,0,
//                -1,0.5,0,
//                -1,0.5,1,
//                -0.5,-0.5,1,
//
//                -1,0.5,1,         //lefttop
//                -1,0.5,0,
//                 0,1,0,
//                0,1,0,
//                -1,0.5,1,
//                0,1,1,
//
//
//                 1,0.5,1,         //back
//                -1,0.5,1,
//                0,1,1,
//                1,0.5,1,
//                -0.5,-0.5,1,
//                -1,0.5,1,
//                1,0.5,1,
//                0.5,-0.5,1,
//                -0.5,-0.5,1
//
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
//
//    0.0f, 0.0f,
//    1.0f, 0.0f,
//    1.0f, 1.0f,
//    1.0f, 1.0f,
//    0.0f, 1.0f,
//    0.0f, 0.0f,
//
//
//    0.0f, 0.0f,
//    1.0f, 0.0f,
//    1.0f, 1.0f,
//    1.0f, 1.0f,
//    0.0f, 1.0f,
//    0.0f, 0.0f,
//};
//
//// Vertex data for light cube positions
//float lightCubeVertices[] = {
//    -0.1f, -0.1f, -0.1f,
//    -0.1f, -0.1f,  0.1f,
//    -0.1f,  0.1f,  0.1f,
//    0.1f,  0.1f, -0.1f,
//    -0.1f, -0.1f, -0.1f,
//    -0.1f,  0.1f, -0.1f,
//    0.1f, -0.1f,  0.1f,
//    -0.1f, -0.1f, -0.1f,
//    0.1f, -0.1f, -0.1f,
//    0.1f,  0.1f, -0.1f,
//    0.1f, -0.1f, -0.1f,
//    -0.1f, -0.1f, -0.1f,
//    -0.1f, -0.1f, -0.1f,
//    -0.1f,  0.1f,  0.1f,
//    -0.1f,  0.1f, -0.1f,
//    0.1f, -0.1f,  0.1f,
//    -0.1f, -0.1f,  0.1f,
//    -0.1f, -0.1f, -0.1f,
//    -0.1f,  0.1f,  0.1f,
//    -0.1f, -0.1f,  0.1f,
//    0.1f, -0.1f,  0.1f,
//    0.1f,  0.1f,  0.1f,
//    0.1f, -0.1f, -0.1f,
//    0.1f,  0.1f, -0.1f,
//    0.1f, -0.1f, -0.1f,
//    0.1f,  0.1f,  0.1f,
//    0.1f, -0.1f,  0.1f,
//    0.1f,  0.1f,  0.1f,
//    0.1f,  0.1f, -0.1f,
//    -0.1f,  0.1f, -0.1f,
//    0.1f,  0.1f,  0.1f,
//    -0.1f,  0.1f, -0.1f,
//    -0.1f,  0.1f,  0.1f,
//    0.1f,  0.1f,  0.1f,
//    -0.1f,  0.1f,  0.1f,
//    0.1f, -0.1f,  0.1f
//};
//
//glm::vec3 cubePositions[] = {
//
//    glm::vec3(-1.7f,  3.0f, -7.5f),
//    glm::vec3(-1.3f,  1.0f, -1.5f)
//};
//
//int main()
//{
//    // Initialize GLFW and create a window
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    GLFWwindow* window = glfwCreateWindow(800, 600, "Cube with Single Texture", nullptr, nullptr);
//
//    glfwMakeContextCurrent(window);
//
//    // tell GLFW to capture our mouse
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
//
//    // Initialize GLAD
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//        std::cerr << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // Compile Vertex Shader
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
//    glCompileShader(vertexShader);
//
//    // Compile Fragment Shader
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
//    glCompileShader(fragmentShader);
//
//    // Link Shaders into Shader Program
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    // Check for shader compilation and linking errors
//    int success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success) {
//        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
//        std::cerr << "Vertex shader compilation failed: " << infoLog << std::endl;
//    }
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//    if (!success) {
//        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
//        std::cerr << "Fragment shader compilation failed: " << infoLog << std::endl;
//    }
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
//        std::cerr << "Shader program linking failed: " << infoLog << std::endl;
//    }
//
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
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
//    // Set up light properties
//    vec3 lightPos(0.7f, 0.7f, 0.7f);
//    vec3 lightAmbient(0.0f, 1.0f, 0.0f); // Green light
//    vec3 lightDiffuse(1.0f, 0.0f, 0.0f);
//    vec3 lightSpecular(1.0f, 1.0f, 1.0f);
//
//    // Render loop
//    while (!glfwWindowShouldClose(window))
//    {
//        // Process input
//        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//            glfwSetWindowShouldClose(window, true);
//
//        glClearColor(0.7, 0.7, 0.7, 1);
//
//        // per-frame time logic
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // Light control input
//        float deltaTime = 0.001f; // adjust as needed
//        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//            lightPos.y += deltaTime;
//        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//            lightPos.y -= deltaTime;
//        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
//            lightPos.z += deltaTime;
//        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
//            lightPos.z -= deltaTime;
//        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//            lightPos.x -= deltaTime;
//        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//            lightPos.x += deltaTime;
//
//        //camera control input
//        //float cameraSpeed = static_cast<float>(2.5 * deltaTime);
//        float cameraSpeed = 2.5f * deltaTime;             //ajust accordingly
//        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//            cameraPos += cameraSpeed * cameraFront;
//        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//            cameraPos -= cameraSpeed * cameraFront;
//        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
//            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
//            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//
//
//
//        // Clear the screen and depth buffer
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        // Bind textures using texture units
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, texture1);
//
//        // Use shader program for rendering cube
//        glUseProgram(shaderProgram);
//
//
//
//
//        // Set projection matrix
//        int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
//        glm::mat4 projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);
//        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//        // Set view matrix
//        int viewLoc = glGetUniformLocation(shaderProgram, "view");
//        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//
//        // Set model matrix for cube
//        int modelLoc = glGetUniformLocation(shaderProgram, "model");
//        glm::mat4 model = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 1.0f));
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//        // Set light properties
//        int lightPosLoc = glGetUniformLocation(shaderProgram, "lightPos");
//        glUniform3fv(lightPosLoc, 1, glm::value_ptr(lightPos));
//
//        int lightAmbientLoc = glGetUniformLocation(shaderProgram, "lightAmbient");
//        glUniform3fv(lightAmbientLoc, 1, glm::value_ptr(lightAmbient));
//
//        int lightDiffuseLoc = glGetUniformLocation(shaderProgram, "lightDiffuse");
//        glUniform3fv(lightDiffuseLoc, 1, glm::value_ptr(lightDiffuse));
//
//        int lightSpecularLoc = glGetUniformLocation(shaderProgram, "lightSpecular");
//        glUniform3fv(lightSpecularLoc, 1, glm::value_ptr(lightSpecular));
//
//        //// Draw cube
//        //glBindVertexArray(VAO);
//        //glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        // camera/view transformation
//        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//        //ourShader.setMat4("view", view);
//        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//
//        glBindVertexArray(VAO);
//
//        for (unsigned int i = 0; i < 2; i++)
//        {
//            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::translate(model, cubePositions[i]);
//            float angle = 20.0f * i;
//            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//            // ourShader.setMat4("model", model);
//
//            glDrawArrays(GL_TRIANGLES, 0, 48);
//        }
//
//        // Use shader program for rendering light cube
//        glUseProgram(shaderProgram);
//
//        // Set model matrix for light cube
//        model = glm::translate(glm::mat4(1.0f), lightPos);
//        model = glm::scale(model, glm::vec3(0.2f)); // Make light cube smaller
//        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//        // Draw light cube
//        glBindVertexArray(lightCubeVAO);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        // Swap buffers and poll IO events
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // Clean up
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO_positions);
//    glDeleteBuffers(1, &VBO_texCoords);
//    glDeleteVertexArrays(1, &lightCubeVAO);
//    glDeleteBuffers(1, &lightCubeVBO);
//    glDeleteProgram(shaderProgram);
//
//    // Terminate GLFW
//    glfwTerminate();
//    return 0;
//}
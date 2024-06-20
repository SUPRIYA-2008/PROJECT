//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
//#include <vector>
//using namespace std;
//
//// Cube vertices
//float cubeVertices[] = {
//    // Positions          
//    -1.0f,  1.0f, -1.0f,
//    -1.0f, -1.0f, -1.0f,
//     1.0f, -1.0f, -1.0f,
//     1.0f, -1.0f, -1.0f,
//     1.0f,  1.0f, -1.0f,
//    -1.0f,  1.0f, -1.0f,
//
//    -1.0f, -1.0f,  1.0f,
//    -1.0f, -1.0f, -1.0f,
//    -1.0f,  1.0f, -1.0f,
//    -1.0f,  1.0f, -1.0f,
//    -1.0f,  1.0f,  1.0f,
//    -1.0f, -1.0f,  1.0f,
//
//     1.0f, -1.0f, -1.0f,
//     1.0f, -1.0f,  1.0f,
//     1.0f,  1.0f,  1.0f,
//     1.0f,  1.0f,  1.0f,
//     1.0f,  1.0f, -1.0f,
//     1.0f, -1.0f, -1.0f,
//
//    -1.0f, -1.0f,  1.0f,
//    -1.0f,  1.0f,  1.0f,
//     1.0f,  1.0f,  1.0f,
//     1.0f,  1.0f,  1.0f,
//     1.0f, -1.0f,  1.0f,
//    -1.0f, -1.0f,  1.0f,
//
//    -1.0f,  1.0f, -1.0f,
//     1.0f,  1.0f, -1.0f,
//     1.0f,  1.0f,  1.0f,
//     1.0f,  1.0f,  1.0f,
//    -1.0f,  1.0f,  1.0f,
//    -1.0f,  1.0f, -1.0f,
//
//    -1.0f, -1.0f, -1.0f,
//    -1.0f, -1.0f,  1.0f,
//     1.0f, -1.0f, -1.0f,
//     1.0f, -1.0f, -1.0f,
//    -1.0f, -1.0f,  1.0f,
//     1.0f, -1.0f,  1.0f
//};
//
//// Shader sources
//const char* vertexShaderSource = R"(
//    #version 330 core
//    layout (location = 0) in vec3 aPos;
//
//    out vec3 TexCoords;
//
//    uniform mat4 projection;
//    uniform mat4 view;
//
//    void main()
//    {
//        TexCoords = aPos;
//        gl_Position = projection * view * vec4(aPos, 1.0);
//    }
//)";
//
//const char* fragmentShaderSource = R"(
//    #version 330 core
//    out vec4 FragColor;
//
//    in vec3 TexCoords;
//
//    uniform samplerCube skybox;
//
//    void main()
//    {
//        FragColor = texture(skybox, TexCoords);
//    }
//)";
//
//// Load cube map
//unsigned int loadCubemap(vector<std::string> faces)
//{
//    unsigned int textureID;
//    glGenTextures(1, &textureID);
//    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
//
//    int width, height, nrChannels;
//    for (unsigned int i = 0; i < faces.size(); i++)
//    {
//        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
//        if (data)
//        {
//            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
//                0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
//            );
//            stbi_image_free(data);
//        }
//        else
//        {
//            std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
//            stbi_image_free(data);
//        }
//    }
//    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
//
//    return textureID;
//}
//
//int main()
//{
//    // Initialize GLFW
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    // Create window
//    GLFWwindow* window = glfwCreateWindow(800, 600, "Cube Map Example", nullptr, nullptr);
//    if (window == nullptr)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//    // Initialize GLAD
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // Compile shaders
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//    // Check for shader compile errors
//
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//    // Check for shader compile errors
//
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    // Check for linking errors
//
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    // Set up cube map faces
//    vector<std::string> faces
//    {
//        "F:/COMPUTER GRAPHICS/skybox/back.jpg",
//        "F:/COMPUTER GRAPHICS/skybox/bottom.jpg",
//        "F:/COMPUTER GRAPHICS/skybox/front.jpg",
//        "F:/COMPUTER GRAPHICS/skybox/left.jpg",
//        "F:/COMPUTER GRAPHICS/skybox/right.jpg",
//        "F:/COMPUTER GRAPHICS/skybox/back.jpg"
//    };
//    unsigned int cubemapTexture = loadCubemap(faces);
//
//    // Vertex buffer and array objects
//    unsigned int VBO, cubeVAO;
//    glGenVertexArrays(1, &cubeVAO);
//    glGenBuffers(1, &VBO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
//
//    glBindVertexArray(cubeVAO);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    // Enable depth testing
//    glEnable(GL_DEPTH_TEST);
//
//    // Render loop
//    while (!glfwWindowShouldClose(window))
//    {
//        // Input handling
//        glfwPollEvents();
//
//        // Rendering commands
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        glUseProgram(shaderProgram);
//        glBindVertexArray(cubeVAO);
//
//        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
//        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//
//        glm::mat4 view = glm::mat4(glm::mat3(glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f))));
//        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
//
//        glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        // Swap buffers
//        glfwSwapBuffers(window);
//    }
//
//    // Cleanup
//    glDeleteVertexArrays(1, &cubeVAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteProgram(shaderProgram);
//
//    // Terminate GLFW
//    glfwTerminate();
//    return 0;
//}
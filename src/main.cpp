#include <glad/glad.h> /* ������ ������������ ����� GLFW, �.� �������������� ���� � ������� */
#include <GLFW/glfw3.h>

#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_NAME = "LAB #1";

int main(void)
{
	/************************
		������������� GLFW
	*************************/
	glfwInit();

	/* �������� ����������� ��������� ������ OpenGL (3.3) */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	/* ��������� �������� ��� �������� ��������� ��������
		������������� CORE �������. */
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* ���������� ����������� ��������� ������� ���� */
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


	/*****************************************************
		�������� � ��������� ��������� ��� ������� ����
	 *****************************************************/

	 /* �������� ������� ����, � �����������,
	   (������, ������, ��������)*/
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME, nullptr, nullptr);
	if (window == nullptr) // ��������, ��������� �� ����
	{
		std::cerr << "Failed to created Window!" << std::endl;
		glfwTerminate(); // ���������� GLFW
		return -1;
	}
	/* ��������� ��������� GLFW, ��� ����� ��������� ���� */
	glfwMakeContextCurrent(window);

	/*********************************
		�������� ������������� GLAD
	 *********************************/

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	/* ����� ���. ���������� � OpenGL � ������� */
	std::cout << "Render: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

	/************************
		��������� VIEWPORT
	 ************************/

	 /* �������� OpenGL - ������ ��������������� ���� */
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);



	/***************************
		�������� ���� �������
	 ***************************/


	 /* glfwWindowShouldClose() :: ��������� � ������ ������
	   �������� �����, ������� �� GLFW ������, � ��������

		  glfwPollEvents() :: ��������� ���� �� ������� ����� ���� �������
	  (���������� ��� ����, ��������) � �������� ������������� �������
	  (��������� �� callback �������)

	  glfwSwapBuffers() :: �������� �������� �����
	  (������� ������, ���������� �������� ����� ��� ������� ������� � ����),
	  ���������� ��������� �� ������.

	   */

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}


	/* ������� �� �������, ������� ���������� ��� �������. */
	glfwTerminate();
	return 0;
}
#include <glad/glad.h> /* Должна подключаться перед GLFW, т.к пероопределяет типы и функции */
#include <GLFW/glfw3.h>

#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_NAME = "LAB #1";

int main(void)
{
	/************************
		Инициализация GLFW
	*************************/
	glfwInit();

	/* Задается минимальная требуемая версия OpenGL (3.3) */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	/* Установка профайла для которого создается контекст
		Используяется CORE профиль. */
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Выключение возможности изменения размера окна */
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


	/*****************************************************
		Создание и установка контекста для Объекта ОКНА
	 *****************************************************/

	 /* Создание объекта окна, с параметрами,
	   (высота, ширина, название)*/
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME, nullptr, nullptr);
	if (window == nullptr) // Проверка, создалось ли окно
	{
		std::cerr << "Failed to created Window!" << std::endl;
		glfwTerminate(); // Выключение GLFW
		return -1;
	}
	/* Установка контекста GLFW, для ранее созданого окна */
	glfwMakeContextCurrent(window);

	/*********************************
		Проверка инициализации GLAD
	 *********************************/

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	/* Вывод доп. информации о OpenGL в консоль */
	std::cout << "Render: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

	/************************
		Настройка VIEWPORT
	 ************************/

	 /* Сообщаем OpenGL - размер отрисовываемого окна */
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);



	/***************************
		Основной Цикл Рендера
	 ***************************/


	 /* glfwWindowShouldClose() :: проверяет в начале каждой
	   итерации цикла, получил ли GLFW сигнал, к закрытия

		  glfwPollEvents() :: Проверяет были ли вызваны какие либо события
	  (клавиатура или мышь, например) и вызывает установленные функции
	  (указатели на callback функции)

	  glfwSwapBuffers() :: Заменяет цветовой буфер
	  (большой буффер, содержащий значения цвета дял каждого пикселя в окне),
	  показывает результат на экране.

	   */

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}


	/* Выходим из функции, очищаем выделенные нам ресурсы. */
	glfwTerminate();
	return 0;
}
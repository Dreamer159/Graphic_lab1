#include <Windows.h>
#include <GLFW/glfw3.h>

double W = 1000, H = -2000;

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;
	W *= 0.001;
	H *= 0.001;
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "Lab 1", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	double  x1 = -W / 4,
		y1 = H / 4,
		x2 = W / 4,
		y2 = -H / 4;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_LINE_STIPPLE); 
		glEnable(GL_POINT_SMOOTH);
		glLineStipple(2, 11110100);
		glLineWidth(3);  

		glBegin(GL_LINES);
		glColor3d(0, 0.2, 0.6);     
		glVertex2d(-W/5, H/2.5); 
		glVertex2d(W/5, H/2.5);
		glColor3d(0.6, 0.6, 0.6);
		glVertex2d(-W / 4, H / 4); 
		glVertex2d(W / 4, -H / 4);
		glEnd();

		glDisable(GL_LINE_STIPPLE);
		glDisable(GL_POINT_SMOOTH);

		double y, x, x3 = -W / 5;
		for (int i = 1; i < 11; i++)
		{
			y = y1 + ((y2 - y1) / 10)*i;
			if (i > 9) 
				y = (y1 + ((y2 - y1) / 10)*i) + 5;
			x = (((y - y1) / (y2 - y1))*(x2 - x1)) + x1;
			glPointSize(i);
			glBegin(GL_POINTS);
			glColor3d(0.6,0.6,0.6); //сірий
			glVertex2d(x3 + 0.02, H / 2.5);
			glEnd();
			x3 += (W / 5) / 5;

			glEnable(GL_POINT_SMOOTH);
			glBegin(GL_POINTS);
			glColor3d(0, 0, 1); // синій
			glVertex2d(x, y);
			glEnd();
			glDisable(GL_POINT_SMOOTH);
		}

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
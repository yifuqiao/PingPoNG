#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <math.h>
#include "CGfxOpenGL.h"
#include "PaddleBase.h"
#include "PaddleHuman.h"
#include "PaddleAI.h"
#include "GameManager.h"
#include "GraphicsTools.h"

// disable implicit float-double casting
#pragma warning(disable:4305)
//Obstacle m_obstacles[MAX_OBSTACLES];

#define  RAD_TO_DEG 57.2957795 

CGfxOpenGL::CGfxOpenGL()
{
}

CGfxOpenGL::~CGfxOpenGL()
{
}

bool CGfxOpenGL::Init()
{	
	int sep = 10;

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	m_paddles[HUMAN] = new PaddleHuman(Vec2(-35,0),1,3,30);
	m_paddles[AI] = new PaddleAI(Vec2(35,0),1,3,30);

	GameManager::Get()->SetPlayers(m_paddles[AI],m_paddles[HUMAN],&m_ball);
	return true;
}

bool CGfxOpenGL::Shutdown()
{
	delete m_paddles[0];
	delete m_paddles[1];

	return true;
}

void CGfxOpenGL::SetupProjection(int width, int height)
{
	if (height == 0)					// don't want a divide by zero
	{
		height = 1;					
	}

	glViewport(0, 0, width, height);		// reset the viewport to new dimensions
	glMatrixMode(GL_PROJECTION);			// set projection matrix current matrix
	glLoadIdentity();						// reset projection matrix

	// calculate aspect ratio of window
	gluPerspective(60,(GLfloat)width/(GLfloat)height,1.0f,1000.0f);

	glMatrixMode(GL_MODELVIEW);				// set modelview matrix
	glLoadIdentity();						// reset modelview matrix

	m_windowWidth = width;
	m_windowHeight = height;
}

void CGfxOpenGL::Prepare(float dt)
{
	GameManager::Get()->Update(dt);

	for(int i = 0; i < TOTAL; ++i)
		m_paddles[i]->Update(dt);	

	m_ball.Update(dt);
}

void CGfxOpenGL::Render()
{
	// clear screen and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);			// set projection matrix current matrix
	glLoadIdentity();						// reset projection matrix

	// calculate aspect ratio of window
	gluPerspective(60,(GLfloat)800/(GLfloat)600,1.0f,1000.0f);
	glMatrixMode(GL_MODELVIEW);				// set modelview matrix
	
	// load the identity matrix (clear to default position and orientation)
	glLoadIdentity();

	glPushMatrix();							// put current matrix on stack
		glLoadIdentity();					// reset matrix
		glTranslatef(0.0f, 0.0f, -50.0f);	// move to (0, 0, -30)

		glPointSize(1);
		glPushMatrix();
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f); //rotate so it walks on x/y plane
			glColor3f(1,1,1);
			
			for(int i = 0; i < TOTAL; ++i)
			{
				m_paddles[i]->Render();	
				int score = m_paddles[i]->GetFitness();
				for(int j = 0; j < score; ++j)
				{
					GraphicsTools::DrawQuad(-32 + j * 7,i == 0 ? -27 : 27,2,1);
				}
			}
			m_ball.Render();

			glBegin(GL_LINES);
				glVertex3f(-40,0,-25);
				glVertex3f(40,0,-25);
			glEnd();

			glBegin(GL_LINES);
				glVertex3f(-40,0,25);
				glVertex3f(40,0,25);
			glEnd();

			glBegin(GL_LINES);
				glVertex3f(0,0,-25);
				glVertex3f(0,0,25);
			glEnd();

		glPopMatrix();
		glPointSize(1);
	glPopMatrix();	
}

//////////////////////////////////////////////////////////////////////////

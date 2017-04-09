#include "StdAfx.h"
#include "MyOpenGL.h"
#include "resource.h"


MyOpenGL::MyOpenGL(void)
{
	step=0.0;
	s=0.1;
}


MyOpenGL::~MyOpenGL(void)
{
	wglMakeCurrent(NULL,NULL);
	wglDeleteContext(hglrc);//删除渲染描述表
	::ReleaseDC(m_hWnd,hdc);//释放设备描述表
}
BEGIN_MESSAGE_MAP(MyOpenGL, CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


int MyOpenGL::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	if(MySetPixelFormat(::GetDC(m_hWnd))==FALSE)
		return 0;

	// 获得绘图描述表
	hdc = ::GetDC(m_hWnd);
	// 创建渲染描述表
	hglrc = wglCreateContext(hdc);
	// 使绘图描述表为当前调用现程的当前绘图描述表 
	wglMakeCurrent(hdc, hglrc); 
	return 0;
}


void MyOpenGL::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除颜色缓存和深度缓存
	s+=0.005;
	if(s>1.0)
		s=0.5;
	step = step + 1.0;
	if (step > 360.0)
		step = step - 360.0;
	glPushMatrix();
	
	glScalef(s,s,s);
	glRotatef(-75,1.0,1.0,0.0);
	//glRotatef(step,0.0,0.0,1.0);
	//glRotatef(step,1.0,0.0,0.0);
	//DrawColorBox();
	
	Rendercene();
	glPopMatrix();
	glFlush();
	SwapBuffers(hdc);
	// Do not call CWnd::OnPaint() for painting messages
	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	double space=0.0;
  space+=0.005;

  if(space>1.0)

          space=0.1;

   step = step + 1.0;

 if (step > 360.0)

          step = step - 360.0;

  glPushMatrix();

   glScalef(space,space,space);

  glRotatef(step,0.0,1.0,0.0);

  glRotatef(step,0.0,0.0,1.0);

  glRotatef(step,1.0,0.0,0.0);

 

  LightShine();                             //添加光照属性

   glutSolidSphere(200.0,20,16);                  //绘制球体
  
  glPopMatrix();

  glFlush();

 

   SwapBuffers(hdc);                         //使用双缓存技术实现交换缓冲区*/
}

int MyOpenGL::MySetPixelFormat(HDC hDC)
{
	PIXELFORMATDESCRIPTOR pixelDesc;

	pixelDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelDesc.nVersion = 1;

	pixelDesc.dwFlags = PFD_DRAW_TO_WINDOW | 
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER |
		PFD_TYPE_RGBA;

	pixelDesc.iPixelType = PFD_TYPE_RGBA;
	pixelDesc.cColorBits = 32;
	pixelDesc.cRedBits = 0;
	pixelDesc.cRedShift = 0;
	pixelDesc.cGreenBits = 0;
	pixelDesc.cGreenShift = 0;
	pixelDesc.cBlueBits = 0;
	pixelDesc.cBlueShift = 0;
	pixelDesc.cAlphaBits = 0;
	pixelDesc.cAlphaShift = 0;
	pixelDesc.cAccumBits = 0;
	pixelDesc.cAccumRedBits = 0;
	pixelDesc.cAccumGreenBits = 0;
	pixelDesc.cAccumBlueBits = 0;
	pixelDesc.cAccumAlphaBits = 0;
	pixelDesc.cDepthBits = 0;
	pixelDesc.cStencilBits = 1;
	pixelDesc.cAuxBuffers = 0;
	pixelDesc.iLayerType = PFD_MAIN_PLANE;
	pixelDesc.bReserved = 0;
	pixelDesc.dwLayerMask = 0;	
	pixelDesc.dwVisibleMask = 0;
	pixelDesc.dwDamageMask = 0;

	int iPixelFormat; 

	// 为设备描述表得到最匹配的像素格式 
	if((iPixelFormat = ChoosePixelFormat(hDC, &pixelDesc)) == 0)
	{
		MessageBox("ChoosePixelFormat Failed", NULL, MB_OK);
		return FALSE;
	}

	// 设置最匹配的像素格式为当前的像素格式 
	if(SetPixelFormat(hDC, iPixelFormat, &pixelDesc) == FALSE)
	{
		MessageBox("SetPixelFormat Failed", NULL, MB_OK);
		return FALSE;
	}
	return TRUE;
}

void MyOpenGL::Rendercene()
{
	/*glBegin(GL_LINES);
	glVertex2f(-0.5f,-0.3f);
	glVertex2f(0.4f,0.6f);
	glEnd();*/
	double theta = 0.00001;
	double delta=theta;
	double r=2;
	int n=314150*2;
	double h=5;
	//柱面
	glBegin(GL_QUAD_STRIP);
	glColor3d(1.0,0.5,1.0);
	glVertex3d(r, 0, h);
	glColor3d(1.0,0.5,1.0);
	glVertex3d(r, 0, 0);
	for (int i = 1; i < n; ++i)
	{
		double x = r * cos(theta);
		double y = r * sin(theta);
		glColor3d(1.0,0.5,1.0);
		glVertex3d(x, y, h);
		glColor3d(1.0,0.5,1.0);
		glVertex3d(x, y, 0);
		theta += delta;
	}
	glVertex3d(r, 0, h);
	glVertex3d(r, 0, 0);
	glEnd();
	//下底面
	
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(1.0,0.7,0.7);
	glVertex3d(0, 0, 0);
	glColor3d(1.0,0.7,0.7);
	glVertex3d(r, 0, 0);
	
	for (int i = 1; i < n; ++i)
	{	
		double x = r * cos(theta);
		double y = r * sin(theta);
		glColor3d(1.0,0.7,0.7);
		glVertex3d(x, y, 0);
		
		theta += delta;
	}
	glColor3d(1.0,0.7,0.7);
	glVertex3d(r, 0, 0);
	glEnd();
	//上底面
	
	glBegin(GL_TRIANGLE_FAN);

	glColor3d(1.0,0.5,0);
	glVertex3d(0, 0, h);
	glColor3d(1.0,0.5,0);
	glVertex3d(r, 0, h);
	for (int i = 0; i < n; ++i)
	{
		double x = r * cos(theta);
		double y = r * sin(theta);
		glColor3d(1.0,0.5,0);
		glVertex3d(x, y, h);
		theta += delta;
	}
	glColor3d(1.0,0.5,0);
	glVertex3d(r, 0, h);
	glEnd();
  

    

	
}

void MyOpenGL::DrawColorBox()
{
	GLfloat p1[]={0.5,-0.5,-0.5}, p2[]={0.5,0.5,-0.5},
		p3[]={0.5,0.5,0.5}, p4[]={0.5,-0.5,0.5},
		p5[]={-0.5,-0.5,0.5}, p6[]={-0.5,0.5,0.5},
		p7[]={-0.5,0.5,-0.5}, p8[]={-0.5,-0.5,-0.5};

	GLfloat m1[]={1.0,0.0,0.0}, m2[]={-1.0,0.0,0.0},
		m3[]={0.0,1.0,0.0}, m4[]={0.0,-1.0,0.0},
		m5[]={0.0,0.0,1.0}, m6[]={0.0,0.0,-1.0};


	GLfloat c1[]={0.0,0.0,1.0}, c2[]={0.0,1.0,1.0},
		c3[]={1.0,1.0,1.0}, c4[]={1.0,0.0,1.0},
		c5[]={1.0,0.0,0.0}, c6[]={1.0,1.0,0.0},
		c7[]={0.0,1.0,0.0}, c8[]={1.0,1.0,1.0};


	glBegin (GL_QUADS); //绘制多个四边形

	glColor3fv(c1);
	glNormal3fv(m1);
	glVertex3fv(p1);
	glColor3fv(c2);
	glVertex3fv(p2);
	glColor3fv(c3);
	glVertex3fv(p3);
	glColor3fv(c4);
	glVertex3fv(p4);

	glColor3fv(c5);
	glNormal3fv(m5);
	glVertex3fv(p5);
	glColor3fv(c6);
	glVertex3fv(p6);
	glColor3fv(c7);
	glVertex3fv(p7);
	glColor3fv(c8);
	glVertex3fv(p8);
	glColor3fv(c5);
	glNormal3fv(m3);
	glVertex3fv(p5);
	glColor3fv(c6);
	glVertex3fv(p6);
	glColor3fv(c3);
	glVertex3fv(p3);
	glColor3fv(c4);
	glVertex3fv(p4);

	glColor3fv(c1);
	glNormal3fv(m4);
	glVertex3fv(p1);
	glColor3fv(c2);
	glVertex3fv(p2);
	glColor3fv(c7);
	glVertex3fv(p7);
	glColor3fv(c8);
	glVertex3fv(p8);

	glColor3fv(c2);
	glNormal3fv(m5);
	glVertex3fv(p2);
	glColor3fv(c3);
	glVertex3fv(p3);
	glColor3fv(c6);
	glVertex3fv(p6);
	glColor3fv(c7);
	glVertex3fv(p7);

	glColor3fv(c1);
	glNormal3fv(m6);
	glVertex3fv(p1);
	glColor3fv(c4);
	glVertex3fv(p4);
	glColor3fv(c5);
	glVertex3fv(p5);
	glColor3fv(c8);
	glVertex3fv(p8);

	glEnd();
}



/*void MyOpenGL::LightShine(void)

{

 

       GLfloat mat_diffuse[4]={1,0.5,0.5,1.0};

       GLfloat mat_specular[4]={1.0,1.0,1.0,1.0};

       GLfloat mat_shininess[1]={100.0};

    //光源 1

       GLfloat light_position0[4]={0,500,500,0};

       glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);

       glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);

       glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

       glLightfv(GL_LIGHT0,GL_POSITION,light_position0);

       glEnable(GL_LIGHT0);

       //光源 2   

       GLfloat light_position1[4]={1000,-1000,1000,0};

       GLfloat mat_diffuse1[4]={0.5,0.5,1.0,1.0};

       glLightfv(GL_LIGHT1,GL_DIFFUSE,mat_diffuse1);

       glLightfv(GL_LIGHT1,GL_SPECULAR,mat_specular);

       glLightfv(GL_LIGHT1,GL_SHININESS,mat_shininess);

       glLightfv(GL_LIGHT1,GL_POSITION,light_position1);

       glEnable(GL_LIGHT1);

 

       //使模型能接受光照

       glEnable(GL_LIGHTING); 

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);

    glDepthFunc(GL_LESS);

glEnable(GL_DEPTH_TEST);

//计算定点法线

glEnable(GL_AUTO_NORMAL);

glEnable(GL_NORMALIZE);

 

}
*/
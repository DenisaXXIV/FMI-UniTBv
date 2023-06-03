#include "framework.h"
#include "Lab2 - Hello DirectX 9.h"

#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")

// define the screen resolution #define SCREEN_WIDTH 800 #define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define DELTA_WIDTH 0
#define DELTA_HEIGHT 10

// global declarations
LPDIRECT3D9 d3d;			// the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;	// the pointer to the device class
LPDIRECT3DVERTEXBUFFER9 pVertexBuffer; // the pointer to the vertex buffer 

#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

struct CUSTOMVERTEX		// Custom vertex structure
{
	FLOAT x, y, z, rhw;		// from the D3DFVF_XYZRHW flag
	DWORD color;			// from the D3DFVF_DIFFUSE flag
};

void InitD3D(HWND hWnd);	// sets up and initializes Direct3D
void RenderFrame(void);		// renders a single frame
void CleanD3D(void);		// closes Direct3D and releases memory

void InitD3D(HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);		// create the Direct3D interface
	D3DPRESENT_PARAMETERS d3dpp;				// create a struct to hold various device information
	ZeroMemory(&d3dpp, sizeof(d3dpp));			// clear out the struct for use
	d3dpp.Windowed = TRUE;						// program windowed, not fullscreen
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	// discard old frames
	d3dpp.hDeviceWindow = hWnd;					// set the window to be used by Direct3D

	// create a device class using this information and information from the d3dpp stuct 
	d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddev);

	d3ddev->CreateVertexBuffer(3 * sizeof(CUSTOMVERTEX),
		0,
		CUSTOMFVF,
		D3DPOOL_MANAGED,
		&pVertexBuffer,
		NULL);

	RECT windowRect;
	GetClientRect(hWnd, &windowRect);

	VOID* pVoid; // the void pointer
	pVertexBuffer->Lock(0, 0, (void**)&pVoid, 0); // lock the vertex buffer 
	CUSTOMVERTEX pTriangleVertices[] =
	{
		{ SCREEN_WIDTH / 2.0, DELTA_HEIGHT, 1.0f, 1.0f, D3DCOLOR_XRGB(0, 0, 255),},
		{ SCREEN_WIDTH - DELTA_WIDTH, SCREEN_HEIGHT - DELTA_HEIGHT, 1.0f,
			1.0f, D3DCOLOR_XRGB(0, 255, 0), },
		{ DELTA_WIDTH,SCREEN_HEIGHT - DELTA_HEIGHT, 1.0F , 1.0F, D3DCOLOR_XRGB(255, 0, 0), },
	};
	memcpy(pVoid, pTriangleVertices, sizeof(pTriangleVertices)); // copy the vertices to the locked buffer
	pVertexBuffer->Unlock(); // unlock the vertex buffer
}

void RenderFrame(void)
{
	// clear the window to a deep blue
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);

	d3ddev->BeginScene(); // begins the 3D scene
	{ // do 3D rendering on the back buffer here

		// select which vertex format we are using 
		d3ddev->SetFVF(CUSTOMFVF);

		// select the vertex buffer to display
		d3ddev->SetStreamSource(0, pVertexBuffer, 0, sizeof(CUSTOMVERTEX));

		// copy the vertex buffer to the back buffer
		d3ddev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
	}
	d3ddev->EndScene(); // ends the 3D scene

	d3ddev->Present(NULL, NULL, NULL, NULL); //displays the created frame
}

void CleanD3D(void)
{
	pVertexBuffer->Release();	// close and release the vertex buffer
	d3ddev->Release();			// close and release the 3D device
	d3d->Release();				// close and release Direct3D
}

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;							// current instance
WCHAR szTitle[MAX_LOADSTRING];				// The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];		// the main window class name


//Forward declarations of functions included in this code module:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int, HWND&);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE			hInstance,
	_In_opt_ HINSTANCE	hPrevInstance,
	_In_ LPWSTR			lpCmdLine,
	_In_ int				nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	// TODO: Place code here.


	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_LAB2HELLODIRECTX9, szWindowClass, MAX_LOADSTRING);

	MyRegisterClass(hInstance);

	// Perform application initialization:
	HWND hWnd;
	if (!InitInstance(hInstance, nCmdShow, hWnd)) {
		return FALSE;
	}

	InitD3D(hWnd);

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB2HELLODIRECTX9));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0)) {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			RenderFrame();
		}
	}

	CleanD3D();

	return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB2HELLODIRECTX9)); wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LAB2HELLODIRECTX9); wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow, HWND& hWnd)
{
	hInst = hInstance; // Store instance handle in our global variable
	hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, SCREEN_WIDTH,
		SCREEN_HEIGHT, nullptr, nullptr, hInstance, nullptr);
	if (!hWnd) {
		return FALSE;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId) {
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
		}
		break;
	}

	case WM_PAINT:
	{
		//PAINTSTRUCT ps;
		//HDC hdc = BeginPaint (hWnd, &ps);
		//// TODO: Add any drawing code that uses hdc here... 
		//EndPaint (hWnd, &ps);
	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message) {
	case WM_INITDIALOG:
		return(INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

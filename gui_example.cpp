#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <tchar.h>
#include <windows.h>

/* Declare Windows procedure */
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

/* Make the class name into a global variable */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

HWND textbox;
HWND button;

int WINAPI WinMain(
    HINSTANCE hThisInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpszArgument,
    int nCmdShow
)
{
    HWND hwnd;          /* This is the handle for our window */
    MSG messages;       /* Here messages to the application are saved */
    WNDCLASSEX wincl;   /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;    /* This function is called by windows */
    wincl.style = CS_DBLCLKS;               /* Catch double-clicks */
    wincl.cbSize = sizeof(WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);

    wincl.lpszMenuName = NULL;  /* No menu */
    wincl.cbClsExtra = 0;       /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;       /* structure or the window instance */

    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) 0;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx(&wincl)) {
        return 0;
    }

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx(
               0,                   /* Extended possibilites for variation */
               szClassName,         /* Classname */
               _T("GUI example"),   /* Title Text */
               WS_OVERLAPPEDWINDOW, /* default window */
               CW_USEDEFAULT,       /* Windows decides the position */
               CW_USEDEFAULT,       /* where the window ends up on the screen */
               400,                 /* The programs width */
               100,                 /* and height in pixels */
               HWND_DESKTOP,        /* The window is a child-window to desktop */
               NULL,                /* No menu */
               hThisInstance,       /* Program Instance handler */
               NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow(hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage(&messages, NULL, 0, 0)) {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

/* This function is called by the Windows function DispatchMessage() */
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    char old_text[20];

    switch (message) {

    case WM_DESTROY:
        PostQuitMessage(0);    /* send a WM_QUIT to the message queue */
        break;

    case WM_COMMAND:
        if (wParam == 1) {
            GetWindowText(textbox, &old_text[0], 20);
            char new_text[60] = "You have ";
            strcat(strcat(new_text, old_text), " kg.");
            MessageBox(hwnd, (LPSTR)new_text, "Response", MB_OK);
        }
        break;

    case WM_CREATE:
        CreateWindow(
            "STATIC",
            "Enter your weight:",
            WS_VISIBLE | WS_CHILD,
            10,
            20,
            150,
            20,
            hwnd, NULL, NULL, NULL
        );

        textbox = CreateWindow(
                      "EDIT",
                      "",
                      WS_VISIBLE | WS_CHILD | WS_BORDER,
                      150,
                      20,
                      100,
                      20,
                      hwnd, NULL, NULL, NULL
                  );

        button = CreateWindow(
                     "BUTTON",
                     "Enter",
                     WS_VISIBLE | WS_CHILD | WS_BORDER,
                     270,
                     20,
                     60,
                     20,
                     hwnd, (HMENU) 1, NULL, NULL
                 );
        break;

    default:
        return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}
